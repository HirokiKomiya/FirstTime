/* 100はじめt超える最初の七の倍数　*/

#include<stdio.h>
main()
{
	int a, b,c,d;
	
	a = 7;
	b = 0;
	d = 1;
	
			
	while(b < 100)
	{printf("%3d回目、%3d\n",d,b);
		b = b + a;
		d = 1 + d;}
	while(100 < b < 106);
		printf("%3d回目、%3d\n",d,b);
		b = b + a;
		d = 1 + d;
	}
	
	printf("100を初めて超える７の倍数は、%3dです。\n", b);
}
