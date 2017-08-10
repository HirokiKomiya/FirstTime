//ファイルに書き込むやり方。

#include<stdio.h>

main(){

	FILE *fp;	//ファイルのポインタ
	int result;
	char FileName[] = "data.t";
	char Name[] = "Data\\list.txt";
	
	//ファイルを開く
	
	fp = fopen(FileName,"w"); 	//ファイルの開き方を指定
	
	//ファイルの書き出し
	result = fprintf(fp," "," ");
	
	if(result<0){
	} //エラー処理の文。fprintでちゃんと読み込めないと-1が返される。
}


//ファイルは開いたら必ず閉じよう。


//ファイルに読み込むやり方
/*#include<stdio.h>

int main(){

	FILE *fp;	//ファイルのポインタ
	int ID;
	char FileName[] = "text.txt";
	char Name[64];
	
	fp = fopen(FileName,"r");	//ファイルを開く(読み込みモード)
	
	//読み込み
	fscanf(fp,"%d %s",&ID,NAME);
	
	
	fclose(fp);	//ファイルを閉じる
	
	
	//ファイルを開く*/