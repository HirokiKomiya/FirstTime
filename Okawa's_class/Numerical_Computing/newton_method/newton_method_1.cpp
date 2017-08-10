#include <stdio.h>
#include<math.h>

/*
void main(void){
}
*/

/*
main(){
}*/

//�萔��define��
#define EPS 0.000001	//very small value

//�ő�J��Ԃ���
#define NMAX 100	//max number of iteration

#define PI 3.141592

double f(double x){		//�v���g�^�C�v�錾���K�v�Ȃ�
	return(x/2 + cos(x*PI/180));	//���
}

//���֐�	�����ł�����̂͂��̂܂ܓ���Ă��܂���
double df(double x){
	return(1/2 - sin(x*PI/180));	//���
}


void newton(double x){
	int n = 0;
	int count = 0;	//�J�E���^�[
	double delta;
	double result;
	char Name[]="newton_data_x.txt";
	int mode=0;
	
	FILE *fp;
	fp = fopen(Name,"w");
	fclose(fp);
	do{
		delta = -f(x) /df(x);
		x += delta;
		count++;	//�C���N�������g���Z�q�@n=n+1�Ɠ����Ӗ�
		printf("round:%d,x:%f\n",count,x);
		fp = fopen(Name,"a");
		result = fprintf(fp,"round:%d,x:%f\n",count,x);
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
