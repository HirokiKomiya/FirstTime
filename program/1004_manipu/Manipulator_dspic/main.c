//Programed by Kazuhisa Ietomi (Nakajima Lab) 2010.9.25
//��t�H�Ƒ�w �H�w���@�������{�e�B�N�X�w�� 2�N�@����K�C�Ȗ�
//���{�b�g�݌v����_3 �}�j�s�����[�^���K�p�v���O����

//�v���O�����T�v
//1:HOST-PC����V���A���ʐM�ő����Ă���}�j�s�����[�^�֐ߊp�x���}�j�s�����[�^�֑��M�D
//�@ �܂��CHOST-PC����̓d���يJ�w�߂̎��s
//2:�}�j�s�����[�^�⏕��ɐڑ�����Ă���AD,IO�Ȃǂ̓��͏���HOST-PC�֑��M
//3:�}�j�s�����[�^�⏕����LCD��LED�Ȃǂ̕\������

//dsPIC3012�ڑ��T�v
//�s���ԍ��@�@�g�p�@�\�@ �@�@�@���l�@
//  1:      MCLR       �������݃s��
//  2�F     AN0/RB0   �@�iINPUT�j�ėpAD�|�[�g or�@�ėpIO���̓|�[�g�@�iIO�|�[�g�̏ꍇ�v���A�b�v�ݒ�̕K�v�L�j
//  3:     AN1/RB1   �@�iINPUT�j�ėpAD�|�[�g or�@�ėpIO���̓|�[�g�@�iIO�|�[�g�̏ꍇ�v���A�b�v�ݒ�̕K�v�L�j
//  4:     AN2/RB2    �iINPUT�j�ėpAD�|�[�g or�@�ėpIO���̓|�[�g�@�iIO�|�[�g�̏ꍇ�v���A�b�v�ݒ�̕K�v�L�j
//  5:       RB3      �iOUTPUT�j�@IO�o�̓|�[�g�@LED1
//  6:       RB4�@�@  �@�iOUTPUT�j�@IO�o�̓|�[�g�@LED2
//  7:       RB5�@�@�@  �iOUTPUT�j�@IO�o�̓|�[�g�@LED3
//  8:       VSS       GND�ڑ�
//  9:      OSC1      �N���b�N���̓s���i�Z�����b�N 10MHZ�j
// 10:      OSC2    �@�@�N���b�N���̓s���i�Z�����b�N 10MHZ�j
// 11:�@�@ �@�@U1ATX     �iOUTPUT�j�V���A���ʐM UART1 �}�j�s�����[�^���ڑ�        
// 12:      U1ARX     �iINPUT�j �V���A���ʐM UART1 �}�j�s�����[�^���ڑ�      
// 13:       VDD�@�@�@�@�@�@Vdd�ڑ��i5[V]�j
// 14:       RD9      �iOUTPUT�j�d���ِ���pIO�|�[�g�@FET�֐ڑ� 
// 15:       RD8�@�@�@�@�@�iOUTPUT�j�@LCD-7 �F E�@�֐ڑ�
// 16:       RF6�@�@�@�@�@�iOUTPUT�j�@LCD-4 �FRS�@�֐ڑ�
// 17:    PGD/U1TX�@�@�@�@�������݃s��
// 18:    PGC/U1RX�@�@�@�@�������݃s��
// 19:       VSS�@�@�@�@�@�@GND�ڑ�  
// 20:       VDD�@�@�@�@�@�@Vdd�ڑ��i5[V]�j
// 21:      U2TX�@�@�@�@�@�iOUTPUT�j�@�V���A���ʐM UART2  HOST-PC���ڑ�
// 22:      U2TX�@�@�@�@�@�iINPUT�j �@�V���A���ʐM UART2  HOST-PC���ڑ�
// 23:       RB9      �iOUTPUT�j�@LCD-14:RB7 �ڑ�
// 24:       RB8�@�@�@�@�@�iOUTPUT�j�@LCD-13:RB6�@�ڑ�
// 25:       RB7�@�@�@�@�@�iOUTPUT�j�@LCD-12:RB5�@�ڑ�
// 26:       RB6�@�@�@�@�@�iOUTPUT�j�@LCD-11:RB4�@�ڑ�
// 27:      AVSS      �@GND�ڑ�
// 28:      AVDD�@�@�@�@�@�@Vdd�ڑ�


