/*aの平方根を超えない自然数*/

#include<stdio.h>
#include<math.h>

main()
{
	short a,b;
	b=0;
	
	scanf("%d",&a);
	
	printf("の平方根を超えない自然数は、\n");
	while(b ++ < sqrt(a))
	{
	printf("%d\n" ,b);}
	printf("です。");
}