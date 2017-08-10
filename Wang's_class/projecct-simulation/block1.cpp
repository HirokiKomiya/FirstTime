#include <GL/glut.h>
#include <GL/block.h>
#include <cmath>
#include <iostream>
#include <cstdlib> 
using namespace std;
#define WIDTH 640   // 画面の横サイズ 
#define HEIGHT 480  // 画面の縦サイズ 
#define PI 3.141592     // 円周率 


void player(){  // バーの生成 
     glBegin(GL_POLYGON); 
     glColor3d(1.0, 1.0, 0.0); 
     glVertex2f(px + pmovex, py); 
     glVertex2f(px + 40 + pmovex, py - 5); 
     glVertex2f(px + 40 + pmovex, py + 5); 
     glVertex2f(px - 40 + pmovex, py + 5); 
     glVertex2f(px - 40 + pmovex, py - 5); 
     glVertex2f(px + 40 + pmovex, py - 5); 
     glEnd(); 
 } 


void Ball::reverse(){ 
     if(5 <= bx && bx <= 635 ){  // x軸(左右)の壁に当たった場合 
         /* 何もしない */ 
     }else{ 
         l = -1 * l;     // x軸の増減値を反転させる 
         bx += l  * movex; 
         by += ll * movey; 
     } 

if(5 <= by && by <= 490){   // y軸(上)の壁に当たった場合 
         /* 何もしない */ 
    }else{ 
         ll = -1 * ll;   // y軸の増減値を反転させる 
         bx += l  * movex; 
         by += ll * movey; 
     } 
 
     // 自機(バー)の当たり判定 
     if(px + pmovex - 40 < bx && bx < px + pmovex + 40 && py - 10 < by && by < py){  
         ll = -1 * ll;   // y軸の増減値を反転させる 
         bx += l  * movex; 
         by += ll * movey; 
     } 
 
     if(by > 480){ exit(1); }    // 弾が画面下に出たら終了 
 } 
 
 void Ball::ball(){ // ボールの生成 
     setdec=true;
	 if(setdec){ set(); }    // 一度だけ初期化 
 
     glBegin(GL_POLYGON); 
     //glColor3d(1.0, 0.0, 0.0); 
    glVertex2f(bx, by); 
     for(int i = 0; i < 360; ++i){ 
glVertex2f(bx + br * cos(i), by + br * sin(i)); 
     } 
     glEnd(); 
 } 


 void Ball::set(){   // 初期化内容 
     setdec=true;
	 br = 5;         // ボールの半径 
     shotr = 45;     // ボールの移動角度 
     shotdec = 0;    // 最初に発射する時に、spaceキーを押してるかの判定 
     setdec = false; 
} 

void Block::decision(int Num, int hNum){    // ブロックの反射判定 
	blockx = 40;
	blocky = 20;
	spownx = 70;
	spowny = 30;
     // ブロック上の反射 
     if(blockx - 30 + (spownx * Num)  < bx && bx < blockx + 30 + (spownx * Num) && 
        blocky - 15 + (spowny * hNum) < by && by < blocky - 10 + (spowny * hNum)) { 

         if(Life[hNum][Num] == 0){   // 敵機に当たった時、弾の座標を戻す 
               ll = -1 * ll;       // x軸の増減値を反転させる 
                 Life[hNum][Num] = 1;     
         }            
     } 
// ブロック下の反射 
     if(blockx - 30 + (spownx * Num)  < bx && bx < blockx + 30 + (spownx * Num) && 
        blocky + 10 + (spowny * hNum) < by && by < blocky + 15 + (spowny * hNum)) { 
 
         if(Life[hNum][Num] == 0){   // 敵機に当たった時、弾の座標を戻す 
               ll = -1 * ll;       // x軸の増減値を反転させる 
                 Life[hNum][Num] = 1;     
         }            
     } 
 
     // ブロック左の反射 
    if(blockx - 30 + (spownx * Num)  < bx && bx < blockx - 25 + (spownx * Num) && 
        blocky - 15 + (spowny * hNum) < by && by < blocky + 15 + (spowny * hNum)) { 
 
         if(Life[hNum][Num] == 0){   // 敵機に当たった時、弾の座標を戻す 
                 l = -1 * l;     // x軸の増減値を反転させる 
                 Life[hNum][Num] = 1;     
         }            
     } 

     // ブロック右の反射 
     if(blockx + 25 + (spownx * Num)  < bx && bx < blockx + 30 + (spownx * Num) && 
        blocky - 15 + (spowny * hNum) < by && by < blocky + 15 + (spowny * hNum)) { 

         if(Life[hNum][Num] == 0){   // 敵機に当たった時、弾の座標を戻す 
                 l = -1 * l;     // x軸の増減値を反転させる 
                 Life[hNum][Num] = 1;     
         }            
     } 
 } 
 
 // ブロックの生成 
 void Block::block(int Num, int hNum){
 	blockx = 40;
	blocky = 20;
	spownx = 70;
	spowny = 30;
decision(Num, hNum); 
        if(Life[hNum][Num] == 0){ 
        glBegin(GL_POLYGON); 
         colorset(hNum); 
         glVertex2f(blockx + (spownx * Num), blocky + (spowny * hNum)); 
         glVertex2f(blockx + 30 + (spownx * Num), blocky - 10 + (spowny * hNum)); 
         glVertex2f(blockx + 30 + (spownx * Num), blocky + 10 + (spowny * hNum)); 
         glVertex2f(blockx - 30 + (spownx * Num), blocky + 10 + (spowny * hNum)); 
         glVertex2f(blockx - 30 + (spownx * Num), blocky - 10 + (spowny * hNum)); 
         glVertex2f(blockx + 30 + (spownx * Num), blocky - 10 + (spowny * hNum)); 
         glEnd(); 
     } 
 } 
 
 //　ブロックの色判定 
 void Block::colorset(int Num){
 	blockx = 40;
	blocky = 20;
	spownx = 70;
	spowny = 30;
     (Num == 0 ? glColor3d(1.0, 0.0, 0.0) : Num == 1 ? glColor3d(1.0, 1.0, 0.0) : Num == 2  
               ? glColor3d(0.0, 1.0, 0.0) : Num == 3 ? glColor3d(0.0, 0.0, 1.0) : Num == 4 
               ? glColor3d(1.0, 0.0, 1.0) : glColor3d(1.0, 1.0, 1.0)); 
} 


 //　画面表示 
 void display(){ 
     Ball b; 
     Block blo[5][10]; 
glClear(GL_COLOR_BUFFER_BIT); 

    player();   // 自機生成 
     b.ball();   // 弾の生成 


     for(int i = 0; i < 5; ++i){ 
         for(int j = 0; j < 10; ++j){ 
             blo[i][j].block(j, i);  // ブロックの生成 
             glEnd(); 
         } 
     } 
	 
    glFlush();
	
} 
void leftmove(){    // 自機左移動 
    if(px + pmovex > 40){   // 左端の当たり判定 
             pmovex -= 10.0;      
             //if(smovey == 430.0){ spmovex -= 50.0; }   // 弾の左移動 
             glutPostRedisplay(); 
         } 
 } 
 
 void rightmove(){   // 自機右移動 
     if(px + pmovex < 600){ 
            pmovex += 10.0;     // 右端の当たり判定 
            //if(smovey == 430.0){ spmovex += 50.0; }   // 弾の右移動 
            glutPostRedisplay(); 
    } 
 } 
 
 // キーを押した時の 
