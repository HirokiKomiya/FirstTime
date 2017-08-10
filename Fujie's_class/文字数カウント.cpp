#include <stdio.h>

int strcount(char *);

main(){
	char str[] = "Hello, World!";
	int c;
	
	c = strcount(str);
	
	printf("count of '%s' = %d\n",str, c);
}

int strcount(char *x){
	int y = 0;
	char *ptr;
	
	for(ptr = x; *ptr != '\0'; ptr++)
	y++;
	
	return y;
}
