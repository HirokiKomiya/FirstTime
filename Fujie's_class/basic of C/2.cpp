#include <stdio.h>

int sum(int x[], int n);/*　x[]は*xでもOK.*/

main(){
	int a[] ={1,2,3,4,5,6,7,8,9,10};
	int total;
	
	total = sum(a, 10);
	
	printf("total = %d\n",total);
}

int sum(int *x, int n){/*　配列を*x(ポインタで受けてる。)、要素数をnで受け取る*/
	int y = 0, i;
	
	for(i = 0;i < n;i++)/*　文が一本なので{}は省略。*/
	y += x[i];
	
	return y;
}
