/* 設計製作論演習３
 ・シリアル送信機能
 ・タイマ割り込み機能
  Ver.1 2007 Nakajima
  modified Ietomi 2010.9.28(Nakajima Lab.)*/

#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "kik_std2.h"
#include "init.c"
COMMTIMEOUTS timeout;

//マニピュレータ補助基板とのシリアル通信設定
void InitSerWrite(DCB dcb, HANDLE* hCommW, BaudRate baud)
{
		*hCommW = CreateFile(
        "COM4",                       // シリアルポートの指定     自分のPCのものを設定する．デバイスマネージャで確認
         GENERIC_READ | GENERIC_WRITE,// アクセスモード 
        0,                            // 共有モード 
        NULL,                         // セキュリティ属性 
        OPEN_EXISTING,                // 作成フラグ 
        FILE_ATTRIBUTE_NORMAL,        // 属性 
        NULL                          // テンプレートのハンドル 
    ); 
  
    GetCommState(*hCommW, &dcb); /* DCB を取得 */
    dcb.BaudRate = baud;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    SetCommState(*hCommW, &dcb); /* DCB を設定 */
}


//コールバック関数 規定時間(時間イベント)で繰り返し処理される関数．タイマ割り込みのようなもの
VOID CALLBACK TimerProc(HWND hwnd , UINT uMsg ,UINT idEvent , DWORD dwTime) {
	HDC hdc;
	TCHAR strCount[64];
	unsigned char senddat1=0, comma=',',flag=0x0d, comdat[64]={0};
	char s[6];
	int k,kk,j;
	unsigned int AD_dat[3]={0},i;
	hdc = GetDC(hwnd);
	
	static unsigned int time_cnt=0,seq_local=0,n=0,display_cnt;

	//タイマ割り込み関数にdisplayを置くことで周期的に描写
	display_cnt++;
	if(display_cnt==1){//画面がちらちらして見づらかったらここの数値を増やす(その分動きは荒く見える)
		display();
		display_cnt=0;
	}

	//====================================================//
	//ここに自分オリジナルのマニピュレータ動作戦略を書く！//
	//====================================================//
	if(StrategyStart==ON){
		if(ModeControl == SYS_OPE){
			switch(StrategyNumber){
				case 0:break;
					//何もしない
				
				case 1://サンプル戦略①：一定のシーケンスを延々続けるだけ
					if(n==0){
						JointAngle[1]=43;JointAngle[2]=92;JointAngle[3]=42;JointAngle[4]=20;
					}
					if(n>50 && n<=100){
						JointAngle[3]--;
						JointAngle[4]=JointAngle[4]-2;
					}else if(n>100 && n<=150){
						JointAngle[3]++;
						JointAngle[4]=JointAngle[4]+2;
					}else if(n>150 && n<=200){
						JointAngle[1]--;
					}else if(n>200 & n<=300){
						//待ち
					}else if(n>300 && n<=350){
						JointAngle[1]++;
					}else if((n>0 && n<=50) || (n>350 && n<=400)){
					
					}else{n=0;}
					n++;
				break;
				
				case 2://サンプル戦略②：AD情報を使ってシーケンスの動きを変える
					
					if(AD_Data[0] > 800) seq_local=1;
					if(AD_Data[1] > 800) seq_local=0;
					if(AD_Data[0] > 800 && AD_Data[1] > 800){
						
					}else{
						time_cnt++;
						if(time_cnt==1){
							time_cnt=0;
							if(seq_local==0){
								JointAngle[1] +=2;
								if(JointAngle[1]>100){
									 seq_local=1;
									 senddat2=0x23;
								}
							}else{
								JointAngle[1] -=2;
								if(JointAngle[1]<-100){
									 seq_local=0;
									 senddat2=0x24;
								}
							}
						}
					}
					if(JointAngle[1]>120) JointAngle[1]=120;
					if(JointAngle[1]<-120) JointAngle[1]=-120;

				break;
				case 3:
					time_cnt++;
					if(time_cnt<20){
						JointAngle[1]=0; JointAngle[2]=40; JointAngle[3]=40; JointAngle[4]=40; JointAngle[5]=0;
					}else if(time_cnt<40){
						JointAngle[1]=90; JointAngle[2]=0; JointAngle[3]=60; JointAngle[4]=0; JointAngle[5]=0;
					}else if(time_cnt<60){
						JointAngle[1]=0; JointAngle[2]=40; JointAngle[3]=40; JointAngle[4]=40; JointAngle[5]=0;						
					}else{
						JointAngle[1]=-90; JointAngle[2]=0; JointAngle[3]=60; JointAngle[4]=0; JointAngle[5]=0;						
					}
					
					if(time_cnt>80) time_cnt=0;
				break;
				default:break;
			}
		}else if(ModeControl == MANU_OPE){
		  	//手動操作中に何か動きを追加したければここに書く．手動操作時にセンサ情報を用いるなど．
		}else if(ModeControl == PREPARE){
		 	//初期姿勢に戻す
			JointAngle[1]=0;  JointAngle[2]=40; JointAngle[3]=40;
		 	JointAngle[4]=40; JointAngle[5]=0;
		}
	}
	
	//リンクパラメータに関節角度を代入
	LINK_PARAMETERS[1][3] =  rad(JointAngle[1]);
	LINK_PARAMETERS[2][3] = -rad(JointAngle[2]) + (M_PI/2.0);
	LINK_PARAMETERS[3][3] = -rad(JointAngle[3]);
	LINK_PARAMETERS[4][3] = -rad(JointAngle[4]) + (M_PI/2.0);
	LINK_PARAMETERS[5][3] =  rad(JointAngle[5]);
	
	//================目標関節角度，電磁弁制御信号の送信部分(特にいじらない方が吉)===========//
	 //送信変数mani_data[i]に目標角度JointAngleを代入
	for(i=0;i<=4;i++) mani_data[i]=(int)JointAngle[i+1];		
	
	//送信関節角度のリミッタ
	if(mani_data[0] > J1_ULMT) mani_data[0] = J1_ULMT;
	if(mani_data[0] < J1_LLMT) mani_data[0] = J1_LLMT;
	if(mani_data[1] > J2_ULMT) mani_data[1] = J2_ULMT;
	if(mani_data[1] < J2_LLMT) mani_data[1] = J2_LLMT;
	if(mani_data[2] > J3_ULMT) mani_data[2] = J3_ULMT;
	if(mani_data[2] < J3_LLMT) mani_data[2] = J3_LLMT;
	if(mani_data[3] > J4_ULMT) mani_data[3] = J4_ULMT;
	if(mani_data[3] < J4_LLMT) mani_data[3] = J4_LLMT;
	if(mani_data[4] > J5_ULMT) mani_data[4] = J5_ULMT;
	if(mani_data[4] < J5_LLMT) mani_data[4] = J5_LLMT;

	
	//mani_data[i]をアスキー文字に変換してマニピュレータ補助基板に送信．
	//プロトコルは  45,30,20,10,45＠CRといった具合に第1関節から第5関節までカンマで区切り，最後にCR(0x0d)をつける．
	//＠部分はマニピュレータ自体には送信されないが，電磁弁制御指令をボードに送るための送信枠
	for(k=0;k<5;k++){
		kk=0;
		if(mani_data[k]==0){
			senddat1='0';
			WriteFile(hCommW,&senddat1,1,&writesize1,NULL);
		}
		if(mani_data[k]>=0) j=mani_data[k];
		else{
			j=-mani_data[k];
			senddat1='-';
			WriteFile(hCommW,&senddat1,1,&writesize1,NULL);
		}
		while(0<j){
			s[kk++]=j-((int)(j/10)*10);
			j=(long)j/10;
		}
		while(kk!=0){
			kk-=1;
			senddat1='0'+s[kk];
			WriteFile(hCommW,&senddat1,1,&writesize1,NULL);	//ハンド行きのｼﾘｱﾙ通信
		}
		if(k!=4){
			WriteFile(hCommW,&comma,1,&writesize1,NULL);//１つの関節角度情報の送信後，”，”を送信
		}else{
			
			WriteFile(hCommW,&senddat2,1,&writesize1,NULL);//電磁弁の制御信号の送信
			WriteFile(hCommW,&flag,1,&writesize1,NULL);    //マニピュレータ角度指令のエンドフラグ(CR(0x0d))の送信
		}
	}
	//==================================================================================================//
		
	//==================マニピュレータ補助ボードからのデータ受信（AD，IO）==================//
	ReadFile(hCommW, &comdat, 7, &readsize, NULL);
	//AD情報の組み立て＆IO情報の取得（12bitADデータを2分割して6bitデータを組み立てなおす）
	AD_dat[0] = (unsigned int)comdat[1];
	AD_dat[0] = AD_dat[0] | (unsigned int)(comdat[0]<<6);
	AD_dat[1] = (unsigned int)comdat[3];
	AD_dat[1] = AD_dat[1] | (unsigned int)(comdat[2]<<6);
	AD_dat[2] = (unsigned int)comdat[5];
	AD_dat[2] = AD_dat[2] | (unsigned int)(comdat[4]<<6);
	//======================================================================================//
	//AD情報を大域変数への代入（たまたま使用しているだけ）
	AD_Data[0] = AD_dat[0];
	AD_Data[1] = AD_dat[1];
	AD_Data[2] = AD_dat[2];
	io_status=comdat[6];
	
	//====================  表示系 ==================//
	//第1関節角度表示
	wsprintf(strCount , "θ1 = %d°" ,(int)JointAngle[1]);
	TextOut(hdc , 0 , 10 , strCount , lstrlen(strCount));
	//第2関節角度表示
	wsprintf(strCount , "θ2 = %d°" ,(int)JointAngle[2]);
	TextOut(hdc , 0 , 30 , strCount , lstrlen(strCount));
	//第3関節角度表示
	wsprintf(strCount , "θ3 = %d°" ,(int)JointAngle[3]);
	TextOut(hdc , 0 , 50 , strCount , lstrlen(strCount));
	//第4関節角度表示
	wsprintf(strCount , "θ4 = %d°" ,(int)JointAngle[4]);
	TextOut(hdc , 0 , 70 , strCount , lstrlen(strCount));
	//第5関節角度表示
	wsprintf(strCount , "θ5 = %d°" ,(int)JointAngle[5]);
	TextOut(hdc , 0 , 90 , strCount , lstrlen(strCount));
	
	//AD[0]表示
	wsprintf(strCount , "AD[0] = %d" ,(int)AD_Data[0]);
	TextOut(hdc , 270 , 10 , strCount , lstrlen(strCount));
	//AD[1]表示
	wsprintf(strCount , "AD[1] = %d" ,(int)AD_Data[1]);
	TextOut(hdc , 270 , 30 , strCount , lstrlen(strCount));
	//AD[2]表示
	wsprintf(strCount , "AD[2] = %d" ,(int)AD_Data[2]);
	TextOut(hdc , 270 , 50 , strCount , lstrlen(strCount));
	//IO情報の表示
	wsprintf(strCount , "IO = %d" ,(int)comdat[6]);
	TextOut(hdc , 270 , 70 , strCount , lstrlen(strCount));
	
	
	
	
	//電磁弁の状態表示
	if(senddat2==0x24){
		wsprintf(strCount , "ELE_VALVE = CLOSE" );
		TextOut(hdc , 400 , 30 , strCount , lstrlen(strCount));
	}else{
		wsprintf(strCount , "ELE_VALVE = OPEN");
		TextOut(hdc , 400 , 30 , strCount , lstrlen(strCount));
	}
	//StrategyStartの状態表示
	if(StrategyStart==ON){
		//wsprintf(strCount , "Stra = ON" ,(int)StrategyStart);
		wsprintf(strCount , "StraStart = ON" );
		TextOut(hdc , 400 , 50 , strCount , lstrlen(strCount));
	}else{
		wsprintf(strCount , "StraStart = OFF");
		TextOut(hdc , 400 , 50 , strCount , lstrlen(strCount));
	}
	
	
	//戦略番号の表示
	wsprintf(strCount , "StraNumber = %d",(int)StrategyNumber);
	TextOut(hdc , 400 , 70 , strCount , lstrlen(strCount));
	
	//モードの表示
	if(ModeControl==PREPARE){
		wsprintf(strCount , "ModeControl = PREPARE" );
		TextOut(hdc , 400 , 90 , strCount , lstrlen(strCount));
	}else if(ModeControl == SYS_OPE){
		wsprintf(strCount , "ModeControl = SYS_OPE");
		TextOut(hdc , 400 , 90 , strCount , lstrlen(strCount));
	}else if(ModeControl == MANU_OPE){
		wsprintf(strCount , "ModeControl = MANU_OPE");
		TextOut(hdc , 400 , 90 , strCount , lstrlen(strCount));
	}

	
	//マウス座標の表示（おまけ要素。使いたい人はマウス座標で関節角度の目標角度を変えていくとか）
	wsprintf(strCount , "Mouse(%d,%d)" ,mouse_x,mouse_y);
	TextOut(hdc , 20 , 200 , strCount , lstrlen(strCount));
	
	
	ReleaseDC(hwnd , hdc);
}



