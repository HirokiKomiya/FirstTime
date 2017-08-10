

#include <stdio.h>


int main (void){

	char FileName[] = "test.txt";
	char Name[32]; // 名前保存用
	int ID;        // ID(ガクばん？)保存用

	//ファイルポインタ
	FILE *fp;

	//ファイルを開く(読み込みモード)
	fp = fopen(FileName,"r");

	//読み込み
	fscanf(fp, "%d %s",&ID, Name);

	//ファイルを閉じる
	fclose(fp);

	printf("ID: %d\n",ID);
}