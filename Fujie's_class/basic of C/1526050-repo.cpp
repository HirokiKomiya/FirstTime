#include<stdio.h>
main(){
	char str[]= "Hello,World!";/*�@�Ō�Ƀk���������B��Ă�*/
	char* ptr = str;/*�@char�^�̃|�C���^�ϐ�ptr�̐錾�Bptr�͏���ɒu��������*/
	int i=0;
		while(*(ptr + i) != '\0'){/*�k���ɂȂ�܂ŌJ��Ԃ�*/
			if('a' <= *(ptr + i) && 'x' >= *(ptr + i)){/*a����z�̊ԂȂ�*/
				*(ptr + i)=*(ptr + i)-0x20;/*��s�����炷*/
				}
		    printf("%c\n",*(ptr + i));
			i++;
		}
}