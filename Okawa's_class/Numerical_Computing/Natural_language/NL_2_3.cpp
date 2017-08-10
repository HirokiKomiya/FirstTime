//************************************//
//
//入力:sample.txt
//出力:NoMarkSample.txt
//
//
//NL2_2と同様の機能。
//入力ファイルの記号を取り除く
//その結果を出力ファイルにコピーする
//カウントはしない
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
char file_name[] = "Sample.txt";
char file_name1[]= "A.txt";
int flag=0;

void RemoveMark(FILE *fp){
	int num;
	
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	
	while ((num = getc(fp)) != EOF){
		//printf("%d ",num);
		
		if((fp1 = fopen(file_name1, "a+")) == NULL)
				fprintf(stderr,"%s", "error: can't read file.");
		
		if(isalpha(num)){
			fprintf(fp1,"%c",num);
			fclose(fp1);
			printf("%c",num);
		}else{
			if(num=='\n'){
				if(flag){
					fclose(fp1);
					flag=0;
				}else{
					fprintf(fp1,"%c",' ');
					fclose(fp1);
					printf(" ");
				}
			}else{
				if(num==' '){
					fprintf(fp1,"%c",num);
					fclose(fp1);
					flag=1;
					printf("%c",num);
				}else{
					fclose(fp1);
				}
			}
		}
	}
	fclose(fp);
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
	
	printf("変換中です...\n\n");
	RemoveMark(fp);
	printf("\n\n変換完了\n");
}
