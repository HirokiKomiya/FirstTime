#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define J 1	//相互作用の強さ
#define STEP 1000		//この値ごとに出力

#define size 10	//サイズ
#define T 1	//温度パラメータ
#define RoundMax 100000
#define STEP 1000		//この値ごとに出力


double E;	//エネルギー


int a[100][100];
int b;
int i,j;

int k;

int site_i;
int site_j;
double r;

double Ei1;
double Ei2;

double DE;
double RND;

int sum;	//エネルギーの合計

main()
{
	//初期スピン配置
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			
			b=(int)rand()%2;
			if(b==0){
				b=-1;
			}
			a[i][j]=b;
			if(a[i][j]<0)
					printf("□");
				else
					printf("■");
		}
		printf("\n");
	}
	
	for(k=0;k<RoundMax;k++){
		site_i=rand()%10;
		site_j=rand()%10;
		/*printf("i=%d",site_i);
		printf("k=%d/n",site_k);
		*/
		a[site_i][site_j]=a[site_i][site_j]*(-1);
		sum=0;
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
			sum=sum+a[i][j];
			}
		}
		Ei1=J*sum;
		
		r=exp(-2*Ei1/T);
		//printf("r:%d",r);
		
		DE=Ei1-Ei2;
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				if(DE<=0){
					a[i][j]=a[i][j]*(-1);
				}else{
					RND=0 + (int)( rand() * (1 - 0 + 1.0) / (1.0 + RAND_MAX) );
					if(RND<r){
						a[i][j]=a[i][j]*(-1);
					}
				}
			}
		}
		
		if(!( (k+1) % STEP )){
			printf("Round:%d\n",k+1);
			
			for(i=0;i<size;i++){
				for(j=0;j<size;j++){
					if(a[i][j]<0)
						printf("□");
					else
						printf("■");
				}
			printf("\n");
			}
		}
	}
}