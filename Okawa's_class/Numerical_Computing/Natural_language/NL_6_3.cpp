//************************************//
//
//����:NoMarkSample.txt
//
//���̓t�@�C���̕����������_���ɏo��
//�@2�����o�[�W����
//�@file_name[]�ɓ��̓t�@�C����
//�@n�ɔ��������镶���̌�
//�@m�ɓ��̓t�@�C���̕�����
//
//**********************************//


#include <stdio.h>
#include <stdlib.h>

int counter[300]={0};
char file_name[] = "NoMarkSample.txt";

#define n 100	//�����̌�
#define m 38000	//�����̏��

void random(FILE *fp){
	
	int i, x;
	int j;
	char num[1000000];
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<n;i++){
		if((fp = fopen(file_name, "r")) == NULL) 
			fprintf(stderr, "%s\n", "error: can't read file.");
		
		//2�܂ł͗]�v�ȃf�[�^����
		x = (int)( rand() / (double)RAND_MAX * m)*2+3;
		
		//printf("%d������:",(x-1)/2);
		
		
		if(x!=3){
			for(j=0;j<x;++j){
				num[j] = getc(fp);
				//printf("%c",num[j]);
			}
			//printf("\n");
			printf("%c",num[x-1]);
			printf("%c",num[x-3]);
			//printf("\n");
		}else
			i=i-1;
	fclose(fp);
	}
}

void main(void){
	int x;
	FILE *fp;
	
	if ((fp = fopen(file_name, "r")) == NULL) {		/* �t�@�C�����J���Ȃ���� */
		fprintf ( stderr, "Can't Open File\n" );
		exit (2);									/* �I�� */
	}
	printf("\n");
	random(fp);
	printf("\n");
}
