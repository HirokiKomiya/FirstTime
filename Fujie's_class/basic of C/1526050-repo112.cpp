#include <stdio.h>
double read_right_sensor(void);
double read_left_sensor(void);
void wait_millisec(int t);
void rotate_right_wheel(double);
void rotate_left_wheel(double);/*　ここまで関数の宣言*/


void main(void){

double speed=1;

	double Rs=0,Ls=0;
	int t;
	while(Rs >=0,Ls >=0){
		Rs = read_right_sensor();
		Ls = read_left_sensor();/*　左右のセンサの値を読み込む*/
		if(Rs <=1.0 && Rs >= 0.4 && Ls <=1.0 && Ls >= 0.4){/*左右に障害物*/
			rotate_right_wheel(-speed);
			rotate_left_wheel(-speed);
			wait_millisec(t);
			rotate_right_wheel(-speed);
			rotate_left_wheel(speed);
			wait_millisec(t);}
		if(Rs <=1.0 && Rs >= 0.4){/*右だけに障害物*/
			rotate_right_wheel(speed);
			rotate_left_wheel(-speed);
			wait_millisec(t);}
			else{
				if(Ls <=1.0 && Ls >= 0.4){/*左だけに障害物*/
				rotate_right_wheel(-speed);
				rotate_left_wheel(speed);
				wait_millisec(t);}
				else{/*障害物なし*/
				rotate_right_wheel(speed);
				rotate_left_wheel(speed);}
			}
	}
}

double read_right_sensor(void){
	double value;
	printf("IMPUT RIGHT VALUE: ");
	scanf("%lf\n", &value);
	return value;
} /*　右センサ*/
double read_left_sensor(void){
	double value;
	printf("IMPUT LEFT VALUE: ");
	scanf("%lf\n", &value);
	return value;
} /*　左センサ*/
void wait_millisec(int t){
	printf("WAIT %d\n", t);
}/*tミリ秒待機*/
void rotate_right_wheel(double speed){
	printf("ROTATE RIGHT %lf\n", speed);
}/*右の車輪を回転*/
void rotate_left_wheel(double speed){
	printf("ROTATE LEFT %lf\n", speed);
}/*左の車輪を回転*/
