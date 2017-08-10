//足の形を保ったままのキックシミュレーション

#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<time.h>

#define PI 3.14159265

static GLfloat x	 = 0.0;
static GLfloat y	 = 0.0;
static GLfloat up	 = 0.0;
static GLfloat ud	 = 0.0;

int mode=0,mode1=0,mode2=0;
int i=0, n=100, h=0;

	/*ボールの情報*/
//半径
float  R=4;
//初期の中心座標
float  x0=20;
float  y0=-10;
float  Vx = 50;		//初速(x方向)
float  Vy = -10;	//初速(y方向)
float ddx = 0;		//加速度(x方向)
float ddy = 0;		//加速度(y方向)

	/*運動に関する値*/
float  g = 0.0980665;	//重力加速度
float  t = 0;			//時間
float dt = 0.001;		//時間の変化量


	/*係数*/
float w = 0.9;		//跳ね返り係数
float u = 0.95;		//床の摩擦係数
float o = 0.9;		//足の反射係数

//足とボールの距離
float D2 = 0,D = 0;

//あたり判定の大きさ
float p = 0;

	/*足の情報*/
float fx=0;		//足の初期位置(x方向)
float fdx=0;	//足の速度(x方向)
float fddx=3.0;	//足加速度(x方向)
float fy=0,fdy=0,fddy=0;	//y方向

int fl = 20;	//足の長さ
int fd = 7;		//足の太さ
float fr = 2.5;	//足先の大きさ

static GLfloat ang = -20.0;	//足の初期角度



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-45, -45);
		glVertex2f(-45,  45);
		glVertex2f( 45,  45);
		glVertex2f( 45, -45);
	glEnd();
		
		//ボール
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
		
		up = 0;
		ud = 101;
		
		for(i=up;i<ud;i++){
			y = y0 + R*sin(2*PI*(float)i/n);
			x = x0 + R*cos(2*PI*(float)i/n);
			glVertex2f(x, y);
		}
		glVertex2f(x0, y0);
		
	glEnd();
	
	//脚
	glPushMatrix();
		glRotatef(ang, 0.0, 0.0, 1.0);        //向き(ヨー, ピッチ, ロー)
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
			
			glVertex2f(fx-fd-1, -fy-fl);
			glVertex2f(fx-fd-5.5, -fy-fl);
			glVertex2f(fx-fd-7, -fy);
			glVertex2f(fx-fd, -fy);
			glVertex2f(fx-fd-2, -fy-fl+2);
			glVertex2f(fx-fd+4, -fy-fl);
			
			for(i=0;i<50;i++){
			x = -3 + fr*sin(2*PI*(float)i/n);
			y = -fl - 2.5  	+ fr*cos(2*PI*(float)i/n);
			glVertex2f(x, y);
			}
			
			glVertex2f(-fd+4, -fl-5);
			glVertex2f(-fd-5.5, -fl-5);
			glVertex2f(-fd-6, -fl-2.5);
			glVertex2f(-fd-5.5, -fl);
			
		glEnd();
	glPopMatrix();
	
	glFlush();
	
	glPopMatrix();
	glutSwapBuffers();
}

void simu(void)
{
	ddy = ddy - g;
	D2 = (x-x0)*(x-x0) + (y-y0)*(y-y0);
	D = sqrt(D2);
	
	p = R + fr;
	
	static time_t last_time = 0.0;
	double delta_t;
	
	delta_t = (double)(clock() - last_time) / CLOCKS_PER_SEC;
	if(delta_t != 0.0)
		printf("FPS: %lf\n", 1.0 / delta_t);
	last_time = clock();
	
	t = t + dt;
	
	Vx = Vx + ddx*dt;
	x0 = x0 + Vx*dt + ddy*dt*dt/2.0;
	Vy = Vy + ddy*dt;
	y0 = y0 + Vy * dt + ddy*dt*dt/2.0;
	
	if(y0 <= -45+R && mode==0){
		Vy = -w * Vy;
		Vx = Vx * u;	//床の摩擦
		mode=1;
		}
	if(y0 >= 45-R){
		Vy = -w * Vy;
		mode1=1;
	}
	if(x0 <= -45+R && mode1==0){
		Vx = -w * Vx;
		mode1=1;
	}
	if(x0 >= 45-R && mode2==0){
		Vx = -w * Vx;
		mode2=1;
	}
	
	if(Vy<=0)
		mode=0;
		
	if(Vx <= 0)
		mode1=0;
		
	if(Vx >= 0)
		mode2=0;
		
	if(y0 <= -45.01+R){
		y0 = -45+R;
	}
	if(D <= p){
		Vx = -Vx * o + ddx;
		Vy = -Vy * o + ddy;
	}
	
	
	//キックモーション
	if ( ang < 30.0 )
		ang = ang + 0.02;//回転速度
	
	
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
	glViewport( 0, 0, w, h );                      //ビューポイント
	glMatrixMode(GL_PROJECTION);                   //視野
	glLoadIdentity();                              //行列リセット
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);  //正射影行列
	glMatrixMode(GL_MODELVIEW);                    //モード切替え
	glLoadIdentity();                              //行列リセット
}

void mouse(int button, int state, int x, int y){
	switch (button) {
		case GLUT_LEFT_BUTTON:           //左クリック
			if ( state == GLUT_DOWN)     //ボタン押された:GLUT_DOWN
				glutIdleFunc(simu);
		break;
		
		case GLUT_RIGHT_BUTTON:          //右クリック
			if ( state == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
		 
		default:
		break; 
}
}

void keyboard(unsigned char key, int x, int y)
{
	if ( key == '\x1b') exit(0);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (400, 400);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
