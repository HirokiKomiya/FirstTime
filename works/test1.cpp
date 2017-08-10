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
#include <string.h>

#define kaigyou 0
#define other 1


int counter[300]={0};
char file_name[] = "sample.txt";
char file_name1[]= "step1.txt";


FILE *fp;
FILE *fp1;

void henkan(FILE *fp)
{
	char num;
	
	/* ファイルオープン */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	while ((num = getc(fp)) != EOF){
		if((fp1 = fopen(file_name1, "a+")) == NULL)
				fprintf(stderr,"%s", "error: can't read file.");
		if(mbscmp(、,num)==0){
			fprintf(fp1,"%c",',');
			fclose(fp1);
		}else{
			if(strcmp(num,'。')==0){
				fprintf(fp1,"%c",'.');
				fclose(fp1);
			}else{
				fprintf(fp1,"%c",num);
				fclose(fp1);
			}
		}
	}
	
	fclose(fp);
}



void main(void)
{
	FILE *fp;
	
	if ((fp = fopen(file_name, "r")) == NULL) {		/* ファイルを開けなければ */
		fprintf ( stderr, "Can't Open File\n" );
		exit (2);									/* 終了 */
	}
	henkan(fp) ;		/* 文字の出現頻度を調べて */
	fclose(fp);			/* ファイルを閉じる */
}