#include "p30F3013.h"
#include "uart.h"   
#include "stdio.h"
#include "adc12.h"
#include "timer.h"
#include "math.h"
#include "ports.h"


//�N���b�N�����ݒ�
_FOSC(CSW_FSCM_OFF & XT_PLL4); //�O���N���b�N(�Z�����b�N 10Mz x 4 = 40MHz)
_FWDT(WDT_OFF);                 //WDT  OFF
_FBORPOR(PBOR_ON & BORV_20 & PWRT_64 & MCLR_EN);
_FGS(CODE_PROT_OFF);

//�e��define 
#define CLOCK 40 //[MHz]
#define FCY   (CLOCK*250000) //[MHz]
#define BAUD 9600
#include "lcd.c"

#define ELE_VALVE LATDbits.LATD9 //�d���ً쓮FET�ւ̐ڑ��s��
#define LED1 LATBbits.LATB3      //LED1
#define LED2 LATBbits.LATB4      //LED2
#define LED3 LATBbits.LATB5      //LED3

#define ON 1
#define OFF 0

//dsPICF3013��uart.h�Œ�`����Ȃ��̂�
#define UART_RX_TX              0xFBE7
#define UART_ALTRX_ALTTX        0xFFE7

//UART1 �����ݒ�ϐ��@�@Manipulator
unsigned int U1MODEvalue  = UART_EN & UART_IDLE_CON & UART_ALTRX_ALTTX & UART_DIS_WAKE & UART_DIS_LOOPBACK &
							UART_DIS_ABAUD & UART_NO_PAR_8BIT & UART_1STOPBIT;

unsigned int U1STAvalue  =  UART_INT_TX_BUF_EMPTY & UART_TX_PIN_NORMAL & UART_TX_ENABLE &
							UART_INT_RX_CHAR & UART_ADR_DETECT_DIS & UART_RX_OVERRUN_CLEAR;

//UART2 �����ݒ�ϐ�  Host-PC
unsigned int U2MODEvalue  = UART_EN & UART_IDLE_CON & UART_RX_TX & UART_DIS_WAKE & UART_DIS_LOOPBACK &
							UART_DIS_ABAUD & UART_NO_PAR_8BIT & UART_1STOPBIT;

unsigned int U2STAvalue  =  UART_INT_TX_BUF_EMPTY & UART_TX_PIN_NORMAL & UART_TX_ENABLE &
							UART_INT_RX_CHAR & UART_ADR_DETECT_DIS & UART_RX_OVERRUN_CLEAR;

//AD �R���o�[�^�����ݒ�ϐ�
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
  	CNPU1bits.CN4PUE=1;//�v���A�b�v��RON�iRB2�j
	TRISB = 0x0007;//0000 0000 0000 0111
  	TRISD = 0x0000;//0000 0000 0000 0000
	TRISF = 0x0014;//0000 0000 0001 0100
	//UART1 init set
	OpenUART1(U1MODEvalue,U1STAvalue,64);
	ConfigIntUART1(UART_RX_INT_EN & UART_TX_INT_DIS);
	
	//UART2 (Host-PC)
	OpenUART2(U2MODEvalue,U2STAvalue,64);
	ConfigIntUART2(UART_RX_INT_EN & UART_TX_INT_DIS);

	//LCD������
  	lcd_init();
   
  	//AD���W���[���ƃ^�C�}�R�̑g�ݍ��킹�Ŏ����I��AD�l���擾
	//AD initialize
	OpenADC12(ADconfig1,ADconfig2,ADconfig3,ADconfigPort,ADconfigScan);
	ConfigIntADC12(ADC_INT_ENABLE & ADC_INT_PRI_1);
	//timer3 initialize function
	ConfigIntTimer3(T3_INT_PRIOR_4 & T3_INT_OFF);
	OpenTimer3(T3config,SampleTime);

	//======================= Main�@Loop ======================//
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


