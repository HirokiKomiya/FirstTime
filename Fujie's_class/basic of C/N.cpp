#include <stdio.h>

int strcmp(char *,char*);

main(){
	char str[100],ttr[100];
	int c,i = 0;
	
	printf("��̕�����̎������������܂��B�p��œ�̌����͂��Ă��������B\n");
	do{
		str[i] = getchar();
	}while(str[i++] != 0x0a);
	i = 0;
	do{
		ttr[i] = getchar();
	}while(str[i++] != '\0');
	
	c = strcmp(str,ttr);
	
	printf("���ʂ́A%d\n", c);
}

int strcmp(char *x,char *z){
	int y = 0,i = 0;
	char *ptr,*str;
	
	for(ptr = x,str = z; *ptr != '\0' && *str != '\0'; ptr++,str++){
		while(y == 0){
			if(ptr[i] < str[i]){
			y = 1;
			}
			if(ptr[i] > str[i]){
			y = -1;
			}
			i++;
		}
	}
	return y;
}

int strcount(char *x){
	int y = 0;
	char *ptr;
	
	for(ptr = x; *ptr != '\0'; ptr++)
	y++;
	
	return y;
}
