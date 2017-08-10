#include <stdio.h>
#include <stdlib.h>
#include <time.h> //�����_���֐����g�����߁H�i���Ԃŕω�����j
#include <math.h>
#include <string.h>

char Character[250];
int n, num=0, state=1, data[1024],statelog[62],out=0;
double count;

#define RoundMax 4

//�S�[���ƃ{�[���̐F�̒�`
#define E 5
#define R 1
#define Y 2
#define B 3
#define S 4



//�����_���֐�
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
	//�ڂ̈ړ��̐ݒ�
int Move(HMM *model, int *state){
	double rnd_move;
	rnd_move = Random();
	if(rnd_move <= model[*state].a[*state][*state]){
		return 0; //���[�v
	}else{
		return 1; //����
	}
}
void OutPut(HMM *model, int *state, int *data, int num){
	data[num]=Ball(model, state);
	*state+=Move(model, state);
}

int main(int){
	srand((unsigned int)time(NULL));	//srand�̓v���O�����̐擪�̈��̂݁D
	
	int i,tubo;
	int count;
	double ratio1;
	
	HMM model[81];
	printf("�c�{�̌����w�肵�Ă�������\n");
	scanf("\n%d",&tubo);
	
	for(count=1;count<tubo+1;count++){
		printf("�c�{%d�̐Ԃ̊m������͂��Ă�������:",count);
		scanf("%lf",&model[count].b[R]);
		printf("�c�{%d�̉��̊m������͂��Ă�������:",count);
		scanf("%lf",&model[count].b[Y]);
		printf("�c�{%d�̐̊m������͂��Ă�������:",count);
		scanf("%lf",&model[count].b[B]);
		ratio1 = model[count].b[R]+model[count].b[Y]+model[count].b[B];
		if(ratio1>1.0){
			printf("�m����1�𒴂��Ă��܂��D");
			count=count-1;
		}else{
			model[count].b[S] = 1 - ratio1;
			printf("�c�{%d�̋�̊m����%lf�ł��D\n",count,model[count].b[S]);
			printf("���̃c�{�ւ̑J�ڊm������͂��Ă���������:");
			scanf("%lf",&model[count].a[count][count+1]);
			if(model[count].a[count][count+1]>1.0){
				printf("�m����1�𒴂��Ă��܂��D���͂���蒼���Ă��������D\n");
				count=count-1;
			}else{
				model[count].a[count][count] = 1 - model[count].a[count][count+1];
				printf("���̃c�{�Ɉڂ�Ȃ��m����%lf�ł��D\n",model[count].a[count][count]);
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
				printf("��%lf �� ",model[state].b[R]*100);
				printf("��%lf �� ",model[state].b[Y]*100);
				printf("��%lf �� ",model[state].b[B]*100);
				printf("��%lf �� ",model[state].b[S]*100);
				printf("���̂ڂւ̑J�ڊm��%lf ��",model[state].a[state][state+1]*100);
				printf("\n ");
				OutPut(model,&state,data,num);
				
				if(data[num]==1)printf("��");
				else if(data[num]==2)printf("��");
				else if(data[num]==3)printf("��");
				else if(data[num]==4)printf("��");
				num++;
				out++;
				printf("cehcker\n");
		}
		printf("\n");
		out = 0;
		
		/*while(state==2 && num<400){
			if(out==0){
				printf("State2 ");
				printf("��%0.1f �� ",R2*100);
				printf("��%0.1f �� ",Y2*100);
				printf("��%0.1f �� ",B2*100);
				printf("��%0.1f �� ",S2*100);
				printf("���̂ڂւ̑J�ڊm��%0.1f ��",a23*100);
				printf("\n ");
			}
			OutPut(model,&state,data,num);
			
			if(data[num]==1)printf("��");
			else if(data[num]==2)printf("��");
			else if(data[num]==3)printf("��");
			else if(data[num]==4)printf("��");
			num++;
			out++;
		}
		printf("\n\n");
		out = 0;
		
		while(state==3 && num<500){
			if(out==0){
				printf("State3 ");
				printf("��%0.1f �� ",R3*100);
				printf("��%0.1f �� ",Y3*100);
				printf("��%0.1f �� ",B3*100);
				printf("��%0.1f �� ",S3*100);
				printf("���̂ڂւ̑J�ڊm��%0.1f ��",a34*100);
				printf("\n ");
			}
			OutPut(model,&state,data,num);
			if(data[num]==1)printf("��");
			else if(data[num]==2)printf("��");
			else if(data[num]==3)printf("��");
			else if(data[num]==4)printf("��");
			num++;
			out++;
		}
		printf("\n\n");
		out = 0;
		
		while(state==4 && num<500){
			if(out==0){
				printf("State4 ");
				printf("��%0.1f �� ",R4*100);
				printf("��%0.1f �� ",Y4*100);
				printf("��%0.1f �� ",B4*100);
				printf("��%0.1f �� ",S4*100);
				printf("���̂ڂւ̑J�ڊm��%0.1f ��",a45*100);
				printf("\n ");
			}
			OutPut(model,&state,data,num);
			if(data[num]==1)printf("��");
			else if(data[num]==2)printf("��");
			else if(data[num]==3)printf("��");
			else if(data[num]==4)printf("��");
			num++;
			out++;
		}
		
		printf("\n\n");
		out = 0;
		
		while(state==5 && num<600){
			if(out==0){
				printf("State5 ");
				printf("��%0.1f �� ",R5*100);
				printf("��%0.1f �� ",Y5*100);
				printf("��%0.1f �� ",B5*100);
				printf("��%0.1f �� ",S5*100);
				printf("���̂ڂւ̑J�ڊm��%0.1f ��",a5E*100);
				printf("\n ");
			}
			OutPut(model,&state,data,num);
			if(data[num]==1)printf("��");
			else if(data[num]==2)printf("��");
			else if(data[num]==3)printf("��");
			else if(data[num]==4)printf("��");
			num++;
			out++;
		}*/
	}
	printf("\n\n");
	printf("END\n");
	return 0;
}

