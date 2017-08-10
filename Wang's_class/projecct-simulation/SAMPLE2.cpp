#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.141592

int i=0;
float r = 0.4,a=1;

void display(void)
{
	float x=0.3;			//中心
	float y=0.3;			//座標
	
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glVertex2d(x+r,y+r);		//
  glVertex2d(x+r,-y+r);		//(1.0 1.0)は画面の右上隅
 glVertex2d(-x+r,-y+r);
 glVertex2d(-x+r,y+r);
  glEnd();
  glFlush();		//まだ実行されてない命令の実行を始める
  
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
  glClearColor(0.0, 1.0, 1.0, 0.0);	//RED,GREEN BLUE、透明度(0で透明)の順
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);		//GLUTとOPGLの環境の初期化
  glutInitDisplayMode(GLUT_RGBA);		//ウィンドウを指定した色で塗りつぶす
  glutCreateWindow(argv[0]);		//GLUTのウィンドウを開く
  glutDisplayFunc(display);		//ディスプレイに映す関数のポインタを指定

	glutIdleFunc(anime);
	
  init();
  glutMainLoop();	//無限ループ。これがあることによりイベント待ちになり、実行が継続される。
  return 0;
}
