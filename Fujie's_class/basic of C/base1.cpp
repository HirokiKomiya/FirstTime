/*base*/

#include<stdio.h>

main()
{
	short value; 
	
	printf("整数を入力してください：");
	
	scanf("%4d",&value);
	
	printf("入力した変数の値は%4lfです。",value);
	printf("入力した番地の値は%4xです。\n",&value);
	
}