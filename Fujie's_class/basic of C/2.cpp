#include <stdio.h>

int sum(int x[], int n);/*�@x[]��*x�ł�OK.*/

main(){
	int a[] ={1,2,3,4,5,6,7,8,9,10};
	int total;
	
	total = sum(a, 10);
	
	printf("total = %d\n",total);
}

int sum(int *x, int n){/*�@�z���*x(�|�C���^�Ŏ󂯂Ă�B)�A�v�f����n�Ŏ󂯎��*/
	int y = 0, i;
	
	for(i = 0;i < n;i++)/*�@������{�Ȃ̂�{}�͏ȗ��B*/
	y += x[i];
	
	return y;
}
