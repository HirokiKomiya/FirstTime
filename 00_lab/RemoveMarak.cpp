//************************************//
//
//入力:sample.txt
//出力:NoMarkSample.txt
//
//
//NL1_2と同様の機能。
//入力ファイルの記号を取り除く
//その結果を出力ファイルにコピーする
//
//改行は半角スペースに変換
//その他の記号は削除
//半角文字半角スペースはそのままコピー
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


char file_name[] = "F1F2ALL.txt";
char file_name1[]= "F1F2ALLNoMark.txt";

void RemoveMark(FILE *fp){
	char num[100];
	int num1;
	float num2;
	int check;
	int i=0;
	int flag=0;
	int counter=0;
	
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	while (1){
		printf("Checker1\n");
		fscanf(fp,"%s\n%d\n%f\n\n",num,&num1,&num2);
		check=strcmp(num,"END");
		printf("%s %d %f\n",num,num1,num2);
		if(check==0){
			printf("Checker2\n");
			break;
		}
		
		if((fp1 = fopen(file_name1, "a+")) == NULL){
			printf("Checker3\n");
				fprintf(stderr,"%s", "error: can't read file.");
		}
		
		fprintf(fp1,"%d %d\n",num1,num2);
	}
	fclose(fp);
}


void main(void)
{
	int a=0;
	
	printf("出力先のファイルを空にしてから書き込みますか？\n");
	printf("yes:1 no:OTHER\n");
	scanf("%d",&a);
	
	if(a){
		fp = fopen(file_name1, "w+");
		fclose(fp);
	}
	
	printf("変換中です...\n");
	RemoveMark(fp);
	printf("変換完了\n");
	
}
