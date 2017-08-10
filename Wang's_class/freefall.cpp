#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>
#include<stdio.h>

#define PI 3.14159265

static GLfloat ang = 0.0;
static GLfloat x = 0.0;
static GLfloat y = 0.0;
static GLfloat up = 0.0;
static GLfloat ud = 0.0;


int i=0, n=100, h=0;
int mode;

//半径
float  R=2;
//中心
float  x0=0;
float  y0=45;
//運動に関する値
float  g = -0.00980665;		//重力加速度
float  t = 0;
float  Vx = 10;		//x初速
float  Vy = -10;		//y初速
float  V1 = 0;
float ddx = 0;
float ddy = 0;
float dt = 0.001;

float w = 0.9;		//跳ね返り係数
float u = 0.9;		//床の摩擦係数

void display(void)
{  
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 0.0);
  glPushMatrix();
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINE_LOOP);		//床
	
	glVertex2f(-50, -47);
	glVertex2f(50, -47);
	
	
	glEnd();
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
	glFlush();
	
  glPopMatrix();
  glutSwapBuffers();
  
  
}

void simu(void)
{
   t = t + dt;
	ddy = ddy + g;
	
  /*ang = ang + 0.10;//回転速度
  if ( ang > 360.0 )
  	ang = ang - 360.0;*/
	
  Vx = Vx + ddx*dt;
  x0 = x0 + Vx*dt + ddy*dt*dt/2.0;
  Vy = Vy + ddy*dt;
  y0 = y0 + Vy * dt + ddy*dt*dt/2.0;
  
  if(y0 <= -45)
    	{
			Vy = -Vy*w;
			Vx = Vx * u;
    	}
	
	if(y0 < -45.01)
	{
	
		y0 = -45;
		
	}
	
	if(x0<=-48 | x0 >= 48)		//横壁の跳ね返り判定
	{
		Vx = -Vx;
		
	}
	
	
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
  //Functions
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutDisplayFunc(display);
    glutMainLoop();
  return 0;
}