//************************************//
//
//����:sample.txt
//�o��:NoMarkSample.txt
//
//
//NL2_2�Ɠ��l�̋@�\�B
//���̓t�@�C���̋L������菜��
//���̌��ʂ��o�̓t�@�C���ɃR�s�[����
//�J�E���g�͂��Ȃ�
//���s�͔��p�X�y�[�X�ɕϊ�
//���̑��̋L���͍폜
//���p�������p�X�y�[�X�͂��̂܂܃R�s�[
//
//***********************************//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define kaigyou 0
#define other 1

#define renzoku 1	//�������A���œǂނ�

FILE *fp;
FILE *fp1;

int counter[1000];
char file_name[] = "Sample.txt";
char file_name1[]= "A.txt";
int flag=0;

void RemoveMark(FILE *fp){
	int num;
	
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	
	while ((num = getc(fp)) != EOF){
		//printf("%d ",num);
		
		if((fp1 = fopen(file_name1, "a+")) == NULL)
				fprintf(stderr,"%s", "error: can't read file.");
		
		if(isalpha(num)){
			fprintf(fp1,"%c",num);
			fclose(fp1);
			printf("%c",num);
		}else{
			if(num=='\n'){
				if(flag){
					fclose(fp1);
					flag=0;
				}else{
					fprintf(fp1,"%c",' ');
					fclose(fp1);
					printf(" ");
				}
			}else{
				if(num==' '){
					fprintf(fp1,"%c",num);
					fclose(fp1);
					flag=1;
					printf("%c",num);
				}else{
					fclose(fp1);
				}
			}
		}
	}
	fclose(fp);
}

void main(void)
{
	int a=0;
	
	printf("�o�͐�̃t�@�C��������ɂ��Ă��珑�����݂܂����H\n");
	printf("yes:1 no:OTHER\n");
	scanf("%d",&a);
	
	if(a){
		fp = fopen(file_name1, "w+");
		fclose(fp);
	}
	
	printf("�ϊ����ł�...\n\n");
	RemoveMark(fp);
	printf("\n\n�ϊ�����\n");
}
