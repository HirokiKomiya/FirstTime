//2点で接線表示

#include <stdio.h>
#include<math.h>

//定数はdefineで
#define EPS 0.000001	//very small value

//最大繰り返し回数
#define NMAX 100		//max number of iteration

#define PI 3.141592

double f(double x){		//プロトタイプ宣言が必要ない
	return(x*x - 4);	//例題
}

//導関数	微分できるものはそのまま入れてしまおう
double df(double x){
	return(2*x);	//例題
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
	double f1;
	char Name[]="newton_data_x.txt";
	char Namey[]="newton_data_y.txt";
	char Name1[]="newton_data_x1.txt";
	char Name2[]="newton_data_x(No_count).txt";
	
	int mode=0;
	
	FILE *fp;
	fp = fopen(Name,"w");
	fp = fopen(Namey,"w");
	fp = fopen(Name1,"w");
	fp = fopen(Name2,"w");
	fclose(fp);
	
	fp = fopen(Name,"a");
	result = fprintf(fp,"round:%d,x:%f\n",count,x);
	fclose(fp);
	fp = fopen(Name2,"a");
	result = fprintf(fp,"%f\n",x);
	fclose(fp);
	
	do{
		delta = -f(x) /df(x);
		f1=f(x);
		x += delta;
		
		count++;	//インクリメント演算子　n=n+1と同じ意味
		printf("round:%d,x:%f\n",count,x);
		
		fp = fopen(Name,"a");
		result = fprintf(fp,"round:%d,x:%f\n",count,x);
		fclose(fp);
		
		fp = fopen(Name2,"a");
		result = fprintf(fp,"%f\n",x);
		fclose(fp);
		
		fp = fopen(Namey,"a");
		result = fprintf(fp,"%f\n",f1);	//接線の傾き
		fclose(fp);
		
		fp = fopen(Name1,"a");
		result = fprintf(fp,"%f\n",x);
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

//return 0;	←エラーなく終了したことを示す

/************************************************/
//解くべき方程式は関数という形で埋め込んでしまう
//初期値のみ外部からで他はすべて埋め込む
//いろいろな非線型関数で試す
//	解が複数あるもの
//	解が求まらないもの
/*************************************************/
