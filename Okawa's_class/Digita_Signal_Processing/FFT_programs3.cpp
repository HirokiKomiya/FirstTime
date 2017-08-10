#include <stdio.h>
#include <math.h>
#include "common.h"
#include "fftcore.h"
#define SIZE 256
#include <stdlib.h>

FILE *fp;
char name[] = "signal.txt";


void maketimedomain(double data[],int size)
{
	char a[10];
	//int data[20000];
    FILE *fp;
    char file_name[] = "signal.txt";
	int i = 0;
	
    /* �t�@�C���I�[�v�� */
    if ((fp = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "%s\n", "error: can't read file.");
    }
    while (fscanf(fp, "%s", a) != EOF){
        data[i] = atoi(a);
		printf("%d\n",data[i]);
 		i++;
    }
    fclose(fp);
}

main()
{
 double timedomain[SIZE]; /*���ԗ̈�f�[�^�i�[��*/
 dcomplex_t fftwork[SIZE]; /*���f����Ɨ̈�*/

 /*FFT�̏�����*/
 initfft(SIZE);

 /*���ԗ̈�f�[�^�̍쐬�ƃt�@�C���ۑ�*/
 maketimedomain(timedomain,SIZE);
 savereal(timedomain,SIZE,"timedomain.txt");

 /*FFT��Ƃ̏����̂��߁C���ԗ̈�f�[�^�𕡑f����Ɨ̈��*/
 /*�R�s�[�ƃt�@�C���ۑ�*/
 real2cmp(timedomain,fftwork,SIZE);
 savecmp(fftwork,SIZE,"comptimedomain.txt");

 /*FFT�i�������t�[���G�ϊ��j*/
 /*��Ɨ̈�fftwork�̓��e���X�y�N�g���ɂȂ�*/
 /*����ꂽ�X�y�N�g���̃t�@�C���ւ̕ۑ�*/
 fft(1,fftwork,SIZE);
 savecmp(fftwork,SIZE,"spectrum.txt");

}
