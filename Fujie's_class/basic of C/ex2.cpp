#include<stdio.h>
main(){
	char str[]= "Hello,World!";/*�@�Ō�Ƀk���������B��Ă�*/
	int i=0;
	char* ptr = str;/*�@char�^�̃|�C���^�ϐ�ptr�̐錾*/
	while(*(ptr+i) != '\0')/*�@ptr����i���ꂽ�ii�Ԗڂ́j������\0(0...�k������)�Ɠ������Ȃ���Α�����*/
	{
		if(i==1)
		{*ptr=*ptr-0x20;}
		printf("%c\n",*(ptr +i));/*�@%c�͈ꕶ����*/
		i++;
	    	if(*(ptr+i) == '\0')
				break;}
}
