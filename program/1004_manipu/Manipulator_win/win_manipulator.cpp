/* �݌v����_���K�R
 �E�V���A�����M�@�\
 �E�^�C�}���荞�݋@�\
  Ver.1 2007 Nakajima
  modified Ietomi 2010.9.28(Nakajima Lab.)*/

#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "kik_std2.h"
#include "init.c"
COMMTIMEOUTS timeout;

//�}�j�s�����[�^�⏕��Ƃ̃V���A���ʐM�ݒ�
void InitSerWrite(DCB dcb, HANDLE* hCommW, BaudRate baud)
{
		*hCommW = CreateFile(
        "COM4",                       // �V���A���|�[�g�̎w��     ������PC�̂��̂�ݒ肷��D�f�o�C�X�}�l�[�W���Ŋm�F
         GENERIC_READ | GENERIC_WRITE,// �A�N�Z�X���[�h 
        0,                            // ���L���[�h 
        NULL,                         // �Z�L�����e�B���� 
        OPEN_EXISTING,                // �쐬�t���O 
        FILE_ATTRIBUTE_NORMAL,        // ���� 
        NULL                          // �e���v���[�g�̃n���h�� 
    ); 
  
    GetCommState(*hCommW, &dcb); /* DCB ���擾 */
    dcb.BaudRate = baud;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    SetCommState(*hCommW, &dcb); /* DCB ��ݒ� */
}


