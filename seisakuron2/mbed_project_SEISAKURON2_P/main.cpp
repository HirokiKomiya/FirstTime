// 台車の速度制御（P制御）

#include "mbed.h"
#include "Motor.h"
#include "QEI.h"

BusOut led(LED1, LED2, LED3, LED4);	//基板LED用IO設定
AnalogIn pen(xp15);									//ポテンショメータ用IO設定
AnalogIn ad(xp17);
Ticker pen_control;								//台車の速度制御用タイマー割り込み

Serial pc(USBTX, USBRX);						//デバッグ用シリアル通信

//モータ制御用オブジェクト
Motor motor_left(MOTOR1_IN1, MOTOR1_IN2, MOTOR1_PWM);		//左モータ
Motor motor_right(MOTOR2_IN1, MOTOR2_IN2, MOTOR2_PWM);	//右モータ
//エンコーダ設定　ここから//
BusIn in(GPIO1, GPIO2, GPIO3, GPIO4);
//エンコーダの入力ピン
QEI qei_left(GPIO1, GPIO2, NC, 48, QEI::X4_ENCODING);			//左モーターのエンコーダ
QEI qei_right(GPIO3, GPIO4, NC, 48, QEI::X4_ENCODING);		//右モーターのエンコーダ
//エンコーダ設定　ここまで//

//***************　台車の速度制御　ここから　***************//
int pen_val;												//振子についているポテンショメータのAD値格納用
int goal_pen_val = 820;							//振子の目標値(AD値)
int goal_pen_val_2 = 820;
int ad_val;
double speed, last_speed;						//車体の速度　，　前回の車体の速度
double pen_kp = 0.05;							//ゲイン設定用変数
double x=0;								//速度
double x0=0;
double xi;
//振子の目標値(AD値)
int mode=0;
#define PULSE_TO_METER	0.0005	//エンコーダパルス数を台車の位置に変換する係数 
#define end_x 0.1
#define error_end_x -0.1

int enc_left, enc_right;	//エンコーダの値
int enc_left_d;
int enc_right_d;
int enc_right_0;
int enc_left_0;

int pen_diff;										//振子の目標値とポテンショメータのAD値の差分格納用

void pen_control_handler(){
	pen_val = pen.read_u16()>>6;					//ADCを通してポテンショメータのAD値を取得
	//搭載されているLPC1114のADCは10bitのため6bit右にシフト
	
	pen_diff = (double)(goal_pen_val - pen_val) ;		//振子の目標値とポテンショメータのAD値の差分を計算して格納
	
	speed = (pen_diff * pen_kp);					//P制御
	
	//速度指令値の頭打ち処理
	if(speed > 1.0) speed = 1.0;
	if(speed < -1.0) speed = -1.0;
	
	//**** 速度指令値によって発行するLEDを変える ****//
		if(speed > 0.8 ){
			led = 8;
		}else if(speed <= 0.8 && speed >= 0){
			led = 4;
		}else if(speed < 0 && speed >= -0.8){
			led = 2;
		}else if(speed < -0.8){
			led = 1;
		}
	//**** 速度指令値によって発行するLEDを変える　ここまで ****//
	
	last_speed = speed;										//前回の速度指令を格納
	if(x>=end_x){
	mode=1;
	led = 9;
	}
if(x<=error_end_x){
	mode = 2;
	led = 6;		//LEDの値代入するのはここじゃないとダメ
	}
	//計算結果をモータの速度指令に反映
	if(mode==0){
	motor_left = speed;
	motor_right = -speed;
	}else{
	speed=0;
	motor_left = speed;
	motor_right = -speed;
	}
	
}
//***************　台車の速度制御　ここまで　***************//

//***************　main関数　ここから　***************//
int main() {

	//モータの最大速度を設定
	motor_left.setMaxRatio(0.8);
	motor_right.setMaxRatio(0.8);

	pen_control.attach(&pen_control_handler, 0.001);		//台車の速度制御用のタイマー関数を設定
	
	led = 1;		//LEDの値を設定　動作確認用
		
	in.mode(PullUp);
	qei_left.reset();
	qei_right.reset();
	wait(1.0);		//なんとなく1秒待つ
	
	motor_left.setMaxRatio(0.9);
	motor_right.setMaxRatio(0.9);
	while(1) {		//無限ループ
		enc_left = qei_left.getPulses();
		enc_right = qei_right.getPulses();
		x = (float)(-enc_left + enc_right) / 2 * PULSE_TO_METER;
		printf("pen:%d speed:%2.2f place:%2f \r\n", pen_val ,speed,x);
		wait(0.08);
		if(mode==1){		//正常終了時の挙動
			motor_left = 0;
			motor_right = 0;
			wait(0.2);
			break;
			}
			if(mode==2){		//異常終了時の挙動
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

