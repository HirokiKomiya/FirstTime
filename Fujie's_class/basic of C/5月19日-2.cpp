#include<stdio.h>
main(){
	char str[]= "Hello,World!";/*　最後にヌル文字が隠れてる*/
	char *ptr = str;
	int n=0;
	
	for(*ptr=1;*ptr != '\0';*ptr++,n++)/*　再初期化式は,でならべられる*/
		{printf("%c\n",*ptr);}
	printf("%d",n);
}
