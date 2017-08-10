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
#define func(x) ((x-1)*(x+1))	//扱う関数をここに入力

#include <stdio.h>
#include <math.h>
#include <float.h>	//FLT_EPSILONのために呼び出す

#define EPS 0.000001	//very small value
#define NMAX 100		//max number of iteration
#define PI 3.141592		//π
#define dfMAX 10


//導関数
double df(double x){
	double dy,dfx;
	double dx = FLT_EPSILON;
	dy  = -func(x+2*dx)+8*func(x+dx)-8*func(x-dx)+func(x-2*dx);	//前後の差をとる
	dfx = dy/(dx*12);
	
	printf("dy=%f dfx=%f\n",dy,dfx);	//チェック用
	
	if(dfx!=0){
	return(dfx);
	/*↓0割防止↓*/
	}else{
		x=x+0.1;
		printf("(初期)値を%fに変更しました。\n",x);
		dy  = -func(x+2*dx)+8*func(x+dx)-8*func(x-dx)+func(x-2*dx);	//前後の差をとる
		dfx = dy/(dx*2);
		return(dfx);
	}
}


double df_count(void){
	double a;
	int count  = 0 ;
	int count1 = 0;
	double df1;
	double df2[100];
	
	for(a=-dfMAX;a<dfMAX;){
		//printf("%f",a);		チェック用
		df1 = df(a);
		if(df1==0){
			df2[count] = df1;
			count = count+1;
		}
		a=a+0.1;
	}
	printf("変曲点は%d個です。\n",count);
	for(count1=0;count1<count;count1++){
		printf("%10.7f\n",df2[count1]);
	}
}


//各仮の解のy切片を求める関数
double fb(double x,double df1){
	return(-x*df1);
}

//Newton-Raphson Method 関数定義
void newton(double x){
	int count = 0;	//カウンター
	char Name [] ="newton_data_x.txt";	//近似解
	char Namea[]="newton_data_a.txt";	//接線の傾き＝微分
	char Nameb[]="newton_data_b.txt";	//接線のy切片
	double df1;
	double b = 0;	//y差分
	double delta;	//近似解の差分
	double result;
	
	FILE *fp;
	
	fp = fopen(Name ,"w");
	fp = fopen(Namea,"w");
	fp = fopen(Nameb,"w");
	fclose(fp);
	
	fp = fopen(Name ,"a");
	result = fprintf(fp,"%f\n",x);
	fclose(fp);
	
	printf("round:%3d,x:%13f\n",count,x);
	do{
		df1   = df(x);	//傾き
		delta = -func(x) /df1;		//差分の計算
		
		//printf("%f ",df1);	//チェック用
		
		x += delta;		//解の更新
		b  = fb(x,df1);
		count++;
		
		printf("round:%3d,x:%13f\n",count,x);
		
		/*各データの保存*/
		fp = fopen(Name ,"a");
		result = fprintf(fp,"%f\n",x);	//近似解
		fclose(fp);
		
		fp = fopen(Namea,"a");
		result = fprintf(fp,"%f\n",df1);//接線の傾き
		fclose(fp);
		
		fp = fopen(Nameb,"a");
		result = fprintf(fp,"%f\n",b);	//接戦のy切片
		fclose(fp);
		/*データの保存ここまで*/
		
		//桁あふれによるエラーを防ぐ
		if(fabs(x)<-10000000000000000 | fabs(x)>10000000000000000){
			printf("解が見つかりませんでした。(Overflow)\n");
			break;
		}
	}while(fabs(delta) > EPS && count< NMAX);
	
	
	/*最終結果の出力部分*/
	if(count==NMAX){
		printf("解が見つかりませんでした。\n");
	}else{
		printf("\n解が見つかりました\n");
		printf("x = %f\n",x);
	}
	/*出力ここまで*/
}

int main(){
	double x;
	printf("input initial value->");
	//scanf("%lf",&x);
	df_count();
	//newton(x);	/*newton method*/
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

