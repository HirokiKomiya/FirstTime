/*登録と閲覧*/

#include<stdio.h>
#include<string.h>

struct person{
	char	name[40];
	char	address[100];
	long	phone;
};


int main(void)
{
	struct person student[100];
	int mode, l, i = 0, n = 1;
	int lan = 0;
	
	FILE  *fp, *pw;
	char  filename[] = "data_test.txt";
	
	char  pass[100];
	char  type[100];
	char  Npass[100] = "NewPass";
	char  Cpass[100];
	
	int   key = 0;
	int   k = 0;
	int   end = 0;
	
	char  str1[100]  = {'\0'};
	char  str2[40]   = "name";
	long  str3       = {'\0'};
	char  str4[100]  = {'\0'}; //(仮)
	char  str5[40]   = {'\0'}; //(仮)
	long  str6       = {'\0'}; //(仮)
	
	printf("登録と 閲覧\n\n");
	
	printf("【 English:1 日本語:2 中国:3 】\n");
	printf("Language:");
	scanf("%d", &lan);
	
	if(lan == 0){
	scanf(" %s",type);
	}
	for(k=0;k<4;k++){
		pw = fopen("password.txt", "r");
		fscanf(pw, "%s", pass);
		
		switch(lan){
			case 1:
				printf("\n***【 NewPass 】Change Password Key ***\n\n");
				printf("Password:");
			break;
			
			case 2:
				printf("\n***【 NewPass 】パスワード変更キー ***\n\n");
				printf("パスワード:");
			break;
			
			case 3:
				printf("\n***【 NewPass 】蜜碼更改関鍵 ***\n\n");
				printf("蜜碼:");
			break;
			
			default:
				printf("\n***【 NewPass 】Change Password Key ***\n\n");
				printf("Password:");
			break;
		}
		
		scanf("%s", &type);
		
		if(strcmp(pass, type)==0){//パスワード入力
			switch(lan){
				case 1:
					printf("\n\n≪  H E L L O  ≫\n\n");
				break;
				
				case 2:
					printf("\n\n≪  よ う こ そ  ≫\n\n");
				break;
				
				case 3:
					printf("\n\n≪  歓 迎   ≫\n\n");
				break;
				
				default:
					printf("\n\n≪  H E L L O  ≫\n\n");
				break;
			}
			
			key = 1;
			k = 5;
		}else if(strcmp(Npass, type)==0){//新規パスワード
			//旧パスワード確認
			switch(lan){
				case 1:
					printf("\nOld Password:");
				break;
				
				case 2:
					printf("\n旧パスワード:");
				break;
				
				case 3:
					printf("\n旧蜜碼:");
				break;
				
				default:
					printf("\nOld Password:");
				break;
			}
			
			scanf("%s", &type);
			//確認完了
			if(strcmp(pass, type)==0){
				fclose(pw);
				pw = fopen("password.txt", "w");
				
				switch(lan){
					case 1:
						printf("\n***【 NewPass 】Not Available! ***\n\n");
						printf("New Password:");
					break;
					
					case 2:
						printf("\n***【 NewPass 】はパスワードに使用できない ***\n\n");
						printf("新パスワード:");
					break;
					
					case 3:
						printf("\n***【 NewPass 】它不能在密碼中使用! ***\n\n");
						printf("新密碼:");
					break;
					
					default:
						printf("\n***【 NewPass 】Not Available! ***\n\n");
						printf("New Password:");
					break;
				}
				
				scanf("%s", &pass);
				
				switch(lan){
					case 1:
						printf("\nConfirm Password:");
					break;
					
					case 2:
						printf("\n確認パスワード:");
					break;
					
					case 3:
						printf("\n確認蜜碼:");
					break;
					
					default:
						printf("\nOld Password:");
					break;
				}
				
				scanf("%s", &Cpass);
				
				if(strcmp(Cpass, pass)==0){
					switch(lan){
						case 1:
							printf("\n≪ Complete ≫\n");
						break;
						
						case 2:
							printf("\n≪ 登録完了 ≫\n");
						break;
						
						case 3:
							printf("\n≪ 注冊完了 ≫\n");
						break;
						
						default:
							printf("\n≪ Complete ≫\n");
						break;
					}
					
					fprintf(pw, "%s", pass);
					k = 0;
				}else{
					//三回失敗すると終了
					switch(lan){
						case 1:
							printf("\n≪ Different ≫\n");
						break;
						
						case 2:
							printf("\n≪ 確認できません ≫\n");
						break;
						
						case 3:
							printf("\n≪ 無法證實 ≫\n");
						break;
						
						default:
							printf("\n≪ Different ≫\n");
						break;
					}
					
					
				}
			//確認不正
			}else{
				switch(lan){
					case 1:
						printf("\n≪ Different ≫\n");
					break;
					
					case 2:
						printf("\n≪ 確認できません ≫\n");
					break;
					
					case 3:
						printf("\n≪ 無法證實 ≫\n");
					break;
					
					default:
						printf("\n≪ Different ≫\n");
					break;
				}
			}
			
		}else{
			switch(k){
				case 0:
					switch(lan){
						case 1:
							printf("\n\n　 　　＿＿＿＿　\n　　／　    ―   ＼\n　／ ノ　　 ( ●)　＼\n ｜　( ●)　　　⌒  |\n ｜　　（__ノ￣　　 /　Who are U?-3-\n ｜　　　　　　　  /\n　＼＿　　　⊂ヽ∩＼\n　　　/´　　(,＿＼.＼\n　 　/   　　 ＼＿ノ\n\n");
						break;
						
						case 2:
							printf("\n\n　 　　＿＿＿＿　\n　　／　    ―   ＼\n　／ ノ　　 ( ●)　＼\n ｜　( ●)　　　⌒  |\n ｜　　（__ノ￣　　 /　どちら様ですか?-3-\n ｜　　　　　　　  /\n　＼＿　　　⊂ヽ∩＼\n　　　/´　　(,＿＼.＼\n　 　/   　　 ＼＿ノ\n\n");
						break;
						
						case 3:
							printf("\n\n　 　　＿＿＿＿　\n　　／　    ―   ＼\n　／ ノ　　 ( ●)　＼\n ｜　( ●)　　　⌒  |\n ｜　　（__ノ￣　　 /　誰?-3-\n ｜　　　　　　　  /\n　＼＿　　　⊂ヽ∩＼\n　　　/´　　(,＿＼.＼\n　 　/   　　 ＼＿ノ\n\n");
						break;
						
						default:
							printf("\n\n　 　　＿＿＿＿　\n　　／　    ―   ＼\n　／ ノ　　 ( ●)　＼\n ｜　( ●)　　　⌒  |\n ｜　　（__ノ￣　　 /　Who are U?-3-\n ｜　　　　　　　  /\n　＼＿　　　⊂ヽ∩＼\n　　　/´　　(,＿＼.＼\n　 　/   　　 ＼＿ノ\n\n");
						break;
					}
					
				break;
				
				case 1:
					switch(lan){
						case 1:
							printf("\n\n　　   ／￣￣￣￣＼\n　  ／　─　　  ─  ＼\n  ／　 （●）　 （●）＼  Are U fooling me?-2-\n |　　　 （__人__）     |\n  ＼　　　 ｀ ⌒´　　／\n ／　　　　　　　     ＼\n");
						break;
						
						case 2:
							printf("\n\n　　   ／￣￣￣￣＼\n　  ／　─　　  ─  ＼\n  ／　 （●）　 （●）＼  ちょっと勘弁してくださいよ... -2-\n |　　　 （__人__）     |\n  ＼　　　 ｀ ⌒´　　／\n ／　　　　　　　     ＼\n");
						break;
						
						case 3:
							printf("\n\n　　   ／￣￣￣￣＼\n　  ／　─　　  ─  ＼\n  ／　 （●）　 （●）＼  什麼是錯的?-2-\n |　　　 （__人__）     |\n  ＼　　　 ｀ ⌒´　　／\n ／　　　　　　　     ＼\n");
						break;
						
						default:
							printf("\n\n　　   ／￣￣￣￣＼\n　  ／　─　　  ─  ＼\n  ／　 （●）　 （●）＼  Are U fooling me?-2-\n |　　　 （__人__）     |\n  ＼　　　 ｀ ⌒´　　／\n ／　　　　　　　     ＼\n");
						break;
					}
					
				break;
				
				case 2:
					switch(lan){
						case 1:
							printf("\n\n      _＿＿__________\n　　／　　        　 ＼\n  ／　　　_ノ　   ヽ、_＼\n／ 　　 （●） 　（●）  |\n|　 　　 　 （__人__）　 |  Are U silly？-1-\n /　　　　 ∩ノ ⊃　   ／\n(　 ＼　／ ＿ノ　|　|\n.＼　“　　／＿＿|　|  \n　 ＼   ／  ＿＿＿ ／ \n");
						break;
						
						case 2:
							printf("\n\n      _＿＿__________\n　　／　　        　 ＼\n  ／　　　_ノ　   ヽ、_＼\n／ 　　 （●） 　（●）  |\n|　 　　 　 （__人__）　 |  お巡りさん、此奴です。-1-\n /　　　　 ∩ノ ⊃　   ／\n(　 ＼　／ ＿ノ　|　|\n.＼　“　　／＿＿|　|  \n　 ＼   ／  ＿＿＿ ／ \n");
						break;
						
						case 3:
							printf("\n\n      _＿＿__________\n　　／　　        　 ＼\n  ／　　　_ノ　   ヽ、_＼\n／ 　　 （●） 　（●）  |\n|　 　　 　 （__人__）　 |  回顧... -1-\n /　　　　 ∩ノ ⊃　   ／\n(　 ＼　／ ＿ノ　|　|\n.＼　“　　／＿＿|　|  \n　 ＼   ／  ＿＿＿ ／ \n");
						break;
						
						default:
							printf("\n\n      _＿＿__________\n　　／　　        　 ＼\n  ／　　　_ノ　   ヽ、_＼\n／ 　　 （●） 　（●）  |\n|　 　　 　 （__人__）　 |  Are U silly？-1-\n /　　　　 ∩ノ ⊃　   ／\n(　 ＼　／ ＿ノ　|　|\n.＼　“　　／＿＿|　|  \n　 ＼   ／  ＿＿＿ ／ \n");
						break;
					}
					
				break;
			}
		}
		fclose(pw);
	}
	
	while(key){
		printf("\n\n");
		printf("***************************************************************************\n");
		printf("\n");
		switch(lan){
			case 1:
				printf("【 Writing:1 Reading:2 Serching:3 Delete:4 】\n【 End:0 】 \n\n");
				printf("Select:");
			break;
			
			case 2:
				printf("【 登録:1 閲覧:2 検索:3 】\n【 終了:0 】 \n\n");
				printf("選択:");
			break;
			
			case 3:
				printf("【 定位:1 瀏覽:2 搜:3 】\n【 完:0 】 \n\n");
				printf("選擇:");
			break;
			
			default:
				printf("【 Writing:1 Reading:2 Serching:3 】\n【 End:0 】 \n\n");
				printf("Select:");
			break;
		}
		
		scanf("%d", &mode);
		
		switch(mode){
			//終了
			case 0:
				key = 0;
				end = 1;
			break;
			//書き込み
			case 1:
				l=1;
				
				switch(lan){
					case 1:
						printf("\n≪New Account≫\n\n");
					break;
					
					case 2:
						printf("\n≪新規登録≫\n\n");
					break;
					
					case 3:
						printf("\n≪新註冊≫\n\n");
					break;
					
					default:
						printf("\n≪New Account≫\n\n");
					break;
				}
				
				while(l){
					fp = fopen(filename, "a");
					
					switch(lan){
						case 1:
							printf("name:");
						break;
						
						case 2:
							printf("名前:");
						break;
						
						case 3:
							printf("命名:");
						break;
						
						default:
							printf("name:");
						break;
					}
					
					scanf("%s", &student[i].name);
					
					switch(lan){
						case 1:
							printf("address:");
						break;
						
						case 2:
							printf("アドレス:");
						break;
						
						case 3:
							printf("住址:");
						break;
						
						default:
							printf("address:");
						break;
					}
					
					scanf("%s", &student[i].address);
					
					switch(lan){
						case 1:
							printf("phone number:");
						break;
						
						case 2:
							printf("電話番号:");
						break;
						
						case 3:
							printf("電話號碼:");
						break;
						
						default:
							printf("phone number:");
						break;
					}
					
					scanf("%ld", &student[i].phone);
					
					fprintf(fp, "%s %s %ld\n", student[i].name, student[i].address, student[i].phone);
					
					fclose(fp);
					
					switch(lan){
						case 1:
							printf("\n【 Countinue:1 End:0 】\n");
							printf("Select:");
						break;
						
						case 2:
							printf("\n【 入力を続ける:1 終了:0 】\n");
							printf("選択:");
						break;
						
						case 3:
							printf("\n【 延續:1 完:0 】\n");
							printf("選擇:");
						break;
						
						default:
							printf("\n【 Countinue:1 End:0 】\n");
							printf("Select:");
						break;
					}
					
					scanf("%d", &l);
					
					i++;
					
					switch(lan){
						case 1:
							printf("\n≪ Complete ≫\n\n");
						break;
						
						case 2:
							printf("\n≪ 登録完了 ≫\n\n");
						break;
						
						case 3:
							printf("\n≪ 注冊完了 ≫\n\n");
						break;
						
						default:
							printf("\n≪ Complete ≫\n\n");
						break;
					}
					
				}
			break;
			//閲覧
			case 2:
				switch(lan){
					case 1:
						printf("\n≪ Display ≫\n\n");
					break;
					
					case 2:
						printf("\n≪ 閲覧 ≫\n\n");
					break;
					
					case 3:
						printf("\n≪ 瀏覽 ≫\n\n");
					break;
					
					default:
						printf("\n≪ Display ≫\n\n");
					break;
				}
				
				
				fp = fopen(filename, "r");
				
				n=1;
				
				while(n){
					fscanf(fp, "%s %s %ld", str1, str2, &str3);
					
					//同じadressかどうか判定
					if(strcmp(str2, str5)==0){
						n = 0;
					}else{
						printf("%s %s %ld\n", str1, str2, str3);
					}
					
					strcpy(str2, str5);
					
				}
				
				fclose(fp);
			break;
			//検索
			case 3:
				//name検索
				switch(lan){
					case 1:
						printf("Searching name:");
					break;
					
					case 2:
						printf("名前検索:");
					break;
					
					case 3:
						printf("名稱檢索:");
					break;
					
					default:
						printf("Searching name:");
					break;
				}
				
				scanf("%s", &str4);
				
				switch(lan){
					case 1:
						printf("\n≪ Result ≫\n\n");
					break;
					
					case 2:
						printf("\n≪ 検索結果 ≫\n\n");
					break;
					
					case 3:
						printf("\n≪ 搜索結果 ≫\n\n");
					break;
					
					default:
						printf("\n≪ Result ≫\n\n");
					break;
				}
				
				fp = fopen(filename, "r");
				
				n=1;
				
				while(n){
					fscanf(fp, "%s %s %ld", str1, str2, &str3);
					
					//str1の中からstr4にあたる個所があるか検索
					if(strstr(str1, str4) != NULL && fscanf(fp,"%s ", str1) != EOF){
						printf("%s %s %ld\n", str1, str2, str3);
						n=1;
						printf("\n%s",str2);
					}else if(strcmp(str2,str5) == 0  | fscanf(fp,"%s",str1) == EOF){
						switch(lan){
							case 1:
								printf("≪ None... ≫");
							break;
							
							case 2:
								printf("≪ 該当なし... ≫");
							break;
							
							case 3:
								printf("≪ 不適用... ≫");
							break;
							
							default:
								printf("≪ None... ≫");
							break;
						}
						
						n = 0;
						printf("\n%s",str2);
					}
					
					strcpy(str2, str5);
					
					
				}
				
				fclose(fp);
			break;
			
			default:
				switch(lan){
					case 1:
						printf("Error\n\n");
					break;
					
					case 2:
						printf("対応出来ません\n\n");
					break;
					
					case 3:
						printf("錯誤\n\n");
					break;
				}
			break;
		}
	}
	if(end == 1){
		//正規終了
		switch(lan){
			case 1:
				printf("\n	  　 ________\n　　　　　/　　　　　　＼\n　 _　 ／ ⌒           ⌒＼ \n　( | /   -==、       (●)ヽ  　Thank U for playing！ \n　| |｜   ⌒    (_人_) ⌒  | \n|￣)ヽ＼         ヽノ     ノ \n|￣) | /　　      　　　＼\n");
			break;
			
			case 2:
				printf("\n	  　 ________\n　　　　　/　　　　　　＼\n　 _　 ／ ⌒           ⌒＼ \n　( | /   -==、       (●)ヽ  　また、いつでも開いてくれ！ \n　| |｜   ⌒    (_人_) ⌒  | \n|￣)ヽ＼         ヽノ     ノ \n|￣) | /　　      　　　＼\n");
			break;
			
			case 3:
				printf("\n	  　 ________\n　　　　　/　　　　　　＼\n　 _　 ／ ⌒           ⌒＼ \n　( | /   -==、       (●)ヽ  　謝謝, 再見！ \n　| |｜   ⌒    (_人_) ⌒  | \n|￣)ヽ＼         ヽノ     ノ \n|￣) | /　　      　　　＼\n");
			break;
			
			default:
				printf("\n	  　 ________\n　　　　　/　　　　　　＼\n　 _　 ／ ⌒           ⌒＼ \n　( | /   -==、       (●)ヽ  　Thank U for playing！ \n　| |｜   ⌒    (_人_) ⌒  | \n|￣)ヽ＼         ヽノ     ノ \n|￣) | /　　      　　　＼\n");
			break;
		}
	}else{
		//不正終了
		switch(lan){
			case 1:
				printf("     ＿＿＿＿＿\n　 ／ 　　　　  ＼\n ／　 ─ 　　 ― ヽ　Overe the rainbow...\n|　（ ●） （ ●）\n|　　　（_人_）　 |\n ＼　　　　　　　／\n ／　　　　　　　ヽ( :3\n 　　　　　　　　(;　:3\n 　　 i　　／＾r ￣￣i\n 　　 l　 /　 ノ、＿ノ\n 　　 l ／　　r 　　l");
			break;
			
			case 2:
				printf("     ＿＿＿＿＿\n　 ／ 　　　　  ＼\n ／　 ─ 　　 ― ヽ　おととい来な\n|　（ ●） （ ●）\n|　　　（_人_）　 |\n ＼　　　　　　　／\n ／　　　　　　　ヽ( :3\n 　　　　　　　　(;　:3\n 　　 i　　／＾r ￣￣i\n 　　 l　 /　 ノ、＿ノ\n 　　 l ／　　r 　　l");
			break;
			
			case 3:
				printf("     ＿＿＿＿＿\n　 ／ 　　　　  ＼\n ／　 ─ 　　 ― ヽ　閃爍\n|　（ ●） （ ●）\n|　　　（_人_）　 |\n ＼　　　　　　　／\n ／　　　　　　　ヽ( :3\n 　　　　　　　　(;　:3\n 　　 i　　／＾r ￣￣i\n 　　 l　 /　 ノ、＿ノ\n 　　 l ／　　r 　　l");
			break;
			
			default:
				printf("     ＿＿＿＿＿\n　 ／ 　　　　  ＼\n ／　 ─ 　　 ― ヽ　Overe the rainbow...\n|　（ ●） （ ●）\n|　　　（_人_）　 |\n ＼　　　　　　　／\n ／　　　　　　　ヽ( :3\n 　　　　　　　　(;　:3\n 　　 i　　／＾r ￣￣i\n 　　 l　 /　 ノ、＿ノ\n 　　 l ／　　r 　　l");
			break;
		}
	}
	
	return 0;
}
