#include <stdio.h>

int main(void){

	//ファイルポインタ
	FILE *fp;

	char FileName[] = "data.txt";
	//char Name[] = "Data\\list.txt";

	//ファイルを開く
	fp = fopen(FileName, "w");

	/*
	ここにエラー処理
	*/

	//適当に変数を宣言
	int ID = 123456789;
	char Name[] = "Wang-LAb.";
	int result;

    //ファイルに書き出し
	result = fprintf(fp, "%d %c\n", ID, Name);
	//result = fprintf(fp, Name);

	/*
	if(result < 0)
	*/

	//ファイルを閉じる
	fclose(fp);







}