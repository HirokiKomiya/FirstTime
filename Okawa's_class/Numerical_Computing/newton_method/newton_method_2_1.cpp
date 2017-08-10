//各仮の解のy切片を同時に求める
//与える関数のマクロ化

#include <stdio.h>
#include<math.h>

//定数はdefineで
#define EPS 0.000001	//very small value

//最大繰り返し回数
#define NMAX 100	//max number of iteration

#define PI 3.141592

//与える式をマクロ関数として定義
#define func(x) (x*x - 1)	//引数に型はいらない
#define deri(x) (2*x)


double f(double x){		//プロトタイプ宣言が必要ない
	return(func(x));	//例題
}

//導関数	微分できるものはそのまま入れてしまおう
double df(double x){
	return(deri(x));	//例題
}

//各仮の解のy切片を求める関数
double fb(double x,double df1){
	return(-x*df1);
}


void newton(double x){
	int n = 0;
	int count = 0;	//カウンター
	double b=0;
	double delta;
	double result;
	double df1;
	char Name[]="newton_data_x.txt";
	char Namea[]="newton_data_a.txt";
	char Nameb[]="newton_data_b.txt";
	int mode=0;
	
	FILE *fp;
	fp = fopen(Name,"w");
	fp = fopen(Namea,"w");
	fp = fopen(Nameb,"w");
	fclose(fp);
	do{
		delta = -f(x) /df(x);
		x += delta;
		df1=df(x);
		b = fb(x,df1);
		
		count++;	//インクリメント演算子　n=n+1と同じ意味
		printf("round:%d,x:%f\n",count,x);
		fp = fopen(Name,"a");
		result = fprintf(fp,"round:%d,x:%f\n",count,x);
		fclose(fp);
		
		fp = fopen(Namea,"a");
		result = fprintf(fp,"%f\n",df1);	//接線の傾き
		fclose(fp);
		
		fp = fopen(Nameb,"a");
		result = fprintf(fp,"%f\n",b);	//接戦のy切片
		fclose(fp);
		
		//中身を確認するprintfを入れる
		if(fabs(x)>10000000000000000){	//桁あふれによるエラーを防ぐ
			mode = 1;
			break;
		}
	}while(fabs(delta) > EPS && count< NMAX);
	
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
//プログラムのOSに

//return 0;	←エラーなく終了したことを示す

/************************************************/
//解くべき方程式は関数という形で埋め込んでしまう
//初期値のみ外部からで他はすべて埋め込む
//いろいろな非線型関数で試す
//	解が複数あるもの
//	解が求まらないもの
/*************************************************/
