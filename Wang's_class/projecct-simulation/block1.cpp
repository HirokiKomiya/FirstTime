#include <GL/glut.h>
#include <GL/block.h>
#include <cmath>
#include <iostream>
#include <cstdlib> 
using namespace std;
#define WIDTH 640   // ��ʂ̉��T�C�Y 
#define HEIGHT 480  // ��ʂ̏c�T�C�Y 
#define PI 3.141592     // �~���� 


void player(){  // �o�[�̐��� 
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
     if(5 <= bx && bx <= 635 ){  // x��(���E)�̕ǂɓ��������ꍇ 
         /* �������Ȃ� */ 
     }else{ 
         l = -1 * l;     // x���̑����l�𔽓]������ 
         bx += l  * movex; 
         by += ll * movey; 
     } 

if(5 <= by && by <= 490){   // y��(��)�̕ǂɓ��������ꍇ 
         /* �������Ȃ� */ 
    }else{ 
         ll = -1 * ll;   // y���̑����l�𔽓]������ 
         bx += l  * movex; 
         by += ll * movey; 
     } 
 
     // ���@(�o�[)�̓����蔻�� 
     if(px + pmovex - 40 < bx && bx < px + pmovex + 40 && py - 10 < by && by < py){  
         ll = -1 * ll;   // y���̑����l�𔽓]������ 
         bx += l  * movex; 
         by += ll * movey; 
     } 
 
     if(by > 480){ exit(1); }    // �e����ʉ��ɏo����I�� 
 } 
 
 void Ball::ball(){ // �{�[���̐��� 
     setdec=true;
	 if(setdec){ set(); }    // ��x���������� 
 
     glBegin(GL_POLYGON); 
     //glColor3d(1.0, 0.0, 0.0); 
    glVertex2f(bx, by); 
     for(int i = 0; i < 360; ++i){ 
glVertex2f(bx + br * cos(i), by + br * sin(i)); 
     } 
     glEnd(); 
 } 


 void Ball::set(){   // ���������e 
     setdec=true;
	 br = 5;         // �{�[���̔��a 
     shotr = 45;     // �{�[���̈ړ��p�x 
     shotdec = 0;    // �ŏ��ɔ��˂��鎞�ɁAspace�L�[�������Ă邩�̔��� 
     setdec = false; 
} 

void Block::decision(int Num, int hNum){    // �u���b�N�̔��˔��� 
	blockx = 40;
	blocky = 20;
	spownx = 70;
	spowny = 30;
     // �u���b�N��̔��� 
     if(blockx - 30 + (spownx * Num)  < bx && bx < blockx + 30 + (spownx * Num) && 
        blocky - 15 + (spowny * hNum) < by && by < blocky - 10 + (spowny * hNum)) { 

         if(Life[hNum][Num] == 0){   // �G�@�ɓ����������A�e�̍��W��߂� 
               ll = -1 * ll;       // x���̑����l�𔽓]������ 
                 Life[hNum][Num] = 1;     
         }            
     } 
// �u���b�N���̔��� 
     if(blockx - 30 + (spownx * Num)  < bx && bx < blockx + 30 + (spownx * Num) && 
        blocky + 10 + (spowny * hNum) < by && by < blocky + 15 + (spowny * hNum)) { 
 
         if(Life[hNum][Num] == 0){   // �G�@�ɓ����������A�e�̍��W��߂� 
               ll = -1 * ll;       // x���̑����l�𔽓]������ 
                 Life[hNum][Num] = 1;     
         }            
     } 
 
     // �u���b�N���̔��� 
    if(blockx - 30 + (spownx * Num)  < bx && bx < blockx - 25 + (spownx * Num) && 
        blocky - 15 + (spowny * hNum) < by && by < blocky + 15 + (spowny * hNum)) { 
 
         if(Life[hNum][Num] == 0){   // �G�@�ɓ����������A�e�̍��W��߂� 
                 l = -1 * l;     // x���̑����l�𔽓]������ 
                 Life[hNum][Num] = 1;     
         }            
     } 

     // �u���b�N�E�̔��� 
     if(blockx + 25 + (spownx * Num)  < bx && bx < blockx + 30 + (spownx * Num) && 
        blocky - 15 + (spowny * hNum) < by && by < blocky + 15 + (spowny * hNum)) { 

         if(Life[hNum][Num] == 0){   // �G�@�ɓ����������A�e�̍��W��߂� 
                 l = -1 * l;     // x���̑����l�𔽓]������ 
                 Life[hNum][Num] = 1;     
         }            
     } 
 } 
 
 // �u���b�N�̐��� 
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
 
 //�@�u���b�N�̐F���� 
 void Block::colorset(int Num){
 	blockx = 40;
	blocky = 20;
	spownx = 70;
	spowny = 30;
     (Num == 0 ? glColor3d(1.0, 0.0, 0.0) : Num == 1 ? glColor3d(1.0, 1.0, 0.0) : Num == 2  
               ? glColor3d(0.0, 1.0, 0.0) : Num == 3 ? glColor3d(0.0, 0.0, 1.0) : Num == 4 
               ? glColor3d(1.0, 0.0, 1.0) : glColor3d(1.0, 1.0, 1.0)); 
} 


 //�@��ʕ\�� 
 void display(){ 
     Ball b; 
     Block blo[5][10]; 
glClear(GL_COLOR_BUFFER_BIT); 

    player();   // ���@���� 
     b.ball();   // �e�̐��� 


     for(int i = 0; i < 5; ++i){ 
         for(int j = 0; j < 10; ++j){ 
             blo[i][j].block(j, i);  // �u���b�N�̐��� 
             glEnd(); 
         } 
     } 
	 
    glFlush();
	
} 
void leftmove(){    // ���@���ړ� 
    if(px + pmovex > 40){   // ���[�̓����蔻�� 
             pmovex -= 10.0;      
             //if(smovey == 430.0){ spmovex -= 50.0; }   // �e�̍��ړ� 
             glutPostRedisplay(); 
         } 
 } 
 
 void rightmove(){   // ���@�E�ړ� 
     if(px + pmovex < 600){ 
            pmovex += 10.0;     // �E�[�̓����蔻�� 
            //if(smovey == 430.0){ spmovex += 50.0; }   // �e�̉E�ړ� 
            glutPostRedisplay(); 
    } 
 } 
 
 // �L�[������������ 
