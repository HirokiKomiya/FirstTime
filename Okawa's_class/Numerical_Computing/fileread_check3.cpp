#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(void){
	FILE *fp;
	char Name[] = "data1.txt";
	char data[10][10];
	char data1[10][10];
	int i=0,j=0;
	int rst;
	
	int n[500];
	int nc;	//�J�E���^�[
	int row=10;
	int mode=0;
	
	
	//fp = fopen(Name,"a");
	//fclose(fp);
	fp = fopen(Name,"r+");
	
	for(nc=0;nc<500;nc++){
		if(row==i)
			break;
		fscanf(fp,"%c",&data[i][j]);
		n[nc] = atoi(&data[i][j]);
		
		//������0��5�������Ȃ�����p���B
		
		if(n[nc]==0 && n[nc-1]==0 && n[nc-2]==0 && n[nc-3]==0&& n[nc-4]==0){
			
			i=i+1;
			row=j-5;	//�s�͗�-1�̐���
			j=0;
			printf("nc=%d\n",n[nc]);
			mode=1;
			
		}else{
			printf("(%c,[%d][%d])",data[i][j],i,j);
			j=j+1;
		}
	}
	fclose(fp);
}

//�擪�A�܂��͍Ō����0������Ƃ��܂������Ȃ�
