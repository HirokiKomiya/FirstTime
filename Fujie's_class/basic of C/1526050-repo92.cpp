#include <stdio.h>

int strcmp(char *,char*);

main(){
	char str[100],ttr[100];
	int c,i = 0;
	
	printf("二つの文字列の辞書順を示します。\n前の文字列のほうが早ければ１、同じなら０、遅ければ-１と表示します。\n一つ目の文字列を入力してください。\n");
	do{
		str[i] = getchar();
	}while(str[i++] != 0x0a);
	i = 0;
	printf("もう一つの文字列を入れてください。\n");
	do{
		ttr[i] = getchar();
	}while(str[i++] != '\0');/*　ここまで文字の読み込み。*/
	c = strcmp(str,ttr);
	
	printf("結果は、%d\n", c);
}

int strcmp(char *x,char *z){
	int y = 0,i = 0;
	char *ptr,*str;
	
	for(ptr = x,str = z; *(ptr+i) != '\0' && *(str+i) != '\0'; ptr++,str++){
		while(y == 0,ptr[i] != '\0'){/*　yがゼロなら繰り返し。ただし最後まで判定してもyが０で抜ける。*/
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
