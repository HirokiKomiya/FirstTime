#include"wavetest.h"
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<windows.h>
#include<stdio.h>
#include<gl/glut.h>

#define HISTORY 100

int mode;
short *sound_data;
float p,yp;
int temp_w;
double rate;

double data[HISTORY][FRAME];
int num=0;

int bitmap_sentence(char *word,float x,float y){
	unsigned int i;
	for(i=0;i<strlen(word);i++){
		glRasterPos3f(x,y,0.0);
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,word[i]);
		x=x+glutBitmapWidth(GLUT_BITMAP_8_BY_13,word[i])*p+2.0*p;
	}
	return 0;
}

void display(void)
{
	short sound[FRAME];
	//double power_spec[FRAME/2];
	int i,j;
	static double **data_matrix;
	if(data_matrix == NULL)
		data_matrix = (double**)malloc(HISTORY*sizeof(double*));

	glClear(GL_COLOR_BUFFER_BIT);
	memcpy(sound,sound_data,FRAME*sizeof(short));
	if(mode == 0)
	{
		calc_spec(data[num],sound,FRAME);

		i=num;
		for(j=0;j<HISTORY;j++)
		{
			data_matrix[j] = data[i];
			i++;
			if(i>=HISTORY) i=0;
		}

		glColor3f(1.0,0.0,0.0);
		for(i=0;i<HISTORY;i++)
		{
			glBegin(GL_LINE_STRIP);
			for(j=0;j<(int)(FRAME/(float)SAMPLING*11000);j++)
			{
				glVertex3d((double)j/(FRAME/(double)SAMPLING*11z000.0)*0.54,data_matrix[i][j]/rate,(double)((-i)*6.0/HISTORY));
			}
			glEnd();
		}
		glColor3f(0.0,0.0,0.0);
		bitmap_sentence("0",0,0);
		bitmap_sentence("1k",(float)FRAME/SAMPLING*1000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		bitmap_sentence("2k",(float)FRAME/SAMPLING*2000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		bitmap_sentence("3k",(float)FRAME/SAMPLING*3000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		bitmap_sentence("4k",(float)FRAME/SAMPLING*4000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		bitmap_sentence("5k",(float)FRAME/SAMPLING*5000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		bitmap_sentence("6k",(float)FRAME/SAMPLING*6000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		bitmap_sentence("7k",(float)FRAME/SAMPLING*7000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		bitmap_sentence("8k",(float)FRAME/SAMPLING*8000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		bitmap_sentence("9k",(float)FRAME/SAMPLING*9000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		bitmap_sentence("10k",(float)FRAME/SAMPLING*10000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		bitmap_sentence("11k",(float)FRAME/SAMPLING*11000.0/(FRAME/(float)SAMPLING*11000.0)*0.54,0);
		num--;
		if(num<0) num=HISTORY-1;
	}
	else if(mode == 1 || mode == 2)
	{
		if(mode == 1)
			calc_powerspec(data[num],sound,FRAME);
		else
			calc_sound_to_spec_houraku(data[num],sound,FRAME);
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_LINE_STRIP);
		for(j=0;j<FRAME/2*2/3;j++)
		{
			glVertex2d((double)j/(FRAME/2.0*2.0/3.0),(data[num][j] + 80)/90);
		}
		glEnd();
		glColor3f(0.0,0.0,0.0);
		bitmap_sentence("0",0,0);
		bitmap_sentence("1k",(float)FRAME/SAMPLING*1000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("2k",(float)FRAME/SAMPLING*2000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("3k",(float)FRAME/SAMPLING*3000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("4k",(float)FRAME/SAMPLING*4000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("5k",(float)FRAME/SAMPLING*5000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("6k",(float)FRAME/SAMPLING*6000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("7k",(float)FRAME/SAMPLING*7000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("8k",(float)FRAME/SAMPLING*8000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("9k",(float)FRAME/SAMPLING*9000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("10k",(float)FRAME/SAMPLING*10000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("11k",(float)FRAME/SAMPLING*11000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("12k",(float)FRAME/SAMPLING*12000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("13k",(float)FRAME/SAMPLING*13000.0/(FRAME/2.0*2.0/3.0),0);
		bitmap_sentence("14k",(float)FRAME/SAMPLING*14000.0/(FRAME/2.0*2.0/3.0),0);
	}
	else if(mode==3 || mode==4)
	{
		if(mode==3)
			calc_powerspec(data[num],sound,FRAME);
		else
			calc_sound_to_spec_houraku(data[num],sound,FRAME);
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_LINE_STRIP);
		for(j=0;j<FRAME/2*2/3;j++)
		{
			glVertex2d(log((double)j)/log((FRAME/2.0*2.0/3.0)),(data[num][j] + 80)/90);
		}
		glEnd();
		glColor3f(0.0,0.0,0.0);
		bitmap_sentence("0",0,0);
		bitmap_sentence("500",log((float)FRAME/SAMPLING*500.0)/log((FRAME/2.0*2.0/3.0)),0);
		bitmap_sentence("10k",log((float)FRAME/SAMPLING*10000.0)/log((FRAME/2.0*2.0/3.0)),0);
	}
	else
	{
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);
		glVertex2d(0,0.5);
		glVertex2d(1.0,0.5);
		glEnd();
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_LINE_STRIP);
		for(j=0;j<FRAME;j++)
		{
			glVertex2d((double)j/(FRAME),sound[j]/(double)0x7FFF + 0.5);
		}
		glEnd();
	}
	glutSwapBuffers();
}

void reshape(int w,int h)
{
	glViewport( 0, 0, w, h );
	temp_w=w;
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	if( mode == 0 )
	{
		p=0.5/w;
		gluPerspective(30.0, (double)1.0, 0.001, 100.0);
		glTranslated(-0.27, -0.25, 0);
		gluLookAt(0.001, 0.3, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	}
	else
	{
		p=1.0/w;
		glOrtho(0.0,1.0,0.0,1.0,0.0,1.0);
	}
}

void simu(void)
{
	Sleep(30);
	glutPostRedisplay();
}

void keyboard(unsigned char key,int x,int y){
	switch(key){
		case 'e':
			glutIdleFunc(NULL);
			break;
		case 's':
			glutIdleFunc(simu);
			break;
		case '1':
			mode=0;
			p=0.5/temp_w;
			glLoadIdentity();
			glMatrixMode(GL_PROJECTION);
			gluPerspective(30.0, (double)1.0, 0.001, 100.0);
			glTranslated(-0.27, -0.25, 0);
			gluLookAt(0.001, 0.3, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			break;
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
			mode=key-'1';
			p=1.0/temp_w;
			glLoadIdentity();
			glMatrixMode(GL_PROJECTION);
			glOrtho(0.0,1.0,0.0,1.0,0.0,1.0);
			break;
	}
}

int gl_Plot(int argc,char *argv[],short *sound)
{
	char c;
	FILE *fp;
	fp = fopen("set.ini","r");
	if(fp == NULL)
	{
		printf("not open set.ini\n");
		return 1;
	}
	fscanf(fp, "%lf", &rate);
	fscanf(fp,"%c", &c);
	sound_data=sound;
	glutInit(&argc, argv);
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  	glutInitWindowSize (400, 300);
  	glutInitWindowPosition(100,100);
  	glutCreateWindow("plot window");
  	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(simu);
	glutKeyboardFunc(keyboard);
    glutMainLoop();
	return 0;
}