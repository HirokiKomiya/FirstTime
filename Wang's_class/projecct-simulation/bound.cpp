#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<time.h>

#define PI 3.14159265

static GLfloat ang = 0.0;
static GLfloat x	 = 0.0;
static GLfloat y	 = 0.0;
static GLfloat up	 = 0.0;
static GLfloat ud	 = 0.0;

int mode=0;
int i=0, n=100, h=0;
//半径
float  R=3;
//中心
float  x0=0;
float  y0=0;
//運動に関する値
float  g = 9.80665;
float  t = 0;
float  Vx = 0;
float  Vy = 0;
float ddx = 0;
float  dx = 9.0/2;
float ddy = -9.8/2;//加速度
float dt = 0.001;//時間の変化量
float  e = 0.9;

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
	//脚の成形
	glPushMatrix();
		glRotatef(ang, 0.0, 0.0, 1.0);        //向き(ヨー, ピッチ, ロー)
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
			
			glVertex2f(-15, -20);
			glVertex2f(-19.5, -20);
			glVertex2f(-21, 0);
			glVertex2f(-14, 0);
			glVertex2f(-16, -18);
			glVertex2f(-10, -20);
			
			for(i=0;i<50;i++){
			x = -10 	+ 2.5*sin(2*PI*(float)i/n);
			y = -22.5  	+ 2.5*cos(2*PI*(float)i/n);
			glVertex2f(x, y);
			}
			
			glVertex2f(-10, -25);
			glVertex2f(-19.5, -25);
			glVertex2f(-20, -22.5);
			glVertex2f(-19.5, -20);
			
		glEnd();
	glPopMatrix();
	
	glFlush();
	
	glPopMatrix();
	glutSwapBuffers();
}

void simu(void)
{
	static time_t last_time = 0.0;
	double delta_t;
	
	delta_t = (double)(clock() - last_time) / CLOCKS_PER_SEC;
	if(delta_t != 0.0)
		printf("FPS: %lf\n", 1.0 / delta_t);
	last_time = clock();
	
	t = t + dt;
	
	ang = ang + 0.10;//回転速度
	if ( ang > 360.0 )
		ang = ang - 360.0;
	
	Vx = dx;
	Vy = Vy + ddy * dt;
	
	x0 = x0 + Vx * dt;
	y0 = y0 + Vy * dt; 
	
	if(y0 <= -45 && mode==0){
		Vy = -e * Vy;
		mode=1;
		}
	if(y0 >= 45)
		Vy = -e * Vy;
	if(x0 <= -45)
		dx = -e * dx;
	if(x0 >= 45)
		dx = -e * dx;
	if(Vy<=0)
		mode=0;
	
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