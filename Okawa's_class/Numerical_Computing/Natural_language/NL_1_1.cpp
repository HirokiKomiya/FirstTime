#include <stdio.h>
#include <stdlib.h>

/*FILE *fp;
char name[] = "sample1.txt";
*/

#define kaigyou 0
#define other 1


int counter[1000];
char file_name[] = "sample.txt";


void mojicount(FILE *fp)
{
	int num;
	
	/* ファイルオープン */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	
	while ((num = getc(fp)) != EOF){
		if(num>='a' && num<='z' || num>='A' && num<='Z'){
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
	int num;
	
	for (num = 'a'; num <= 'z'; num++)			/* 小文字の出現頻度を */
		printf("%c:%2d\t",  num, counter[num]);	/* 表示 */
	printf("\n\n");
	
	for (num = 'A'; num <= 'Z'; num++)			/* 大文字の出現頻度を */
		printf("%c:%2d\t",  num, counter[num] );	/* 表示 */
	printf("\n\n");
	
	printf("改行:%2d\n",counter[0]);
	printf("other:%2d\n",counter[1]);
	
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
