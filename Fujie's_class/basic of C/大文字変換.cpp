#include <stdio.h>

int strupper(char *);

int main(void){
	char str[] = "Hello, World!";
	int c;
	
	c = strupper(str);
	
	printf("'%s'",str, c);
	return 0;
}

int strupper(char *x){
	char *ptr;
	
	for(ptr = x; *ptr != '\0'; ptr++){
		if(*ptr >= 'a'&& *ptr <= 'z'){
		*ptr = *ptr - 0x20;
		}
	}
}
