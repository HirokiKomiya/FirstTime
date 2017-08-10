/*****���̃v���O�����Ɏ�������Ă������*****/
//
//�ߎ����A�e�ߎ����̐ڐ��A�ڐ���y�ؕЂ̌v�Z
//��L�f�[�^�̃e�L�X�g�t�@�C���ւ̕ۑ�
//�e���̉���y�ؕЂ𓯎��ɋ��߂�
//�T�_�ߎ��ɂ�铱�֐��̎Z�o
//dfx=0�̏ꍇ��0����h�~�����{
//
/********************************************/

/*(x-1)*(x-2)*(x-3)��x*x*x-6*x*x+11*x-6�`�ƋL�ڂ���Ƃ��������Ȃ�*/

//�^���鎮(func)���}�N���֐��Ƃ��Ē�`
#define func(x) ((x-1)*(x+1))	//�����֐��������ɓ���

#include <stdio.h>
#include <math.h>
#include <float.h>	//FLT_EPSILON�̂��߂ɌĂяo��

#define EPS 0.000001	//very small value
#define NMAX 100		//max number of iteration
#define PI 3.141592		//��
#define dfMAX 10


//���֐�
double df(double x){
	double dy,dfx;
	double dx = FLT_EPSILON;
	dy  = -func(x+2*dx)+8*func(x+dx)-8*func(x-dx)+func(x-2*dx);	//�O��̍����Ƃ�
	dfx = dy/(dx*12);
	
	printf("dy=%f dfx=%f\n",dy,dfx);	//�`�F�b�N�p
	
	if(dfx!=0){
	return(dfx);
	/*��0���h�~��*/
	}else{
		x=x+0.1;
		printf("(����)�l��%f�ɕύX���܂����B\n",x);
		dy  = -func(x+2*dx)+8*func(x+dx)-8*func(x-dx)+func(x-2*dx);	//�O��̍����Ƃ�
		dfx = dy/(dx*2);
		return(dfx);
	}
}


double df_count(void){
	double a;
	int count  = 0 ;
	int count1 = 0;
	double df1;
	double df2[100];
	
	for(a=-dfMAX;a<dfMAX;){
		//printf("%f",a);		�`�F�b�N�p
		df1 = df(a);
		if(df1==0){
			df2[count] = df1;
			count = count+1;
		}
		a=a+0.1;
	}
	printf("�ϋȓ_��%d�ł��B\n",count);
	for(count1=0;count1<count;count1++){
		printf("%10.7f\n",df2[count1]);
	}
}


//�e���̉���y�ؕЂ����߂�֐�
double fb(double x,double df1){
	return(-x*df1);
}

//Newton-Raphson Method �֐���`
void newton(double x){
	int count = 0;	//�J�E���^�[
	char Name [] ="newton_data_x.txt";	//�ߎ���
	char Namea[]="newton_data_a.txt";	//�ڐ��̌X��������
	char Nameb[]="newton_data_b.txt";	//�ڐ���y�ؕ�
	double df1;
	double b = 0;	//y����
	double delta;	//�ߎ����̍���
	double result;
	
	FILE *fp;
	
	fp = fopen(Name ,"w");
	fp = fopen(Namea,"w");
	fp = fopen(Nameb,"w");
	fclose(fp);
	
	fp = fopen(Name ,"a");
	result = fprintf(fp,"%f\n",x);
	fclose(fp);
	
	printf("round:%3d,x:%13f\n",count,x);
	do{
		df1   = df(x);	//�X��
		delta = -func(x) /df1;		//�����̌v�Z
		
		//printf("%f ",df1);	//�`�F�b�N�p
		
		x += delta;		//���̍X�V
		b  = fb(x,df1);
		count++;
		
		printf("round:%3d,x:%13f\n",count,x);
		
		/*�e�f�[�^�̕ۑ�*/
		fp = fopen(Name ,"a");
		result = fprintf(fp,"%f\n",x);	//�ߎ���
		fclose(fp);
		
		fp = fopen(Namea,"a");
		result = fprintf(fp,"%f\n",df1);//�ڐ��̌X��
		fclose(fp);
		
		fp = fopen(Nameb,"a");
		result = fprintf(fp,"%f\n",b);	//�ڐ��y�ؕ�
		fclose(fp);
		/*�f�[�^�̕ۑ������܂�*/
		
		//�����ӂ�ɂ��G���[��h��
		if(fabs(x)<-10000000000000000 | fabs(x)>10000000000000000){
			printf("����������܂���ł����B(Overflow)\n");
			break;
		}
	}while(fabs(delta) > EPS && count< NMAX);
	
	
	/*�ŏI���ʂ̏o�͕���*/
	if(count==NMAX){
		printf("����������܂���ł����B\n");
	}else{
		printf("\n����������܂���\n");
		printf("x = %f\n",x);
	}
	/*�o�͂����܂�*/
}

int main(){
	double x;
	printf("input initial value->");
	//scanf("%lf",&x);
	df_count();
	//newton(x);	/*newton method*/
	return 0;
}

/***************���ӓ_�A���P�_�A���̌�̕��j��******************/
//
//�����ׂ��������͊֐��Ƃ����`�Ŗ��ߍ���ł��܂�
//�����l�̂݊O������ő��͂��ׂĖ��ߍ���
//�������߂�ǂ������ꍇ�͂ǂ�����H	�E�E�E�T�_�ߎ��̎����ς�
//���낢��Ȕ���^�֐��Ŏ���
//	���������������
//	�������܂�Ȃ�����
//
/***************************************************************/

