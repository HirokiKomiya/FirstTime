#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.141592

int i=0;

 int px = 320; // バーの基準x座標 
     int py = 430; // バーの基準y座標 
     int pmovex;   // バーの移動値 

     int bx = 320;   // ボールのx座標 
     int by = 420;   // ボールのy座標 
     int l  = 1;     // x軸反射角変数の符号判定 
     int ll = -1;    // y軸反射角変数の符号判定 
     int movex = 4;  // ボールのx軸増減値 
     int movey = 4;  // ボールのy軸増減値 
 
 
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
  
  glutDisplayFunc(display);
  init();
  glutMainLoop();	//無限ループ。これがあることによりイベント待ちになり、実行が継続される。
  return 0;
}
