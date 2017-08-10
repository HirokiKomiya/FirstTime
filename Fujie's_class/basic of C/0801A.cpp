/*0802A*/
#include<stdio.h>

main()
{
	char a[99];
	int i = 0;
	printf("10以内の文字入力：");
	do{
		a[i] = getchar();
	}while(a[i++] != 0x0a);
	i = 0;
		printf("読み込んだ文字列　　：");
/*	do{*/
     while(1){
		putchar(a[i]);
		i++;
		if(i>=9){break;}}
	/*}while (a[i++] != 0x0a);*/
}