//====================================== Windowsプログラムの特徴的処理部分 ==========================================//
//Windowsプログラムはマウス，キーボード，ｳｨﾝﾄﾞｳ操作，規定時間経過などの”イベント”というものが発生したとき
//ここの関数が呼ばれ，イベントに対応した処理を”自分の好きなように”記述していくことでプログラミングすることになる．
//===================================================================================================================//
LRESULT CALLBACK WndProc(HWND hwnd , UINT msg , WPARAM wp , LPARAM lp) {
	HDC hdc;
	TCHAR strCount[64];
	
	switch (msg) {

	case WM_DESTROY:
		//MessageBox(NULL, "プログラム終了", "確認", MB_OK);
		PostQuitMessage(0);
		return 0;

	case WM_CREATE://Windowが生成された時に行われるイベント処理(多分最初に実行したタイミングの一回のみ処理される)
		//上のコールバック関数をどういう割り込みでやるか
		SetTimer(hwnd , 1 , 50 , TimerProc);//50msecで割り込み おおよそ・・・
		return 0;
	    
	case WM_COMMAND:break;
	
  	case WM_PAINT:// 描画ウィンドウに変化がおこるイベント時に実行される場所
		break;
		
	case WM_CHAR://キーボードが押されたとき，wp変数には押されたキー情報が代入されているのでwpの違いで処理の変更．好きに変えましょう．
		
		
		if(ModeControl==MANU_OPE && StrategyStart==ON){
			//----------J1----------
			if(wp=='q') JointAngle[1]+=2;
			if(wp=='a') JointAngle[1]-=2;
			if(JointAngle[1] > J1_ULMT) JointAngle[1] = J1_ULMT;
			if(JointAngle[1] < J1_LLMT) JointAngle[1] = J1_LLMT;
			//----------J2----------
			if(wp=='w') JointAngle[2]++;
			if(wp=='s') JointAngle[2]--;
			if(JointAngle[2] > J2_ULMT) JointAngle[2] = J2_ULMT;
			if(JointAngle[2] < J2_LLMT) JointAngle[2] = J2_LLMT;
			//----------J3----------
			if(wp=='e') JointAngle[3]++;
			if(wp=='d') JointAngle[3]--;
			if(JointAngle[3] > J3_ULMT) JointAngle[3] = J3_ULMT;
			if(JointAngle[3] < J3_LLMT) JointAngle[3] = J3_LLMT;
			//----------J4----------
			if(wp=='r') JointAngle[4]++;
			if(wp=='f') JointAngle[4]--;
			if(JointAngle[4] > J4_ULMT) JointAngle[4] = J4_ULMT;
			if(JointAngle[4] < J4_LLMT) JointAngle[4] = J4_LLMT;
			//----------J5----------
			if(wp=='t') JointAngle[5]+=2;
			if(wp=='g') JointAngle[5]-=2;
			if(JointAngle[5] > J5_ULMT) JointAngle[5] = J5_ULMT;
			if(JointAngle[5] < J5_LLMT) JointAngle[5] = J5_LLMT;
			//----------------------
			
		}
		
		
		//手動操作 or オートシステム動作の選択
		     if(wp == 'm') ModeControl = MANU_OPE;
		else if(wp == 'n') ModeControl = SYS_OPE;
		else if(wp == 'p') ModeControl = PREPARE;
		
		
		//戦略番号の指定
		
		if(wp == '0') StrategyNumber = 0;
		if(wp == '1') StrategyNumber = 1;
		if(wp == '2') StrategyNumber = 2;
		if(wp == '3') StrategyNumber = 3;
		
		//xが押された場合電磁弁の制御信号のON，OFFを変える
		if(wp=='x'){
			if(senddat2==0x24) senddat2=0x23;//開き
			else senddat2=0x24;
		}
		//zが押された場合スタートフラグがONとなる(別にこれを使わなくてもよい)
		if(wp=='z'){
			 StrategyStart=!StrategyStart;
		}
		//cを押すと強制的に目標関節角度を0[deg]にする
		/*if(wp=='c'){
			JointAngle[1]=JointAngle[2]=JointAngle[3]=JointAngle[4]=JointAngle[5]=0;
		}*/
		break;

	case WM_MOUSEMOVE://マウス位置が変化した場合におきるイベント処理
		//マウス位置をmouse変数に代入(使いたい人は使う)
		mouse_x = LOWORD(lp);
		mouse_y = HIWORD(lp);
		if(io_status==0 && mouse_y>300) JointAngle[1]=(mouse_x-400)/1;
		if(io_status==0 && mouse_y>300) JointAngle[3]=(mouse_y-400)/1;
//		if(io_status==0 && mouse_y>300) JointAngle[4]=(mouse_x-400)/1;
//		if(io_status==0 && mouse_y>300) JointAngle[5]=(mouse_x-400)/1;
		if(JointAngle[1] > J1_ULMT) JointAngle[1] = J1_ULMT;
		if(JointAngle[1] < J1_LLMT) JointAngle[1] = J1_LLMT;
		if(JointAngle[2] > J2_ULMT) JointAngle[2] = J2_ULMT;
		if(JointAngle[2] < J2_LLMT) JointAngle[2] = J2_LLMT;
		if(JointAngle[3] > J3_ULMT) JointAngle[3] = J3_ULMT;
		if(JointAngle[3] < J3_LLMT) JointAngle[3] = J3_LLMT;
		if(JointAngle[4] > J4_ULMT) JointAngle[4] = J4_ULMT;
		if(JointAngle[4] < J4_LLMT) JointAngle[4] = J4_LLMT;
		if(JointAngle[5] > J5_ULMT) JointAngle[5] = J5_ULMT;
		if(JointAngle[5] < J5_LLMT) JointAngle[5] = J5_LLMT;
		return 0;
	case WM_LBUTTONDOWN://マウスの左ボタンが押された場合に入るイベント処理(これも好きに使ってよい，右クリックなどもある．自分で調べよう)
		
		if(MK_LBUTTON==wp){
		if(mouse_x > 400 && mouse_y > 300) JointAngle[1]+=5;
		if(mouse_x < 400 && mouse_y > 300) JointAngle[1]-=5;
		if(JointAngle[1] > J1_ULMT) JointAngle[1] = J1_ULMT;
		if(JointAngle[1] < J1_LLMT) JointAngle[1] = J1_LLMT;
		}
		
		break;
	}
	
	return DefWindowProc(hwnd , msg , wp , lp);
}



