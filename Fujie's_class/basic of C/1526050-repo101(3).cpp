#include<stdio.h>
#include<ctype.h>
main(){
	char str[]= "Hello,World!";/*　最後にヌル文字が隠れてる*/
	char* ptr = str;/*　char型のポインタ変数ptrの宣言。ptrは勝手に置いた文字*/
	int i=0;
		while(*(ptr + i) != '\0'){/*ヌルになるまで繰り返し*/
			str[i] = toupper(str[i]);
			

			
		    printf("%s\n",*(ptr + i));
			i++;
		}
}