#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MICHI "city022"		//未知のデータ
#define KIJUN "city021"		//既知のデータ

#define JIGEN 15			//次元数

struct CepstData{
	int size;
	char name[20];
	char city[20];
	double data[200][15];
};

CepstData FileRead(char *filename){
	FILE *file;
	CepstData data;
	
	int i,j;
	
	file = fopen(filename,"r");
	
	if(file == NULL){
		printf("ファイルが開けません\n");
		exit(1);
	}
	
	fscanf(file,"%s\n",data.name);
	fscanf(file,"%s\n",data.city);
	fscanf(file,"%d\n",&data.size);
	
	for(i=0;i<data.size;i++){
		for(j=0;j<JIGEN;j++){
			fscanf(file,"%lf",&data.data[i][j]);
		}
	}
	fclose(file);
	return data;
}
	
double min3(double num0,double num1,double num2){
	if(num0<num1){
		if(num0<num2){
			return num0;
		}else{
			return num2;
		}
	}else{
		if(num1<num2){
			return num1;
		}else{
			return num2;
		}
	}
}

//DP Matching

double DP(CepstData MichiData, CepstData KichiData){
	int i,j,k;
	double d[140][140],g[140][140];
	double num0,num1,num2;
	
	for(i=0;i<MichiData.size;i++){
		for(j=0;j<KichiData.size;j++){
			
			d[i][j]=0;	//初期値
			
			for(k=0;k<JIGEN;k++){
				d[i][j] += pow(MichiData.data[i][k] - KichiData.data[j][k], 2);
			}
			
			d[i][j] = sqrt(d[i][j]);
			
			if(i==0 && j==0){
				g[i][j] = d[i][j];
			}else{
				if(i==0){
					g[i][j] = g[i][j-1] + d[i][j];
				}else{
					if(j==0){
						g[i][j] = g[i-1][j] + d[i][j];
					}else{
						num0 = g[i][j-1] + d[i][j];
						num1 = g[i-1][j-1] + 2.0 * d[i][j];
						num2 = g[i-1][j] + d[i][j];
						
						g[i][j] = min3(num0,num1,num2);
					}
				}
			}
		}
	}
	return g[MichiData.size-1][KichiData.size-1] / (MichiData.size + KichiData.size);
}

int main(){
	CepstData KichiData;
	CepstData MichiData;
	
	int i=0;
	int j=0;
	int count=0;
	
	char filename[60];
	char filename1[40];
	double g;
	double min;
	char City[20];
	char City1[20];
	
		
	FILE *file;
	sprintf(filename1,"MissingList_%s_%s.txt",MICHI,KIJUN);
	file = fopen(filename1,"w");
	fprintf(file,"　　　　　↓不正解リスト↓\n\n");
	fprintf(file,"　　未知データ\t | \t　　既知データ\n");
	fclose(file);
	
	for(i=0;i < 100;i++){
		sprintf(filename,"%s\\%s_%03d.txt",MICHI,MICHI,i + 1);
		MichiData = FileRead(filename);
		
		
		
		for(j=0;j < 100;j++){
			sprintf(filename,"%s\\%s_%03d.txt",KIJUN,KIJUN,j + 1);
			KichiData =  FileRead(filename);
			
			g = DP(MichiData, KichiData);
			if(j==0 || min > g){
				min = g;
				strcpy(City,KichiData.city);
			}
		}
		
		if(strcmp(City,MichiData.city) == 0){
			count++;
		}else{
			FILE *file;
			file = fopen(filename1,"a+");
			
			fprintf(file,"%12s\t | \t%12s\n",MichiData.city,City);
			fclose(file);
		}
	}
	
	printf("マッチング完了\n");
	
	file = fopen(filename1,"a+");
	fprintf(file,"\n認識率は %3d%です\n",count);
	fclose(file);
	
	return 0;
}


