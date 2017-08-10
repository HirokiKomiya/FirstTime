#include<stdio.h>
main(){
	char str[]= "Hello,World!";/*@ÅŒã‚Éƒkƒ‹•¶š‚ª‰B‚ê‚Ä‚é*/
	char *ptr = str;
	int n=0;
	
	for(*ptr=1;*ptr != '\0';*ptr++,n++)/*@Ä‰Šú‰»®‚Í,‚Å‚È‚ç‚×‚ç‚ê‚é*/
		{printf("%c\n",*ptr);}
	printf("%d",n);
}
