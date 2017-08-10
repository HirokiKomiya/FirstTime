#include <stdio.h>
#include<string.h>
#include<stdlib.h>

//coefficient matrix(係数行列)の[11]成分＝co1_1

//2
double get_x1_2(double x2,double co1_1,double co1_2,double y_1)
{
	return((y_1-x2*co1_2)/co1_1);
}
double get_x2_2(double x1,double co2_1,double co2_2,double y_2)
{
	return((y_2-x1*co2_1)/co2_2);
}

//3

double get_x1_3(double x2,double x3,double co1_1,double co1_2,double co1_3,double y_1)
{
	return((y_1-x2*co1_2-x3*co1_3)/co1_1);
}
double get_x2_3(double x1,double x3,double co2_1,double co2_2,double co2_3,double y_2)
{
	return((y_2-x1*co2_1-x3*co2_3)/co2_2);
}
double get_x3_3(double x1,double x2,double co3_1,double co3_2,double co3_3,double y_3)
{
	return((y_3-x1*co3_1-x2*co3_2)/co3_3);
}


int main(){
	int count=0;	//カウンター
	int times;	//試行回数
	
	int flag_x1=0;	//収束判定のモード
	int flag_x2=0;
	int flag_x3=0;
	
	double x1[1000],x2[1000],x3[1000];
	double dif_x1;	//x1の差
	double dif_x2;	//x2の差
	double dif_x3;	//x3の差
	
	FILE *fp;		//ファイルのポインタ
	double result;
	char data[10][10];
	char data1[10][10];
	int i=0,j=0;
	int rst;
	int n[500];
	int nc;	//カウンター
	int row=10;
	char Name[] = "data3.txt";
	char Name1[] = "data_x1.txt";
	char Name2[] = "data_x2.txt";
	char Name3[] = "data_x3.txt";
	
	//ファイルがない場合は強制的に新規作成をする。
	fp = fopen(Name,"a");
	fclose(fp);
	fp = fopen(Name,"r+");
	
	for(nc=0;nc<500;nc++){
		if(row==i)
			break;
		fscanf(fp,"%c",&data[i][j]);
		n[nc] = atoi(&data[i][j]);
		
		//成分に0が5が続かない限り継続。
		
		if(n[nc]==0 && n[nc-1]==0 && n[nc-2]==0 && n[nc-3]==0&& n[nc-4]==0){
			
			i=i+1;
			row=j-5;	//行は列-1個の成分
			j=0;
			//printf("nc=%d\n",n[nc]);
			
		}else{
			
			j=j+1;
		}
	}
	fclose(fp);
	printf("　読み込んだ係数行列は以下の通りです。\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;++j){
			printf("(%c,[%d][%d])",data[i][j],i,j);
		}
		printf("\n");
	}
	
		
	//チェック用
	/*for(nc=0;nc<20;nc++){
		printf("n[%d]=%d\n",nc,n[nc]);
	}*/
	
	printf("\n扱う変数の個数を入力して下さい。(2から10まで)\n");
	printf("3\n");
	
	/*初期値を代入させる*/
	printf("x1の初期値を入力してください。(少数第7桁を四捨五入します。)\n");
	scanf("\n%lf",&x1[0]);
		fp = fopen(Name1,"a");
		result = fprintf(fp, "%12.10f\n",x1[0]);
		fclose(fp);
		
		fp = fopen(Name2,"a");
		printf("x2の初期値を入力してください。(少数第7桁を四捨五入します。)\n");
		scanf("\n%lf",&x2[0]);
		result = fprintf(fp, "%12.10f\n",x2[0]);
		fclose(fp);
		
		fp = fopen(Name3,"a");
		printf("x3の初期値を入力してください。(少数第7桁を四捨五入します。)\n");
		scanf("\n%lf",&x3[0]);
		result = fprintf(fp, "%12.10f\n",x3[0]);
		fclose(fp);
	/*最大回数の入力*/
	/*printf("最大試行回数を入力してください(1000回まで)\n");
	scanf(" %d",&times);*/
	times=30;
		
	/*初期値の出力*/
	printf("round: 0 (%12.10f,%12.10f,%12.10f)\n",x1[0],x2[0],x3[0]);
	
	
	/*試行*/
	for(count=0;count<times;count++){
		x1[count+1]=get_x1_3(x2[count],x3[count],n[0],n[1],n[2],n[3]);
		fp = fopen(Name1,"a");
		result = fprintf(fp, "%12.10f\n",x1[count+1]);
		fclose(fp);
		
		x2[count+1]=get_x2_3(x1[count+1],x3[count],n[9],n[10],n[11],n[12]);
		fp = fopen(Name2,"a");
		result = fprintf(fp, "%12.10f\n",x2[count+1]);
		fclose(fp);
		
		x3[count+1]=get_x3_3(x1[count+1],x2[count+1],n[18],n[19],n[20],n[21]);
		fp = fopen(Name3,"a");
		result = fprintf(fp, "%12.10f\n",x3[count+1]);
		fclose(fp);
		
		printf("round:%2d (%12.10f,%12.10f,%12.10f)\n",count+1,x1[count+1],x2[count+1],x3[count+1]);
		
		dif_x1=x1[count]-x1[count+1];
		dif_x2=x2[count]-x2[count+1];
		dif_x3=x3[count]-x3[count+1];
		
		
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
		/*if(flag_x1==1 && flag_x2==1 && flag_x3==1){
			printf(" 収束しました。\n");
			printf(" 試行回数は、%d回です。\n",count+1);
			break;
		}
		//試行回数上限により終了
		else{*/
			if(times==count+1){
				printf(" 収束しませんでした。\n");
				printf(" 試行回数は、%d回です。\n",count+1);	//for文の関係で上限まで試行しなかった場合回数が1少なくなる
			}
		//}
	}
}

/**********************************/
//課題はこれを2×2から10×10で使えるように。
//式を外部から読み込むようにすると良し
//きれいに分かりやすく書こう
//収束発散判定部分をつけること・・・OK！
//ソースコー実行結果、数値解析に関する考察を含めること
/**********************************/
