//Programed by Kazuhisa Ietomi (Nakajima Lab) 2010.9.25
//千葉工業大学 工学部　未来ロボティクス学科 2年　後期必修科目
//ロボット設計製作論3 マニピュレータ演習用プログラム

//プログラム概要
//1:HOST-PCからシリアル通信で送られてくるマニピュレータ関節角度をマニピュレータへ送信．
//　 また，HOST-PCからの電磁弁開閉指令の実行
//2:マニピュレータ補助基板に接続されているAD,IOなどの入力情報をHOST-PCへ送信
//3:マニピュレータ補助基板上のLCDやLEDなどの表示制御

//dsPIC3012接続概要
//ピン番号　　使用機能　 　　　備考　
//  1:      MCLR       書き込みピン
//  2：     AN0/RB0   　（INPUT）汎用ADポート or　汎用IO入力ポート　（IOポートの場合プルアップ設定の必要有）
//  3:     AN1/RB1   　（INPUT）汎用ADポート or　汎用IO入力ポート　（IOポートの場合プルアップ設定の必要有）
//  4:     AN2/RB2    （INPUT）汎用ADポート or　汎用IO入力ポート　（IOポートの場合プルアップ設定の必要有）
//  5:       RB3      （OUTPUT）　IO出力ポート　LED1
//  6:       RB4　　  　（OUTPUT）　IO出力ポート　LED2
//  7:       RB5　　　  （OUTPUT）　IO出力ポート　LED3
//  8:       VSS       GND接続
//  9:      OSC1      クロック入力ピン（セラロック 10MHZ）
// 10:      OSC2    　　クロック入力ピン（セラロック 10MHZ）
// 11:　　 　　U1ATX     （OUTPUT）シリアル通信 UART1 マニピュレータ側接続        
// 12:      U1ARX     （INPUT） シリアル通信 UART1 マニピュレータ側接続      
// 13:       VDD　　　　　　Vdd接続（5[V]）
// 14:       RD9      （OUTPUT）電磁弁制御用IOポート　FETへ接続 
// 15:       RD8　　　　　（OUTPUT）　LCD-7 ： E　へ接続
// 16:       RF6　　　　　（OUTPUT）　LCD-4 ：RS　へ接続
// 17:    PGD/U1TX　　　　書き込みピン
// 18:    PGC/U1RX　　　　書き込みピン
// 19:       VSS　　　　　　GND接続  
// 20:       VDD　　　　　　Vdd接続（5[V]）
// 21:      U2TX　　　　　（OUTPUT）　シリアル通信 UART2  HOST-PC側接続
// 22:      U2TX　　　　　（INPUT） 　シリアル通信 UART2  HOST-PC側接続
// 23:       RB9      （OUTPUT）　LCD-14:RB7 接続
// 24:       RB8　　　　　（OUTPUT）　LCD-13:RB6　接続
// 25:       RB7　　　　　（OUTPUT）　LCD-12:RB5　接続
// 26:       RB6　　　　　（OUTPUT）　LCD-11:RB4　接続
// 27:      AVSS      　GND接続
// 28:      AVDD　　　　　　Vdd接続


#include "p30F3013.h"
#include "uart.h"   
#include "stdio.h"
#include "adc12.h"
#include "timer.h"
#include "math.h"
#include "ports.h"


//クロック初期設定
_FOSC(CSW_FSCM_OFF & XT_PLL4); //外部クロック(セラロック 10Mz x 4 = 40MHz)
_FWDT(WDT_OFF);                 //WDT  OFF
_FBORPOR(PBOR_ON & BORV_20 & PWRT_64 & MCLR_EN);
_FGS(CODE_PROT_OFF);

//各種define 
#define CLOCK 40 //[MHz]
#define FCY   (CLOCK*250000) //[MHz]
#define BAUD 9600
#include "lcd.c"

#define ELE_VALVE LATDbits.LATD9 //電磁弁駆動FETへの接続ピン
#define LED1 LATBbits.LATB3      //LED1
#define LED2 LATBbits.LATB4      //LED2
#define LED3 LATBbits.LATB5      //LED3

#define ON 1
#define OFF 0

//dsPICF3013はuart.hで定義されないので
#define UART_RX_TX              0xFBE7
#define UART_ALTRX_ALTTX        0xFFE7

//UART1 初期設定変数　　Manipulator
unsigned int U1MODEvalue  = UART_EN & UART_IDLE_CON & UART_ALTRX_ALTTX & UART_DIS_WAKE & UART_DIS_LOOPBACK &
							UART_DIS_ABAUD & UART_NO_PAR_8BIT & UART_1STOPBIT;

