// ��Ԃ̑��x����iP����j

#include "mbed.h"
#include "Motor.h"
#include "QEI.h"

BusOut led(LED1, LED2, LED3, LED4);	//���LED�pIO�ݒ�
AnalogIn pen(xp15);									//�|�e���V�����[�^�pIO�ݒ�
AnalogIn ad(xp17);
Ticker pen_control;								//��Ԃ̑��x����p�^�C�}�[���荞��

Serial pc(USBTX, USBRX);						//�f�o�b�O�p�V���A���ʐM

//���[�^����p�I�u�W�F�N�g
Motor motor_left(MOTOR1_IN1, MOTOR1_IN2, MOTOR1_PWM);		//�����[�^
Motor motor_right(MOTOR2_IN1, MOTOR2_IN2, MOTOR2_PWM);	//�E���[�^
//�G���R�[�_�ݒ�@��������//
BusIn in(GPIO1, GPIO2, GPIO3, GPIO4);
//�G���R�[�_�̓��̓s��
QEI qei_left(GPIO1, GPIO2, NC, 48, QEI::X4_ENCODING);			//�����[�^�[�̃G���R�[�_
QEI qei_right(GPIO3, GPIO4, NC, 48, QEI::X4_ENCODING);		//�E���[�^�[�̃G���R�[�_
//�G���R�[�_�ݒ�@�����܂�//

//***************�@��Ԃ̑��x����@��������@***************//
int pen_val;												//�U�q�ɂ��Ă���|�e���V�����[�^��AD�l�i�[�p
int goal_pen_val = 820;							//�U�q�̖ڕW�l(AD�l)
int goal_pen_val_2 = 820;
int ad_val;
double speed, last_speed;						//�ԑ̂̑��x�@�C�@�O��̎ԑ̂̑��x
double pen_kp = 0.05;							//�Q�C���ݒ�p�ϐ�
double x=0;								//���x
double x0=0;
double xi;
//�U�q�̖ڕW�l(AD�l)
int mode=0;
#define PULSE_TO_METER	0.0005	//�G���R�[�_�p���X�����Ԃ̈ʒu�ɕϊ�����W�� 
#define end_x 0.1
#define error_end_x -0.1

int enc_left, enc_right;	//�G���R�[�_�̒l
int enc_left_d;
int enc_right_d;
int enc_right_0;
int enc_left_0;

int pen_diff;										//�U�q�̖ڕW�l�ƃ|�e���V�����[�^��AD�l�̍����i�[�p

void pen_control_handler(){
	pen_val = pen.read_u16()>>6;					//ADC��ʂ��ă|�e���V�����[�^��AD�l���擾
	//���ڂ���Ă���LPC1114��ADC��10bit�̂���6bit�E�ɃV�t�g
	
	pen_diff = (double)(goal_pen_val - pen_val) ;		//�U�q�̖ڕW�l�ƃ|�e���V�����[�^��AD�l�̍������v�Z���Ċi�[
	
	speed = (pen_diff * pen_kp);					//P����
	
	//���x�w�ߒl�̓��ł�����
	if(speed > 1.0) speed = 1.0;
	if(speed < -1.0) speed = -1.0;
	
	//**** ���x�w�ߒl�ɂ���Ĕ��s����LED��ς��� ****//
		if(speed > 0.8 ){
			led = 8;
		}else if(speed <= 0.8 && speed >= 0){
			led = 4;
		}else if(speed < 0 && speed >= -0.8){
			led = 2;
		}else if(speed < -0.8){
			led = 1;
		}
	//**** ���x�w�ߒl�ɂ���Ĕ��s����LED��ς���@�����܂� ****//
	
	last_speed = speed;										//�O��̑��x�w�߂��i�[
	if(x>=end_x){
	mode=1;
	led = 9;
	}
if(x<=error_end_x){
	mode = 2;
	led = 6;		//LED�̒l�������̂͂�������Ȃ��ƃ_��
	}
	//�v�Z���ʂ����[�^�̑��x�w�߂ɔ��f
	if(mode==0){
	motor_left = speed;
	motor_right = -speed;
	}else{
	speed=0;
	motor_left = speed;
	motor_right = -speed;
	}
	
}
//***************�@��Ԃ̑��x����@�����܂Ł@***************//

//***************�@main�֐��@��������@***************//
int main() {

	//���[�^�̍ő呬�x��ݒ�
	motor_left.setMaxRatio(0.8);
	motor_right.setMaxRatio(0.8);

	pen_control.attach(&pen_control_handler, 0.001);		//��Ԃ̑��x����p�̃^�C�}�[�֐���ݒ�
	
	led = 1;		//LED�̒l��ݒ�@����m�F�p
		
	in.mode(PullUp);
	qei_left.reset();
	qei_right.reset();
	wait(1.0);		//�Ȃ�ƂȂ�1�b�҂�
	
	motor_left.setMaxRatio(0.9);
	motor_right.setMaxRatio(0.9);
	while(1) {		//�������[�v
		enc_left = qei_left.getPulses();
		enc_right = qei_right.getPulses();
		x = (float)(-enc_left + enc_right) / 2 * PULSE_TO_METER;
		printf("pen:%d speed:%2.2f place:%2f \r\n", pen_val ,speed,x);
		wait(0.08);
		if(mode==1){		//����I�����̋���
			motor_left = 0;
			motor_right = 0;
			wait(0.2);
			break;
			}
			if(mode==2){		//�ُ�I�����̋���
			motor_left = 0;
			motor_right = 0;
			wait(0.2);
			break;
			}
	}
	led=13;
			motor_left = 0;
			motor_right = 0;
	wait(0.5);
			motor_left = 0;
			motor_right = 0;
	wait(1.0);
}

