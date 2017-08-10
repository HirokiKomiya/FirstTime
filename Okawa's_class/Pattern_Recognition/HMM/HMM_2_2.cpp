#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

char Character[250];
int n, num=0, state=1, data[1024],statelog[62],out=0;
double count;

//
typedef struct Model {
	double a[8][8];
	double b[8];
}HMM;

//ランダム関数
double Random() {
	return (double)rand()/((double)RAND_MAX+1);
}

//ツボから出てくるボールの色を数字にして返す関数
int Ball(HMM *model, int *state){
	double rnd_ball;
	rnd_ball = Random();
	
	if(rnd_ball <= model[*state].b[1]){
		return 1;
	}else if(rnd_ball <= model[*state].b[1]+model[*state].b[2]){
		return 2;
	}else if(rnd_ball <= model[*state].b[1]+model[*state].b[2]+model[*state].b[3]){
		return 3;
	}else{
		return 4;
	}
}

//遷移確率から次のツボに移るかの判定
int Move(HMM *model, int *state){
	double rnd_move;
	rnd_move = Random();
	if(rnd_move <= model[*state].a[*state][*state]){
		return 0; //同じつぼへ
	}else{
		return 1; //次のつぼへ
	}
}

//上記の二つの関数の結果をまとめてメインに返す関数
void OutPut(HMM *model, int *state, int *data, int num){
	data[num]=Ball(model, state);
	*state+=Move(model, state);
}

int main(int)
{
	HMM model[100];
	srand((unsigned int)time(NULL));
	
	int i;
	int count;
	int count1;
	double ratio1;
	
	double R[100]={0};
	double Y[100]={0};
	double B[100]={0};
	double S[100]={0};
	double a[100][100];
	int tubo=0;
	int RoundMax=0;	//これらは初期化がなければexitに入らない為初期化
	
	
	printf("\n試行回数を入力してください\n");
	scanf("\n%d",&RoundMax);
	if(RoundMax<=0){
		printf("入力が不正です．\n");
		exit(1);
	}
	
	printf("ツボの個数を指定してください\n");
	scanf("\n%d",&tubo);
	if(tubo<=0){
		printf("入力が不正です．\n");
		exit(1);
	}
	
	for(count=1;count<tubo+1;count++){
		printf("ツボ%dの〇の確率を入力してください:",count);
		scanf("%lf",&R[count]);
		if(R[count]<0){
			printf("入力が不正です．\n");
			exit(1);
		}
		printf("ツボ%dの●の確率を入力してください:",count);
		scanf("%lf",&Y[count]);
		if(Y[count]<0){
			printf("入力が不正です．\n");
			exit(1);
		}
		printf("ツボ%dの■の確率を入力してください:",count);
		scanf("%lf",&B[count]);
		if(B[count]<0){
			printf("入力が不正です．\n");
			exit(1);
		}
		ratio1 = R[count]+Y[count]+B[count];
		if(ratio1>1.0){
			printf("確率が1を超えています．入力をやり直してください．\n");
			count=count-1;
		}else{
			S[count] = 1 - ratio1;
			printf("ツボ%dの▲の確率は%.3lfです．\n",count,S[count]);
			printf("次のツボへの遷移確率を入力してくいださい:");
			scanf("%lf",&a[count][count+1]);
			if(a[count][count+1]>1.0 | a[count][count+1]<=0){
				printf("確率が1を超えているか，0以下です．入力をやり直してください．\n");
				count=count-1;
			}else{
				a[count][count] = 1 - a[count][count+1];
				printf("次のツボに移らない確率は%lfです．\n",a[count][count]);
			}
		}
	}
	
	for(i=0;i<RoundMax;i++){
		for(count=1;count<tubo+1;count++){
			model[count].b[1] = R[count];
			model[count].b[2] = Y[count];
			model[count].b[3] = B[count];
			model[count].b[4] = S[count];
			model[count].a[count][count] = a[count][count];
			model[count].a[count][count+1] = a[count][count+1];
		}
		
		printf("ROUND:%d",i+1);
		out=0;num=0;
		
		for(count=1;count<tubo+1;count++){
			
			printf("\nState%d ",count);
			printf("〇%0.1f ％ ",R[count]*100);
			printf("●%0.1f ％ ",Y[count]*100);
			printf("■%0.1f ％ ",B[count]*100);
			printf("▲%0.1f ％ ",S[count]*100);
			printf("次のつぼへの遷移確率%0.1f ％",a[count][count+1]*100);
			printf("\n ");
			
			state=count;
			int d;
			while(1){ //結果を出力
				d=state;
				OutPut(model,&state,data,num);
				
				if(data[num]==1)printf("〇");
				else if(data[num]==2)printf("●");
				else if(data[num]==3)printf("■");
				else if(data[num]==4)printf("▲");
				num++;
				out++;
				if(state != d){
					break;
				}
			//out=0;
			}
		//printf("\nState%d",count+1);
		}
	printf("\n");
	}
	
	printf("\n\n");
	printf("END\n");
	return 0;
}

