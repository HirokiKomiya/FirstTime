//2�_�Őڐ��\��

#include <stdio.h>
#include<math.h>

//�萔��define��
#define EPS 0.000001	//very small value

//�ő�J��Ԃ���
#define NMAX 100		//max number of iteration

#define PI 3.141592

double f(double x){		//�v���g�^�C�v�錾���K�v�Ȃ�
	return(x*x - 4);	//���
}

//���֐�	�����ł�����̂͂��̂܂ܓ���Ă��܂���
double df(double x){
	return(2*x);	//���
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
	double f1;
	char Name[]="newton_data_x.txt";
	char Namey[]="newton_data_y.txt";
	char Name1[]="newton_data_x1.txt";
	char Name2[]="newton_data_x(No_count).txt";
	
	int mode=0;
	
	FILE *fp;
	fp = fopen(Name,"w");
	fp = fopen(Namey,"w");
	fp = fopen(Name1,"w");
	fp = fopen(Name2,"w");
	fclose(fp);
	
	fp = fopen(Name,"a");
	result = fprintf(fp,"round:%d,x:%f\n",count,x);
	fclose(fp);
	fp = fopen(Name2,"a");
	result = fprintf(fp,"%f\n",x);
	fclose(fp);
	
	do{
		delta = -f(x) /df(x);
		f1=f(x);
		x += delta;
		
		count++;	//�C���N�������g���Z�q�@n=n+1�Ɠ����Ӗ�
		printf("round:%d,x:%f\n",count,x);
		
		fp = fopen(Name,"a");
		result = fprintf(fp,"round:%d,x:%f\n",count,x);
		fclose(fp);
		
		fp = fopen(Name2,"a");
		result = fprintf(fp,"%f\n",x);
		fclose(fp);
		
		fp = fopen(Namey,"a");
		result = fprintf(fp,"%f\n",f1);	//�ڐ��̌X��
		fclose(fp);
		
		fp = fopen(Name1,"a");
		result = fprintf(fp,"%f\n",x);
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

//return 0;	���G���[�Ȃ��I���������Ƃ�����

/************************************************/
//�����ׂ��������͊֐��Ƃ����`�Ŗ��ߍ���ł��܂�
//�����l�̂݊O������ő��͂��ׂĖ��ߍ���
//���낢��Ȕ���^�֐��Ŏ���
//	���������������
//	�������܂�Ȃ�����
/*************************************************/
