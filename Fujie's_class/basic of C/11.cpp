/* 200�܂ł̋������J�E���g����@�@*/

#include<stdio.h>
main()
{
	short n = 0;
	
	while(n < 200)
	{
		n ++ ;
		printf("%4d", n);
		if(n % 20 == 0){
			printf("\n");}
	}
}
