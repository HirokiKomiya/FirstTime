#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.141592

int i=0;

void display1(void)
{
	float r = 0.4;		//直径
	float x = 0;			//中心
	float y = 0;

  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glVertex2d(x-r,y);		//
  glVertex2d(x+r,y);		//(1.0 1.0)は画面の右上隅
  
 while(i<=36){
  glVertex2d(x + r * cos((10*i)*PI/180), y + r * sin((10*i)*PI/180));
  i++;
  }
  glEnd();
  glFlush();		//まだ実行されてない命令の実行を始める
}

void display2(void)
{

	float r = 0.2;		//直径
	float x=0;
	float y=0;
	
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glVertex2d(x-r,y);
  glVertex2d(x+r,y);		//(1.0 1.0)は画面の右上隅
  for(i=0;i<=36;i++){
  glVertex2d(x + r * cos((10*i)*PI/180), y + r * sin((10*i)*PI/180));
  }
  glEnd();
  glFlush();
}

void simu(void)
{
  ang = ang + 1.0;		//ここで回転速さの調整。
  						//ただし座標による操作に改良すべし
  if ( ang > 360.0 )
  	ang = ang - 360.0;
  glutPostRedisplay();	//displayに書いたものを実行
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
  glutDisplayFunc(display1);		//ディスプレイに映す関数のポインタを指定
  init();
  
  glutDisplayFunc(display2);
  init();
  glutMainLoop();	//無限ループ。これがあることによりイベント待ちになり、実行が継続される。
  return 0;
}
