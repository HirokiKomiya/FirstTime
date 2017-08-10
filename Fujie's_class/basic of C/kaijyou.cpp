#include<stdio.h>
/*12‚Ü‚Å‚µ‚©‚Å‚«‚È‚¢*/
main()
{
	int a=1,i,n;
	printf("ŠKæ‚ğŒvZ‚µ‚Ü‚·B\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a = a*i;
	}
	i = i-1;
	printf("%d‚ÌŠKæ‚Í%ld\n",i,a);
}