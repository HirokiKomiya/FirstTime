#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.141592

int i=0;

 int px = 320; // �o�[�̊x���W 
     int py = 430; // �o�[�̊y���W 
     int pmovex;   // �o�[�̈ړ��l 

     int bx = 320;   // �{�[����x���W 
     int by = 420;   // �{�[����y���W 
     int l  = 1;     // x�����ˊp�ϐ��̕������� 
     int ll = -1;    // y�����ˊp�ϐ��̕������� 
     int movex = 4;  // �{�[����x�������l 
     int movey = 4;  // �{�[����y�������l 
 
 
void display(void)
{
glBegin(GL_POLYGON); 
     glColor3d(1.0, 1.0, 0.0); 
     glVertex2f(px + pmovex, py); 
     glVertex2f(px + 40 + pmovex, py - 5); 
     glVertex2f(px + 40 + pmovex, py + 5); 
     glVertex2f(px - 40 + pmovex, py + 5); 
     glVertex2f(px - 40 + pmovex, py - 5); 
     glVertex2f(px + 40 + pmovex, py - 5); 
     glEnd(); 
  glFlush();		//�܂����s����ĂȂ����߂̎��s���n�߂�
}

/*void display2(void)
{

	float r = 0.2;		
	float x=0;
	float y=0;
	
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glVertex2d(x-r,y);
  glVertex2d(x+r,y);		//(1.0 1.0)�͉�ʂ̉E���
  for(i=0;i<=36;i++){
  glVertex2d(x + r * cos((10*i)*PI/180), y + r * sin((10*i)*PI/180));
  }
  glEnd();
  glFlush();
}*/

void simu(void)
{
  ang = ang + 1.0;		//�����ŉ�]�����̒����B
  						//���������W�ɂ�鑀��ɉ��ǂ��ׂ�
  if ( ang > 360.0 )
  	ang = ang - 360.0;
  glutPostRedisplay();	//display�ɏ��������̂����s
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
  glutDisplayFunc(display1);		//�f�B�X�v���C�ɉf���֐��̃|�C���^���w��
  init();
  
  glutDisplayFunc(display);
  init();
  glutMainLoop();	//�������[�v�B���ꂪ���邱�Ƃɂ��C�x���g�҂��ɂȂ�A���s���p�������B
  return 0;
}
