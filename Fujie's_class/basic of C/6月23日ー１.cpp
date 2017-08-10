#include <stdio.h>

int add_i(int a, int b);/*　関数宣言。関数名は「add_i」*/

main(){
	int x = 10, y = 20, z;
	
	z = add_i(x, y);/　*関数の呼び出し*/
	
	printf("%d + %d = %d\n", x, y, z);
}

/*　ここから先が関数定義(実際の処理の内容はこっち。)*/

int add_i(int a, int b){
	int c;
	
	c = a + b;
	
	return c;
	
}