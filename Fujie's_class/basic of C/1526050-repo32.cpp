/* 4.2B */
#include<stdio.h>

main()
{
	int a ,b,c;
	c = 0;
	
	scanf("%d",&a);
	
	for(b = 2; b < a ; b++)
		{if((a % b) == 0)
			{c = 1;
			}
		}
		if(c == 1)
		printf("%dは素数ではない\n",a);
		if(c == 0)
		printf("%dは素数\n",a);
		
}