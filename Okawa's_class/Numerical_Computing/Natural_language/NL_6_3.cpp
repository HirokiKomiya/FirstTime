//************************************//
//
//入力:NoMarkSample.txt
//
//入力ファイルの文字をランダムに出力
//　2文字バージョン
//　file_name[]に入力ファイル名
//　nに発生させる文字の個数
//　mに入力ファイルの文字数
//
//**********************************//


#include <stdio.h>
#include <stdlib.h>

int counter[300]={0};
char file_name[] = "NoMarkSample.txt";

#define n 100	//乱数の個数
#define m 38000	//乱数の上限

void random(FILE *fp){
	
	int i, x;
	int j;
	char num[1000000];
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<n;i++){
		if((fp = fopen(file_name, "r")) == NULL) 
			fprintf(stderr, "%s\n", "error: can't read file.");
		
		//2までは余計なデータあり
		x = (int)( rand() / (double)RAND_MAX * m)*2+3;
		
		//printf("%d文字目:",(x-1)/2);
		
		
		if(x!=3){
			for(j=0;j<x;++j){
				num[j] = getc(fp);
				//printf("%c",num[j]);
			}
			//printf("\n");
			printf("%c",num[x-1]);
			printf("%c",num[x-3]);
			//printf("\n");
		}else
			i=i-1;
	fclose(fp);
	}
}

void main(void){
	int x;
	FILE *fp;
	
	if ((fp = fopen(file_name, "r")) == NULL) {		/* ファイルを開けなければ */
		fprintf ( stderr, "Can't Open File\n" );
		exit (2);									/* 終了 */
	}
	printf("\n");
	random(fp);
	printf("\n");
}