unsigned int U1STAvalue  =  UART_INT_TX_BUF_EMPTY & UART_TX_PIN_NORMAL & UART_TX_ENABLE &
							UART_INT_RX_CHAR & UART_ADR_DETECT_DIS & UART_RX_OVERRUN_CLEAR;

//UART2 初期設定変数  Host-PC
unsigned int U2MODEvalue  = UART_EN & UART_IDLE_CON & UART_RX_TX & UART_DIS_WAKE & UART_DIS_LOOPBACK &
							UART_DIS_ABAUD & UART_NO_PAR_8BIT & UART_1STOPBIT;

unsigned int U2STAvalue  =  UART_INT_TX_BUF_EMPTY & UART_TX_PIN_NORMAL & UART_TX_ENABLE &
							UART_INT_RX_CHAR & UART_ADR_DETECT_DIS & UART_RX_OVERRUN_CLEAR;

//AD コンバータ初期設定変数
unsigned int ADconfig1 = ADC_MODULE_ON & ADC_IDLE_STOP & ADC_FORMAT_INTG &
						 ADC_CLK_TMR & ADC_AUTO_SAMPLING_ON & ADC_SAMP_OFF;
						 
unsigned int ADconfig2 = ADC_VREF_AVDD_AVSS & ADC_SCAN_ON & ADC_SAMPLES_PER_INT_2 & 
						ADC_ALT_BUF_OFF & ADC_ALT_INPUT_OFF;
						
unsigned int ADconfig3 = ADC_SAMPLE_TIME_2 & ADC_CONV_CLK_SYSTEM & ADC_CONV_CLK_2Tcy;

unsigned int ADconfigPort = ENABLE_AN0_ANA & ENABLE_AN1_ANA;// & ENABLE_AN2_ANA;
							
unsigned int ADconfigScan = 0x0003;//AN scan 0000 0000 0000 0111

//timer 3 init set >> AD converter start trigger
unsigned int T3config = T3_ON & T3_GATE_OFF & T3_PS_1_1 & T3_SOURCE_INT;
unsigned int SampleTime = 5002;//Max count >> [65535]

unsigned char AD_dat[8]={0};
unsigned int Recv_num=0,ValveState=OFF;
char SendData[128]={0},HostBuff[128]={0};
 
int main(void)
{
	//IO initialize
 	//ConfigCNPullups(0x0001000);
  	CNPU1bits.CN4PUE=1;//プルアップ抵抗ON（RB2）
	TRISB = 0x0007;//0000 0000 0000 0111
  	TRISD = 0x0000;//0000 0000 0000 0000
	TRISF = 0x0014;//0000 0000 0001 0100
	//UART1 init set
	OpenUART1(U1MODEvalue,U1STAvalue,64);
	ConfigIntUART1(UART_RX_INT_EN & UART_TX_INT_DIS);
	
	//UART2 (Host-PC)
	OpenUART2(U2MODEvalue,U2STAvalue,64);
	ConfigIntUART2(UART_RX_INT_EN & UART_TX_INT_DIS);

	//LCD初期化
  	lcd_init();
   
  	//ADモジュールとタイマ３の組み合わせで周期的にAD値を取得
	//AD initialize
	OpenADC12(ADconfig1,ADconfig2,ADconfig3,ADconfigPort,ADconfigScan);
	ConfigIntADC12(ADC_INT_ENABLE & ADC_INT_PRI_1);
	//timer3 initialize function
	ConfigIntTimer3(T3_INT_PRIOR_4 & T3_INT_OFF);
	OpenTimer3(T3config,SampleTime);

	//======================= Main　Loop ======================//
	while(1){
		lcd_clr();
    	lcd_home();
		
		LED1=!LED1;
		
		lcd_outs("ManipulatorStart");
	    lcd_locate(2,1);
		lcd_outs("Nakajima Lab.");
		delay_ms(200);
	}
	//=========================================================//
}


