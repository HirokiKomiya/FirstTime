#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define tem "city011"
#define unk "city012"
#define frame 200
#define dimension 15

typedef struct{
	char name[20];//名前
	char word[20];//言葉
	int frame_size;//フレームサイズ
	double MFCC[frame][dimension];//データ保存
}data;

data template_data;
data unknow_data;

//送られた構造体の中身を表示する関数
void confirmation(data confirmation_data)
{
	int i,j;
	printf("%s\n",confirmation_data.name);
	printf("%s\n",confirmation_data.word);
	printf("%d\n",confirmation_data.frame_size);
	for(i = 0;i < confirmation_data.frame_size; i++)
	{
		for(j=0; j < dimension; j++)
		{
			printf("%lf",confirmation_data.MFCC[i][j]);
		}
		printf("\n");
	}
}

//ファイルの読み込みを行う関数
data File_Read(char *file_name)
{
	FILE *file;
	data read_data;
	
	int i,j;
	//printf("%s\n",file_name);			//開くファイル名の確認
	file = fopen(file_name,"r");
	if(file == NULL)					//ファイルが読み込めない場合＿終了
	{
		printf("ファイルが開けません\n");
		exit(1);
	}
	
	fscanf(file,"%s\n",read_data.name);
	fscanf(file,"%s\n",read_data.word);
	fscanf(file,"%d\n",&read_data.frame_size);
	
	for(i = 0;i < read_data.frame_size; i++)
	{
		for(j=0; j < dimension; j++)
		{
			fscanf(file,"%lf",&read_data.MFCC[i][j]);
		}
	}
	
	fclose(file);
	
	//confirmation(read_data);//読み込んだデータを確認
	
	return read_data;
}

double road(double po_1,double po_2,double po_3)
{
	if(po_1 < po_2)
	{
		if(po_1 < po_3){return po_1;}
		else {return po_3;}
	}
	else
	{
		if(po_2 <po_3){return po_2;}
		else {return po_3;}
	}
}

//DPマッチングを行う関数
double DP()
{
	int i,j,k;
	double d[frame][frame],g[frame][frame];
	double po_1,po_2,po_3;
	
	for(i = 0; i < template_data.frame_size; i++)
	{
		for(j = 0; j < unknow_data.frame_size; j++)
		{
			d[i][j] = 0;
			for(k = 0; k < dimension; k++)
			{
				d[i][j] += pow(template_data.MFCC[i][k] - unknow_data.MFCC[j][k],2);
			}
			d[i][j] = sqrt(d[i][j]);
			
			if(i == 0 && j == 0){g[i][j] = d[i][j];}
			else if(i == 0){g[i][j] = g[i][j- 1 ] + d[i][j];}
			else if(j == 0){g[i][j] = g[i - 1][j] + d[i][j];}
			else
			{
				po_1 = g[i][j - 1] + d[i][j];
				po_2 = g[i - 1][j - 1] + 2 * d[i][j];//sqrt(2)*d[i][j]
				po_3 = g[i-1][j] + d[i][j];
				
				g[i][j] = road(po_1,po_2,po_3);
			}
		}
	}
	return g[template_data.frame_size - 1][unknow_data.frame_size - 1] / (template_data.frame_size + unknow_data.frame_size);
}

int main(void)
{
	int i,j,count = 0;
	char file_name[20],word[20];
	double g;
	double min=0;
	for(i=0; i < 100; i++)
	{
		printf("%3d番",i+1);
		sprintf(file_name,"%s\\%s_%03d.txt",tem,tem,i+1);
		//printf("%s\n",file_name);//開くファイル名を確認
		template_data = File_Read(file_name);
		//confirmation(template_data);//テンプレートのデータ確認
		for(j = 0; j < 100; j++)
		{
			sprintf(file_name,"%s\\%s_%03d.txt",unk,unk,j+1);
			//printf("%s\n",file_name);//開くファイル名の確認
			unknow_data = File_Read(file_name);
			//confirmation(unknow_data);//未知入力のデータ確認
			g=DP();
			
			if(j==0 || min > g)
			{
				min = g;
				strcpy(word,unknow_data.word);
			}
			
		}
		printf("%15s | %15s ",template_data.word,word);
		if(strcmp(template_data.word,word)==0)
		{
			printf("o\n");
			count++;
		}
		else{printf("x\n");}
	}
	
	printf("テンプレート：%s 未知入力：%s 認識率 %3d\n",tem,unk,count);
	
	return 0;
}