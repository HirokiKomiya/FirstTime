//************************************//
//
//入力:sample.txt
//
//各半角文字の個数をカウント
//
//**********************************//


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define kaigyou 0
#define other 1


int counter[300]={0};
char file_name[] = "sample.txt";


void mojicount(FILE *fp)
{
	int num;
	
	/* ファイルオープン */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	
	while ((num = getc(fp)) != EOF){
		if(isalpha(num)){
			counter[num]++;
		}else{
			if(num=='\n'){
				counter[kaigyou]++;
			}else{
				counter[other]++;
			}
		}
	}
	
	fclose(fp);
}

void PrintResult(void){
	int i,j,tmp;
	int num;
	
	for (num = 'a'; num <= 'z'; num++)
		printf("%c:%2d\t",  num, counter[num]);	/* 表示 */
	printf("\n\n");
	
	for (num = 'A'; num <= 'Z'; num++)			/* 大文字の出現頻度を */
		printf("%c:%2d\t",  num, counter[num] );	/* 表示 */
	printf("\n\n");
	
	printf("改行:%2d\n",counter[kaigyou]);
	printf("other:%2d\n",counter[other]);
	
	printf("\n");
}

void WriteForText(void){
	
}

void main(void)
{
	FILE *fp;
	
	if ((fp = fopen(file_name, "r")) == NULL) {		/* ファイルを開けなければ */
		fprintf ( stderr, "Can't Open File\n" );
		exit (2);									/* 終了 */
	}
	printf("\n");
	printf("%sの各文字の出現頻度表\n",file_name);
	mojicount(fp) ;		/* 文字の出現頻度を調べて */
	PrintResult();		/* 表示する */
	fclose(fp);			/* ファイルを閉じる */
}
