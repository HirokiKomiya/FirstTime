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
#define func(x) ((x-1)*(x+1)*(x+2))	//�����֐��������ɓ���

#include <stdio.h>
#include <math.h>
#include <float.h>	//FLT_EPSILON�̂��߂ɌĂяo��

#define EPS 0.1	//very small value
#define EPS2 0.001
#define NMAX 100		//max number of iteration
#define PI 3.141592		//��
#define dfMAX 10


//���֐�
double df(double x){
	double dy,dfx;
	double dx = FLT_EPSILON;
	dy = func(x+dx)-func(x-dx);	//�O��̍����Ƃ�
	dfx = dy/(dx*2);
	
	//printf("dy=%f dfx=%f\n",dy,dfx);	//�`�F�b�N�p
	
	return(dfx);
}


double df_count(void){
	double a;
	int count  = 0 ;
	int count1 = 0;
	int count2 = 0;
	double df1;
	double df2[100];
	
	for(a=-dfMAX;a<dfMAX;count2++){
		//printf("%f",a);		�`�F�b�N�p
		df1 = df(a);
		if(df1<0.1&&df1>-0.1){
			df2[count] = df1;
			count = count+1;
		}
		a=a+0.00001;
	}
	printf("�v�Z�񐔂�%d�ł�\n",count2);
	printf("�ϋȓ_��%d�ł��B\n",count);
	for(count1=0;count1<count;count1++){
		printf("%.2f\n",df2[count1]);
	}
}


int main(){
	double x;
	//printf("input initial value->");
	//scanf("%lf",&x);
	df_count();
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