//Host-PC�@�V���A����M���荞��
void __attribute__((interrupt,shadow,auto_psv)) _U2RXInterrupt(void)
{
	int i=0;
	char recv_temp=0;
	static int CR_cnt=0;

	IFS1bits.U2RXIF =0; //��M���荞�݃t���O�̃N���A
	
	recv_temp = ReadUART2();//��M�f�[�^�̊i�[
	
	//1�ڂ�CR(0x0d)�̎��A��������֐ߊp�x��񂪎n�܂�̂Ŏ擾���Ă���
	if(CR_cnt==1){
		HostBuff[Recv_num] = recv_temp;
		Recv_num++;
	}
	
	if(recv_temp==0x0d) CR_cnt++;//��M�f�[�^��CR�i0x0d�j�������ꍇCR_cnt�𑝂₷
	
	//�Q�ڂ�CR�������^�C�~���O�Ŋ֐ߊp�x���̎擾���I�����邽�߁C�}�j�s�����[�^�Ɋ֐ߊp�x�𑗐M���Ă���
	if(CR_cnt==2){
		ValveState = HostBuff[Recv_num-2];//�d���ِ���M���̔��o��
		if(ValveState == 0x23) ELE_VALVE =ON;
		else                   ELE_VALVE =OFF;
		
		HostBuff[Recv_num-2]=0x0d;//�d���ِM���������z�񕔕���CR�i0x0d�j����
		CR_cnt=1;//CR_cnt��1�ɖ߂��C���̊֐ߊp�x��M�ɔ�����
		
		//��M�����֐ߊp�x���𑗐M�f�[�^�z��ɑ��
		for(i=0;i<Recv_num;i++){
			SendData[i] = HostBuff[i];
		}
	
		SendData[Recv_num-1]=NULL;//�ŏI����NULL�̑��(���̑��M���@�Ȃ炢��Ȃ�����putc�A��)
		
		//Host-PC��AD�CIO���̑��M
		for(i=0;i<7;i++){
			delay_us(600);
			putcUART2(AD_dat[i]);		
		}
		//�}�j�s�����[�^�ɖڕW�֐ߊp�x�𑗐M
		for(i=0;i<Recv_num-1;i++){
			delay_us(1500);
			putcUART1(SendData[i]);
		}
		Recv_num=0;
	}
}

//ad-converter interval function
//AD�̎����X�L�����́C���3�̐ݒ莞�Ԃɂ�茈�肷��(���荞�݃^�C�~���O�����߂Ă���킯�ł͂Ȃ�)�D
//�X�L�������Ԍ����CAD�o�b�t�@�������y�X�g�b�N���ꂽ�犄�荞�݂�����z�Ƃ����ݒ肪�ł��C
//���̐ݒ�ƁC���3�Őݒ肵�����Ԃɂ��CAD���荞�݂̎��������肳���D
//�����1��AD�X�L�����ɑ΂���0.5[ms]�ƂȂ��Ă���C2��AD�o�b�t�@���X�g�b�N���ꂽ��CAD�̊��荞�݂�
//����邽�߁C0.5[ms]x2�� = ��1[ms]�̎�����AD���荞�݊֐������s�����D
//AD����12bit��2��������������Host-PC�ɑ��M���CHost-PC����12bit�ɉ��H���Ȃ����D
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



	

		
	


///�ȉ��͂��܂��D�^�C�}1,2���]���Ă���C�^�C�}���荞�݂�C���Ԍv���ȂǂɎg�p�ł���D
//�}�C�R�������Ń}�j�s�����[�^�𓮂��������I�Ƃ����l�͐��񉺋L�̃^�C�}��L�����p����
//�}�j�s�����[�^�𐧌䂵�Ă݂Ă��������B

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
//50�`70[ms]�����œ������AStrategy���������Ă���
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
