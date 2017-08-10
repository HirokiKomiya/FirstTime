/*ここまでにクリアした課題
*
*指定の人数分IDや名前を入力し、それを保存することができる。
*モード振り分けを追加(途中)。
*
*/

#include<stdio.h>

struct person{
	unsigned int id;
	char name[40];
	unsigned long phone; //unsignedは-を無視。最初が0ならどうする？
};

main(){
	
	int a=1;	//フラグ
	int h;
	int i=0;	//カウンター
	int j;		//何人分入れるか
	char mode;
	
	while(a==1){
		printf("モード選択。情報入力モード:q データの読み出しモード:a\n");
		scanf("\n%c",&mode);
		switch(mode){
			case'q':
				printf("何人分の情報を入力しますか？\n");
				scanf("\n%d",&j);
				j=j-1;
				struct person student[100];		//適当に大きさを定義
				while(i<=j){  							//何人分入れたいか
						printf("ID 名前 電話番号\nの順で打ち込んでください。\n");
						scanf("%d %s %ld",&student[i].id,student[i].name,&student[i].phone);
						printf(" %d\n  %s\n   %ld\n",student[i].id,student[i].name,student[i].phone); //配列は&いらない
					i++;
				}
				i=0;
			break;
			case'a':
				printf("何番目のデータを読み出しますか。\n");		//fscanfを使おう。scanは一行しか読み込まないので注意
				scanf("\n%d",&h);
				
				printf("%d,%s,%ld\n",student[h-1].id,student[h-1].name,student[h-1].phone); //h番目のデータを表示
				h=0;
			break;
			
			
		}
	printf("継続する場合は1を入力して下さい");
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
*ファイル分割をする。(コン基11回目の授業を参照)
*
*/