//���̌`��ۂ����܂܂̃L�b�N�V�~�����[�V����

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

	/*�{�[���̏��*/
//���a
float  R=4;
//�����̒��S���W
float  x0=20;
float  y0=-10;
float  Vx = 50;		//����(x����)
float  Vy = -10;	//����(y����)
float ddx = 0;		//�����x(x����)
float ddy = 0;		//�����x(y����)

	/*�^���Ɋւ���l*/
float  g = 0.0980665;	//�d�͉����x
float  t = 0;			//����
float dt = 0.001;		//���Ԃ̕ω���


	/*�W��*/
float w = 0.9;		//���˕Ԃ�W��
float u = 0.95;		//���̖��C�W��
float o = 0.9;		//���̔��ˌW��

//���ƃ{�[���̋���
float D2 = 0,D = 0;

//�����蔻��̑傫��
float p = 0;

	/*���̏��*/
float fx=0;		//���̏����ʒu(x����)
float fdx=0;	//���̑��x(x����)
float fddx=3.0;	//�������x(x����)
float fy=0,fdy=0,fddy=0;	//y����

int fl = 20;	//���̒���
int fd = 7;		//���̑���
float fr = 2.5;	//����̑傫��

static GLfloat ang = -20.0;	//���̏����p�x



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
		
		//�{�[��
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
	
	//�r
	glPushMatrix();
		glRotatef(ang, 0.0, 0.0, 1.0);        //����(���[, �s�b�`, ���[)
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
		Vx = Vx * u;	//���̖��C
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
	
	
	//�L�b�N���[�V����
	if ( ang < 30.0 )
		ang = ang + 0.02;//��]���x
	
	
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
			if ( state == GLUT_DOWN)     //�{�^�������ꂽ:GLUT_DOWN
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
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
