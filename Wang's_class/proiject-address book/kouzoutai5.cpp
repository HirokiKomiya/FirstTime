/*ここまでにクリアした課題
*
*指定の人数分IDや名前を入力し、それを保存することができる。
*モード振り分けを追加(途中)。
*
*/

#include<stdio.h>
#include<string.h>			//文字列を扱うヘッダー

struct person{
	unsigned int id;
	char name[40];
	unsigned long phone; //unsignedは-を無視。最初が0ならどうする？
};
#define keitai 090



main(){
	
	int a=1;	//フラグ
	int h;		//自由。
	int i=0,k=0;	//カウンター
	int j;		//何人分入れるか
	
	int result;	//結果を評価するための変数
	FILE *fp;	//ファイルのポインタ
	char mode;	//モード振り分け
	char FileName[] = "data.txt";
	//char Name[] = "Data\\list.txt";
	struct person student[100];		//personという名前の構造体にstudent100個を作る
	
	while(a==1){
		printf("モード選択。情報入力モード:q データの読み出しモード:a\n");
		scanf("\n%c",&mode);
		switch(mode){
			
			case'q':
				//ファイルを開く(書き込みモード)
				fp = fopen("data.txt","a+");		//a+は追加書き込みor新規作成。ファイルの開け閉めは繰り返しの外に。
				
				printf("何人分の情報を入力しますか？\n");
				scanf("\n%d",&j);
				j=j-1;
				
				while(i<=j){  							//何人分入れたいか
						printf("ID 名前 電話番号\nの順で打ち込んでください。\n");
						scanf("%d %s %ld",&student[i].id,student[i].name,&student[i].phone);
						result = fprintf(fp,"%d %s %ld",student[i].id,student[i].name,student[i].phone);
						/*
						if(result < 0)		ここに異常時の処理
						*/
						
						//printf(" %d\n  %s\n   %ld\n",student[i].id,student[i].name,student[i].phone); //配列は&いらない
						
					i++;
				}
				//ファイルを閉じる
				fclose(fp);
				
				
				
			break;
			
			case'a':
				fp = fopen("data.txt","r");
				printf("何番目のデータを読み出しますか。\n");		//fscanfを使おう。scanは一行しか読み込まないので注意
				scanf("\n%d",&h);
				
				fscanf(fp,"%d %s %ld",&student[h-1].id,student[h-1].name,&student[h-1].phone); //h番目のデータを表示
				printf("%d,%s,%ld\n",student[h-1].id,student[h-1].name,student[h-1].phone);
				fclose(fp);
			break;
			
			case'c':
				printf("copy mode \n");
				
				//strcpy
				
			break;
		}
	printf("継続する場合は1を入力して下さい。\n");
	scanf("\n%d",&a);
	}
}

/*ここまでの問題点。
*
*オーバーフロー対策をしていない。
*電話番号などで最初がゼロの場合読み飛ばされる。
*デバックをしていない。
*
*/

/*これからの課題
*
*名前や番号で検索をできるようにする。これはコンピューター基礎の資料を参照。
*ファイルに読み書きをする。
*
*extra
*ファイル分割をする。(コン基11回目の授業を参照)
*
*/