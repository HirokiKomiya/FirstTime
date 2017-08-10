#include"wavetest.h"
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<windows.h>
#include<stdio.h>
#include<gl/glut.h>

#define HISTORY 100

int mode = 6, func1 = 0, func2 = 0, m = 0;
int fg1 = 1, fg2 = 0, fg3 = 0, fg4 = 0;
short *sound_data;
float p, yp;
int temp_w;
double rate, demo;

double data[HISTORY][FRAME];
double ndata[HISTORY][FRAME];
double fdata[HISTORY][FRAME] = { 0 };

int f1_a, f1_i, f1_u, f1_e, f1_o, f2_a, f2_i, f2_u, f2_e, f2_o;

int num = 0;

int bitmap_sentence(char *word, float x, float y){
	unsigned int i;
	for (i = 0; i<strlen(word); i++){
		glRasterPos3f(x, y, 0.0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, word[i]);//•¶Žš‚Ì‘å‚«‚³‚Í‚±‚±
		x = x + glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, word[i])*p + 2.0*p;
	}
	return 0;
}

void display(void)
{
	short sound[FRAME];
	//double power_spec[FRAME/2];
	int i, j, k = 0;
	double R = 1.0, G = 0.0, B = 0.0;
	static double **data_matrix;
	if (data_matrix == NULL)
		data_matrix = (double**)malloc(HISTORY*sizeof(double*));

	glClear(GL_COLOR_BUFFER_BIT);
	memcpy(sound, sound_data, FRAME*sizeof(short));
	if (mode == 0)
	{
		calc_spec(data[num], sound, FRAME);

		i = num;
		for (j = 0; j<HISTORY; j++)
		{
			data_matrix[j] = data[i];
			i++;
			if (i >= HISTORY) i = 0;
		}



		for (i = 0; i<HISTORY / 6; i++)
		{
			glColor3f(R, G, 0.0);
			glBegin(GL_LINE_STRIP);
			for (j = 0; j<(int)(FRAME / (float)SAMPLING * 22000); j++)
			{
				glVertex3d((double)j / (FRAME / (double)SAMPLING*22000.0)*0.54, data_matrix[i][j] / rate, (double)((-i)*6.0 / HISTORY));
			}
			glEnd();
			G = G + k*0.01;
			k++;
		}

		k = 0;

		for (i = i; i<HISTORY * 2 / 6; i++)
		{
			glColor3f(R, G, 0.0);
			glBegin(GL_LINE_STRIP);
			for (j = 0; j<(int)(FRAME / (float)SAMPLING * 22000); j++)
			{
				glVertex3d((double)j / (FRAME / (double)SAMPLING*22000.0)*0.54, data_matrix[i][j] / rate, (double)((-i)*6.0 / HISTORY));
			}
			glEnd();
			R = R - k*0.01;
			k++;
		}

		k = 0;

		for (i = i; i<HISTORY * 3 / 6; i++)
		{
			glColor3f(R, G, B);
			glBegin(GL_LINE_STRIP);
			for (j = 0; j<(int)(FRAME / (float)SAMPLING * 22000); j++)
			{
				glVertex3d((double)j / (FRAME / (double)SAMPLING*22000.0)*0.54, data_matrix[i][j] / rate, (double)((-i)*6.0 / HISTORY));
			}
			glEnd();
			B = B + k*0.01;
			k++;

		}

		k = 0;

		for (i = i; i<HISTORY * 4 / 6; i++)
		{
			glColor3f(R, G, B);
			glBegin(GL_LINE_STRIP);
			for (j = 0; j<(int)(FRAME / (float)SAMPLING * 22000); j++)
			{
				glVertex3d((double)j / (FRAME / (double)SAMPLING*22000.0)*0.54, data_matrix[i][j] / rate, (double)((-i)*6.0 / HISTORY));
			}
			glEnd();
			G = G - k*0.01;
			k++;

		}

		k = 0;

		for (i = i; i<HISTORY; i++)
		{
			glColor3f(R, G, B);
			glBegin(GL_LINE_STRIP);
			for (j = 0; j<(int)(FRAME / (float)SAMPLING * 22000); j++)
			{
				glVertex3d((double)j / (FRAME / (double)SAMPLING*22000.0)*0.54, data_matrix[i][j] / rate, (double)((-i)*6.0 / HISTORY));
			}
			glEnd();
			R = R + k*0.01;
			k++;

		}



		glColor3f(1.0, 1.0, 1.0);//0,0,0‚Å•
		bitmap_sentence("0", 0, 0);
		bitmap_sentence("1k", (float)FRAME / SAMPLING*1000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("2k", (float)FRAME / SAMPLING*2000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("3k", (float)FRAME / SAMPLING*3000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("4k", (float)FRAME / SAMPLING*4000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("5k", (float)FRAME / SAMPLING*5000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("6k", (float)FRAME / SAMPLING*6000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("7k", (float)FRAME / SAMPLING*7000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("8k", (float)FRAME / SAMPLING*8000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("9k", (float)FRAME / SAMPLING*9000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("10k", (float)FRAME / SAMPLING*10000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("11k", (float)FRAME / SAMPLING*11000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("12k", (float)FRAME / SAMPLING*12000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("13k", (float)FRAME / SAMPLING*13000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("14k", (float)FRAME / SAMPLING*14000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("15k", (float)FRAME / SAMPLING*15000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("16k", (float)FRAME / SAMPLING*16000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("17k", (float)FRAME / SAMPLING*17000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("18k", (float)FRAME / SAMPLING*18000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("19k", (float)FRAME / SAMPLING*19000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("20k", (float)FRAME / SAMPLING*20000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("21k", (float)FRAME / SAMPLING*21000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		bitmap_sentence("22k", (float)FRAME / SAMPLING*22000.0 / (FRAME / (float)SAMPLING*22000.0)*0.54, 0);
		num--;
		if (num<0) num = HISTORY - 1;
	}
	else if (mode == 1 || mode == 2)
	{
		if (mode == 1)
			calc_powerspec(data[num], sound, FRAME);
		else
			calc_sound_to_spec_houraku(data[num], sound, FRAME);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_STRIP);
		for (j = 0; j<FRAME / 2 * 2 / 3; j++)
		{
			glVertex2d((double)j / (FRAME / 2.0*2.0 / 3.0), (data[num][j] + 80) / 90);
		}
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		bitmap_sentence("0", 0, 0);
		bitmap_sentence("1k", (float)FRAME / SAMPLING*1000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("2k", (float)FRAME / SAMPLING*2000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("3k", (float)FRAME / SAMPLING*3000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("4k", (float)FRAME / SAMPLING*4000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("5k", (float)FRAME / SAMPLING*5000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("6k", (float)FRAME / SAMPLING*6000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("7k", (float)FRAME / SAMPLING*7000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("8k", (float)FRAME / SAMPLING*8000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("9k", (float)FRAME / SAMPLING*9000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("10k", (float)FRAME / SAMPLING*10000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("11k", (float)FRAME / SAMPLING*11000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("12k", (float)FRAME / SAMPLING*12000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("13k", (float)FRAME / SAMPLING*13000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("14k", (float)FRAME / SAMPLING*14000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
	}
	else if (mode == 3 || mode == 4)
	{
		if (mode == 3)
			calc_powerspec(data[num], sound, FRAME);
		else
			calc_sound_to_spec_houraku(data[num], sound, FRAME);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_STRIP);
		for (j = 0; j<FRAME / 2 * 2 / 3; j++)
		{
			glVertex2d(log((double)j) / log((FRAME / 2.0*2.0 / 3.0)), (data[num][j] + 80) / 90);
		}
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		bitmap_sentence("0", 0, 0);
		bitmap_sentence("500", log((float)FRAME / SAMPLING*500.0) / log((FRAME / 2.0*2.0 / 3.0)), 0);
		bitmap_sentence("10k", log((float)FRAME / SAMPLING*10000.0) / log((FRAME / 2.0*2.0 / 3.0)), 0);
	}
	else if (mode == 6)
	{
		calc_sound_to_spec_houraku(data[num], sound, FRAME);

		i = num;
		for (j = 0; j<HISTORY; j++)
		{
			data_matrix[j] = data[i];
			i++;
			if (i >= HISTORY) i = 0;
		}
		if (func1 == 1){

			for (j = 0; j<(int)(FRAME / (float)SAMPLING * 11000); j++){
				fdata[m][j] = data_matrix[i - 1][j];
				for (j = 0; j<FRAME / 2 * 2 / 3; j++)
				{
					if (fg2 == 0 && fg3 == 0){
						if (fdata[num][j - 1] >= (data[num][j] + 80) / 90 && fdata[num][j + 1] <= (data[num][j] + 80) / 90 && fg1 == 0){
							f1_a = j;
							printf("f1_a = %d Hz\n", (f1_a + 1) * 14000 / (FRAME / 2 * 2 / 3));
							fg1 = 1;
							fg2 = 1;
						}
						if (fdata[num][j - 1] < (data[num][j] + 80) / 90 && fg1 == 1){
							fg1 = 0;
						}
						fdata[num][j] = (data[num][j] + 80) / 90;

					}

					if (fg2 == 1 && fg3 == 0){
						if (fdata[num][j - 1] > (data[num][j] + 80) / 90 && fdata[num][j + 1] <= (data[num][j] + 80) / 90 && fg1 == 0){
							f2_a = j;
							printf("f2_a = %d Hz\n", (f2_a + 1) * 14000 / (FRAME / 2 * 2 / 3));
							fg1 = 1;
							fg2 = 2;

						}
						if (fdata[num][j - 1] < (data[num][j] + 80) / 90 && fg1 == 1){
							fg1 = 0;
						}
						fdata[num][j] = (data[num][j] + 80) / 90;
					}

					if (fg2 == 2 && fg3 == 1){
						if (fdata[num][j - 1] > (data[num][j] + 80) / 90 && fdata[num][j + 1] <= (data[num][j] + 80) / 90 && fg1 == 0){
							f1_i = j;
							printf("f1_i = %d Hz\n", (f1_i + 1) * 14000 / (FRAME / 2 * 2 / 3));
							fg1 = 1;
							fg2 = 3;
						}
						if (fdata[num][j - 1] < (data[num][j] + 80) / 90 && fg1 == 1){
							fg1 = 0;
						}
						fdata[num][j] = (data[num][j] + 80) / 90;

					}

					if (fg2 == 3 && fg3 == 1){
						if (fdata[num][j - 1] > (data[num][j] + 80) / 90 && fdata[num][j + 1] <= (data[num][j] + 80) / 90 && fg1 == 0){
							f2_i = j;
							printf("f2_i = %d Hz\n", (f2_i + 1) * 14000 / (FRAME / 2 * 2 / 3));
							fg1 = 1;
							fg2 = 4;

						}
						if (fdata[num][j - 1] < (data[num][j] + 80) / 90 && fg1 == 1){
							fg1 = 0;
						}
						fdata[num][j] = (data[num][j] + 80) / 90;
					}

					if (fg2 == 4 && fg3 == 2){
						if (fdata[num][j - 1] > (data[num][j] + 80) / 90 && fdata[num][j + 1] <= (data[num][j] + 80) / 90 && fg1 == 0){
							f1_u = j;
							printf("f1_u = %d Hz\n", (f1_u + 1) * 14000 / (FRAME / 2 * 2 / 3));
							fg1 = 1;
							fg2 = 5;
						}
						if (fdata[num][j - 1] < (data[num][j] + 80) / 90 && fg1 == 1){
							fg1 = 0;
						}
						fdata[num][j] = (data[num][j] + 80) / 90;

					}

					if (fg2 == 5 && fg3 == 2){
						if (fdata[num][j - 1] > (data[num][j] + 80) / 90 && fdata[num][j + 1] <= (data[num][j] + 80) / 90 && fg1 == 0){
							f2_u = j;
							printf("f2_u = %d Hz\n", (f2_u + 1) * 14000 / (FRAME / 2 * 2 / 3));
							fg1 = 1;
							fg2 = 6;

						}
						if (fdata[num][j - 1] < (data[num][j] + 80) / 90 && fg1 == 1){
							fg1 = 0;
						}
						fdata[num][j] = (data[num][j] + 80) / 90;
					}

					if (fg2 == 6 && fg3 == 3){
						if (fdata[num][j - 1] > (data[num][j] + 80) / 90 && fdata[num][j + 1] <= (data[num][j] + 80) / 90 && fg1 == 0){
							f1_e = j;
							printf("f1_e = %d Hz\n", (f1_e + 1) * 14000 / (FRAME / 2 * 2 / 3));
							fg1 = 1;
							fg2 = 7;
						}
						if (fdata[num][j - 1] < (data[num][j] + 80) / 90 && fg1 == 1){
							fg1 = 0;
						}
						fdata[num][j] = (data[num][j] + 80) / 90;

					}

					if (fg2 == 7 && fg3 == 3){
						if (fdata[num][j - 1] > (data[num][j] + 80) / 90 && fdata[num][j + 1] <= (data[num][j] + 80) / 90 && fg1 == 0){
							f2_e = j;
							printf("f2_e = %d Hz\n", (f2_e + 1) * 14000 / (FRAME / 2 * 2 / 3));
							fg1 = 1;
							fg2 = 8;

						}
						if (fdata[num][j - 1] < (data[num][j] + 80) / 90 && fg1 == 1){
							fg1 = 0;
						}
						fdata[num][j] = (data[num][j] + 80) / 90;
					}

					if (fg2 == 8 && fg3 == 4){
						if (fdata[num][j - 1] > (data[num][j] + 80) / 90 && fdata[num][j + 1] <= (data[num][j] + 80) / 90 && fg1 == 0){
							f1_o = j;
							printf("f1_o = %d Hz\n", (f1_o + 1) * 14000 / (FRAME / 2 * 2 / 3));
							fg1 = 1;
							fg2 = 9;
						}
						if (fdata[num][j - 1] < (data[num][j] + 80) / 90 && fg1 == 1){
							fg1 = 0;
						}
						fdata[num][j] = (data[num][j] + 80) / 90;

					}

					if (fg2 == 9 && fg3 == 4){
						if (fdata[num][j - 1] > (data[num][j] + 80) / 90 && fdata[num][j + 1] <= (data[num][j] + 80) / 90 && fg1 == 0){
							f2_o = j;
							printf("f2_o = %d Hz\n", (f2_o + 1) * 14000 / (FRAME / 2 * 2 / 3));
							fg1 = 1;
							fg2 = 10;
							fg4 = 1;

						}
						if (fdata[num][j - 1] < (data[num][j] + 80) / 90 && fg1 == 1){
							fg1 = 0;
						}
						fdata[num][j] = (data[num][j] + 80) / 90;
					}

				}
			}

			func1 = 0;
			fg3++;


		}

		if (func1 == 0 && fg4 == 0){
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_LINES);
			glVertex2d(0, 0.5);
			glVertex2d(1.0, 0.5);
			glEnd();
			glColor3f(0.0, 1.0, 0.0);
			glBegin(GL_LINE_STRIP);
			for (j = 0; j<FRAME; j++)
			{
				glVertex2d((double)j / (FRAME), sound[j] / (double)0x7FFF + 0.5);
			}
			glEnd();

		}
		if (func1 == 0 && fg4 == 1){
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_LINES);
			glVertex2d(0.15, 0.1);
			glVertex2d(0.95, 0.1);
			glEnd();

			glBegin(GL_LINES);
			glVertex2d(0.15, 0.1);
			glVertex2d(0.15, 0.9);
			glEnd();

			glBegin(GL_LINES);
			glVertex2d(200 * 0.1 / 125 + 0.15, 0.1);
			glVertex2d(200 * 0.1 / 125 + 0.15, 0.11);
			glEnd();
			glBegin(GL_LINES);
			glVertex2d(400 * 0.1 / 125 + 0.15, 0.1);
			glVertex2d(400 * 0.1 / 125 + 0.15, 0.11);
			glEnd();
			glBegin(GL_LINES);
			glVertex2d(600 * 0.1 / 125 + 0.15, 0.1);
			glVertex2d(600 * 0.1 / 125 + 0.15, 0.11);
			glEnd();
			glBegin(GL_LINES);
			glVertex2d(800 * 0.1 / 125 + 0.15, 0.1);
			glVertex2d(800 * 0.1 / 125 + 0.15, 0.11);
			glEnd();
			glBegin(GL_LINES);
			glVertex2d(1000 * 0.1 / 125 + 0.15, 0.1);
			glVertex2d(1000 * 0.1 / 125 + 0.15, 0.11);
			glEnd();

			glBegin(GL_LINES);
			glVertex2d(0.15, 500 * 0.1 / 312.5 + 0.1);
			glVertex2d(0.16, 500 * 0.1 / 312.5 + 0.1);
			glEnd();
			glBegin(GL_LINES);
			glVertex2d(0.15, 1000 * 0.1 / 312.5 + 0.1);
			glVertex2d(0.16, 1000 * 0.1 / 312.5 + 0.1);
			glEnd();
			glBegin(GL_LINES);
			glVertex2d(0.15, 1500 * 0.1 / 312.5 + 0.1);
			glVertex2d(0.16, 1500 * 0.1 / 312.5 + 0.1);
			glEnd();
			glBegin(GL_LINES);
			glVertex2d(0.15, 2000 * 0.1 / 312.5 + 0.1);
			glVertex2d(0.16, 2000 * 0.1 / 312.5 + 0.1);
			glEnd();
			glBegin(GL_LINES);
			glVertex2d(0.15, 2500 * 0.1 / 312.5 + 0.1);
			glVertex2d(0.16, 2500 * 0.1 / 312.5 + 0.1);
			glEnd();


			bitmap_sentence("0", 0.05, 0.05);
			bitmap_sentence("200", 200 * 0.1 / 125 + 0.1, 0.05);
			bitmap_sentence("400", 400 * 0.1 / 125 + 0.1, 0.05);
			bitmap_sentence("600", 600 * 0.1 / 125 + 0.1, 0.05);
			bitmap_sentence("800", 800 * 0.1 / 125 + 0.1, 0.05);
			bitmap_sentence("1000", 1000 * 0.1 / 125 + 0.1, 0.05);

			bitmap_sentence("500", 0.02, 500 * 0.1 / 312.5 + 0.1);
			bitmap_sentence("1000", 0.02, 1000 * 0.1 / 312.5 + 0.1);
			bitmap_sentence("1500", 0.02, 1500 * 0.1 / 312.5 + 0.1);
			bitmap_sentence("2000", 0.02, 2000 * 0.1 / 312.5 + 0.1);
			bitmap_sentence("2500", 0.02, 2500 * 0.1 / 312.5 + 0.1);

			bitmap_sentence("a", ((f1_a + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 125 + 0.15, ((f2_a + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 312.5 + 0.1);
			bitmap_sentence("e", ((f1_e + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 125 + 0.15, ((f2_e + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 312.5 + 0.1);
			bitmap_sentence("i", ((f1_i + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 125 + 0.15, ((f2_i + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 312.5 + 0.1);
			bitmap_sentence("u", ((f1_u + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 125 + 0.15, ((f2_u + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 312.5 + 0.1);
			bitmap_sentence("o", ((f1_o + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 125 + 0.15, ((f2_o + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 312.5 + 0.1);

			bitmap_sentence("F1[Hz]", 950 * 0.1 / 125 + 0.1, 0.15);
			bitmap_sentence("F2[Hz]", 0.1, 2500 * 0.1 / 312.5 + 0.15);

			glColor3f(0.0, 1.0, 0.0);
			glBegin(GL_LINE_LOOP);
			glVertex2d(((f1_a + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 125 + 0.15, ((f2_a + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 312.5 + 0.1);
			glVertex2d(((f1_e + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 125 + 0.15, ((f2_e + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 312.5 + 0.1);
			glVertex2d(((f1_i + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 125 + 0.15, ((f2_i + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 312.5 + 0.1);
			glVertex2d(((f1_u + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 125 + 0.15, ((f2_u + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 312.5 + 0.1);
			glVertex2d(((f1_o + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 125 + 0.15, ((f2_o + 1) * 14000 / (FRAME / 2 * 2 / 3))*0.1 / 312.5 + 0.1);

			glEnd();

		}
		num--;
		if (num<0) num = HISTORY - 1;
	}

	else if (mode == 7){
		calc_sound_to_spec_houraku(data[num], sound, FRAME);

		for (j = 0; j<FRAME / 2 * 2 / 3; j++)
		{
			if (fdata[num][j - 1] >(data[num][j] + 80) / 90){
				f1_a = j;
			}
			fdata[num][j] = (data[num][j] + 80) / 90;

		}
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_STRIP);
		for (j = 0; j<FRAME / 2 * 2 / 3; j++)
		{
			glVertex2d((double)j / (FRAME / 2.0*2.0 / 3.0), (data[num][j] + 80) / 90);
		}
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		bitmap_sentence("0", 0, 0);
		bitmap_sentence("1k", (float)FRAME / SAMPLING*1000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("2k", (float)FRAME / SAMPLING*2000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("3k", (float)FRAME / SAMPLING*3000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("4k", (float)FRAME / SAMPLING*4000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("5k", (float)FRAME / SAMPLING*5000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("6k", (float)FRAME / SAMPLING*6000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("7k", (float)FRAME / SAMPLING*7000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("8k", (float)FRAME / SAMPLING*8000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("9k", (float)FRAME / SAMPLING*9000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("10k", (float)FRAME / SAMPLING*10000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("11k", (float)FRAME / SAMPLING*11000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("12k", (float)FRAME / SAMPLING*12000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("13k", (float)FRAME / SAMPLING*13000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
		bitmap_sentence("14k", (float)FRAME / SAMPLING*14000.0 / (FRAME / 2.0*2.0 / 3.0), 0);
	}



	else
	{
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2d(0, 0.5);
		glVertex2d(1.0, 0.5);
		glEnd();
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_STRIP);
		for (j = 0; j<FRAME; j++)
		{
			glVertex2d((double)j / (FRAME), sound[j] / (double)0x7FFF + 0.5);
		}
		glEnd();
	}

	glutSwapBuffers();
}

void reshape(int w, int h){
	glViewport(0, 0, w, h);
	temp_w = w;
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	if (mode == 0)
	{
		p = 0.5 / w;
		gluPerspective(30.0, (double)1.0, 0.001, 100.0);
		glTranslated(-0.27, -0.25, 0);
		gluLookAt(0.001, 0.3, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	}
	else
	{
		p = 1.0 / w;
		glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0);
	}
}

void simu(void)
{
	Sleep(30);
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
	switch (key){
	case 'e':
		glutIdleFunc(NULL);
		break;
	case 's':
		glutIdleFunc(simu);
		break;
	case '1':
		mode = 0;
		p = 0.5 / temp_w;
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
	case '7':
	case '8':
		mode = key - '1';
		p = 1.0 / temp_w;
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0);
		break;
	case 'c':
		if (func1 == 0 && fg4 == 0){
			func1 = 1;
			break;
		}
		if (func1 == 0 && fg4 == 1){
			fg2 = 0;
			fg3 = 0;
			fg4 = 0;
		}

		break;
	}
}

int gl_Plot(int argc, char *argv[], short *sound)
{
	char c;
	/*FILE *fp;
	fp = fopen("set.ini","r");
	if(fp == NULL)
	{
	printf("not open set.ini\n");
	return 1;
	}
	fscanf(fp, "%lf", &rate);
	fscanf(fp,"%c", &c);*/
	rate = 2.5;
	c = 2.5;
	sound_data = sound;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("plot window");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(simu);

	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}