/*******************************/
//
//o—Í‚³‚ê‚½—”‚Ì•½‹Ï’l‚ğ‹‚ß‚é
//‘å‚«‚¢‡”Ô‚É•À‚×‘Ö‚¦‚Ä•\¦‚·‚é
//
/*******************************/

#include <stdio.h>
#include<stdlib.h>
#define n 100	//—”‚ÌŒÂ”
#define m 100	//—”‚ÌãŒÀ

int main(){
	int i, x[n];
	int j,k;
	int all=0;
	int result;
	double ave;
	char name[]="RandomData.txt";
	
	FILE *fp;
	fp = fopen(name,"w");
	fclose(fp);
	
	srand((unsigned)time(NULL));
	
	
	for(i=0;i<n;i++){
		x[i] = (int)( rand() / (double)RAND_MAX * m);
		all = all + x[i];
	}
	
	for(k=0;k<n-1;k++){
    	for(j=n-1;j>k;j--){
      		if(x[j-1]<x[j]){
        	int d=x[j-1];
			x[j-1]=x[j];
			x[j]=d;
      		}
      	}
	}
	
	fp= fopen(name,"a");
	for(i=0;i<n;i++){
		printf("%d\n",x[i]);
		result = fprintf(fp,"%d\n",x[i]);
	}
	fclose(fp);
	
	ave = all/i;
	printf("%f\n",ave);
	
	return 0;
}