//�R�[���o�b�N�֐� �K�莞��(���ԃC�x���g)�ŌJ��Ԃ����������֐��D�^�C�}���荞�݂̂悤�Ȃ���
VOID CALLBACK TimerProc(HWND hwnd , UINT uMsg ,UINT idEvent , DWORD dwTime) {
	HDC hdc;
	TCHAR strCount[64];
	unsigned char senddat1=0, comma=',',flag=0x0d, comdat[64]={0};
	char s[6];
	int k,kk,j;
	unsigned int AD_dat[3]={0},i;
	hdc = GetDC(hwnd);
	
	static unsigned int time_cnt=0,seq_local=0,n=0,display_cnt;

	//�^�C�}���荞�݊֐���display��u�����ƂŎ����I�ɕ`��
	display_cnt++;
	if(display_cnt==1){//��ʂ����炿�炵�Č��Â炩�����炱���̐��l�𑝂₷(���̕������͍r��������)
		display();
		display_cnt=0;
	}

	//====================================================//
	//�����Ɏ����I���W�i���̃}�j�s�����[�^����헪�������I//
	//====================================================//
	if(StrategyStart==ON){
		if(ModeControl == SYS_OPE){
			switch(StrategyNumber){
				case 0:break;
					//�������Ȃ�
				
				case 1://�T���v���헪�@�F���̃V�[�P���X�����X�����邾��
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
						//�҂�
					}else if(n>300 && n<=350){
						JointAngle[1]++;
					}else if((n>0 && n<=50) || (n>350 && n<=400)){
					
					}else{n=0;}
					n++;
				break;
				
				case 2://�T���v���헪�A�FAD�����g���ăV�[�P���X�̓�����ς���
					
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
		  	//�蓮���쒆�ɉ���������ǉ���������΂����ɏ����D�蓮���쎞�ɃZ���T����p����ȂǁD
		}else if(ModeControl == PREPARE){
		 	//�����p���ɖ߂�
			JointAngle[1]=0;  JointAngle[2]=40; JointAngle[3]=40;
		 	JointAngle[4]=40; JointAngle[5]=0;
		}
	}
	
	//�����N�p�����[�^�Ɋ֐ߊp�x����
	LINK_PARAMETERS[1][3] =  rad(JointAngle[1]);
	LINK_PARAMETERS[2][3] = -rad(JointAngle[2]) + (M_PI/2.0);
	LINK_PARAMETERS[3][3] = -rad(JointAngle[3]);
	LINK_PARAMETERS[4][3] = -rad(JointAngle[4]) + (M_PI/2.0);
	LINK_PARAMETERS[5][3] =  rad(JointAngle[5]);
	
	//================�ڕW�֐ߊp�x�C�d���ِ���M���̑��M����(���ɂ�����Ȃ������g)===========//
	 //���M�ϐ�mani_data[i]�ɖڕW�p�xJointAngle����
	for(i=0;i<=4;i++) mani_data[i]=(int)JointAngle[i+1];		
	
	//���M�֐ߊp�x�̃��~�b�^
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

	
	//mani_data[i]���A�X�L�[�����ɕϊ����ă}�j�s�����[�^�⏕��ɑ��M�D
	//�v���g�R����  45,30,20,10,45��CR�Ƃ�������ɑ�1�֐߂����5�֐߂܂ŃJ���}�ŋ�؂�C�Ō��CR(0x0d)������D
	//�������̓}�j�s�����[�^���̂ɂ͑��M����Ȃ����C�d���ِ���w�߂��{�[�h�ɑ��邽�߂̑��M�g
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
			WriteFile(hCommW,&senddat1,1,&writesize1,NULL);	//�n���h�s���̼رْʐM
		}
		if(k!=4){
			WriteFile(hCommW,&comma,1,&writesize1,NULL);//�P�̊֐ߊp�x���̑��M��C�h�C�h�𑗐M
		}else{
			
			WriteFile(hCommW,&senddat2,1,&writesize1,NULL);//�d���ق̐���M���̑��M
			WriteFile(hCommW,&flag,1,&writesize1,NULL);    //�}�j�s�����[�^�p�x�w�߂̃G���h�t���O(CR(0x0d))�̑��M
		}
	}
	//==================================================================================================//
		
	//==================�}�j�s�����[�^�⏕�{�[�h����̃f�[�^��M�iAD�CIO�j==================//
	ReadFile(hCommW, &comdat, 7, &readsize, NULL);
	//AD���̑g�ݗ��ā�IO���̎擾�i12bitAD�f�[�^��2��������6bit�f�[�^��g�ݗ��ĂȂ����j
	AD_dat[0] = (unsigned int)comdat[1];
	AD_dat[0] = AD_dat[0] | (unsigned int)(comdat[0]<<6);
	AD_dat[1] = (unsigned int)comdat[3];
	AD_dat[1] = AD_dat[1] | (unsigned int)(comdat[2]<<6);
	AD_dat[2] = (unsigned int)comdat[5];
	AD_dat[2] = AD_dat[2] | (unsigned int)(comdat[4]<<6);
	//======================================================================================//
	//AD������ϐ��ւ̑���i���܂��܎g�p���Ă��邾���j
	AD_Data[0] = AD_dat[0];
	AD_Data[1] = AD_dat[1];
	AD_Data[2] = AD_dat[2];
	io_status=comdat[6];
	
	//====================  �\���n ==================//
	//��1�֐ߊp�x�\��
	wsprintf(strCount , "��1 = %d��" ,(int)JointAngle[1]);
	TextOut(hdc , 0 , 10 , strCount , lstrlen(strCount));
	//��2�֐ߊp�x�\��
	wsprintf(strCount , "��2 = %d��" ,(int)JointAngle[2]);
	TextOut(hdc , 0 , 30 , strCount , lstrlen(strCount));
	//��3�֐ߊp�x�\��
	wsprintf(strCount , "��3 = %d��" ,(int)JointAngle[3]);
	TextOut(hdc , 0 , 50 , strCount , lstrlen(strCount));
	//��4�֐ߊp�x�\��
	wsprintf(strCount , "��4 = %d��" ,(int)JointAngle[4]);
	TextOut(hdc , 0 , 70 , strCount , lstrlen(strCount));
	//��5�֐ߊp�x�\��
	wsprintf(strCount , "��5 = %d��" ,(int)JointAngle[5]);
	TextOut(hdc , 0 , 90 , strCount , lstrlen(strCount));
	
	//AD[0]�\��
	wsprintf(strCount , "AD[0] = %d" ,(int)AD_Data[0]);
	TextOut(hdc , 270 , 10 , strCount , lstrlen(strCount));
	//AD[1]�\��
	wsprintf(strCount , "AD[1] = %d" ,(int)AD_Data[1]);
	TextOut(hdc , 270 , 30 , strCount , lstrlen(strCount));
	//AD[2]�\��
	wsprintf(strCount , "AD[2] = %d" ,(int)AD_Data[2]);
	TextOut(hdc , 270 , 50 , strCount , lstrlen(strCount));
	//IO���̕\��
	wsprintf(strCount , "IO = %d" ,(int)comdat[6]);
	TextOut(hdc , 270 , 70 , strCount , lstrlen(strCount));
	
	
	
	
	//�d���ق̏�ԕ\��
	if(senddat2==0x24){
		wsprintf(strCount , "ELE_VALVE = CLOSE" );
		TextOut(hdc , 400 , 30 , strCount , lstrlen(strCount));
	}else{
		wsprintf(strCount , "ELE_VALVE = OPEN");
		TextOut(hdc , 400 , 30 , strCount , lstrlen(strCount));
	}
	//StrategyStart�̏�ԕ\��
	if(StrategyStart==ON){
		//wsprintf(strCount , "Stra = ON" ,(int)StrategyStart);
		wsprintf(strCount , "StraStart = ON" );
		TextOut(hdc , 400 , 50 , strCount , lstrlen(strCount));
	}else{
		wsprintf(strCount , "StraStart = OFF");
		TextOut(hdc , 400 , 50 , strCount , lstrlen(strCount));
	}
	
	
	//�헪�ԍ��̕\��
	wsprintf(strCount , "StraNumber = %d",(int)StrategyNumber);
	TextOut(hdc , 400 , 70 , strCount , lstrlen(strCount));
	
	//���[�h�̕\��
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

	
	//�}�E�X���W�̕\���i���܂��v�f�B�g�������l�̓}�E�X���W�Ŋ֐ߊp�x�̖ڕW�p�x��ς��Ă����Ƃ��j
	wsprintf(strCount , "Mouse(%d,%d)" ,mouse_x,mouse_y);
	TextOut(hdc , 20 , 200 , strCount , lstrlen(strCount));
	
	
	ReleaseDC(hwnd , hdc);
}



