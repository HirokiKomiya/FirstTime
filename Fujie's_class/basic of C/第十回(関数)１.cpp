#include <stdio.h>
#include <math.h>

int pytha(int a, int b);/*　関数宣言。関数名は「add_i」*/

main(){
	int x = 10, y = 20, z;
	
	z = pytha(x, y);/*　関数の呼び出し*/
	
	printf("%d + %d = %d\n", x, y, z);
}

/*　ここから先が関数定義(実際の処理の内容はこっち。)*/

int pytha(int a, int b){
	int x,y;
	
	x = a^2 + b^2;
	
	y = sqrt(x);
	return y;/*値を返す*/
}
/*違う関数内で宣言された変数は互いに影響を与えない→スコープの話へ。*/

/*グローバル変数は使用禁止。(そもそも使わないほうがいい)*/