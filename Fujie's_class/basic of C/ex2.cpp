#include<stdio.h>
main(){
	char str[]= "Hello,World!";/*　最後にヌル文字が隠れてる*/
	int i=0;
	char* ptr = str;/*　char型のポインタ変数ptrの宣言*/
	while(*(ptr+i) != '\0')/*　ptrからiずれた（i番目の）文字が\0(0...ヌル文字)と等しくなければ続ける*/
	{
		if(i==1)
		{*ptr=*ptr-0x20;}
		printf("%c\n",*(ptr +i));/*　%cは一文字分*/
		i++;
	    	if(*(ptr+i) == '\0')
				break;}
}
