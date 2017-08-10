//���s�����N�ł̃L�b�N�V�~�����[�V����

#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<time.h>

#define PI 3.14159265

static GLfloat ang = 0.0;		//���̏����ʒu
static GLfloat x = 0.0;
static GLfloat y = 0.0;
static GLfloat up = 0.0;
static GLfloat ud = 0.0;


int i=0, n=100;		//�J�E���^�[
int mode=0;			//���[�h


/*�{�[���Ɋւ�����*/

//���a
float R=4;
//���S
float x0=40;
float y0=10;
//���x
float Vx = -20;
float Vy = -5;
//�����x
float ddx = 0;
float ddy = 0;

	/*�d�͉����x�A����*/
float g = -0.00980665;
float t = 0;
float dt = 0.001;

	/*�W��*/
float w = 0.9;		//���˕Ԃ�W��
float u = 0.9;		//���̖��C�W��
float o = 0.9;		//���̔��ˌW��

//�����蔻��̑傫��
float p = 0;
float R2 = 5;

//���ƃ{�[���̋���
float D2 = 0,D = 0;


	/*���̏��*/
float fx=0;		//���̏����ʒu(x����)
float fdx=0;	//���̑��x(x����)
float fddx=3.0;	//�������x(x����)
float fy=0,fdy=0,fddy=0;	//y����

int fl = 20;	//���̒���
int fd = 10;	//���̑���

int xf = -20,yf = 35;		//���̉�]���S�̍��W
int lf = 10;				//��]���a
float the = -30*PI/180;		//�����p�x



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//�n����������
	glBegin(GL_LINE_LOOP);
	
	glVertex2f(-40, -10);
	glVertex2f(40, -10);
	glVertex2f(40, 10);
	glVertex2f(-40, 10);
	
	glEnd();
	
	//�{�[����`��
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
	
	//����`��
	glPushMatrix();
	glRotatef(ang, 0.0, 0.0, 1.0);		//��]����
	
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
	//FPS�̕\��
	static time_t last_time = 0.0;
	double delta_t;
	
	delta_t = (double)(clock() - last_time) / CLOCKS_PER_SEC;
	if(delta_t != 0.0)
		printf("FPS: %lf\n", 1.0 / delta_t);
	last_time = clock();
	
	//�����蔻��̑傫���̒���
	p = R + R2/2 + 0.5;
	
	t = t + dt;				//�^�C��
	ddy = ddy + g;			//Y�����̉����x�ɏd�͉����x��������
	
	
	//�{�[���̈ʒu�A���x�̌v�Z
	Vx = Vx + ddx*dt;
	x0 = x0 + Vx*dt + ddy*dt*dt/2.0;
	Vy = Vy + ddy*dt;
	y0 = y0 + Vy * dt + ddy*dt*dt/2.0;
	
	
	if(x0<=-50+R | x0 >= 50-R)		//���ǂ̒��˕Ԃ蔻��B50�̓E�B���h�E�̒[�̍��W
	{
		Vx = -Vx;
		
	}else{
		if(y0 <= -47+R)
	   	{
			Vy = -Vy*w;
			Vx = Vx * u;
	   	}
		
		//�n�ʂ̉��ɐH�����݂����ɂȂ�����߂�
		if(y0 < -47.01+R)
		y0 = -47+R;
	}
	
	//���ƃ{�[���̋����̌v�Z
	D2 = (x0-(xf+(lf+fl)*sin(the)+10+R2/2+fx)) * (x0-(xf+(lf+fl)*sin(the)+10+R2+fx)) + (y0-(fy-(lf+fl-R2)*cos(the))) * (y0-(fy-(lf+fl-R2)*cos(the)));
	D = sqrt(D2);
	
	//�Փ˂̔���
	if(D<=p && mode==0){
		Vx = -Vx * o + fdx;
		Vy = -Vy * o + fdy;
		mode = 1;
	}
	
	//���������ꂽ�烂�[�h���Z�b�g
	if(mode == 1 && D >= p+0.1){
		mode=0;
	}
	
	
	//�L�b�N���[�V����
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
  if ( key == '\x1b') exit(0);		//esc�ŏI��
  if ( key == '\x7f') exit(0);		//del�ŏI��
  if ( key == '\x20') glutIdleFunc(simu); //sp��simu�X�^�[�g
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