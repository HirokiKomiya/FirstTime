//円が往復して動く

#include<stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define PI 3.141592	//今回はstdio.hもPIも使ってない。

float g = -0.098;				//重力加速度

int i;
float dx = 0,ddx = 0.01;	//加速度変更はここ
float dy = 0,ddy = 0;
float dt = 0.2;
float x = 0.3;			//頂点のx座標
float y = 0.3;			//		y座標
float r = 0.3;
float m = 2.0;			//重さ
float f;
float t = 0;

void display(void)
{
  f = m * ddx;
  
  glClear(GL_COLOR_BUFFER_BIT);
  
  glBegin(GL_LINE_LOOP);	//線で描く下の塗りつぶすやつとどっちか好きな方を使う。ちなみに互いに干渉するので注意。
  glVertex2d(0.5,0.5);
  glVertex2d(0.5,-0.5);
  glEnd();
  
  glColor3f(1.0, 1.0, 0.0);	//色決め。RGB値で指定
  glBegin(GL_POLYGON);		//polygonは塗りつぶす。
  //glVertex2d(x-r,y);
  //glVertex2d(x+r,y);		//(1.0 1.0)は画面の右上隅
  
  for(i=0;i<=36;i++){
  glVertex2d(x + dx * dt + r * cos((10*i)*PI/180) + ddx * dt * dt/2.0, y + dy*dt + (ddy + g) * dt * dt/2.0 + r * sin((10*i)*PI/180));
  }
  
  glEnd();
  glFlush();		//まだ実行されてない命令の実行を始める
  
}

void anime(void)
{
	dx = dx + ddx * dt;	//移動の速さはここで変えられる
	dy = dy + (ddy+g) * dt;
	t = t + dt;
	
	if(dx>5 | dx<-5){				//衝突条件
		ddx = ddx * (-1);		//端まで来たら方向反転。or演算子を使ってもいいと思う。
	}
	
	glutPostRedisplay();	//再描画が必要とマーク次の機会に glutDisplayFuncのコールバック関数を実行
}

void init(void)
{
  glClearColor(0.0, 1.0, 1.0, 0.0);	//RED GREEN BLUE 透明度(0で透明)の順
}

void keyboard(unsigned char key, int x, int y)
{
  if ( key == '\x1b') exit(0);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);		//GLUTとOPGLの環境の初期化
  glutInitDisplayMode(GLUT_RGBA);		//ウィンドウを指定した色で塗りつぶす
  glutCreateWindow(argv[0]);		//GLUTのウィンドウを開く(カッコ内はウィンドウの名前)
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);		//ディスプレイに映す関数のポインタを指定
  glutIdleFunc(anime);		//他にイベントがなければ呼び出される関数を登録(引数は関数名)
  init();			//初期化
  glutMainLoop();	//無限ループ。これがあることによりイベント待ちで実行が継続される。おまじないのようにmainの最後に入れておけばいい
  return 0;
}
