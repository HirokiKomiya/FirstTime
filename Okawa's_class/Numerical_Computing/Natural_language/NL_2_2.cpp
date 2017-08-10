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

#define kaigyou 0
#define other 1

#define renzoku 1	//何文字連続で読むか

FILE *fp;
FILE *fp1;

int counter[1000];
char file_name[] = "NYT.txt";
char file_name1[]= "NoMarkSample.txt";

void RemoveMark(FILE *fp){
	int num;
	
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	while ((num = getc(fp)) != EOF){
		//printf("%d ",num);
		
		if((fp1 = fopen(file_name1, "a+")) == NULL)
				fprintf(stderr,"%s", "error: can't read file.");
		
		if(isalpha(num)){
			counter[num]++;
			fprintf(fp1,"%c",num);
			fclose(fp1);
			
		}else{
			if(num=='\n'){
				counter[kaigyou]++;
				fprintf(fp1,"%c",' ');
				fclose(fp1);
			}else{
				if(num==' '){
					counter[other]++;
					fprintf(fp1,"%c",num);
					fclose(fp1);
				}else{
					counter[other]++;
					fclose(fp1);
				}
			}
		}
	}
	fclose(fp);
}


void PrintResult(void){
	int num;
	
	for (num = 'a'; num <= 'z'; num++)			/* 小文字の出現頻度を */
		printf("%c:%2d\t",  num, counter[num]);	/* 表示 */
	printf("\n\n");
	
	for (num = 'A'; num <= 'Z'; num++)			/* 大文字の出現頻度を */
		printf("%c:%2d\t",  num, counter[num] );/* 表示 */
	printf("\n\n");
	
	printf("改行:%2d\n",counter[0]);
	printf("other:%2d\n",counter[1]);
	
	printf("\n");
}

void main(void)
{
	int a=0;
	
	printf("出力先のファイルをからにしてから書き込みますか？\n");
	printf("yes:1 no:OTHER\n");
	scanf("%d",&a);
	
	if(a){
		fp = fopen(file_name1, "w+");
		fclose(fp);
	}
	
	printf("変換中です...\n");
	RemoveMark(fp);
	printf("変換完了\n");
	
	
	if ((fp = fopen(file_name, "r")) == NULL) {		/* ファイルを開けなければ */
		fprintf ( stderr, "Can't Open File\n" );
		exit (2);									/* 終了 */
	}
	printf("\n");
	printf("%sの各文字の出現頻度表\n",file_name);
	PrintResult();		/* 表示する */
	fclose(fp);			/* ファイルを閉じる */
}
