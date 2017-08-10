/*****���̃v���O�����Ɏ�������Ă������*****/
//
//�ߎ����A�e�ߎ����̐ڐ��A�ڐ���y�ؕЂ̌v�Z
//��L�f�[�^�̃e�L�X�g�t�@�C���ւ̕ۑ�
//�e���̉���y�ؕЂ𓯎��ɋ��߂�
//3�_�ߎ��ɂ�铱�֐��̎Z�o
//�^����֐��̃}�N�����i���֐��̎Z�o�ɗp����
//
/********************************************/

#include <stdio.h>
#include <math.h>
#include <float.h>	//FLT_EPSILON�̂��߂ɌĂяo��

//�萔��define��
#define EPS 0.000001	//very small value

//�ő�J��Ԃ���
#define NMAX 100		//max number of iteration

//�~����
#define PI 3.141592

//�^���鎮(func)�Ɠ��֐�(deri)���}�N���֐��Ƃ��Ē�`
#define func(x) (x*x - 4)	//�����Ɍ^�͂���Ȃ�

//�֐�


//���֐�	�R�_�ߎ��B�O��̓_�ŋ���
double df(double x){
	//�����ʂ̒�`
	double dx = FLT_EPSILON;
	double dy,dfx;
	
	dy = func(x+dx)-func(x-dx);	//�O��̍����Ƃ�
	dfx = dy/(dx*2);
	//printf("dx=%f ",dx);
	return(dfx);	//���
}

//�e���̉���y�ؕЂ����߂�֐�
double fb(double x,double df1){
	return(-x*df1);
}

//Newton-Raphson Method �֐���`
void newton(double x){
	int count = 0;	//�J�E���^�[
	double b = 0;	//y����
	double delta;	//�ߎ����̍���
	double result;
	double df1;
	char Name[]="newton_data_x.txt";	//�ߎ���
	char Namea[]="newton_data_a.txt";	//�ڐ��̌X��������
	char Nameb[]="newton_data_b.txt";	//�ڐ���y�ؕ�
	int mode=0;	//�������܂�Ȃ������ꍇ�̃��[�h�U�蕪��
	
	FILE *fp;
	fp = fopen(Name,"w");
	fp = fopen(Namea,"w");
	fp = fopen(Nameb,"w");
	fclose(fp);
	
	fp = fopen(Name ,"a");
	result = fprintf(fp,"%f\n",x);
	fclose(fp);
	
	printf("round:%3d,x:%13f\n",count,x);
	do{
		df1 = df(x);	//�X��
		delta = -func(x) /df1;	//�����̌v�Z
		x += delta;		//���̍X�V
		b = fb(x,df1);	//
		
		count++;	//�C���N�������g���Z�q�@n=n+1�Ɠ����Ӗ�
		printf("round:%d,x:%f\n",count,x);
		
		/*�e�f�[�^�̕ۑ�*/
		fp = fopen(Name,"a");
		result = fprintf(fp,"round:%d,x:%f\n",count,x);
		fclose(fp);
		
		fp = fopen(Namea,"a");
		result = fprintf(fp,"%f\n",df1);	//�ڐ��̌X��
		fclose(fp);
		
		fp = fopen(Nameb,"a");
		result = fprintf(fp,"%f\n",b);		//�ڐ��y�ؕ�
		fclose(fp);
		/*�f�[�^�̕ۑ������܂�*/
		
		if(fabs(x)>10000000000000000){		//�����ӂ�ɂ��G���[��h��
			mode = 1;
			break;
		}
	}while(fabs(delta) > EPS && count< NMAX);
	//�����\���������Ȃ邩���s����񐔂ɒB������I��
	
	if(mode){
		printf("����������܂���ł����B(Overflow)\n");
	}else{
		if(count==NMAX){
			printf("����������܂���ł����B\n");
		}else{
			printf("\n����������܂���\n");
			printf("x = %f\n",x);	//stderr�̓t�@�C���ɓ���Ȃ�
		}
	}
}

int main(){
	double x;
	printf("input initial value->");
	scanf("%lf",&x);
	newton(x);	/*newton method*/
	return 0;
}


//return 0;	���G���[�Ȃ��I���������Ƃ�OS�Ɏ���


/***************���ӓ_�A���P�_�A���̌�̕��j��******************/
//
//�����ׂ��������͊֐��Ƃ����`�Ŗ��ߍ���ł��܂�
//�����l�̂݊O������ő��͂��ׂĖ��ߍ���
//�������߂�ǂ������ꍇ�͂ǂ�����H	�E�E�E3�_�ߎ��̎����ς�
//���낢��Ȕ���^�֐��Ŏ���
//	���������������
//	�������܂�Ȃ�����
//
/***************************************************************/

