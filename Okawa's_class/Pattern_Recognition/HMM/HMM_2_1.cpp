#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define Keiro "Keiro_data"

char Character[250];
int n, num=0, state=1, data[1024],statelog[62],out=0;
double count;

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
	
	char buf[256];
	int n;
	
	double R[100]={0};
	double Y[100]={0};
	double B[100]={0};
	double S[100]={0};
	double a[100][100];
	int tubo=0;
	
	char filename[60];
	
	FILE *file;
	sprintf(filename,"%s.txt",Keiro);
	file = fopen(filename,"w");
	fclose(file);
	
	
	printf("\n�p�^�[���̌�����͂��Ă�������\n");
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
	
	
	
	for(i=0;i<RoundMax;i++){
		for(count=1;count<tubo+1;count++){
		printf("�c�{%d�̐Ԃ̊m������͂��Ă�������:",count);
		scanf("%lf",&R[count]);
		if(R[count]<0){
			printf("���͂��s���ł��D\n");
			exit(1);
		}
		fprintf(file,"%lf ",R[count]);
		
		printf("�c�{%d�̉��̊m������͂��Ă�������:",count);
		scanf("%lf",&Y[count]);
		if(Y[count]<0){
			printf("���͂��s���ł��D\n");
			exit(1);
		}
		fprintf(file,"%lf ",Y[count]);
		
		printf("�c�{%d�̐̊m������͂��Ă�������:",count);
		scanf("%lf",&B[count]);
		if(B[count]<0){
			printf("���͂��s���ł��D\n");
			exit(1);
		}
		fprintf(file,"%lf ",B[count]);
		
		ratio1 = R[count]+Y[count]+B[count];
		if(ratio1>1.0){
			printf("�m����1�𒴂��Ă��܂��D���͂���蒼���Ă��������D\n");
			count=count-1;
		}else{
			S[count] = 1 - ratio1;
			printf("�c�{%d�̋�̊m����%.3lf�ł��D\n",count,S[count]);
			fprintf(file,"%lf ",S[count]);
			
			printf("���̃c�{�ւ̑J�ڊm������͂��Ă���������:");
			scanf("%lf",&a[count][count+1]);
			if(a[count][count+1]>1.0 | a[count][count+1]<=0){
				printf("�m����1�𒴂��Ă��邩�C0�ȉ��ł��D���͂���蒼���Ă��������D\n");
				count=count-1;
			}else{
				a[count][count] = 1 - a[count][count+1];
				printf("���̃c�{�Ɉڂ�Ȃ��m����%.3lf�ł��D\n",a[count][count]);
				fprintf(file,"%lf\n",a[count][count]);
			}
		}
	}
	
	printf("\n");
	
	
	printf("\n\n");
	printf("END\n");
	return 0;
}

