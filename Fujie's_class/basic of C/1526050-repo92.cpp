#include <stdio.h>

int strcmp(char *,char*);

main(){
	char str[100],ttr[100];
	int c,i = 0;
	
	printf("��̕�����̎������������܂��B\n�O�̕�����̂ق���������΂P�A�����Ȃ�O�A�x�����-�P�ƕ\�����܂��B\n��ڂ̕��������͂��Ă��������B\n");
	do{
		str[i] = getchar();
	}while(str[i++] != 0x0a);
	i = 0;
	printf("������̕���������Ă��������B\n");
	do{
		ttr[i] = getchar();
	}while(str[i++] != '\0');/*�@�����܂ŕ����̓ǂݍ��݁B*/
	c = strcmp(str,ttr);
	
	printf("���ʂ́A%d\n", c);
}

int strcmp(char *x,char *z){
	int y = 0,i = 0;
	char *ptr,*str;
	
	for(ptr = x,str = z; *(ptr+i) != '\0' && *(str+i) != '\0'; ptr++,str++){
		while(y == 0,ptr[i] != '\0'){/*�@y���[���Ȃ�J��Ԃ��B�������Ō�܂Ŕ��肵�Ă�y���O�Ŕ�����B*/
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
