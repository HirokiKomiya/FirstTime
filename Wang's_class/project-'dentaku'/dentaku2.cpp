#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.1415926
main()
{
	int a=1,b;
	double c,w;
	char z,y,x;
	int ran,rana,d,t;										//その他のモードで使用する変数
	
	while(a==1){
	    printf("\n演算子を選択して下さい。\n足し算:+、引き算:-、掛け算:*、割り算:/、関数電卓:a、Extraモード:q\n");
	    scanf("\n%c",&z);
		ran = rand();
		switch(z){
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
			case'a':
				printf("関数電卓モードです。\nsin:s、cos:c、tan:t、√:\n行いたい計算に合わせてコロンの後の文字を入力してください。");
				scanf("\n%c",&z);
				switch(z){
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
					default:
			        printf("演算子が間違っています\n");
				}
			break;
			case'q':												//その他のモード
				printf("Extraモードです。\nジャンケンモード:a、連続計算モード:b、自立起爆モード:c\n");
				scanf("\n%c",&x);
				switch(x){											//その他のモード振り分け
					case'a':
						while(x=='a'){									//ジャンケンモード
							printf("ジャンケンモードです。\n");
							ran = rand();								//ランダム関数
							rana = ran % 3;
							printf("グー:0、チョキ:1、パー:2\n");			//自分が出す目
							scanf("\n%d",&d);
							switch(rana){
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
							scanf("\n%c",&x);
						}
						break;
						case'b':								//その他のモード２
							printf("連続計算モードです。\nこのモードでは四則演算のみ、一括計算ができます。ただし掛け算割り算は優先されません。");
							
							
							/*配列電卓を入れる。*/
							
						break;
						case'c':								//その他のモード３
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
							}else{
								printf("自立起爆が否決されました。\n");
							}
						break;
						default:
						printf("そのモードはないよ\n");
				}
			break;
			default:
			printf("演算子が間違っています\n");
			}
			if(z != 'q' | z=='s'){
				printf("\n今回の計算結果を用いる場合はaを、用いない場合や終了したい場合はそれ以外を入力してください。");
				scanf("\n%c",&y);
				while(y == 'a'){
					printf("\n演算子を選択して下さい。\n足し算:+、引き算:-、掛け算:*、割り算:/、関数電卓:a\n");
			        scanf("\n%c",&z);
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
						    printf("答えは%2fです。\n",c);		//割る値が0の時にはブレイクしよう
							}else
							printf("0では割れません。\n");
						break;
						case'a':
							printf("関数電卓モードです。\nsin:s、cos:c、tan:t、√:r\n行いたい計算に合わせてコロンの後の文字を入力してください。");
							scanf("\n%c",&z);
							switch(z){
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
								default:
			                    printf("演算子が間違っています\n");
							}
						break;
						default:
			            printf("演算子が間違っています\n");
						}
					printf("\n今回の計算結果を用いる場合はaを、用いない場合や終了したい場合はそれ以外を入力してください。");
	            	scanf("%c",&y);
				}
				
		}else
		printf("終了しますか？\n1以外の数字を入力すると終了します。");
		scanf("%d",&a);
		
	}
	printf("終了しますか？\n1以外の数字を入力すると終了します。");
		scanf("%d",&a);
}