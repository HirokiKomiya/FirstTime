#include <stdio.h>

int strcmp(char *);

main(){
	char str[] = "Hello, World!";
	int c;
	
	c = strcmp(str);
	
	printf("'%s'",str, c);
}

int strcmp(char *x){
	char *ptr;
	
	for(ptr = x; *ptr != '\0'; ptr++){
		if(*ptr >= 'a'&& *ptr <= 'z'){
		*ptr = *ptr - 0x20;
		}
	}
}
