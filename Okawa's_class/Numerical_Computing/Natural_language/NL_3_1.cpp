//************************************//
//
//入力:NoMarkSample.txt
//
//
//NL1_2と同様の機能。
//入力ファイルの記号を取り除く
//その結果を出力ファイルにコピーする
//
//***********************************//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define kaigyou 0
#define other 1

#define renzoku 1	//何文字連続で読むか

FILE *fp;
FILE *fp1;

struct eitango{
	char tango[100];
	int kosu;
};

int counter[1000];
char file_name[] = "NoMarkSample.txt";
char file_name1[]= "NoMarkSample.txt";

int a=0;

void mojicount(FILE *fp)
{
	char num;
	int i=0,j=0;
	char tyukan[100];	
	int mojisu;
	char check_word[100];
	
	struct eitango word;
	
	
	printf("check%d\n",a);
	a++;
	
	/* ファイルオープン */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	printf("check%d\n",a);
	a++;
	
	while ((num = getc(fp)) != EOF){
		printf("whilecheck1\n");
		
		if(num != ' '){
			printf("whilecheck2\n");
			
			//スペースがくるまで中間に文字を代入
			tyukan[i] = num;
			i++;
		}
		
		check_word=tyukan;
		
		for (j = 0; ; j++){ 
			//同じ単語だったら文字のカウントを増やす 
			if ( strcmp(word[j].tango,check_word) == 0){
				word[j].kosu++;
				break;
			}
		//今までにない単語だったら新しい構造体に保存 
		if (j == i){ 
			strcpy(word[i].tango, check_word); 
			word[j].kosu++;
			i++;
			break;
		}
		
		printf("%s",tyukan);
	}
	
	printf("check%d\n",a);
	a++;
	
	fclose(fp);
}


void main(void)
{
	int a=0;
	printf("\n");
	printf("%sの各文字の出現頻度表\n",file_name);
	mojicount(fp) ;		/* 文字の出現頻度を調べて */
	//PrintResult();		/* 表示する */
	fclose(fp);			/* ファイルを閉じる */
}
