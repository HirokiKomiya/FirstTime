#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.1415926
main()
{
	int a=1,b;												//aは続行フラグ
	double c,w;												//二回目以降の計算で使用。
	char z,y,x;												//yは計算結果を使うかのフラグ。x,zはモード振り分けのswitchに使用。
	int ran,rana,d,t;										//Extraモードで使用する変数
	double e[100];												//Extraモードの四則演算で使用する変
	char ex[100];												//数。eは数字、exは演算子を入れる。
	int i=0;														//iは何回目かのカウントをする。
	
	while(a==1){
	    printf("\n演算子を選択して下さい。\n足し算:+、引き算:-、掛け算:*、割り算:/、関数電卓:a、Extraモード:q\n");
	    scanf("\n%c",&z);
		ran = rand();
		switch(z){											//１回目の計算のモード振り分け
			case'+':
				printf("a+bを計算します。aを入力してください。\n");
			    scanf("%d",&a);
			    printf("bを入力してください。\n");
			    scanf("%d",&b);
				c = a+b;
			    printf("%d+%d＝%dです。\n",a,b,a+b);
			break;
			case'-':
				printf("a-bを計算します。aを入力してください。\n");
			    scanf("%d",&a);
			    printf("bを入力してください。\n");
			    scanf("%d",&b);
				c = a-b;
			    printf("%d-%d＝%dです。\n",a,b,a-b);
			break;
			case'*':
				printf("a*bを計算します。aを入力してください。\n");
			    scanf("%d",&a);
			    printf("bを入力してください。\n");
			    scanf("%d",&b);
				c =a*b;
			    printf("%d*%d＝%dです。\n",a,b,a*b);
			break;
			case'/':
				printf("a/bを計算します。aを入力してください。\n");
			    scanf("%d",&a);
			    printf("bを入力してください。\n");
			    scanf("%d",&b);
				if(b != 0){
				c = a/b;
			    printf("%d/%d＝%dです。\n",a,b,a/b);
				}else
				printf("0では割れません。\n");
			break;
			case'a':								//関数電卓モード(一回目)
				printf("関数電卓モードです。\nsin:s、cos:c、tan:t、√:r\n行いたい計算に合わせてコロンの後の文字を入力してください。");
				scanf("\n%c",&x);
				switch(x){							//関数電卓モードの中のモード振り分け
					case's':
						printf("sinaを計算します。aを入力してください。\n");
						scanf("%d",&a);
						c =  sin(a*PI/180);
						printf("sin%d＝%lfです。\n",a,c);
					break;
					case'c':
						printf("cosaを計算します。aを入力してください。\n");
						scanf("%d",&a);
						c =  cos(a*PI/180);
						printf("cos%d＝%lfです。\n",a,c);
					break;
					case't':
						printf("tanaを計算します。aを入力してください。\n");
						scanf("%d",&a);
						c =  tan(a*PI/180);
						printf("tan%d＝%lfです。\n",a,c);
					break;
					case'r':
						printf("√aを計算します。aを入力してください。\n");
						scanf("%d",&a);
						c =  sqrt(a);
						printf("√%d＝%lfです。\n",a,c);
					break;
					default:					//関数電卓モードの中の例外処理
			        printf("演算子が間違っています\n");
				}
			break;
			case'q':												//Extraモード
				printf("Extraモードです。\nジャンケンモード:a、連続計算モード:b、自立起爆モード:c\n");
				scanf("\n%c",&x);
				switch(x){											//Extraモード振り分け
					case'a':										//このケースに入った時点でフラグxは立っている。
						while(x=='a'){									//以下、ジャンケンモード
							printf("\nジャンケンモードです。\n");
							ran = rand();								//ランダム関数
							rana = ran % 3;								//ranaは0か1か2
							printf("グー:0、チョキ:1、パー:2\n");		//自分が出す目を選択
							scanf("\n%d",&d);
							switch(rana){								//
								case 0:									//敵はグー
									switch(d){
										case 0:
											printf("あいこ\n");
										break;
										case 1:
											printf("あなたの負け\n");
										break;
										case 2:
											printf("あなたの勝ちです\n");
										break;
										default:
										printf("反則負け\n");
									}
								break;
								case 1 :									//チョキ
									switch(d){
											case 0 :
												printf("あなたの勝ちです\n");
											break;
											case 1 :
												printf("あいこ\n");
											break;
											case 2 :
												printf("あなたの負けです\n");
											break;
											default:
											printf("反則負け\n");
										}
								break;
								case 2 :									//パー
									switch(d){
										case 0 :
											printf("あなたの負けです\n");
										break;
										case 1 :
											printf("あなたの勝ちです\n");
										break;
										case 2 :
											printf("あいこです\n");
										break;
										default:
										printf("反則負け\n");
									}
								break;
							}
							printf("続けてジャンケンする場合は”a”を入力して下さい。\n");
							scanf("\n%c",&x);					//フラグxの判定
						}
						break;
						case'b':								//その他のモード２
							i=0;
							printf("\n連続計算モードです。\nこのモードでは四則演算のみ、'='が入力されるまで一括計算ができます。ただし掛け算割り算は優先されません。\n");
							while(ex[i-1] != '='){
								scanf("\n%lf",&e[i]);	//数字を読み込み
								
								scanf("\n%c",&ex[i]);	//文字を読み込み。数字と文字一つで１セット
								
								if(i !=0){				//iが1から計算を開始する。
									switch(ex[i-1]){
										case'+':
										e[i] = e[i-1] + e[i];
										break;
										case'-':
										e[i] = e[i-1] - e[i];
										break;
										case'*':
										e[i] = e[i-1] * e[i]; 
										break;
										case'/':
										if(e[i] != 0){
										e[i] = e[i-1] / e[i];		//割る値が0の時には計算しない
										}else
										e[i] = e[i-1];
										break;
										default:
										e[i] = e[i-1];
									}
								}else;
							i++;					//カウントを増やす。
							}
						printf("計算結果は%lfです。\n",e[i-1]);			//余分に1増えたカウントを引いて答えを出力。
						break;
						case'c':								//その他のモード３。恐怖の自立起爆モード。
							printf("自立起爆を可決しますか？\nyes:y、no:n\n");
							scanf("\n%c",&x);
							if(x != 'n'){
								for(t=1;t<=30000;t++)
									{
									printf("自立起爆が可決されました。\n");
									}
									while(1){
										ran = rand();
										printf("%d %c%c%d",ran,x,y,ran);
								}
							}else
								printf("自立起爆が否決されました。\n");
							
						break;
						default:								//Extraモードの例外処理
						printf("そのモードはないよ\n");
				}
			break;
			default:											//演算子選択の例外処理
			printf("演算子が間違っています\n");
			}													//一回目の計算ここまで。
			if(z == '+' | z == '-' | z == '*' | z == '/' | z == 'a'){				//一回目で計算を行ったときのみ二回目の計算に進む。
				printf("\n今回の計算結果を用いる場合はaを、用いない場合や終了したい場合はそれ以外を入力してください。");
				scanf("\n%c",&y);													//フラグyを立てるか否か
				while(y == 'a'){													//ここから２回目以降の計算。前の計算結果を変数cに保存し、それを用いた計算をする。
					printf("\n演算子を選択して下さい。\n足し算:+、引き算:-、掛け算:*、割り算:/、関数電卓:a\n");
			        scanf("\n%c",&z);												//演算子の選択
					switch(z){
						case'+':
							printf("%2f+bを計算します。\n",c);
						    printf("bを入力してください。\n");
						    scanf("%d",&b);
							c = c+b;
						    printf("答えは%2fです。\n",c);
						break;
						case'-':
							printf("%2f-bを計算します。\n",c);
						    printf("bを入力してください。\n");
						    scanf("%d",&b);
							c = c-b;
						    printf("答えは%2fです。\n",c);
						break;
						case'*':
							printf("%2f*bを計算します。\n",c);
						    printf("bを入力してください。\n");
						    scanf("%d",&b);
							c =c*b;
						    printf("答えは%2fです。\n",c);
						break;
						case'/':
							printf("%2f/bを計算します。\n",c);
						    printf("bを入力してください。\n");
						    scanf("%d",&b);
							if(b != 0){
							c = c/b;
						    printf("答えは%2fです。\n",c);			//割る値が0の時は計算しない
							}else
							printf("0では割れません。\n");
						break;
						case'a':									//関数モード
							printf("関数電卓モードです。\nsin:s、cos:c、tan:t、√:r\n行いたい計算に合わせてコロンの後の文字を入力してください。");
							scanf("\n%c",&z);
							switch(z){								//関数モードの振り分け
								case's':
									printf("sin%2fを計算します。\n",c);
									c =  sin(c*PI/180);
									printf("答えは%lfです。\n",c);
								break;
								case'c':
									printf("cos%2fを計算します。\n",c);
									c =  cos(c*PI/180);
									printf("答えは%lfです。\n",c);
								break;
								case't':
									printf("tan%2fを計算します。\n",c);
									c =  tan(c*PI/180);
									printf("答え%lfです。\n",c);
								break;
								case'r':
									printf("√%2fを計算します。\n",c);
									c =  sqrt(c);
									printf("答えは%lfです。\n",c);
								break;
								default:							//関数モードの例外処理
			                    printf("演算子が間違っています\n");
							}
						break;
						default:									//演算子選択の例外処理
			            printf("演算子が間違っています\n");
						}
					printf("\n今回の計算結果を用いる場合はaを、用いない場合や終了したい場合はそれ以外を入力してください。");
	            	scanf("\n%c",&y);								//繰り返すかどうかのフラグ判定
				}
				
		}else;
		printf("終了しますか？\n1以外の数字を入力すると終了します。");
		scanf("%d",&a);						//フラグaを立てるか否か
		
	}
}