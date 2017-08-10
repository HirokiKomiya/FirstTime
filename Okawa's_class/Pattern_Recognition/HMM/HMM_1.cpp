#include <stdio.h>
#include <stdlib.h>
#include <time.h> //ランダム関数を使うため？（時間で変化する）
#include <math.h>
#include <string.h>

char Character[250];
int n, num=0, state=1, data[1024],statelog[62],out=0;
double count;

#define RoundMax 4

//ゴールとボールの色の定義
#define E 5
#define R 1
#define Y 2
#define B 3
#define S 4



//ランダム関数
typedef struct Model {
	double a[8][8];
	double b[8];
}HMM;

double Random() {
	return (double)rand()/((double)RAND_MAX+1);
}
int Ball(HMM *model, int *state){
	double rnd_ball;
	rnd_ball = Random();
	
	if(rnd_ball <= model[*state].b[R]){
		return R;
	}else if(rnd_ball <= model[*state].b[R]+model[*state].b[Y]){
		return Y;
	}else if(rnd_ball <= model[*state].b[R]+model[*state].b[Y]+model[*state].b[B]){
		return B;
	}else{
		return S;
	}
}
	//つぼの移動の設定
int Move(HMM *model, int *state){
	double rnd_move;
	rnd_move = Random();
	if(rnd_move <= model[*state].a[*state][*state]){
		return 0; //ループ
	}else{
		return 1; //次へ
	}
}
void OutPut(HMM *model, int *state, int *data, int num){
	data[num]=Ball(model, state);
	*state+=Move(model, state);
}

int main(int){
	srand((unsigned int)time(NULL));	//srandはプログラムの先頭の一回のみ．
	
	int i,tubo;
	int count;
	double ratio1;
	
	HMM model[81];
	printf("ツボの個数を指定してください\n");
	scanf("\n%d",&tubo);
	
	for(count=1;count<tubo+1;count++){
		printf("ツボ%dの赤の確率を入力してください:",count);
		scanf("%lf",&model[count].b[R]);
		printf("ツボ%dの黄の確率を入力してください:",count);
		scanf("%lf",&model[count].b[Y]);
		printf("ツボ%dの青の確率を入力してください:",count);
		scanf("%lf",&model[count].b[B]);
		ratio1 = model[count].b[R]+model[count].b[Y]+model[count].b[B];
		if(ratio1>1.0){
			printf("確率が1を超えています．");
			count=count-1;
		}else{
			model[count].b[S] = 1 - ratio1;
			printf("ツボ%dの銀の確率は%lfです．\n",count,model[count].b[S]);
			printf("次のツボへの遷移確率を入力してくいださい:");
			scanf("%lf",&model[count].a[count][count+1]);
			if(model[count].a[count][count+1]>1.0){
				printf("確率が1を超えています．入力をやり直してください．\n");
				count=count-1;
			}else{
				model[count].a[count][count] = 1 - model[count].a[count][count+1];
				printf("次のツボに移らない確率は%lfです．\n",model[count].a[count][count]);
			}
		}
	}
	
	for(i=0;i<RoundMax;i++){
		state=1;num=0;
		
		HMM model[81];
		
		out=0;
		
		printf("\n\nROUND%d\n\n",i+1);
		
		for(count=1;count<=tubo;count++){
				printf("State%d ",state);
				printf("赤%lf ％ ",model[state].b[R]*100);
				printf("黄%lf ％ ",model[state].b[Y]*100);
				printf("青%lf ％ ",model[state].b[B]*100);
				printf("銀%lf ％ ",model[state].b[S]*100);
				printf("次のつぼへの遷移確率%lf ％",model[state].a[state][state+1]*100);
				printf("\n ");
				OutPut(model,&state,data,num);
				
				if(data[num]==1)printf("赤");
				else if(data[num]==2)printf("黄");
				else if(data[num]==3)printf("青");
				else if(data[num]==4)printf("銀");
				num++;
				out++;
				printf("cehcker\n");
		}
		printf("\n");
		out = 0;
		
		/*while(state==2 && num<400){
			if(out==0){
				printf("State2 ");
				printf("赤%0.1f ％ ",R2*100);
				printf("黄%0.1f ％ ",Y2*100);
				printf("青%0.1f ％ ",B2*100);
				printf("銀%0.1f ％ ",S2*100);
				printf("次のつぼへの遷移確率%0.1f ％",a23*100);
				printf("\n ");
			}
			OutPut(model,&state,data,num);
			
			if(data[num]==1)printf("赤");
			else if(data[num]==2)printf("黄");
			else if(data[num]==3)printf("青");
			else if(data[num]==4)printf("銀");
			num++;
			out++;
		}
		printf("\n\n");
		out = 0;
		
		while(state==3 && num<500){
			if(out==0){
				printf("State3 ");
				printf("赤%0.1f ％ ",R3*100);
				printf("黄%0.1f ％ ",Y3*100);
				printf("青%0.1f ％ ",B3*100);
				printf("銀%0.1f ％ ",S3*100);
				printf("次のつぼへの遷移確率%0.1f ％",a34*100);
				printf("\n ");
			}
			OutPut(model,&state,data,num);
			if(data[num]==1)printf("赤");
			else if(data[num]==2)printf("黄");
			else if(data[num]==3)printf("青");
			else if(data[num]==4)printf("銀");
			num++;
			out++;
		}
		printf("\n\n");
		out = 0;
		
		while(state==4 && num<500){
			if(out==0){
				printf("State4 ");
				printf("赤%0.1f ％ ",R4*100);
				printf("黄%0.1f ％ ",Y4*100);
				printf("青%0.1f ％ ",B4*100);
				printf("銀%0.1f ％ ",S4*100);
				printf("次のつぼへの遷移確率%0.1f ％",a45*100);
				printf("\n ");
			}
			OutPut(model,&state,data,num);
			if(data[num]==1)printf("赤");
			else if(data[num]==2)printf("黄");
			else if(data[num]==3)printf("青");
			else if(data[num]==4)printf("銀");
			num++;
			out++;
		}
		
		printf("\n\n");
		out = 0;
		
		while(state==5 && num<600){
			if(out==0){
				printf("State5 ");
				printf("赤%0.1f ％ ",R5*100);
				printf("黄%0.1f ％ ",Y5*100);
				printf("青%0.1f ％ ",B5*100);
				printf("銀%0.1f ％ ",S5*100);
				printf("次のつぼへの遷移確率%0.1f ％",a5E*100);
				printf("\n ");
			}
			OutPut(model,&state,data,num);
			if(data[num]==1)printf("赤");
			else if(data[num]==2)printf("黄");
			else if(data[num]==3)printf("青");
			else if(data[num]==4)printf("銀");
			num++;
			out++;
		}*/
	}
	printf("\n\n");
	printf("END\n");
	return 0;
}

