#include<stdio.h>
#include<ctype.h>
int main(void){
	char str[]= "Hello,World!";/*�@�Ō�Ƀk���������B��Ă�*/
	char* ptr = str;/*�@char�^�̃|�C���^�ϐ�ptr�̐錾�Bptr�͏���ɒu��������*/
	int i=0;
		while(*(ptr + i) != '\0'){/*�k���ɂȂ�܂ŌJ��Ԃ�*/
			str[i] = toupper(str[i]);
			i++;
		}
		printf("%s\n",str);
		return 0;
}