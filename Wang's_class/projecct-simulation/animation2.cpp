//�~���������ē���

#include<stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define PI 3.141592	//�����stdio.h��PI���g���ĂȂ��B

float g = -0.098;				//�d�͉����x

int i;
float dx = 0,ddx = 0.01;	//�����x�ύX�͂���
float dy = 0,ddy = 0;
float dt = 0.2;
float x = 0.3;			//���_��x���W
float y = 0.3;			//		y���W
float r = 0.3;
float m = 2.0;			//�d��
float f;
float t = 0;

void display(void)
{
  f = m * ddx;
  
  glClear(GL_COLOR_BUFFER_BIT);
  
  glBegin(GL_LINE_LOOP);	//���ŕ`�����̓h��Ԃ���Ƃǂ������D���ȕ����g���B���Ȃ݂Ɍ݂��Ɋ�����̂Œ��ӁB
  glVertex2d(0.5,0.5);
  glVertex2d(0.5,-0.5);
  glEnd();
  
  glColor3f(1.0, 1.0, 0.0);	//�F���߁BRGB�l�Ŏw��
  glBegin(GL_POLYGON);		//polygon�͓h��Ԃ��B
  //glVertex2d(x-r,y);
  //glVertex2d(x+r,y);		//(1.0 1.0)�͉�ʂ̉E���
  
  for(i=0;i<=36;i++){
  glVertex2d(x + dx * dt + r * cos((10*i)*PI/180) + ddx * dt * dt/2.0, y + dy*dt + (ddy + g) * dt * dt/2.0 + r * sin((10*i)*PI/180));
  }
  
  glEnd();
  glFlush();		//�܂����s����ĂȂ����߂̎��s���n�߂�
  
}

void anime(void)
{
	dx = dx + ddx * dt;	//�ړ��̑����͂����ŕς�����
	dy = dy + (ddy+g) * dt;
	t = t + dt;
	
	if(dx>5 | dx<-5){				//�Փˏ���
		ddx = ddx * (-1);		//�[�܂ŗ�����������]�Bor���Z�q���g���Ă������Ǝv���B
	}
	
	glutPostRedisplay();	//�ĕ`�悪�K�v�ƃ}�[�N���̋@��� glutDisplayFunc�̃R�[���o�b�N�֐������s
}

void init(void)
{
  glClearColor(0.0, 1.0, 1.0, 0.0);	//RED GREEN BLUE �����x(0�œ���)�̏�
}

void keyboard(unsigned char key, int x, int y)
{
  if ( key == '\x1b') exit(0);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);		//GLUT��OPGL�̊��̏�����
  glutInitDisplayMode(GLUT_RGBA);		//�E�B���h�E���w�肵���F�œh��Ԃ�
  glutCreateWindow(argv[0]);		//GLUT�̃E�B���h�E���J��(�J�b�R���̓E�B���h�E�̖��O)
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);		//�f�B�X�v���C�ɉf���֐��̃|�C���^���w��
  glutIdleFunc(anime);		//���ɃC�x���g���Ȃ���ΌĂяo�����֐���o�^(�����͊֐���)
  init();			//������
  glutMainLoop();	//�������[�v�B���ꂪ���邱�Ƃɂ��C�x���g�҂��Ŏ��s���p�������B���܂��Ȃ��̂悤��main�̍Ō�ɓ���Ă����΂���
  return 0;
}
