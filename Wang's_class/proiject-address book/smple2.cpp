#include<stdio.h>
#include<string.h>			//文字列を扱うヘッダー

struct person{				//構造体の定義
	int k;
	int id;
	char name[40];
	long phone; 			//最初が0ならどうする？
};


main(){
	int flag;						//フラグ
	char mode1,mode2,mode3,mode4;	//モード切替
	char b;							//Y/Nアンサー
	int h;							//自由。
	int i,j=6,k=0;					//カウンター
	int pass;						//パスワード
	int pass1;						//パスワード入力
	char Qes1[100];					//秘密の質問の問題
	char Ans1[100];					//秘密の質問の正解
	char Ans2[100];					//秘密の質問の回答
	
	FILE *fp;						//ファイルのポインタ
	char mode;						//モード振り分け
	char FileName[] = "data1.txt";	//データを保存するファイル
	char Name[] = "Pass.txt";		//パスワードを保存するファイル
	char Qes[] = "Qestion.txt";		//秘密の質問を保存するファイル
	char Ans[] = "Answer.txt";		//質問の答えを保存するファイル
	
	struct person student[100];		//personという名前の構造体にstudent100個を作る
	int rst1,rst2,rst4;					//名前検索の結果
	int rst3;						//ロック解除の結果
	int s1[10],s11=1;					//ID,Phone検索で使用
	char s2[100],s3[100];			//名前の検索で使用
	
	
	//ファイルがない場合は強制的に新規作成をする。
	fp = fopen(Name,"a");
	fprintf(fp,"%d",1);
	fclose(fp);
	
	fp = fopen(Qes,"a");
	fprintf(fp,"%s","初期値は0です。");
	fclose(fp);
	
	fp = fopen(Ans,"a");
	fprintf(fp,"%s","0\n");
	fclose(fp);
	
	
	while(j>0){
		if(j != 6){				//最初の一回は除外
			printf("終了する場合は0を入力してください。");
			scanf("\n%d",&h);
			if(h==0)
			break;
		}
		
		flag=1;
		printf("\n暗証番号を入力して下さい。暗証番号の初期値は1です。(残り%d回)\nまた、パスワードを忘れた場合は'0'を入力して下さい。",j);
		scanf("\n%d",&pass1);
		if(pass1==0){
			printf("秘密の質問を表示します。\n");
			fp = fopen(Qes,"r+");
			fscanf(fp,"%s",Qes1);
			printf("%s",Qes1);
			fclose(fp);
			printf("\n正しい解答を入力して下さい。");
			scanf("%s",Ans2);
			fp = fopen(Ans,"r+");
			fscanf(fp,"%s",Ans1);
			fclose(fp);
			rst3 = strcmp(Ans1,Ans2);		//解答と正解が同じなら0を返す。
		
		}else{
		fp = fopen(Name,"r+");
		fscanf(fp,"%d",&pass);
		fclose(fp);
		}
		
		if(pass==pass1 | rst3==0){		//入力されたパスワードがあっているなら・・・
			
			while(flag==1){
				j=5;			//パスワード入力可能回数を5に戻す。
				printf("\n q:データの登録、a:データの表示、z:データの検索、d;データの削除、p:パスワードの変更。");
				scanf("\n%c",&mode1);
				printf("\n");
				
				switch(mode1){
					//データの登録
					case'q':
						printf("データを登録します。");
						fp = fopen(FileName,"a+");		/*ここはファイルの名前じゃだめ。*/
						printf("IDを４桁で入力して下さい。\nID:");
						for(i=0;i<4;i++){
						scanf("\n%1d",&student[i].id);
						fprintf(fp,"%d",student[i].id);
						}
						printf("名前を入力してください。\n");
						scanf(" %s",student[0].name);
						fprintf(fp," %s",student[0].name);
						
						printf("電話番号を入力して下さい。\n末尾にローマ字を入れて確定します。\n");
						
						scanf(" %d",&student[0].phone);
						
						fprintf(fp," %d\n",student[0].phone);
						fclose(fp);
						k=k+1; 	//何個入れたかカウント。
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
								printf("以下、今回までに入力したものの一覧表示。\n");
								fp = fopen(FileName,"r+");
								while(1){
									for(i=0;i<4;i++){
										for(i=0;i<4;i++){
											fscanf(fp,"\n%d",&student[i].id);
											if(student[i].id == ""){
											rst4 = rst4;
											}
											
										}
										fscanf(fp," %s",student[0].name);
										fscanf(fp," %d",&student[0].phone);
										
										if(student[0].id==s1[0] && student[1].id==s1[1] && student.id[2]==s1[2] && student.id[3]==s1[3])		//同じやつが二つつずいたら終了
											break;
										//ifbreakはprintfの前に入れないと最後のやつが二つ出てくる。
										printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
									
									}
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
					
					
					case'd':
						printf("全てのデータを削除します。\nよろしければ”y”を入力して下さい。\n");
							if(b=='y'){
							fopen(FileName,"w");
							fclose(fp);
							}else
							
					break;
					
					//パスワード変更
					case'p':
						printf("パスワードや秘密の質問を編集できます。\n変更するものを選択してください。\n");
						printf("パスワード:p、秘密の質問:q、変更しない:n");
						scanf(" %c",&mode4);
						switch(mode4){
							case'p':
								printf("パスワードを変更しますか？y:YES");
								scanf(" %c",&b);
								if(b=='y'){
									printf("\n新しいパスワードを入力して下さい。\n");
									scanf("\n%d",&pass);
									fp = fopen(Name,"w");
									fprintf(fp,"%d\n",pass);
									fclose(fp);
									printf("パスワードを変更しました。\n新しいパスワードは%dです。\n\n",pass);
								}
							break;
							
							case'q':
								printf("秘密の質問を変更しますか？y:YES");
								scanf(" %c",&b);
								if(b=='y'){
									printf("\n新しい秘密の質問を入力して下さい。");
									scanf("\n%s",Qes1);
									fp = fopen(Qes,"w");
									fprintf(fp,"%s\n",Qes1);
									fclose(fp);
									
									printf("秘密の質問の回答を入力して下さい。");
									scanf("\n%s",Ans1);
									fp = fopen(Ans,"w");
									fprintf(fp,"%s\n",Ans1);
									fclose(fp);
									
									printf("変更が完了しました。\n新しい質問は”%s”です。",Qes1);
									printf("また、新しい解答は”%s”です。",Ans1);
								}
							break;
						}
					break;
					//パスワード変更ここまで。
				}
				printf("\n以降は半角で入力してください。\n");
				printf("継続:1、ロック画面に戻る:OTHER");
				scanf("\n%d",&flag);
			}
		}else{		//入力されたパスワードが違ったら・・・
		printf("\nパスワードまたは解答が違います。\n");
		j=j-1;		//パスワードの入力可能回数を減らす
		}
	}
}


			/*進捗状況*/
	/*基本事項*/
//	ファイルの作成					・・・無い場合は自動作成。パスワード初期値設定済み
//	switchによるモード切替			・・・完了(breakがあるのも確認済み)
//	フラグによる継続条件の管理		・・・完了

	/*ノルマ*/
//	ファイルへの書き込み、読み出し	・・・完了
//	登録したデータの一覧表示		・・・完了
//	検索機能						・・・完了

	/*エクストラ*/
//	パスワードによる保護			・・・完了
//	グループ分け					・・・実装予定なし
//	部分検索						・・・別途作成中
//	その他							・・・秘密の質問の実装完了

			/*注意点*/

//追加は後ろに追加してるだけ。場所を選んで追加しているわけではない。
//fscanfは箱を用意して突っ込んでるだけ。
//

			/*改善点*/
//	操作先のファイルがない時の処理	・・・強制的に作成することで解決済み
//	部分一致検索を追加する			・・・作成中
//	終了を入れる					・・・OK!
//	終了のタイミングを変える		・・・OK!
//	同一IDが連続して入力されることを想定していない→通常ありえないので無視
//	暗証番号を忘れたとき用の処理をいれる	・・・完了
//	最初が0の時も読めるようにする	・・・未実装(作成済み)
//	オバーフロー対策				・・・解決策検討中
//	デバックする					・・・実装済みの部分はほぼ完了(12/13時点)

