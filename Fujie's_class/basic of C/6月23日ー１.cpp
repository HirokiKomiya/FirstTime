#include <stdio.h>

int add_i(int a, int b);/*�@�֐��錾�B�֐����́uadd_i�v*/

main(){
	int x = 10, y = 20, z;
	
	z = add_i(x, y);/�@*�֐��̌Ăяo��*/
	
	printf("%d + %d = %d\n", x, y, z);
}

/*�@��������悪�֐���`(���ۂ̏����̓��e�͂������B)*/

int add_i(int a, int b){
	int c;
	
	c = a + b;
	
	return c;
	
}