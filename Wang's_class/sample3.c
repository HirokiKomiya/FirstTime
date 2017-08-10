#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>

#define PI 3.14159265

static GLfloat ang = 0.0;
static GLfloat x = 0.0;
static GLfloat y = 0.0;
int i=0, n=100;
float  R=10;

void display(void)
{  
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 0.0);
  glPushMatrix();
  	glRotatef(ang, 0.0, 0.0, 1.0);        //向き(ヨー, ピッチ, ロー)
	
  /*	glRectf( -15.0, -15.0, 15.0, 15.0 );  //塗りつぶし範囲*/
  	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	
	for(i=10;i<90;i++){
		y = R*sin(2*PI*(float)i/n);
		x = R*cos(2*PI*(float)i/n);
		glVertex2f(x, y);
	}
	glVertex2f(0, 0);
	
	glEnd();
	glFlush();
	
  glPopMatrix();
  glutSwapBuffers();
  
  
}

void simu(void)
{
  ang = ang + 0.10;//回転速度
  if ( ang > 360.0 )
  	ang = ang - 360.0;
	x=x+100;
	y=y+100;
	
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