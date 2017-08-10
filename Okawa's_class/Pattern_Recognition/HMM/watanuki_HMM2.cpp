#include <stdio.h>
#include <stdlib.h>
#include <time.h> //ランダム関数を使うため？（時間で変化する）
#include <math.h>
#include <string.h>

char Character[250];
int n, num=0, state=1, data[1024],statelog[62],out=0;
double count;

#define RoundMax 10

//ゴールとボールの色の定義
#define E 5
#define R 1
#define Y 2
#define B 3
#define S 4

/*各ツボにおけるボールの色の確率の設定*/
#define R1 0.3
#define Y1 0.2
#define B1 0.1
#define S1 0.4
//ツボ２
#define R2 0.3
#define Y2 0.1
#define B2 0.2
#define S2 0.4
//ツボ３
#define R3 0.4
#define Y3 0.6
#define B3 0.0
#define S3 0.0
//ツボ４
#define R4 0.1
#define Y4 0.2
#define B4 0.0
#define S4 0.7
//ツボ５
#define R5 0.4
#define Y5 0.3
#define B5 0.2
#define S5 0.1

/*つぼの遷移確率*/
#define a11 0.2
#define a12 0.8	//次のツボへの遷移確率1
#define a22 0.6
#define a23 0.4	//次のツボへの遷移確率2
#define a33 0.5
#define a34 0.5	//次のツボへの遷移確率3
#define a44 0.6
#define a45 0.4	//次のツボへの遷移確率4
#define a55 0.5
#define a5E 0.5	//次のツボへの遷移確率5



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
	
	int i;
	for(i=0;i<RoundMax;i++){
		state=1;num=0;
		
		HMM model[81];
		/*つぼ1*/
		model[1].b[R] = R1;
		model[1].b[Y] = Y1;
		model[1].b[B] = B1;
		model[1].b[S] = S1;
		/*つぼ2*/
		model[2].b[R] = R2;
		model[2].b[Y] = Y2;
		model[2].b[B] = B2;
		model[2].b[S] = S2;
		/*つぼ3*/
		model[3].b[R] = R3;
		model[3].b[Y] = Y3;
		model[3].b[B] = B3;
		model[3].b[S] = S3;
		
		/*つぼ4*/
		model[4].b[R] = R4;
		model[4].b[Y] = Y4;
		model[4].b[B] = B4;
		model[4].b[S] = S4;
		/*つぼ5*/
		model[5].b[R] = R5;
		model[5].b[Y] = Y5;
		model[5].b[B] = B5;
		model[5].b[S] = S5;
		
		/*つぼ1 の確率*/
		model[1].a[1][1] = a11;
		model[1].a[1][2] = a12;
		/*つぼ2 の確率*/
		model[2].a[2][2] = a22;
		model[2].a[2][3] = a23;
		
		/*つぼ3 の確率*/
		model[3].a[3][3] = a33;
		model[3].a[3][4] = a34;
		/*つぼ4 の確立*/
		model[4].a[4][4] = a44;
		model[4].a[4][5] = a45;
		/*つぼ5 の確立*/
		model[5].a[5][5] = a55;
		model[5].a[5][E] = a5E;
		
		out=0;
		
		
		printf("\n\nROUND%d\n\n",i+1);
		
		while(state==1 && num<300){ //結果を出力
			if(out==0){
				printf("State1 ");
				printf("赤%0.1f ％ ",R1*100);
				printf("黄%0.1f ％ ",Y1*100);
				printf("青%0.1f ％ ",B1*100);
				printf("銀%0.1f ％ ",S1*100);
				printf("次のつぼへの遷移確率%0.1f ％",a12*100);
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
		
		while(state==2 && num<400){
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
		}
	}
	printf("\n\n");
	printf("END\n");
	return 0;
}

