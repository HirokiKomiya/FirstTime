#include <stdio.h>
#include <math.h>

double pytha(double x,double y);/*�@�֐��錾�B�֐����́upytha�v*/

main(){
	double x = 5, y = 4, z;
	
	z = pytha(x, y);/*�@�֐��̌Ăяo��*/
	
	printf("\n���p�O�p�`�ŎΕӂ�%f�A��ӂ�%f�̎��A������%f�ł��B\n\n", x, y, z);
}

/*�@��������悪�֐���`*/

double pytha(double a, double b){
	double x,y;
	
	x = sqrt(a*a - b*b);
	
	return x;/*�l��Ԃ�*/
}