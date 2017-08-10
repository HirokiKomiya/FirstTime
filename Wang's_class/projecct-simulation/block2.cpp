#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.141592

int i=0;

 
 
void display(void)
{	
float px = 0.3; // バーの基準x座標 
     float py = 0.4; // バーの基準y座標 
     float pmovex;   // バーの移動値 

     float bx = 0.3;   // ボールのx座標 
     float by = 0.4;   // ボールのy座標 
     int l  = 1;     // x軸反射角変数の符号判定 
     int ll = -1;    // y軸反射角変数の符号判定 
     float movex = 0.4;  // ボールのx軸増減値 
     float movey = 0.4;  // ボールのy軸増減値 
 
  glBegin(GL_POLYGON); 
     glColor3d(1.0, 1.0, 0.0); 
     glVertex2f(px + pmovex, py); 
     glVertex2f(px + 0.40 + pmovex, py - 0.5); 
     glVertex2f(0.4,-0.5); 
     glVertex2f(-0.4,0.5); 
     glVertex2f(-0.4,-0.5); 
     glVertex2f(0.4, 0.5); 
     glEnd();
  glFlush();		//まだ実行されてない命令の実行を始める
}

/*void display2(void)
{

	float r = 0.2;		
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
}*/

/*void simu(void)
{
  ang = ang + 1.0;		//ここで回転速さの調整。
  						//ただし座標による操作に改良すべし
  if ( ang > 360.0 )
  	ang = ang - 360.0;
  glutPostRedisplay();	//displayに書いたものを実行
}*/

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
  init();
 
  glutMainLoop();	//無限ループ。これがあることによりイベント待ちになり、実行が継続される。
  return 0;
}
