/*****このプログラムに実装されているもの*****/
//
//近似解、各近似解の接線、接線のy切片の計算
//上記データのテキストファイルへの保存
//各仮の解のy切片を同時に求める
//５点近似による導関数の算出
//dfx=0の場合の0割り防止を実施
//
/********************************************/

/*(x-1)*(x-2)*(x-3)をx*x*x-6*x*x+11*x-6～と記載するとおかしくなる*/

//与える式(func)をマクロ関数として定義
#define func(x) ((x-1)*(x+1)*(x+2))	//扱う関数をここに入力

#include <stdio.h>
#include <math.h>
#include <float.h>	//FLT_EPSILONのために呼び出す

#define EPS 0.1	//very small value
#define EPS2 0.001
#define NMAX 100		//max number of iteration
#define PI 3.141592		//π
#define dfMAX 10


//導関数
double df(double x){
	double dy,dfx;
	double dx = FLT_EPSILON;
	dy = func(x+dx)-func(x-dx);	//前後の差をとる
	dfx = dy/(dx*2);
	
	//printf("dy=%f dfx=%f\n",dy,dfx);	//チェック用
	
	return(dfx);
}


double df_count(void){
	double a;
	int count  = 0 ;
	int count1 = 0;
	int count2 = 0;
	double df1;
	double df2[100];
	
	for(a=-dfMAX;a<dfMAX;count2++){
		//printf("%f",a);		チェック用
		df1 = df(a);
		if(df1<0.1&&df1>-0.1){
			df2[count] = df1;
			count = count+1;
		}
		a=a+0.00001;
	}
	printf("計算回数は%dです\n",count2);
	printf("変曲点は%d個です。\n",count);
	for(count1=0;count1<count;count1++){
		printf("%.2f\n",df2[count1]);
	}
}


int main(){
	double x;
	//printf("input initial value->");
	//scanf("%lf",&x);
	df_count();
	return 0;
}

/***************注意点、改善点、この後の方針等******************/
//
//解くべき方程式は関数という形で埋め込んでしまう
//初期値のみ外部からで他はすべて埋め込む
//微分がめんどくさい場合はどうする？	・・・５点近似の実装済み
//いろいろな非線型関数で試す
//	解が複数あるもの
//	解が求まらないもの
//
/***************************************************************/

