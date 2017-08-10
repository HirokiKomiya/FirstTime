#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define InGold 10000	//初期資金
#define InPay 1	//初期掛け金
#define n 1000	//試行回数上限
#define m 6	//乱数の上限
#define Multi 5	//掛け金の乗数


int main(){
	int r;
	int pay;	//掛け金
	int gold;	//所持金
	int sum1;
	int sum2;
	int dice1;
	int dice2;
	int count=0;	//カウンター
	int score;
	int TotalWon=0;
	int flag=0;	//終了フラグ
	double WinPercet;
	double IncomeRatio;
	
	srand((int)time(NULL));
	
	pay=InPay;
	gold=InGold - InPay;
	
	printf("ROUND：%4d，所持金：%5d，掛け金：%5d\n",count,gold,pay);
	
	for(count=0;count<n;count++){
		dice1=(int)( rand() / (double)RAND_MAX * m);
		dice2=(int)( rand() / (double)RAND_MAX * m);
		
		sum1 = dice1 + dice2;
		
		if(sum1==7 | sum1==11){	//ナチュラル（勝ち）
			r=0;
		}else if(sum1==2 | sum1==3 | sum1==12){	//クラップス（負け）
			r=0;
		}else{	//ポイント（さいころ交代）
			sum2=0;
			r=0;
			while(sum2 != 7){
				dice1=(int)( rand() / (double)RAND_MAX * m);
				dice2=(int)( rand() / (double)RAND_MAX * m);
				sum2=dice1 + dice2;
				if(sum2==sum1){
					r=1;
					break;
				}
			}
		}
		if(r){
			gold = gold + pay*2;
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
	WinPercet=(double)(TotalWon)/n*100;
	IncomeRatio=(double)(gold)/InGold;
	printf("\n　試行結果まとめ　\n");
	printf("　初期資金：%d\n",InGold);
	printf("　乗数%d倍\n",Multi);
	printf("　勝利数：%3d，",TotalWon);
	printf("　勝率：%3f%　\n",WinPercet);
	printf("　収支倍率：%3f倍\n　",IncomeRatio);
	printf("\n");
}


