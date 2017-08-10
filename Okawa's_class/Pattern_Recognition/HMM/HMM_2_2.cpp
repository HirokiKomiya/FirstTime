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

//�����_���֐�
double Random() {
	return (double)rand()/((double)RAND_MAX+1);
}

//�c�{����o�Ă���{�[���̐F�𐔎��ɂ��ĕԂ��֐�
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

//�J�ڊm�����玟�̃c�{�Ɉڂ邩�̔���
int Move(HMM *model, int *state){
	double rnd_move;
	rnd_move = Random();
	if(rnd_move <= model[*state].a[*state][*state]){
		return 0; //�����ڂ�
	}else{
		return 1; //���̂ڂ�
	}
}

//��L�̓�̊֐��̌��ʂ��܂Ƃ߂ă��C���ɕԂ��֐�
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
	int RoundMax=0;	//�����͏��������Ȃ����exit�ɓ���Ȃ��׏�����
	
	
	printf("\n���s�񐔂���͂��Ă�������\n");
	scanf("\n%d",&RoundMax);
	if(RoundMax<=0){
		printf("���͂��s���ł��D\n");
		exit(1);
	}
	
	printf("�c�{�̌����w�肵�Ă�������\n");
	scanf("\n%d",&tubo);
	if(tubo<=0){
		printf("���͂��s���ł��D\n");
		exit(1);
	}
	
	for(count=1;count<tubo+1;count++){
		printf("�c�{%d�́Z�̊m������͂��Ă�������:",count);
		scanf("%lf",&R[count]);
		if(R[count]<0){
			printf("���͂��s���ł��D\n");
			exit(1);
		}
		printf("�c�{%d�́��̊m������͂��Ă�������:",count);
		scanf("%lf",&Y[count]);
		if(Y[count]<0){
			printf("���͂��s���ł��D\n");
			exit(1);
		}
		printf("�c�{%d�́��̊m������͂��Ă�������:",count);
		scanf("%lf",&B[count]);
		if(B[count]<0){
			printf("���͂��s���ł��D\n");
			exit(1);
		}
		ratio1 = R[count]+Y[count]+B[count];
		if(ratio1>1.0){
			printf("�m����1�𒴂��Ă��܂��D���͂���蒼���Ă��������D\n");
			count=count-1;
		}else{
			S[count] = 1 - ratio1;
			printf("�c�{%d�́��̊m����%.3lf�ł��D\n",count,S[count]);
			printf("���̃c�{�ւ̑J�ڊm������͂��Ă���������:");
			scanf("%lf",&a[count][count+1]);
			if(a[count][count+1]>1.0 | a[count][count+1]<=0){
				printf("�m����1�𒴂��Ă��邩�C0�ȉ��ł��D���͂���蒼���Ă��������D\n");
				count=count-1;
			}else{
				a[count][count] = 1 - a[count][count+1];
				printf("���̃c�{�Ɉڂ�Ȃ��m����%lf�ł��D\n",a[count][count]);
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
			printf("�Z%0.1f �� ",R[count]*100);
			printf("��%0.1f �� ",Y[count]*100);
			printf("��%0.1f �� ",B[count]*100);
			printf("��%0.1f �� ",S[count]*100);
			printf("���̂ڂւ̑J�ڊm��%0.1f ��",a[count][count+1]*100);
			printf("\n ");
			
			state=count;
			int d;
			while(1){ //���ʂ��o��
				d=state;
				OutPut(model,&state,data,num);
				
				if(data[num]==1)printf("�Z");
				else if(data[num]==2)printf("��");
				else if(data[num]==3)printf("��");
				else if(data[num]==4)printf("��");
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

