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


double f(double x){		//�v���g�^�C�v�錾���K�v�Ȃ�
	return(x + cos(x));	//���
}

//���֐�	�����ł�����̂͂��̂܂ܓ���Ă��܂���
double df(double x){
	return(1 - sin(x));	//���
}



void newton(double x){
	int n = 0;
	int count = 0;	//�J�E���^�[
	double delta;
	char name[]="newton_data_x.txt";
	int mode=0;
	
	do{
		delta = -f(x) /df(x);
		x += delta;
		count++;	//�C���N�������g���Z�q�@n=n+1�Ɠ����Ӗ�
		
		printf("round:%d,x:%f\n",count,x);
		
		//���g���m�F����printf������
		if(fabs(x)>10000000000000000){	//�����ӂ�ɂ��G���[��h��
			mode = 1;
			break;
		}
		
	}while(fabs(delta) > EPS && count< NMAX);
	
	
	if(count==NMAX | mode){
		printf("����������܂���ł����B");
		
	}else{
		printf("\n����������܂���\n");
		printf("x = %f\n",x);	//stderr�̓t�@�C���ɓ���Ȃ�
	}
}

int main(){
	double x;
	
	printf("input initial value->");
	scanf("%lf",&x);
	
	newton(x);	/*newton method*/
	
	return 0;
}
//�v���O������OS��main�̒��g�ɕԂ�

//return 0;	���G���[�Ȃ��I���������Ƃ�����


//�����ׂ��������͊֐��Ƃ����`�Ŗ��ߍ���ł��܂�
//�����l�̂݊O������ő��͂��ׂĖ��ߍ���
