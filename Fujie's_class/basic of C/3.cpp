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
	while(*(ptr + i) != '\0'){/*ヌルになるまで繰り返し*/
		if('a' <= *(ptr + i) && 'x' >= *(ptr + i)){/*aからzの間なら(小文字なら)*/
			*(ptr + i)=*(ptr + i)-0x20;/*二行分ずらして大文字に*/
			}
	    printf("%c\n",*(ptr + i));
		i++;}
}