void keydowan(unsigned char key, int x, int y){ 

     switch(key){ 
         case 'a':   // a を入力すると左に動く 
         case 'A':  
 
         glutIdleFunc(leftmove); 
         break; 
         case 'd':   // d を入力すると右に動く 
         case 'D': 
glutIdleFunc(rightmove); 
         break; 
 
        case 'q':   // q Q ESC を入力するとプログラム終了 
         case 'Q': 
         case '\033': 
         exit(0); 


         default:  
         break; 
    } 
 } 

void keyup(unsigned char key, int x, int y){    // キーを離した時の挙動 
     switch(key){    // a A を離したときに移動を止める 
         case 'a': 
         case 'A':  
        glutIdleFunc(0); 
         break; 

         case 'd':   // d D を話した時に移動を止める 
         case 'D': 
         glutIdleFunc(0); 
         break; 
default: break; 

    }    
} 

void reshape(int w, int h){             // 座標の定義変更 
   glViewport(0, 0, w, h); 
     glMatrixMode(GL_PROJECTION); 
     glLoadIdentity(); 
     gluOrtho2D(0, 640, 480, 0);         // 左上を　(0, 0) 右下を (640, 480)とする 
 } 

void timer(int value){  // 毎秒ごとに再描画して、アニメーションさせる 
     Ball b; 
    Block blo; 
     b.reverse(); 
     //blo.decision(ptrNum, ptrhNum); 
 
    bx += l  * movex;   // x軸のボールの動き(仮) 
     by += ll * movey;   // y軸のボールの動き(仮) 
 
    glutPostRedisplay();                // 再描画 
     glutTimerFunc(30, timer, 0);        // 第一引数毎秒で繰り返す 
} 

void init(){ 
    glClearColor(0.0, 0.0, 0.0, 1.0);   // 背景色　黒 
}

int main(int argc, char *argv[]){ 
     glutInitWindowPosition(100, 200);   // ウィンドウ作成時の座標指定 
     glutInitWindowSize(WIDTH, HEIGHT);  // ウィンドウサイズの指定 
     glutInit(&argc, argv);           
     glutInitDisplayMode(GLUT_RGBA /*| GLUT_DOUBLE*/);   // Red Green Brue +α(透明度)= RGBA  
     glutCreateWindow(argv[0]);          // ウィンドウを生成。 argv[0]だとファイル名がそのままウィンドウ名になる 
     glutDisplayFunc(display);           // display関数内を表示 
     glutKeyboardFunc(keydowan);         // キーボードの入力挙動 
     glutKeyboardUpFunc(keyup);          // 離した時の挙動 
     glutTimerFunc(100, timer, 0);       // timer 関数内の実行 
     glutReshapeFunc(reshape);           // 画面の再定義 
     init(); 
     glutMainLoop(); 
     return 0; 
}


