/******************************************************/
//　
//　InGold	:初期資金
//　Inpay	:最初の賭け金
//　Multi	:負けた後に賭け金を何倍にするか
//　n		:試行上限回数
//　Mode	:モードに関しては以下を参照
//　MaxPay	:一回の払い出しがこの払い出しを超えたら終了
//　MaxRatio:この収支割合を超えたら終了する

//　↓モードの説明↓
//　
//　mode0:試行回数上限まで実行
//　mode1:資金が尽きたら終了
//　mode2:初期資金の半分以上の払い出しで終了
//　mode3:mode1+mode2
//　mode4:mode1+MaxPay以上の払い出しで終了
//　mode5:mode1+MaxRatio以上の収支割合で終了
//　
/******************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define InGold 1000000	//初期資金
#define InPay 1	//初期賭け金
#define n 1000	//試行回数上限
#define Multi 2	//掛け金の乗数
#define Mode 0	//試行モード
#define MaxPay 10000
#define MaxRatio 1.0003

#define Max 6		//乱数の上限（変更不可）
#define Min 1

int main(){
	int r;
	int pay;	//掛け金
	int gold;	//所持金
	int sum1;	//さいころの合計
	int sum2;	//ポイント時のさいころの合計
	int dice1;	//さいころ1
	int dice2;	//さいころ2
	int count=0;//カウンター
	int TotalWon=0;	//勝利数
	int flag=0;		//終了フラグ
	double WinPercet;	//勝率
	double IncomeRatio;	//収支割合
	
	srand((int)time(NULL));
	
	pay=InPay;
	gold=InGold - InPay;
	
	printf("ROUND：%4d，所持金：%5d，掛け金：%5d\n",count,gold,pay);
	
	switch(Mode){
		case 0:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//ナチュラル（勝ち）
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//クラップス（負け）
					r=0;
				}else{	//ポイント（さいころ交代）
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
					pay=1;
					printf("ROUND：%4d，所持金：%5d，勝敗：勝ち，次ゲームの掛け金:%7d\n",count+1,gold,pay);
					TotalWon=TotalWon++;
				}else{
					gold = gold - pay;
					pay = pay*Multi;
					printf("ROUND：%4d，所持金：%5d，勝敗：負け，次ゲームの掛け金:%7d\n",count+1,gold,pay);
				}
				
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n　試行結果まとめ　\n");
			printf("　初期資金：%d\n",InGold);
			printf("　勝利数：%3d，",TotalWon);
			printf("　勝率：%3f%　\n",WinPercet);
			printf("　収支倍率：%3f倍\n　",IncomeRatio);
			printf("\n");
		break;
		
		case 1:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//ナチュラル（勝ち）
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//クラップス（負け）
					r=0;
				}else{	//ポイント（さいころ交代）
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
					pay=1;
					printf("ROUND：%4d，所持金：%5d，勝敗：勝ち，次ゲームの掛け金:%7d\n",count+1,gold,pay);
					TotalWon=TotalWon++;
				}else{
					gold = gold - pay;
					pay = pay*Multi;
					printf("ROUND：%4d，所持金：%5d，勝敗：負け，次ゲームの掛け金:%7d\n",count+1,gold,pay);
				}
				
				if(gold<0){
					printf("所持金が尽きました\n");
					break;
				}
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n　試行結果まとめ　\n");
			printf("　初期資金：%d\n",InGold);
			printf("　勝利数：%3d，",TotalWon);
			printf("　勝率：%3f%　\n",WinPercet);
			printf("　収支倍率：%3f倍\n　",IncomeRatio);
			printf("\n");
			
		break;
		
		case 2:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//ナチュラル（勝ち）
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//クラップス（負け）
					r=0;
				}else{	//ポイント（さいころ交代）
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
					if(pay>=InGold/2){
						flag=1;
					}
					pay=1;
					printf("ROUND：%4d，所持金：%5d，勝敗：勝ち，次ゲームの掛け金:%7d\n",count+1,gold,pay);
					TotalWon=TotalWon++;
					
				}else{
					gold = gold - pay;
					pay = pay*Multi;
					printf("ROUND：%4d，所持金：%5d，勝敗：負け，次ゲームの掛け金:%7d\n",count+1,gold,pay);
				}
				
				if(flag)
					break;
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n　試行結果まとめ　\n");
			printf("　初期資金：%d\n",InGold);
			printf("　乗数%d倍\n",Multi);
			printf("　勝利数：%3d，",TotalWon);
			printf("　勝率：%3f%　\n",WinPercet);
			printf("　収支倍率：%3f倍\n　",IncomeRatio);
			printf("\n");
		break;
		
		case 3:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//ナチュラル（勝ち）
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//クラップス（負け）
					r=0;
				}else{	//ポイント（さいころ交代）
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
					if(pay>=InGold/2){
						flag=1;
					}
					pay=1;
					printf("ROUND：%4d，所持金：%5d，勝敗：勝ち，次ゲームの掛け金:%7d\n",count+1,gold,pay);
					TotalWon=TotalWon++;
					
				}else{
					gold = gold - pay;
					pay = pay*Multi;
					printf("ROUND：%4d，所持金：%5d，勝敗：負け，次ゲームの掛け金:%7d\n",count+1,gold,pay);
				}
				if(gold<0){
					printf("所持金が尽きました\n");
					break;
				}
				if(flag)
					break;
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n　試行結果まとめ　\n");
			printf("　初期資金：%d\n",InGold);
			printf("　乗数%d倍\n",Multi);
			printf("　勝利数：%3d，",TotalWon);
			printf("　勝率：%3f%　\n",WinPercet);
			printf("　収支倍率：%3f倍\n　",IncomeRatio);
			printf("\n");
		break;
		case 4:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//ナチュラル（勝ち）
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//クラップス（負け）
					r=0;
				}else{	//ポイント（さいころ交代）
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
					if(pay>=MaxPay){
						flag=1;
					}
					pay=1;
					printf("ROUND：%4d，所持金：%5d，勝敗：勝ち，次ゲームの掛け金:%7d\n",count+1,gold,pay);
					TotalWon=TotalWon++;
					
				}else{
					gold = gold - pay;
					pay = pay*Multi;
					printf("ROUND：%4d，所持金：%5d，勝敗：負け，次ゲームの掛け金:%7d\n",count+1,gold,pay);
				}
				if(gold<0){
					printf("所持金が尽きました\n");
					break;
				}
				if(flag)
					break;
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n　試行結果まとめ　\n");
			printf("　初期資金：%d\n",InGold);
			printf("　乗数%d倍\n",Multi);
			printf("　勝利数：%3d，",TotalWon);
			printf("　勝率：%3f%　\n",WinPercet);
			printf("　収支倍率：%3f倍\n　",IncomeRatio);
			printf("\n");
		break;
		case 5:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//ナチュラル（勝ち）
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//クラップス（負け）
					r=0;
				}else{	//ポイント（さいころ交代）
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
					pay=1;
					printf("ROUND：%4d，所持金：%5d，勝敗：勝ち，次ゲームの掛け金:%7d\n",count+1,gold,pay);
					TotalWon=TotalWon++;
					IncomeRatio=(double)(gold)/InGold;
					if(IncomeRatio>MaxRatio){
						flag=1;
					}
				}else{
					gold = gold - pay;
					pay = pay*Multi;
					printf("ROUND：%4d，所持金：%5d，勝敗：負け，次ゲームの掛け金:%7d\n",count+1,gold,pay);
				}
				if(gold<0){
					printf("所持金が尽きました\n");
					break;
				}
				if(flag)
					break;
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n　試行結果まとめ　\n");
			printf("　初期資金：%d\n",InGold);
			printf("　乗数%d倍\n",Multi);
			printf("　勝利数：%3d，",TotalWon);
			printf("　勝率：%3f%　\n",WinPercet);
			printf("　収支倍率：%3f倍\n　",IncomeRatio);
			printf("\n");
		break;
		
		default:
			printf("ModeError");
			exit(0);
		break;
	}
}


