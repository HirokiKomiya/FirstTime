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
 double timedomain[SIZE]; /*時間領域データ格納域*/
 dcomplex_t fftwork[SIZE]; /*複素数作業領域*/

 /*FFTの初期化*/
 initfft(SIZE);

 /*時間領域データの作成とファイル保存*/
 maketimedomain(timedomain,SIZE);
 savereal(timedomain,SIZE,"timedomain.txt");

 /*FFT作業の準備のため，時間領域データを複素数作業領域へ*/
 /*コピーとファイル保存*/
 real2cmp(timedomain,fftwork,SIZE);
 savecmp(fftwork,SIZE,"comptimedomain.txt");

 /*FFT（順方向フーリエ変換）*/
 /*作業領域fftworkの内容がスペクトルになる*/
 /*得られたスペクトルのファイルへの保存*/
 fft(1,fftwork,SIZE);
 savecmp(fftwork,SIZE,"spectrum.txt");

}
