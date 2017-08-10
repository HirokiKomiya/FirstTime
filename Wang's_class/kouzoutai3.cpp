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
struct ball{
//���a
	float  R;
//���S
	float  x0;
	float  y0;
//�^���Ɋւ���l
	float  Vx;
	float  Vy;
	float ddx;
	float ddy;
};
  	struct ball a[1];
	a[1].R = 2.0;
  	a[1].x0=0;
  	float  y0=20;
  	float  Vx = 10;
  	float  Vy = 1;
  	float  ddx = 0;
  	float  ddy = 0;
	float  g = -0.00980665;
	float  t = 0;
	float  V1 = 0;
	float dt = 0.001;
	
	float w = 0.9;		//���˕Ԃ�W��
	float u = 0.9;		//���̖��C�W��
	float o = 0.9;		//���̔��ˌW��

	float p = 0;		//�����蔻��̑傫��

	float D2=0,D=0;		//���ƃ{�[���̋���

	float R2 = 5;
	
	float fx=0;
	float fdx=0;
	float fddx=1.5;	//�������x
	float fy=0,fdy=0,fddy=0;
	
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINE_LOOP);
	
	glVertex2f(-50, -47);
	glVertex2f(50, -47);
	
	glEnd();
	glBegin(GL_LINE_LOOP);
	
	up = 0;
	ud = 101;
	
	for(i=up;i<ud;i++){
		y = a[1].y0 + a[1].R * sin(2*PI*(float)i/n);
		x = a[1].x0 + a[1].R * cos(2*PI*(float)i/n);
		glVertex2f(x, y);
	}
	
	glVertex2f(a[0].x0, a[0].y0);
	
	glEnd();
	
	glColor3f(1.0, 0.0, 1.0);
	
	glBegin(GL_POLYGON);
	
	glVertex2f(-40+fx, -20);
	glVertex2f(-40+fx, -40);
	glVertex2f(-40+10+R2+fx, -40);
	glVertex2f(-40+10+R2+fx, -40+R2);
	glVertex2f(-40+10+fx, -40+R2);
	glVertex2f(-40+10+fx, -20);
	
	
	glEnd();
	glFlush();
	
	glPopMatrix();
	glutSwapBuffers();
    
}

void simu(void)
{
	p = a[1].R + R2/2 + 0.5;
	
	t = t + dt;
	a[1].ddy = a[1].ddy + g;
	
  /*ang = ang + 0.10;//��]���x
  if ( ang > 360.0 )
  	ang = ang - 360.0;*/
	
  a[1].Vx = a[1].Vx + a[1].ddx*dt;
  a[1].x0 = a[1].x0 + a[1].Vx*dt + a[1].ddy*dt*dt/2.0;
  a[1].Vy = a[1].Vy + a[1].ddy*dt;
  a[1].y0 = a[1].y0 + a[1].Vy * dt + a[1].ddy*dt*dt/2.0;
  
  if(a[1].y0 <= -45)
    	{
			a[1].Vy = -a[1].Vy*w;
			a[1].Vx = a[1].Vx * u;
    	}
	
	if(a[1].y0 < -45.01)
	{
		
		a[1].y0 = -45;
		
	}
	
	if(a[1].x0<=-48 | a[1].x0 >= 48)		//���ǂ̒��˕Ԃ蔻��
	{
		a[1].Vx = -a[1].Vx;
		
	}
	
	
	D2 = (x0-(-27.5+fx)) * (a[0].x0-(-27.5+fx)) + (a[0].y0-(-37.5)) * (a[0].y0-(-37.5));
	D = sqrt(D2);
	
	if(D<=p){
		
		a[1].Vx = -a[1].Vx * o + fdx;
		a[1].Vy = -a[1].Vy * o + fdy;
	}
	
	
	//�L�b�N���[�V������
	
	fdx = fdx + fddx*dt;
	fx =fx + fdx*dt + fddx*dt*dt/2.0;
	
	
	if(fx>50){
		
		fx=50;
		fdx=0;
		fddx=0;
		
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
  glViewport( 0, 0, w, h );                      //�r���[�|�C���g
  glMatrixMode(GL_PROJECTION);                   //����
  glLoadIdentity();                              //�s�񃊃Z�b�g
  glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);  //���ˉe�s��
  glMatrixMode(GL_MODELVIEW);                    //���[�h�ؑւ�
  glLoadIdentity();                              //�s�񃊃Z�b�g
}

void mouse(int button, int state, int x, int y){
  switch (button) {
     case GLUT_LEFT_BUTTON:           //���N���b�N
     	if ( state == GLUT_DOWN)        //�{�^�������ꂽ:GLUT_DOWN
     		glutIdleFunc(simu);
     	break;
     case GLUT_RIGHT_BUTTON:          //�E�N���b�N
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