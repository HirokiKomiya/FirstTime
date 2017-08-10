#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MICHI "city021"		//���m�̃f�[�^
#define KIJUN "city022"		//���m�̃f�[�^
#define VER "ver3_4_2"
#define B1 100
#define B2 70

#define JIGEN 15			//������

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
		printf("�t�@�C�����J���܂���\n");
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


//DP Matching

double DP(CepstData MichiData, CepstData KichiData){
	int i,j,k;
	double d[140][140],d1[140][140],d2[140][140],g[140][140];
	double num0,num1,num2,num3,num4;
	
	for(i=0;i<MichiData.size;i++){
		for(j=0;j<KichiData.size;j++){
			
			if(j>(i-B2) && j<(i+B1)){
				d[i][j]=0;	//�����l
				d1[i][j]=0;	//�����l
				d2[i][j]=0;	//�����l
				//�Ǐ������̌v�Z
				for(k=0;k<JIGEN;k++){
					d[i][j] += pow(MichiData.data[i][k] - KichiData.data[j][k], 2);
				}
				
				if(i!=0){
					for(k=0;k<JIGEN;k++){
						d1[i][j] += pow(MichiData.data[i-1][k] - KichiData.data[j][k], 2);
					}
				}
				
				if(j!=0){
					for(k=0;k<JIGEN;k++){
						d2[i][j] += pow(MichiData.data[i][k] - KichiData.data[j-1][k], 2);
					}
				}
				
				d[i][j] = sqrt(d[i][j]);
				//d=�Ǐ�����
				
				d1[i][j] = sqrt(d1[i][j]);
				d2[i][j] = sqrt(d2[i][j]);
				
				if(i==0 && j==0){
					g[i][j] = d[i][j];
				}else{
					if(i==0){
						g[i][j] = g[i][j-1] + d[i][j];
					}else{
						if(j==0){
							g[i][j] = g[i-1][j] + d[i][j];
						}else{
							if(i>1&&j>1){
								num0 = g[i-1][j] + d[i][j];
								num1 = g[i-1][j-1] + sqrt(2.0*d[i][j]);
								num2 = g[i-1][j-2] + d[i][j];
								num3 = g[i-2][j-1] + d1[i][j];
								num4 = g[i-1][j-2] + d2[i][j];
								g[i][j] = min5(num0,num1,num2,num3,num4);
							}else{
								num0 = g[i-1][j] + d[i][j];
								num1 = g[i-1][j-1] + sqrt(2.0*d[i][j]);
								num2 = g[i][j-1] + d[i][j];
								g[i][j] = min3(num0,num1,num2);
							}
						}
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
	char filename1[60];
	double g;
	double min;
	char City[20];
	char City1[20];
	
		
	FILE *file;
	sprintf(filename1,"MissingList_%s_%s_%s.txt",VER,MICHI,KIJUN);
	file = fopen(filename1,"w");
	fprintf(file,"�@�@�@�@�@���s�������X�g��\n\n");
	fprintf(file,"�@�@���m�f�[�^\t | \t�@�@���m�f�[�^\n");
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
	
	printf("�}�b�`���O����\n");
	file = fopen(filename1,"a+");
	
	if(count==100)
		fprintf(file,"�@�@�@�@NONE\t | \t�@�@�@NONE\n");
	
	fprintf(file,"\n�F������ %3d%�ł�\n",count);
	fclose(file);
	
	return 0;
}

