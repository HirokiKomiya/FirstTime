#include <stdio.h>

int main(void){
	int i,j;
	int size;
	int a[10][10];
	
	printf("サイズ？\n");
	scanf("%d",&size);
	
	printf("入力\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
		printf("A[%d][%d]= ",i+1,j+1);
		scanf("%d",&a[i][j]);
		}
	}
	
	/*一行一列成分はa[0][0]、２行２列成分はa[1][1]に入る*/
	
	printf("\n行列は\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
		printf("%d",a[i][j]);
		}
		printf("\n");
	}
}
