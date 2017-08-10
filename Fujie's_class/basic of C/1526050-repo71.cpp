/*0802A改*/
#include<stdio.h>

main()
{
	char a[99];/*枠を多めにとる。*/
	int i = 0;
	printf("10以内の文字入力：");
	do{
		a[i] = getchar();
	}while(a[i++] != 0x0a);
	i = 0;
		printf("読み込んだ文字列　　：");
     while(1){
		putchar(a[i]);
		i++;
		if(i>=9){break;}}/*１０こ読み込んだら繰り返しを抜ける*/
}
