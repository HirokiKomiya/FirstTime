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
	while(*(ptr + i) != '\0'){/*�k���ɂȂ�܂ŌJ��Ԃ�*/
		if('a' <= *(ptr + i) && 'x' >= *(ptr + i)){/*a����z�̊ԂȂ�(�������Ȃ�)*/
			*(ptr + i)=*(ptr + i)-0x20;/*��s�����炵�đ啶����*/
			}
	    printf("%c\n",*(ptr + i));
		i++;}
}
