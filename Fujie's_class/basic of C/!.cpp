#include<stdio.h>
/*65535までしかできない*/
main()
{
	int a=0,i,n;
	printf("階乗を計算します。いくつの階乗を計算しますか？\n");
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		a = a+i;
		printf("%dです\n",a);
	}
	i=i-1;
	printf("%d!は%dです\n",i,a);
}


while(a!='='){
}