//====================================== Windows�v���O�����̓����I�������� ==========================================//
//Windows�v���O�����̓}�E�X�C�L�[�{�[�h�C����޳����C�K�莞�Ԍo�߂Ȃǂ́h�C�x���g�h�Ƃ������̂����������Ƃ�
//�����̊֐����Ă΂�C�C�x���g�ɑΉ������������h�����̍D���Ȃ悤�Ɂh�L�q���Ă������ƂŃv���O���~���O���邱�ƂɂȂ�D
//===================================================================================================================//
LRESULT CALLBACK WndProc(HWND hwnd , UINT msg , WPARAM wp , LPARAM lp) {
	HDC hdc;
	TCHAR strCount[64];
	
	switch (msg) {

	case WM_DESTROY:
		//MessageBox(NULL, "�v���O�����I��", "�m�F", MB_OK);
		PostQuitMessage(0);
		return 0;

	case WM_CREATE://Window���������ꂽ���ɍs����C�x���g����(�����ŏ��Ɏ��s�����^�C�~���O�̈��̂ݏ��������)
		//��̃R�[���o�b�N�֐����ǂ��������荞�݂ł�邩
		SetTimer(hwnd , 1 , 50 , TimerProc);//50msec�Ŋ��荞�� �����悻�E�E�E
		return 0;
	    
	case WM_COMMAND:break;
	
  	case WM_PAINT:// �`��E�B���h�E�ɕω���������C�x���g���Ɏ��s�����ꏊ
		break;
		
	case WM_CHAR://�L�[�{�[�h�������ꂽ�Ƃ��Cwp�ϐ��ɂ͉����ꂽ�L�[��񂪑������Ă���̂�wp�̈Ⴂ�ŏ����̕ύX�D�D���ɕς��܂��傤�D
		
		
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
		
		
		//�蓮���� or �I�[�g�V�X�e������̑I��
		     if(wp == 'm') ModeControl = MANU_OPE;
		else if(wp == 'n') ModeControl = SYS_OPE;
		else if(wp == 'p') ModeControl = PREPARE;
		
		
		//�헪�ԍ��̎w��
		
		if(wp == '0') StrategyNumber = 0;
		if(wp == '1') StrategyNumber = 1;
		if(wp == '2') StrategyNumber = 2;
		if(wp == '3') StrategyNumber = 3;
		
		//x�������ꂽ�ꍇ�d���ق̐���M����ON�COFF��ς���
		if(wp=='x'){
			if(senddat2==0x24) senddat2=0x23;//�J��
			else senddat2=0x24;
		}
		//z�������ꂽ�ꍇ�X�^�[�g�t���O��ON�ƂȂ�(�ʂɂ�����g��Ȃ��Ă��悢)
		if(wp=='z'){
			 StrategyStart=!StrategyStart;
		}
		//c�������Ƌ����I�ɖڕW�֐ߊp�x��0[deg]�ɂ���
		/*if(wp=='c'){
			JointAngle[1]=JointAngle[2]=JointAngle[3]=JointAngle[4]=JointAngle[5]=0;
		}*/
		break;

	case WM_MOUSEMOVE://�}�E�X�ʒu���ω������ꍇ�ɂ�����C�x���g����
		//�}�E�X�ʒu��mouse�ϐ��ɑ��(�g�������l�͎g��)
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
	case WM_LBUTTONDOWN://�}�E�X�̍��{�^���������ꂽ�ꍇ�ɓ���C�x���g����(������D���Ɏg���Ă悢�C�E�N���b�N�Ȃǂ�����D�����Œ��ׂ悤)
		
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



/////Windows�v���O������Main������{�I�ɏ����ݒ���s��(���܂肢���邱�Ƃ͂Ȃ�)
int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance ,PSTR lpCmdLine , int nCmdShow ){
	HWND hwnd;
	MSG msg;
	WNDCLASS winc;

	DCB dcb;                 //�ʐM�p�����[�^
    BaudRate baud=br9600;    //BaudRate�ݒ�p

	//�}�j�s�����[�^�����p�x�̑��
	mani_data[0]=0;mani_data[1]=40;mani_data[2]=40;mani_data[3]=40;mani_data[4]=0;
	JointAngle[1]=mani_data[0];
	JointAngle[2]=mani_data[1];
	JointAngle[3]=mani_data[2];
	JointAngle[4]=mani_data[3];
	JointAngle[5]=mani_data[4];
	
	

	InitSerWrite(dcb, &hCommW, baud);
	
	//�^�C���A�E�g�n�ݒ蕔��
	GetCommTimeouts(hCommW,&timeout);
	timeout.ReadIntervalTimeout         = MAXDWORD; // �����ǂݍ��݂̊Ԃ̎���(�����߂�)
	timeout.ReadTotalTimeoutMultiplier  = 0;
	timeout.ReadTotalTimeoutConstant    = 10; // 10ms�Ń^�C���A�E�g(Read)
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

	
	matrix_alloc( &T, 4, 4 );//�s��T�̊m��
  	kik_init( hwnd );//�`��̂��߂̏�����
  	init_link_parameters();//�����N�p�����[�^�̏�����
	
	
	while(GetMessage(&msg , NULL , 0 , 0)){
		DispatchMessage(&msg);
		TranslateMessage(&msg);	//���͂��ꂽ���l�̕ϊ��̂��߂̌Ăяo���֐�
	}

	CloseHandle(hCommW);
	return msg.wParam;
}
