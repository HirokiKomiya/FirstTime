#include <stdio.h>
#include <math.h>

int pytha(double x,double y);/*�@�֐��錾�B�֐����́uadd_i�v*/

main(){
	int x = 3, y = 4, z;
	
	z = pytha(x, y);/*�@�֐��̌Ăяo��*/
	
	printf("��ӂ�%d�A������%d�̎��A�Εӂ�%d\n", x, y, z);
}

/*�@��������悪�֐���`(���ۂ̏����̓��e�͂������B)*/

int pytha(double a, double b){
	double x,y;
	
	x = a*a + b*b;
	
	y = sqrt(x);
	return y;/*�l��Ԃ�*/
}
/*�Ⴄ�֐����Ő錾���ꂽ�ϐ��݂͌��ɉe����^���Ȃ����X�R�[�v�̘b�ցB*/

/*�O���[�o���ϐ��͎g�p�֎~�B(���������g��Ȃ��ق�������)*/