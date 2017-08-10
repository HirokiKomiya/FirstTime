//平行リンクでのキックシミュレーション

#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<time.h>

#define PI 3.14159265

static GLfloat ang = 0.0;		//足の初期位置
static GLfloat x = 0.0;
static GLfloat y = 0.0;
static GLfloat up = 0.0;
static GLfloat ud = 0.0;


int i=0, n=100;		//カウンター
int mode=0;			//モード


/*ボールに関する情報*/

//半径
float R=4;
//中心
float x0=40;
float y0=10;
//速度
float Vx = -20;
float Vy = -5;
//加速度
float ddx = 0;
float ddy = 0;

	/*重力加速度、時間*/
float g = -0.00980665;
float t = 0;
float dt = 0.001;

	/*係数*/
float w = 0.9;		//跳ね返り係数
float u = 0.9;		//床の摩擦係数
float o = 0.9;		//足の反射係数

//あたり判定の大きさ
float p = 0;
float R2 = 5;

//足とボールの距離
float D2 = 0,D = 0;


	/*足の情報*/
float fx=0;		//足の初期位置(x方向)
float fdx=0;	//足の速度(x方向)
float fddx=3.0;	//足加速度(x方向)
float fy=0,fdy=0,fddy=0;	//y方向

int fl = 20;	//足の長さ
int fd = 10;	//足の太さ

int xf = -20,yf = 35;		//足の回転中心の座標
int lf = 10;				//回転半径
float the = -30*PI/180;		//初期角度



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//地平線を引く
	glBegin(GL_LINE_LOOP);
	
	glVertex2f(-40, -10);
	glVertex2f(40, -10);
	glVertex2f(40, 10);
	glVertex2f(-40, 10);
	
	glEnd();
	
	//ボールを描く
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
	
	//足を描く
	glPushMatrix();
	glRotatef(ang, 0.0, 0.0, 1.0);		//回転方向
	
	//glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(xf+lf*sin(the)+fx, fy-lf*cos(the));
	glVertex2f(xf+(lf+fl)*sin(the)+fx, fy-(lf+fl)*cos(the));
	glVertex2f(xf+(lf+fl)*sin(the)+10+R2+fx, fy-(lf+fl)*cos(the));
	glVertex2f(xf+(lf+fl-R2)*sin(the)+10+R2+fx, fy-(lf+fl-R2)*cos(the));
	glVertex2f(xf+(lf+fl-R2)*sin(the)+10+fx, fy-(lf+fl-R2)*cos(the));
	glVertex2f(xf+lf*sin(the)+10+fx, fy-lf*cos(the));
	
	glEnd();
	
	glPopMatrix();
	
	glFlush();
	glutSwapBuffers();
    
}

void simu(void)
{
	//FPSの表示
	static time_t last_time = 0.0;
	double delta_t;
	
	delta_t = (double)(clock() - last_time) / CLOCKS_PER_SEC;
	if(delta_t != 0.0)
		printf("FPS: %lf\n", 1.0 / delta_t);
	last_time = clock();
	
	//あたり判定の大きさの調整
	p = R + R2/2 + 0.5;
	
	t = t + dt;				//タイム
	ddy = ddy + g;			//Y方向の加速度に重力加速度を加える
	
	
	//ボールの位置、速度の計算
	Vx = Vx + ddx*dt;
	x0 = x0 + Vx*dt + ddy*dt*dt/2.0;
	Vy = Vy + ddy*dt;
	y0 = y0 + Vy * dt + ddy*dt*dt/2.0;
	
	
	if(x0<=-50+R | x0 >= 50-R)		//横壁の跳ね返り判定。50はウィンドウの端の座標
	{
		Vx = -Vx;
		
	}else{
		if(y0 <= -47+R)
	   	{
			Vy = -Vy*w;
			Vx = Vx * u;
	   	}
		
		//地面の下に食い込みそうになったら戻す
		if(y0 < -47.01+R)
		y0 = -47+R;
	}
	
	//足とボールの距離の計算
	D2 = (x0-(xf+(lf+fl)*sin(the)+10+R2/2+fx)) * (x0-(xf+(lf+fl)*sin(the)+10+R2+fx)) + (y0-(fy-(lf+fl-R2)*cos(the))) * (y0-(fy-(lf+fl-R2)*cos(the)));
	D = sqrt(D2);
	
	//衝突の判定
	if(D<=p && mode==0){
		Vx = -Vx * o + fdx;
		Vy = -Vy * o + fdy;
		mode = 1;
	}
	
	//距離が離れたらモードリセット
	if(mode == 1 && D >= p+0.1){
		mode=0;
	}
	
	
	//キックモーション
	if(the<30*PI/180)
		the = (the*180/PI + 1*PI/180)*PI/180;
	
	glutPostRedisplay();
}


void init(void)
{
  glClearColor(0.1, 0.1, 1.0, 1.0);
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
     	if ( state == GLUT_DOWN)        //ボタン押された:GLUT_DOWN
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
  if ( key == '\x1b') exit(0);		//escで終了
  if ( key == '\x7f') exit(0);		//delで終了
  if ( key == '\x20') glutIdleFunc(simu); //spでsimuスタート
  if ( key == '\x6a') glutIdleFunc(simu);
  if ( key == '\x6b') glutIdleFunc(simu);	//6b == k
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (600, 600);
  glutInitWindowPosition(500,200);
  glutCreateWindow(argv[0]);
  init();
  //Functions
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}