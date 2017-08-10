//�e���̉���y�ؕЂ𓯎��ɋ��߂�
//�^����֐��̃}�N����

#include <stdio.h>
#include<math.h>

//�萔��define��
#define EPS 0.000001	//very small value

//�ő�J��Ԃ���
#define NMAX 100	//max number of iteration

#define PI 3.141592

//�^���鎮���}�N���֐��Ƃ��Ē�`
#define func(x) (x*x - 1)	//�����Ɍ^�͂���Ȃ�
#define deri(x) (2*x)


double f(double x){		//�v���g�^�C�v�錾���K�v�Ȃ�
	return(func(x));	//���
}

//���֐�	�����ł�����̂͂��̂܂ܓ���Ă��܂���
double df(double x){
	return(deri(x));	//���
}

//�e���̉���y�ؕЂ����߂�֐�
double fb(double x,double df1){
	return(-x*df1);
}


void newton(double x){
	int n = 0;
	int count = 0;	//�J�E���^�[
	double b=0;
	double delta;
	double result;
	double df1;
	char Name[]="newton_data_x.txt";
	char Namea[]="newton_data_a.txt";
	char Nameb[]="newton_data_b.txt";
	int mode=0;
	
	FILE *fp;
	fp = fopen(Name,"w");
	fp = fopen(Namea,"w");
	fp = fopen(Nameb,"w");
	fclose(fp);
	do{
		delta = -f(x) /df(x);
		x += delta;
		df1=df(x);
		b = fb(x,df1);
		
		count++;	//�C���N�������g���Z�q�@n=n+1�Ɠ����Ӗ�
		printf("round:%d,x:%f\n",count,x);
		fp = fopen(Name,"a");
		result = fprintf(fp,"round:%d,x:%f\n",count,x);
		fclose(fp);
		
		fp = fopen(Namea,"a");
		result = fprintf(fp,"%f\n",df1);	//�ڐ��̌X��
		fclose(fp);
		
		fp = fopen(Nameb,"a");
		result = fprintf(fp,"%f\n",b);	//�ڐ��y�ؕ�
		fclose(fp);
		
		//���g���m�F����printf������
		if(fabs(x)>10000000000000000){	//�����ӂ�ɂ��G���[��h��
			mode = 1;
			break;
		}
	}while(fabs(delta) > EPS && count< NMAX);
	
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
//�v���O������OS��

//return 0;	���G���[�Ȃ��I���������Ƃ�����

/************************************************/
//�����ׂ��������͊֐��Ƃ����`�Ŗ��ߍ���ł��܂�
//�����l�̂݊O������ő��͂��ׂĖ��ߍ���
//���낢��Ȕ���^�֐��Ŏ���
//	���������������
//	�������܂�Ȃ�����
/*************************************************/
