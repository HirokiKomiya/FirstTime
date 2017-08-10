#include<stdio.h>
#include<string.h>

void main(void){
	FILE *fp;
	char Name[] = "data1.txt";
	char data[10][10];
	char data1[10][10];
	int i=0,j=0;
	char E1[]="a";
	
	//fp = fopen(Name,"a");
	//fclose(fp);
	fp = fopen(Name,"r+");
	
	while(i<=10){
		fscanf(fp,"%c",&data[i][j]);
		if(strcmp("E",&data[i][j])==0)		//同じやつが二つつずいたら終了
			break;
		//ifbreakはprintfの前に入れないと最後のやつが二つ出てくる。
		printf("%c",data[i][j]);
		
		if(strcmp(&data[i][j],"\n")==0){
			i=i+1;
			printf("\n");
			j=0;
		}else{
		j=j+1;
		}
	}
	fclose(fp);
}
