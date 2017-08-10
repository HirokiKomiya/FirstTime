#include <stdio.h>
double read_right_sensor(void);
double read_left_sensor(void);
void wait_millisec(int t);
void rotate_right_wheel(double speed);
void rotate_left_wheel(double speed);/*�@�����܂Ŋ֐��̐錾*/



void main(void){
#define speed=1
	double Rs=0,Ls=0,Rm,Lm;
	int t;
	while(Rs >=0,Ls >=0){
		Rs = read_right_sensor(void);
		Ls = read_left_sensor(void);/*�@���E�̃Z���T�̒l��ǂݍ���*/
		if(Rs <=1.0 && Rs >= 0.4 && Ls <=1.0 && Ls >= 0.4){/*���E�ɏ�Q��*/
			Rm = rotate_right_wheel(-speed);
			Lm = rotate_left_wheel(-speed);
			t = wait_millisec(t);
			Rm = rotate_right_wheel(-speed);
			Lm = rotate_left_wheel(speed);
			t = wait_millisec(t);}
		if(Rs <=1.0 && Rs >= 0.4){/*�E�����ɏ�Q��*/
			Rm = rotate_right_wheel(speed);
			Lm = rotate_left_wheel(-speed);
			t = wait_millisec(t);}
			else{
				if(Ls <=1.0 && Ls >= 0.4){/*�������ɏ�Q��*/
				Rm = rotate_right_wheel(-speed);
				Lm = rotate_left_wheel(speed);
				t = wait_millisec(t);}
				else{
				Rm = rotate_right_wheel(speed);
				Lm = rotate_left_wheel(speed);}
			}
	}
}

double read_right_sensor(void){
	double value;
	printf("IMPUT RIGHT VALUE: ");
	scanf("%lf\n", &value);
	return value;
} /*�@�E�Z���T*/
double read_left_sensor(void){
	double value;
	printf("IMPUT LEFT VALUE: ");
	scanf("%lf\n", &value);
	return value;
} /*�@���Z���T*/
void wait_millisec(int t){
	printf("WAIT %d\n", t);
}/*t�~���b�ҋ@*/
void rotate_right_wheel(double speed){
	printf("ROTATE RIGHT %lf\n", speed);
}/*�E�̎ԗւ���]*/
void rotate_left_wheel(double speed){
	printf("ROTATE LEFT %lf\n", speed);
}/*���̎ԗւ���]*/
