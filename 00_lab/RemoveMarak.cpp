//************************************//
//
//����:sample.txt
//�o��:NoMarkSample.txt
//
//
//NL1_2�Ɠ��l�̋@�\�B
//���̓t�@�C���̋L������菜��
//���̌��ʂ��o�̓t�@�C���ɃR�s�[����
//
//���s�͔��p�X�y�[�X�ɕϊ�
//���̑��̋L���͍폜
//���p�������p�X�y�[�X�͂��̂܂܃R�s�[
//
//***********************************//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define kaigyou 0
#define other 1

#define renzoku 1	//�������A���œǂނ�

FILE *fp;
FILE *fp1;


char file_name[] = "F1F2ALL.txt";
char file_name1[]= "F1F2ALLNoMark.txt";

void RemoveMark(FILE *fp){
	char num[100];
	int num1;
	float num2;
	int check;
	int i=0;
	int flag=0;
	int counter=0;
	
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	while (1){
		printf("Checker1\n");
		fscanf(fp,"%s\n%d\n%f\n\n",num,&num1,&num2);
		check=strcmp(num,"END");
		printf("%s %d %f\n",num,num1,num2);
		if(check==0){
			printf("Checker2\n");
			break;
		}
		
		if((fp1 = fopen(file_name1, "a+")) == NULL){
			printf("Checker3\n");
				fprintf(stderr,"%s", "error: can't read file.");
		}
		
		fprintf(fp1,"%d %d\n",num1,num2);
	}
	fclose(fp);
}


void main(void)
{
	int a=0;
	
	printf("�o�͐�̃t�@�C������ɂ��Ă��珑�����݂܂����H\n");
	printf("yes:1 no:OTHER\n");
	scanf("%d",&a);
	
	if(a){
		fp = fopen(file_name1, "w+");
		fclose(fp);
	}
	
	printf("�ϊ����ł�...\n");
	RemoveMark(fp);
	printf("�ϊ�����\n");
	
}
