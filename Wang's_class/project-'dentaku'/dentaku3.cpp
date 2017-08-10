#include<stdio.h>
#include<math.h>
#include<string.h> //これに関してはググる

#define PI 3.1415926
main()
{
	double a[100];						//数字の配列の宣言
	double *b = a;						//数字の参照設定
	char c[100];						//文字の配列宣言
	char *d = c; 						//演算子の参照設定
	int i=0;							//何回目のか
	double tashizan(double e, double f);	//プロトタイプ宣言
	double hikizan(double e, double f);
	double kakezan(double e, double f);
	double warizan(double e, double f);
	double sina(double e);
	double cosa(double e);
	double tana(double e);
	double rutoa(double e);
	
	
	
	printf("割る値に0を入力した場合は、その割り算は計算されません\n");
	
		while(*(d+i-1) != '='){
			scanf(" %lf",&*(b+i));
			//printf(" \n%f",*(b+i));
			scanf(" %c",&*(d+i));
			//printf("%c",*(d+i));
				if(i != 0){
					switch(*(d+i-1)){
						case'+':
						*(b+i) = tashizan(*(b+i-1),*(b+i));
						//printf(" \n");
						break;
						case'-':
						*(b+i) = hikizan(*(b+i-1),*(b+i));
						break;
						case'*':
						*(b+i) = kakezan(*(b+i-1),*(b+i)); 
						break;
						case'/':
						if(*(b+i) != 0){
						*(b+i) = warizan(*(b+i-1),*(b+i));		//割る値が0の時にはブレイクしよう
						}else
						*(b+i) = *(b+i-1);
						break;
						
						case' ':								//' 'が入力されたら関数モード
						scanf(" %c",&*(d+i));
							switch(*(d+i-1)){
							case's':
							printf("sin\n");
							*(b+i) != sin(*(b+i));
							}
						
						break;
						
						default:
						;
						
					}
				}else;
			i++;
			//printf("次のiは%d\n",i);
		}
	i=i-1;
	printf("計算結果は%lfです。\n",*(b+i) );
}

		//以下、関数宣言

double tashizan(double e, double f){
	return f=e+f;
}
double hikizan(double e, double f){
	return f=e-f;
}
double kakezan(double e, double f){
	return f=e*f;
}
double warizan(double e, double f){
	return f=e/f;
}
double sina(double e){
	return e = sin(e*PI/180);
}
double cosa(double e){
	return e = cos(e*PI/180);
}
double tana(double e){
	return e = tan(e*PI/180);
}
double rutoa(double e){
	return e = sqrt(e);
}