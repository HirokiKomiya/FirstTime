#include <stdio.h>
#include<math.h>

/*
void main(void){
}
*/

/*
main(){
}*/

//定数はdefineで
#define EPS 0.000001	//very small value

//最大繰り返し回数
#define NMAX 100	//max number of iteration

#define PI 3.141592

double f(double x){		//プロトタイプ宣言が必要ない
	return(x/2 + cos(x*PI/180));	//例題
}

//導関数	微分できるものはそのまま入れてしまおう
double df(double x){
	return(1/2 - sin(x*PI/180));	//例題
}


void newton(double x){
	int n = 0;
	int count = 0;	//カウンター
	double delta;
	double result;
	char Name[]="newton_data_x.txt";
	int mode=0;
	
	FILE *fp;
	fp = fopen(Name,"w");
	fclose(fp);
	do{
		delta = -f(x) /df(x);
		x += delta;
		count++;	//インクリメント演算子　n=n+1と同じ意味
		printf("round:%d,x:%f\n",count,x);
		fp = fopen(Name,"a");
		result = fprintf(fp,"round:%d,x:%f\n",count,x);
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
