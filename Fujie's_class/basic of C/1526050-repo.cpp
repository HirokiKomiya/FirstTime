#include<stdio.h>
main(){
	char str[]= "Hello,World!";/*　最後にヌル文字が隠れてる*/
	char* ptr = str;/*　char型のポインタ変数ptrの宣言。ptrは勝手に置いた文字*/
	int i=0;
		while(*(ptr + i) != '\0'){/*ヌルになるまで繰り返し*/
			if('a' <= *(ptr + i) && 'x' >= *(ptr + i)){/*aからzの間なら*/
				*(ptr + i)=*(ptr + i)-0x20;/*二行分ずらす*/
				}
		    printf("%c\n",*(ptr + i));
			i++;
		}
}