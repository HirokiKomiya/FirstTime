#include <stdio.h>

int main(void){
	int i,j;
	int size;
	int a[10][10];
	
	printf("�T�C�Y�H\n");
	scanf("%d",&size);
	
	printf("����\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
		printf("A[%d][%d]= ",i+1,j+1);
		scanf("%d",&a[i][j]);
		}
	}
	
	/*��s��񐬕���a[0][0]�A�Q�s�Q�񐬕���a[1][1]�ɓ���*/
	
	printf("\n�s���\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
		printf("%d",a[i][j]);
		}
		printf("\n");
	}
}
