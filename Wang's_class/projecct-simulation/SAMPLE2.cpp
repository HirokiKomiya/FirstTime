#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.141592

int i=0;
float r = 0.4,a=1;

void display(void)
{
	float x=0.3;			//���S
	float y=0.3;			//���W
	
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glVertex2d(x+r,y+r);		//
  glVertex2d(x+r,-y+r);		//(1.0 1.0)�͉�ʂ̉E���
 glVertex2d(-x+r,-y+r);
 glVertex2d(-x+r,y+r);
  glEnd();
  glFlush();		//�܂����s����ĂȂ����߂̎��s���n�߂�
  
}

void anime(void)
{
	r = r + a*0.0001;
	if(r>1 | r<-1){
		a = a*(-1);
	}
	
	
	glutPostRedisplay();
}
void init(void)
{
  glClearColor(0.0, 1.0, 1.0, 0.0);	//RED,GREEN BLUE�A�����x(0�œ���)�̏�
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);		//GLUT��OPGL�̊��̏�����
  glutInitDisplayMode(GLUT_RGBA);		//�E�B���h�E���w�肵���F�œh��Ԃ�
  glutCreateWindow(argv[0]);		//GLUT�̃E�B���h�E���J��
  glutDisplayFunc(display);		//�f�B�X�v���C�ɉf���֐��̃|�C���^���w��

	glutIdleFunc(anime);
	
  init();
  glutMainLoop();	//�������[�v�B���ꂪ���邱�Ƃɂ��C�x���g�҂��ɂȂ�A���s���p�������B
  return 0;
}
