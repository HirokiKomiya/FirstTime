#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define Keiro "Keiro_data"

//�ԁF�P�@�F�Q


int main(int){
	/*char filename[20];
	
	FILE *file;
	sprintf(filename,"%s.txt",Keiro);
	file = fopen(filename,"r");
	fclose(file);
	*/
	int i,j;
	
	int BallKosu;	//�{�[���̌�
	int TuboKosu;
	
	float BallRatio[10][10];	//[�F][�c�{]
	float TuboRatio[10][10];
	
	float g[10][10];
	
	BallRatio[1][1]=0.6;
	BallRatio[2][1]=0.4;
	BallRatio[2][2]=0.5;
	BallRatio[3][2]=0.5;
	
	TuboRatio[1][1]=0.6;	//[���݂̃c�{][1:���̂܂� 2:���̂�]
	TuboRatio[1][2]=0.4;
	TuboRatio[2][1]=0.4;
	TuboRatio[2][2]=0.7;
	
	float EndRatio=0.3;
	
	float num0,num1;
	
	BallKosu=3;
	TuboKosu=2;
	
	for(i=1;i<=BallKosu;i++){
		for(j=1;j<=TuboKosu;j++){
			if(j<i+(TuboKosu-BallKosu)){
				
			}else{
				if(i==1 && j==1){
					g[i][j] = BallRatio[i][j];
				}else{
					if(i==1){
						g[i][j] = g[i-1][j] * BallRatio[i][j]*TuboRatio[i-1][j];
						
					}else{
						if(i==j){
							g[i][j]=g[i-1][j-1] * BallRatio[i][j]*TuboRatio[i-1][j];
							printf("%f %d %d\n",g[i][j],i,j);
						}else{
							num0 = g[i-1][j] * BallRatio[i][j]*TuboRatio[i-1][j];
							num1 = g[i-1][j-1] * BallRatio[i][j]*TuboRatio[i-1][j-1];
							g[i][j]=num0+num1;
							printf("num0=%f,%f %d %d\n",num0,num1,i,j);
						}
					}
				}
			}
		}
	}
	g[BallKosu][TuboKosu]=g[BallKosu][TuboKosu]*EndRatio;
	
	printf("\nRBB���o��m����%f�ł��B\n",g[BallKosu][TuboKosu]);
	
}

