#include <stdio.h>

int strcmp(char *);

main(){
	char str[] = "Hello, World!";
	int c=0;
	char*ptr = str[]
	
	c = strcmp(str);
	
	printf("%s\n",str);
}

int strcmp(char *x){
	int i=0;
	char *ptr;
	while(*(ptr + i) != '\0'){/*ƒkƒ‹‚É‚È‚é‚Ü‚ÅŒJ‚è•Ô‚µ*/
		if('a' <= *(ptr + i) && 'x' >= *(ptr + i)){/*a‚©‚çz‚ÌŠÔ‚È‚ç(¬•¶š‚È‚ç)*/
			*(ptr + i)=*(ptr + i)-0x20;/*“ñs•ª‚¸‚ç‚µ‚Ä‘å•¶š‚É*/
			}
	    printf("%c\n",*(ptr + i));
		i++;}
}
