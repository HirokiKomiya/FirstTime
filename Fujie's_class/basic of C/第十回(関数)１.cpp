#include <stdio.h>
#include <math.h>

int pytha(int a, int b);/*�@�֐��錾�B�֐����́uadd_i�v*/

main(){
	int x = 10, y = 20, z;
	
	z = pytha(x, y);/*�@�֐��̌Ăяo��*/
	
	printf("%d + %d = %d\n", x, y, z);
}

/*�@��������悪�֐���`(���ۂ̏����̓��e�͂������B)*/

int pytha(int a, int b){
	int x,y;
	
	x = a^2 + b^2;
	
	y = sqrt(x);
	return y;/*�l��Ԃ�*/
}
/*�Ⴄ�֐����Ő錾���ꂽ�ϐ��݂͌��ɉe����^���Ȃ����X�R�[�v�̘b�ցB*/

/*�O���[�o���ϐ��͎g�p�֎~�B(���������g��Ȃ��ق�������)*/