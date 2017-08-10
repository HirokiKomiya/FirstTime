#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.141592

static GLfloat ang = 0.0;
static GLfloat x = 0.0;
static GLfloat y = 0.0;
int i=0;

void display(void)
{  
	float r = 10;		//���a
	float x=0;
	float y=0;
	
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glColor3f(1.0, 1.0, 0.0);
  glRotatef(ang, 0.0, 0.0, 1.0);	//��]�̌���
  //glBegin(GL_POLYGON);	//�h��Ԃ�
  glVertex2d(x-r,y);
  glVertex2d(x+r,y);		//(1.0 1.0)�͉�ʂ̉E���
  for(i=0;i<=36;i++){
  glVertex2d(x + r * cos((10*i)*PI/180), y + r * sin((10*i)*PI/180));
  }
  
  
  
  glEnd();
  glFlush();
  glPushMatrix();
  glutSwapBuffers();
}

void simu(void)
{
  ang = ang + 1.0;		//�����ŉ�]�����̒����B
  						//���������W�ɂ�鑀��ɉ��ǂ��ׂ�
  if ( ang > 360.0 )
  	ang = ang - 360.0;
  glutPostRedisplay();	//display�ɏ��������̂����s
}

void simu2(void)
{
	x = x + 1.0;
	if(x > 10)
	x =x - 10;
	glutPostRedisplay();
}

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
  glViewport( 0, 0, w, h );
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
  switch (button) {
     case GLUT_LEFT_BUTTON:
     	if ( state == GLUT_DOWN)
     		glutIdleFunc(simu);
     	break;
     case GLUT_RIGHT_BUTTON:
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
  glutInitWindowSize (1000, 1000);		//GULT�̃E�B���h�E�̃T�C�Y���w��
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
