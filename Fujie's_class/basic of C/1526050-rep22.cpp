/* 100はじめt超える最初の七の倍数　*/

#include<stdio.h>
main()
{
	int a, b,c,d;
	
	a = 7;
	b = 0;
	c = 1;
	d = 1;
	
			
	while(b < 100)
	{printf("%3d回目、%3d\n",d,b);
		b = b + a;
		d = c + d;
	}
	
	printf("100を初めて超える７の倍数は、%3dです。\n", b);
}
