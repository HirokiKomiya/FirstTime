/*検索に使える関数*/

#include <string.h>

//文字列を代入するのは'=='じゃできない。→strcpyなどを使う。

char *strcpy(char *s1,char *s2);	//s2をs1にコピーする。

int strcmp(char *s1,char *s2);		//s1とs2が同じなら0を返す。

int strlen(char *s1);				//s1の長さを返す。

