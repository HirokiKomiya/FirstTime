/*****このプログラムに実装されているもの*****/
//
//近似解、各近似解の接線、接線のy切片の計算
//上記データのテキストファイルへの保存
//各仮の解のy切片を同時に求める
//3点近似による導関数の算出
//与える関数のマクロ化（導関数の算出に用いる
//
/********************************************/

#include <stdio.h>
#include <math.h>
#include <float.h>	//FLT_EPSILONのために呼び出す

//定数はdefineで
#define EPS 0.000001	//very small value

//最大繰り返し回数
#define NMAX 100		//max number of iteration

//円周率
#define PI 3.141592

//与える式(func)と導関数(deri)をマクロ関数として定義
#define func(x) (x*x - 4)	//引数に型はいらない

//関数


//導関数	３点近似。前後の点で挟む
double df(double x){
	//微小量の定義
	double dx = FLT_EPSILON;
	double dy,dfx;
	
	dy = func(x+dx)-func(x-dx);	//前後の差をとる
	dfx = dy/(dx*2);
	//printf("dx=%f ",dx);
	return(dfx);	//例題
}

//各仮の解のy切片を求める関数
double fb(double x,double df1){
	return(-x*df1);
}

//Newton-Raphson Method 関数定義
void newton(double x){
	int count = 0;	//カウンター
	double b = 0;	//y差分
	double delta;	//近似解の差分
	double result;
	double df1;
	char Name[]="newton_data_x.txt";	//近似解
	char Namea[]="newton_data_a.txt";	//接線の傾き＝微分
	char Nameb[]="newton_data_b.txt";	//接線のy切片
	int mode=0;	//解が求まらなかった場合のモード振り分け
	
	FILE *fp;
	fp = fopen(Name,"w");
	fp = fopen(Namea,"w");
	fp = fopen(Nameb,"w");
	fclose(fp);
	
	fp = fopen(Name ,"a");
	result = fprintf(fp,"%f\n",x);
	fclose(fp);
	
	printf("round:%3d,x:%13f\n",count,x);
	do{
		df1 = df(x);	//傾き
		delta = -func(x) /df1;	//差分の計算
		x += delta;		//解の更新
		b = fb(x,df1);	//
		
		count++;	//インクリメント演算子　n=n+1と同じ意味
		printf("round:%d,x:%f\n",count,x);
		
		/*各データの保存*/
		fp = fopen(Name,"a");
		result = fprintf(fp,"round:%d,x:%f\n",count,x);
		fclose(fp);
		
		fp = fopen(Namea,"a");
		result = fprintf(fp,"%f\n",df1);	//接線の傾き
		fclose(fp);
		
		fp = fopen(Nameb,"a");
		result = fprintf(fp,"%f\n",b);		//接戦のy切片
		fclose(fp);
		/*データの保存ここまで*/
		
		if(fabs(x)>10000000000000000){		//桁あふれによるエラーを防ぐ
			mode = 1;
			break;
		}
	}while(fabs(delta) > EPS && count< NMAX);
	//差が十分小さくなるか試行上限回数に達したら終了
	
	if(mode){
		printf("解が見つかりませんでした。(Overflow)\n");
	}else{
		if(count==NMAX){
			printf("解が見つかりませんでした。\n");
		}else{
			printf("\n解が見つかりました\n");
			printf("x = %f\n",x);	//stderrはファイルに入らない
		}
	}
}

int main(){
	double x;
	printf("input initial value->");
	scanf("%lf",&x);
	newton(x);	/*newton method*/
	return 0;
}


//return 0;	←エラーなく終了したことをOSに示す


/***************注意点、改善点、この後の方針等******************/
//
//解くべき方程式は関数という形で埋め込んでしまう
//初期値のみ外部からで他はすべて埋め込む
//微分がめんどくさい場合はどうする？	・・・3点近似の実装済み
//いろいろな非線型関数で試す
//	解が複数あるもの
//	解が求まらないもの
//
/***************************************************************/

