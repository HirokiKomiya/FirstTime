#include <stdio.h>
#include <math.h>
#define SIZE 256
#include <stdlib.h>

/*FILE *fp;
char name[] = "sample1.txt";
*/

#define other 0

int counter[1000];
char file_name[] = "sample.txt";


void mojicount(FILE *fp)
{
	int num = 0;
	
	/* ファイルオープン */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	
	while ((num = getc(fp)) != EOF){
		if(num>='a' && num<='z' || num>='A' && num<='Z'){
			counter[c]++;
		}else{
		counter[other]++:
		}
	}
	
	fclose(fp);
}

void PrintResult(void){
	int c;
	
	for (c = 'a'; c <= 'z'; c++)			/* 小文字の出現頻度を */
		printf("%c:%d\n",  c, counter[c]);	/* 表示 */
		printf("\n");
	for (c = 'A'; c <= 'Z'; c++){			/* 大文字の出現頻度を */
		printf("%c:%d\n",  c, counter[c] );	/* 表示 */
		printf("\n");
	}
}

void WriteForText{
	
}
	
void main(void)
{
    FILE *fp;
	
    if ((fp = fopen(file_name, "r")) == NULL) {   /* ファイルを開けなければ */
                                                    /* メッセージを表示して */
        fprintf ( stderr, "Can't Open File\n" );
        exit (2);                                   /* 終了 */
    }
    printf("出現頻度表\n");
    CountLett(fp) ;        /* 文字の出現頻度を調べて */
    PrintResult();       /* 表示する */
    fclose(fp);            /* ファイルを閉じる */
 }
