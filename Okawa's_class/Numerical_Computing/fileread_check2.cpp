#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(void){
	FILE *fp;
	char Name[] = "data1.txt";	//�f�[�^�̎Q�Ɛ�
	char data[10][10];
	char data1[10][10];
	int i=0,j=0;
	int rst;
	int n;
	int row=10;
	
	fp = fopen(Name,"a");
	fclose(fp);		//�t�@�C�����Ȃ��ꍇ�̏���
	
	fp = fopen(Name,"r+");
	
	while(i<=10){
		if(row==i)		
			break;
		fscanf(fp,"%c",&data[i][j]);
		n = atoi(&data[i][j]);
		
		
		if(n==0){
			i=i+1;
			row=j-1;	//�s�͗�-1�̐���
			j=0;
			printf("\n");
		}else{
			printf("(%c,[%d][%d])",data[i][j],i,j);
			j=j+1;
		}
	}
	fclose(fp);
}
