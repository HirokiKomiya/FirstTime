/*�@��̔���@*/

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
		printf("%4d�́A��B\n",a);
	}else if (d == 0 && c == 0)
	{
		printf("%4d�́A�\��̔{���B\n",a);
	}else if (c == 0)
	{
		printf("%4d�́A�l�̔{���B\n",a);
	}else
	{
		printf("%4d�́A�����B\n",a);
	}
}