#include<stdio.h>
main(){
	char str[]= "Hello,World!";/*�@�Ō�Ƀk���������B��Ă�*/
	char *ptr = str;
	int n=0;
	
	for(*ptr=1;*ptr != '\0';*ptr++,n++)/*�@�ď���������,�łȂ�ׂ���*/
		{printf("%c\n",*ptr);}
	printf("%d",n);
}
