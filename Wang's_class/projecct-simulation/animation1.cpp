//�~���������ē���

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.141592	//�����stdio.h��PI���g���ĂȂ��B

int i;
float v=0;
float a=1;	//r�͌��_�Ƃ̋����Aa�͈ړ��̌�����\���ϐ�

void display(void)
{
	float x=0.3;			//���_��x���W
	float y=0.3;			//		y���W
	float r=0.3;
	
  glClear(GL_COLOR_BUFFER_BIT);
  //glBegin(GL_LINE_LOOP);	//���ŕ`�����̓h��Ԃ���Ƃǂ������D���ȕ����g���B���Ȃ݂Ɍ݂��Ɋ�����̂Œ��ӁB
  
  glColor3f(1.0, 1.0, 0.0);	//�F���߁BRGB�l�Ŏw��
  glBegin(GL_POLYGON);		//�h��Ԃ��B
  //glVertex2d(x-r,y);
  //glVertex2d(x+r,y);		//(1.0 1.0)�͉�ʂ̉E���
  for(i=0;i<=36;i++){
  glVertex2d(v + x + r * cos((10*i)*PI/180), y + r * sin((10*i)*PI/180));
  }
  glEnd();
  glFlush();		//�܂����s����ĂȂ����߂̎��s���n�߂�
  
}

void anime(void)
{
	v = v + a*0.0001;	//�ړ��̑����͂����ŕς�����
	if(v>1 | v<-1){
		a = a*(-1);		//�[�܂ŗ�����������]�Bor���Z�q���g���Ă������Ǝv���B
	}
	glutPostRedisplay();	//�ĕ`�悪�K�v�ƃ}�[�N���̋@��� glutDisplayFunc�̃R�[���o�b�N�֐������s
}

void init(void)
{
  glClearColor(0.0, 1.0, 1.0, 0.0);	//RED GREEN BLUE �����x(0�œ���)�̏�
}


int main(int argc, char *argv[])
{
  glutInit(&argc, argv);		//GLUT��OPGL�̊��̏�����
  glutInitDisplayMode(GLUT_RGBA);		//�E�B���h�E���w�肵���F�œh��Ԃ�
  glutCreateWindow(argv[0]);		//GLUT�̃E�B���h�E���J��(�J�b�R���̓E�B���h�E�̖��O)
  glutDisplayFunc(display);		//�f�B�X�v���C�ɉf���֐��̃|�C���^���w��
	glutIdleFunc(anime);		//���ɃC�x���g���Ȃ���ΌĂяo�����֐���o�^(�����͊֐���)
	
  init();			//������
  glutMainLoop();	//�������[�v�B���ꂪ���邱�Ƃɂ��C�x���g�҂��Ŏ��s���p�������B���܂��Ȃ��̂悤��main�̍Ō�ɓ���Ă����΂���
  return 0;
}
