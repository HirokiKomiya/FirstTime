#include <stdio.h>
#include <math.h>
#include "common.h"
#include "fftcore.h"
#define SIZE 16


FILE *fp;
char name[] = "signal.txt";


void maketimedomain(double x[],int size)
{
 int i;
 fp = fopen(name,"r+");
 
 while(){
 	fscanf(fp,"%f",x[i]));
 	
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