/////WindowsプログラムのMain部分基本的に初期設定を行う(あまりいじることはない)
int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance ,PSTR lpCmdLine , int nCmdShow ){
	HWND hwnd;
	MSG msg;
	WNDCLASS winc;

	DCB dcb;                 //通信パラメータ
    BaudRate baud=br9600;    //BaudRate設定用

	//マニピュレータ初期角度の代入
	mani_data[0]=0;mani_data[1]=40;mani_data[2]=40;mani_data[3]=40;mani_data[4]=0;
	JointAngle[1]=mani_data[0];
	JointAngle[2]=mani_data[1];
	JointAngle[3]=mani_data[2];
	JointAngle[4]=mani_data[3];
	JointAngle[5]=mani_data[4];
	
	

	InitSerWrite(dcb, &hCommW, baud);
	
	//タイムアウト系設定部分
	GetCommTimeouts(hCommW,&timeout);
	timeout.ReadIntervalTimeout         = MAXDWORD; // 文字読み込みの間の時間(即時戻り)
	timeout.ReadTotalTimeoutMultiplier  = 0;
	timeout.ReadTotalTimeoutConstant    = 10; // 10msでタイムアウト(Read)
    SetCommTimeouts(hCommW,&timeout);
	
	winc.style		= CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc	= WndProc;
	winc.cbClsExtra	= winc.cbWndExtra	= 0;
	winc.hInstance		= hInstance;
	winc.hIcon		= LoadIcon(NULL , IDI_APPLICATION);
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpszClassName	= TEXT("NAKAJIMA");

	if (!RegisterClass(&winc)) return -1;

	hwnd = CreateWindow(
			TEXT("NAKAJIMA") , TEXT("TEST") ,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE ,
			CW_USEDEFAULT , CW_USEDEFAULT ,
			CW_USEDEFAULT , CW_USEDEFAULT ,
			NULL , NULL , hInstance , NULL
	);

	if (hwnd == NULL) return -1;

	
	matrix_alloc( &T, 4, 4 );//行列Tの確保
  	kik_init( hwnd );//描画のための初期化
  	init_link_parameters();//リンクパラメータの初期化
	
	
	while(GetMessage(&msg , NULL , 0 , 0)){
		DispatchMessage(&msg);
		TranslateMessage(&msg);	//入力された数値の変換のための呼び出し関数
	}

	CloseHandle(hCommW);
	return msg.wParam;
}
