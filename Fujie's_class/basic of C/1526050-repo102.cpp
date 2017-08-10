/*文字列の配列→ポインタ配列*/
#include<stdio.h>
#include<string.h>

main(){
	char* str[] ={"iron blue","ivy green","ivory","ash gray","apple green","apricot","amber","yellow","yellow ocher","wistaria",0};
	int i;
	char* adr;
	for(i = 0;i <10; i++){
		adr = strstr(str[i],"yellow");
		if(adr == '\0'){
			printf("%s\n",str[i]);
			}
	}
}