#include <stdio.h>

int main(void){
		//適当に変数を宣言
	int ID;
	char Name[] = "Wang-LAb.";
	int result;
	int ID1=0;
	char Name1[100];
	//ファイルポインタ
	FILE *fp;	//ファイルの先頭のポインタを指定
	
	char FileName[] = "data.txt";
	
	//ファイルを開く(読みだしモード)
	fp = fopen(FileName,"r+");
	
	//読み込み
	fscanf(fp, "%d %s",&ID1, Name1);
	//ファイルを閉じる
	fclose(fp);
	
	printf("ID: %d %s\n",ID1,Name1);
}
