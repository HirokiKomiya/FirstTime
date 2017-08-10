/* 100までカウントする①　*/

#include<stdio.h>
main()
{
	short n = 0;
	
	while(n < 100)
	{
		n = n +1;
		printf("%3d", n);
		if(!(n % 10)){
			printf("%\n");}
	}
}
