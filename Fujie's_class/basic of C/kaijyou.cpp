#include<stdio.h>
/*12までしかできない*/
main()
{
	int a=1,i,n;
	printf("階乗を計算します。\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a = a*i;
	}
	i = i-1;
	printf("%dの階乗は%ld\n",i,a);
}