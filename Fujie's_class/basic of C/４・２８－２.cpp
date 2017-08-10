/*　奇数の判定　*/

#include<stdio.h>

main()
{
	int a, b ,c ,d;
	
	a = 118;
	b = a % 2;
	c = a % 4;
	d = a % 3;
	
	if (b == 1)
	{
		printf("%4dは、奇数。\n",a);
	}else if (d == 0 && c == 0)
	{
		printf("%4dは、十二の倍数。\n",a);
	}else if (c == 0)
	{
		printf("%4dは、四の倍数。\n",a);
	}else
	{
		printf("%4dは、偶数。\n",a);
	}
}