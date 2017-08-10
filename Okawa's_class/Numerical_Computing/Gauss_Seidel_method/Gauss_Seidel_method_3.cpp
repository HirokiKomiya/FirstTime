#include <stdio.h>
#include<string.h>

double get_x1(double x2,double x3)
{
	return((10-x2-x3)/5);
}
double get_x2(double x1,double x3)
{
	return((12-x1-x3)/4);
}
double get_x3(double x1,double x2)
{
	return((13-x1*2-x2)/3);
}

int main(){
	int i=0;	//カウンター
	int times;	//試行回数
	
	int flag_x1=0;	//収束判定のモード
	int flag_x2=0;
	int flag_x3=0;
	
	double x1[1000],x2[1000],x3[1000];
	double dif_x1;	//x1の差
	double dif_x2;	//x2の差
	double dif_x3;	//x3の差
	
	FILE *fp;		//ファイルのポインタ
	
	char FileName[] = "data1.txt";
	
	//ファイルがない場合は強制的に新規作成をする。
	fp = fopen(FileName,"a");
	fscanf(fp,"%d",);
	fclose(fp);
	
	/*初期値を代入させる*/
	printf("x1の初期値を入力してください。(少数第7桁を四捨五入します。)\n");
	scanf("\n%lf",&x1[0]);
	printf("x2の初期値を入力してください。(少数第7桁を四捨五入します。)\n");
	scanf("\n%lf",&x2[0]);
	printf("x3の初期値を入力してください。(少数第7桁を四捨五入します。)\n");
	scanf("\n%lf",&x3[0]);
	
	/*最大回数の入力*/
	printf("最大試行回数を入力してください(1000回まで)\n");
	scanf(" %d",&times);
	
	/*初期値の出力*/
	printf("round: 0 (%12.10f,%12.10f,%12.10f)\n",x1[0],x2[0],x3[0]);
	
	/*試行*/
	for(i=0;i<times;i++){
		x1[i+1]=get_x1(x2[i],x3[i]);
		x2[i+1]=get_x2(x1[i+1],x3[i]);
		x3[i+1]=get_x3(x1[i+1],x2[i+1]);
		printf("round:%2d (%12.10f,%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1],x3[i+1]);
		
		dif_x1=x1[i]-x1[i+1];
		dif_x2=x2[i]-x2[i+1];
		dif_x3=x3[i]-x3[i+1];
		
		
		/*収束条件を判定*/
		if(dif_x1<=0.0000000001 && dif_x1>=-0.0000000001){
				flag_x1=1;
		}
		if(dif_x2<=0.0000000001 && dif_x2>=-0.0000000001){
				flag_x2=1;
		}
		if(dif_x3<=0.0000000001 && dif_x3>=-0.0000000001){
				flag_x3=1;
		}
		
		/*すべての収束条件を満たせば終了*/
		if(flag_x1==1 && flag_x2==1 && flag_x3==1){
			printf(" 収束しました。\n");
			printf(" 試行回数は、%d回です。\n",i);
			break;
		}
		//試行回数上限により終了
		else{
			if(times==i+1){
				printf(" 収束しませんでした。\n");
				printf(" 試行回数は、%d回です。\n",i+1);	//for文の関係で上限まで試行しなかった場合回数が1少なくなる
			}
		}
	}

}

/**********************************/
//課題はこれを2×2から10×10で使えるように。
//式を外部から読み込むようにすると良し
//きれいに分かりやすく書こう
//収束発散判定部分をつけること・・・OK！
//ソースコー実行結果、数値解析に関する考察を含めること
/**********************************/
