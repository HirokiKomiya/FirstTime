#include <stdio.h>

int main(void){
		//適当に変数を宣言
	int ID = 123456789;
	char Name[] = "Wang-LAb.";
	int result;
	//ファイルポインタ
	FILE *fp;

	char FileName[] = "data.txt";
	//char Name[] = "Data\\list.txt";

	//ファイルを開く
	fp = fopen(FileName, "a+");	//wは新規作成or上書き。a+で追加書き込みor新規作成

	/*
	ここにエラー処理
	*/

    //ファイルに書き出し
	result = fprintf(fp, "%d %c\n", ID, Name);
	//result = fprintf(fp, Name);

	/*
	if(result < 0)
	*/

	//ファイルを閉じる
	fclose(fp);
	
	//ファイルを開く(読みだしモード)
	fp = fopen(FileName,"r");

	//読み込み
	fscanf(fp, "%d %s",&ID, Name);

	//ファイルを閉じる
	fclose(fp);

	printf("ID: %d\n",ID);
}