void keydowan(unsigned char key, int x, int y){ 

     switch(key){ 
         case 'a':   // a ����͂���ƍ��ɓ��� 
         case 'A':  
 
         glutIdleFunc(leftmove); 
         break; 
         case 'd':   // d ����͂���ƉE�ɓ��� 
         case 'D': 
glutIdleFunc(rightmove); 
         break; 
 
        case 'q':   // q Q ESC ����͂���ƃv���O�����I�� 
         case 'Q': 
         case '\033': 
         exit(0); 


         default:  
         break; 
    } 
 } 

void keyup(unsigned char key, int x, int y){    // �L�[�𗣂������̋��� 
     switch(key){    // a A �𗣂����Ƃ��Ɉړ����~�߂� 
         case 'a': 
         case 'A':  
        glutIdleFunc(0); 
         break; 

         case 'd':   // d D ��b�������Ɉړ����~�߂� 
         case 'D': 
         glutIdleFunc(0); 
         break; 
default: break; 

    }    
} 

void reshape(int w, int h){             // ���W�̒�`�ύX 
   glViewport(0, 0, w, h); 
     glMatrixMode(GL_PROJECTION); 
     glLoadIdentity(); 
     gluOrtho2D(0, 640, 480, 0);         // ������@(0, 0) �E���� (640, 480)�Ƃ��� 
 } 

void timer(int value){  // ���b���Ƃɍĕ`�悵�āA�A�j���[�V���������� 
     Ball b; 
    Block blo; 
     b.reverse(); 
     //blo.decision(ptrNum, ptrhNum); 
 
    bx += l  * movex;   // x���̃{�[���̓���(��) 
     by += ll * movey;   // y���̃{�[���̓���(��) 
 
    glutPostRedisplay();                // �ĕ`�� 
     glutTimerFunc(30, timer, 0);        // ���������b�ŌJ��Ԃ� 
} 

void init(){ 
    glClearColor(0.0, 0.0, 0.0, 1.0);   // �w�i�F�@�� 
}

int main(int argc, char *argv[]){ 
     glutInitWindowPosition(100, 200);   // �E�B���h�E�쐬���̍��W�w�� 
     glutInitWindowSize(WIDTH, HEIGHT);  // �E�B���h�E�T�C�Y�̎w�� 
     glutInit(&argc, argv);           
     glutInitDisplayMode(GLUT_RGBA /*| GLUT_DOUBLE*/);   // Red Green Brue +��(�����x)= RGBA  
     glutCreateWindow(argv[0]);          // �E�B���h�E�𐶐��B argv[0]���ƃt�@�C���������̂܂܃E�B���h�E���ɂȂ� 
     glutDisplayFunc(display);           // display�֐�����\�� 
     glutKeyboardFunc(keydowan);         // �L�[�{�[�h�̓��͋��� 
     glutKeyboardUpFunc(keyup);          // ���������̋��� 
     glutTimerFunc(100, timer, 0);       // timer �֐����̎��s 
     glutReshapeFunc(reshape);           // ��ʂ̍Ē�` 
     init(); 
     glutMainLoop(); 
     return 0; 
}


