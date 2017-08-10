#include<stdio.h>

main()
{
	double a=1,i,n;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a = a*i;
		printf("%lf\n",a);
	}

}