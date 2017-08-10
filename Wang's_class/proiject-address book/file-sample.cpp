#include<stdio.h>
#include<string.h>			//文字列を扱うヘッダー

struct person{
	int k;
	unsigned int id;
	char name[40];
	long phone; //unsignedは-を無視。最初が0ならどうする？
};

main(){
	int a=1;	//フラグ
	int h;		//自由。
	int i=0,k=0;	//カウンター
	
	FILE *fp;	//ファイルのポインタ
	char mode;	//モード振り分け
	char FileName[] = "data.txt";
	//char Name[] = "Data\\list.txt";
	struct person student[100];
	
	while(a==1){
		fp = fopen(FileName,"a");
		scanf("\n%d %s %d",&student[0].id,student[0].name,&student[0].phone);
		fprintf(fp,"%d %s %d\n",student[0].id,student[0].name,student[0].phone);
		fclose(fp);
		fp = fopen(FileName,"r+");		/*ここはファイルの名前じゃだめ。*/
		fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
		printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
		fclose(fp);
		k=k+1; //何個入れたかカウント。

		//一覧表示
		printf("以下、今回入力したものの一覧表示。\n");
		fp = fopen(FileName,"r+");
		for(i=0;i<k;i++){
			fscanf(fp,"%d %s %d",&(student+i)->id,(student+i)->name,&(student+i)->phone);
			printf("%d %s %d\n",(student+i)->id,(student+i)->name,(student+i)->phone);
		}
		fclose(fp);

		printf("継続:1\n");
		scanf("\n%d",&a);
	}
}

/********************* 問題点、注意点 ***********************/
//追加は後ろに追加してるだけ。
//読み込みは一番目のデータしか読めない。
//文字列の代入はstrcmpを使おう
//	if(strcmp(name,"Taro")==0)	←文字列が同じなら真
/************************************************************/