#include <stdio.h>
#include <math.h>

double pytha(double x,double y);/*　関数宣言。関数名は「pytha」*/

main(){
	double x = 5, y = 4, z;
	
	z = pytha(x, y);/*　関数の呼び出し*/
	
	printf("\n直角三角形で斜辺が%f、底辺が%fの時、高さは%fです。\n\n", x, y, z);
}

/*　ここから先が関数定義*/

double pytha(double a, double b){
	double x,y;
	
	x = sqrt(a*a - b*b);
	
	return x;/*値を返す*/
}