//Host-PC　シリアル受信割り込み
void __attribute__((interrupt,shadow,auto_psv)) _U2RXInterrupt(void)
{
	int i=0;
	char recv_temp=0;
	static int CR_cnt=0;

	IFS1bits.U2RXIF =0; //受信割り込みフラグのクリア
	
	recv_temp = ReadUART2();//受信データの格納
	
	//1つ目のCR(0x0d)の時、そこから関節角度情報が始まるので取得していく
	if(CR_cnt==1){
		HostBuff[Recv_num] = recv_temp;
		Recv_num++;
	}
	
	if(recv_temp==0x0d) CR_cnt++;//受信データがCR（0x0d）だった場合CR_cntを増やす
	
	//２つ目のCRがきたタイミングで関節角度情報の取得が終了するため，マニピュレータに関節角度を送信していく
	if(CR_cnt==2){
		ValveState = HostBuff[Recv_num-2];//電磁弁制御信号の抜出し
		if(ValveState == 0x23) ELE_VALVE =ON;
		else                   ELE_VALVE =OFF;
		
		HostBuff[Recv_num-2]=0x0d;//電磁弁信号だった配列部分にCR（0x0d）を代入
		CR_cnt=1;//CR_cntを1に戻し，次の関節角度受信に備える
		
		//受信した関節角度情報を送信データ配列に代入
		for(i=0;i<Recv_num;i++){
			SendData[i] = HostBuff[i];
		}
	
		SendData[Recv_num-1]=NULL;//最終情報にNULLの代入(今の送信方法ならいらなそう⇒putc連打)
		
		//Host-PCにAD，IO情報の送信
		for(i=0;i<7;i++){
			delay_us(600);
			putcUART2(AD_dat[i]);		
		}
		//マニピュレータに目標関節角度を送信
		for(i=0;i<Recv_num-1;i++){
			delay_us(1500);
			putcUART1(SendData[i]);
		}
		Recv_num=0;
	}
}

//ad-converter interval function
//ADの自動スキャンは，ﾀｲﾏ3の設定時間により決定する(割り込みタイミングを決めているわけではない)．
//スキャン時間決定後，ADバッファがいくつ【ストックされたら割り込みを入れる】という設定ができ，
//この設定と，ﾀｲﾏ3で設定した時間により，AD割り込みの周期が決定される．
//今回は1つのADスキャンに対し約0.5[ms]となっており，2つのADバッファがストックされた後，ADの割り込みを
//いれるため，0.5[ms]x2個 = 約1[ms]の周期でAD割り込み関数が実行される．
//AD情報は12bitを2分割したうえでHost-PCに送信し，Host-PC側で12bitに加工しなおす．
void __attribute__((interrupt,shadow,auto_psv)) _ADCInterrupt(void)
{
	IFS0bits.ADIF =0;
	
	unsigned int AD_temp[3]={0};
	
	AD_temp[0] = ReadADC12(0);
	AD_temp[1] = ReadADC12(1);
	AD_temp[2] = ReadADC12(2);

	AD_dat[0] = (unsigned char)(AD_temp[0]>>6); 
	AD_dat[1] = (unsigned char)(AD_temp[0] & 0x003f);
	AD_dat[2] = (unsigned char)(AD_temp[1]>>6); 
	AD_dat[3] = (unsigned char)(AD_temp[1] & 0x003f);
	AD_dat[4] = (unsigned char)(AD_temp[2]>>6); 
	AD_dat[5] = (unsigned char)(AD_temp[2] & 0x003f);
	AD_dat[6] = PORTBbits.RB2;
		
}



	

		
	


///以下はおまけ．タイマ1,2が余っており，タイマ割り込みや，時間計測などに使用できる．
//マイコンだけでマニピュレータを動かしたい！という人は是非下記のタイマを有効活用して
//マニピュレータを制御してみてください。

/*
//timer 1 init set >>  1cnt:0.2[us] 
unsigned int T1config = T1_ON & T1_GATE_OFF & T1_PS_1_1 & T1_SYNC_EXT_OFF & T1_SOURCE_INT;
unsigned int IntervalTime1 = 0;

//timer 2 init set >>  1cnt:1.6[us]
unsigned int T2config = T2_ON & T2_GATE_OFF & T2_PS_1_8 & T2_SOURCE_INT;
unsigned int IntervalTime2 = 65500;
*/

//timer1 initialize function
//ConfigIntTimer1(T1_INT_PRIOR_2 & T1_INT_OFF);
//OpenTimer1(T1config,65500);
	
//timer2 initialize function
//ConfigIntTimer2(T2_INT_PRIOR_3 & T2_INT_OFF);
//OpenTimer2(T2config,IntervalTime2);



//timer 1 interval function
//50～70[ms]周期で動かし、Strategyを検討している
/*void __attribute__((interrupt,shadow,auto_psv)) _T1Interrupt(void)
{
	IFS0bits.T1IF =0;
}
*/
//timer 2 interval function >> 20[ms]
/*void __attribute__((interrupt,shadow,auto_psv)) _T2Interrupt(void)
{
	IFS0bits.T2IF =0;
}
*/
