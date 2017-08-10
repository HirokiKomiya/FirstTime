#include<stdio.h>
#include<string.h>			//文字列を扱うヘッダー

struct person{				//構造体の定義
	int k;
	int id;
	char name[40];
	long phone; //最初が0ならどうする？
};


main(){
	int flag;	//フラグ
	char mode1,mode2;	//モード切替
	char b;		//Y/Nアンサー
	int h;		//自由。
	int i,j=6,k=0;	//カウンター
	int pass;		//パスワード
	int pass1;		//パスワード入力
	FILE *fp;	//ファイルのポインタ
	char mode;	//モード振り分け
	char FileName[] = "data1.txt";	//データを保存するファイル
	char Name[] = "Pass.txt";		//パスワードを保存するファイル
	
	struct person student[100];		//personという名前の構造体にstudent100個を作る
	int rst1,rst2;		//結果
	int s1=0,s11=1;			//ID,Phone検索で使用
	char s2[100],s3[100];	//名前の検索で使用
	
	
	fp =fopen(Name,"a");
	fprintf(fp,"%d",0);
	fclose(fp);
	
	while(j>0){
		if(j != 6){		//最初の一回は除外
			printf("終了する場合は0を入力してください。");
			scanf("\n%d",&h);
			if(h==0)
			break;
		}
		
		flag=1;
		printf("暗証番号を入力して下さい。初期値は0です。(残り%d回)\n",j);
		fp = fopen(Name,"r+");
		fscanf(fp,"%d",&pass);
		scanf("\n%d",&pass1);
		fclose(fp);
		if(pass==pass1){		//入力されたパスワードがあっているなら・・・
			
			while(flag==1){
				j=5;		//パスワード入力可能回数を5に戻す。
				printf("q:データの登録、a:データの表示、z:データの検索、p:パスワードの変更。");
				scanf("\n%c",&mode1);
				printf("\n");
				
				switch(mode1){
					//データの登録
					case'q':
						printf("データを登録します。ID、名前、電話番号の順に入力してください。\n");
						fp = fopen(FileName,"a+");		/*ここはファイルの名前じゃだめ。*/
						scanf("\n%d %s %d",&student[0].id,student[0].name,&student[0].phone);
						fprintf(fp,"%d %s %d\n",student[0].id,student[0].name,student[0].phone);
						fclose(fp);
						k=k+1; //何個入れたかカウント。
						printf("登録しました。\n");
					break;
					//データの表示
					case'a':
						printf("q:今回追加したものを表示、a:今回までに追加したものを表示。");
						scanf("\n%c",&mode2);
						switch(mode2){
							case'q':
								printf("以下、今回入力したものの一覧表示。\n");
								if(k==0){
								printf("今回追加したものはありません。\n");
								}else{
								fp = fopen(FileName,"r+");
									for(i=0;i<k;i++){
										fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
										printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
									}
								fclose(fp);
								}
							break;
							
							//一覧表示
							case'a':
								printf("以下、今回までに入力したものの一覧表示。\n");	/*　不完全注意！！　*/
								fp = fopen(FileName,"r+");
								while(1){
									fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
									if(student[0].id==s1)		//同じやつが二つつずいたら終了
										break;
									//ifbreakはprintfの前に入れないと最後のやつが二つ出てくる。
									printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
									s1=student[0].id;
								}
								fclose(fp);
							break;
						}
					break;
					
					
					//検索機能
					case'z':
						printf("検索モードです。\n検索したいものを指定してください。ID番号:q名前:a電話番号:z\n");
						scanf("\n%c",&mode2);
						
						switch(mode2){
							case'q':
								printf("IDで検索します。\nIDを入力して下さい。\n");
								scanf("\n%d",&s11);
								fp = fopen(FileName,"r+");
								while(1){
									fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
									if(student[0].id == s11){
										printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
										break;
									}
									if(student[0].id == s1){
										printf("該当するものはありませんでした。\n");
										break;
									}
									s1=student[0].id;
								}
								fclose(fp);
							break;
							
							
							//名前で検索
							case'a':
								printf("NAMEで検索します。\nNAMEを入力して下さい。\n");
								scanf("\n%s",s3);
								fp = fopen(FileName,"r+");
								while(1){
									fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
									rst1 = strcmp(student[0].name,s3);
									rst2 = strcmp(student[0].name,s2);
									if(rst1==0){
										printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
										break;		//同じものがあったら出力して終了
									}
									if(rst2==0){	//引っかからずに最後までいったら・・・
										printf("該当するものはありませんでした。\n");
										break;	
									}
									strcpy(student[0].name,s2);
								}
								fclose(fp);
							
							break;
							
							
							//電話番号検索
							case'z':
								printf("PhoneNumberで検索します。\nIDを入力して下さい。\n");
								scanf("\n%d",&s11);
								fp = fopen(FileName,"r+");
								while(1){
									fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
									if(student[0].phone==s11){
										printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
										break;
									}
									if(student[0].phone==s1){
										printf("該当するものはありませんでした。\n");
										break;
									}
									s1 = student[0].phone;
								}
								fclose(fp);
							break;
						}
					break;
					//検索ここまで。
					
					//パスワード変更
					case'p':
							printf("パスワードを変更しますか？y:YES\n");
							scanf("\n%c",&b);
							if(b=='y'){
								printf("新しいパスワードを入力して下さい。\n");
								scanf("\n%d",&pass);
								fp = fopen(Name,"w");
								fprintf(fp,"%d\n",pass);
								fclose(fp);
								printf("パスワードを変更しました。\n新しいパスワードは%dです。\n\n",pass);
							}
					break;
					//パスワード変更ここまで。
				}
				printf("継続:1、ロック画面に戻る:OTHER");
				scanf("\n%d",&flag);
			}
		}else{		//入力されたパスワードが違ったら・・・
		printf("パスワードが違います。\n");
		j=j-1;		//パスワードの入力可能回数を減らす
		}
	}
}

			/*進捗状況*/
	/*基本事項*/
//	ファイルの作成					・・・無い場合は自動作成。パスワード初期値設定済み
//	switchによるモード切替			・・・完了(breakがあるのも確認済み)
//	フラグによる継続条件の管理	・・・完了

	/*ノルマ*/
//	ファイルへの書き込み、読み出し	・・・完了
//	登録したデータの一覧表示		・・・完了
//	検索機能						・・・完了

	/*エクストラ*/
//	パスワードによる保護			・・・完了
//	グループ分け					・・・実装予定なし
//	部分検索						・・・別途作成中
//	その他							・・・パスワードを忘れたときの処理を追加予定

			/*注意点*/

//追加は後ろに追加してるだけ。
//	fscanfは箱を用意して突っ込んでるだけ。

			/*改善点*/

//	部分一致検索を追加する			・・・作成中
//	終了を入れる					・・・OK!
//	終了のタイミングを変える		・・・OK!
//	同一IDが連続して入力されることを想定していない→通常ありえないので無視
//	暗証番号を忘れたとき用の処理をいれる	・・・作成中
//	最初が0の時も読めるようにする	・・・未実装(作成済み)
//	オバーフロー対策				・・・解決策検討中
//	デバックする					・・・実装済みの部分はほぼ完了(12/13時点)
