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

#define kaigyou 0
#define other 1

#define renzoku 1	//�������A���œǂނ�

FILE *fp;
FILE *fp1;

int counter[1000];
char file_name[] = "NYT.txt";
char file_name1[]= "NoMarkSample.txt";

void RemoveMark(FILE *fp){
	int num;
	
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	while ((num = getc(fp)) != EOF){
		//printf("%d ",num);
		
		if((fp1 = fopen(file_name1, "a+")) == NULL)
				fprintf(stderr,"%s", "error: can't read file.");
		
		if(isalpha(num)){
			counter[num]++;
			fprintf(fp1,"%c",num);
			fclose(fp1);
			
		}else{
			if(num=='\n'){
				counter[kaigyou]++;
				fprintf(fp1,"%c",' ');
				fclose(fp1);
			}else{
				if(num==' '){
					counter[other]++;
					fprintf(fp1,"%c",num);
					fclose(fp1);
				}else{
					counter[other]++;
					fclose(fp1);
				}
			}
		}
	}
	fclose(fp);
}


void PrintResult(void){
	int num;
	
	for (num = 'a'; num <= 'z'; num++)			/* �������̏o���p�x�� */
		printf("%c:%2d\t",  num, counter[num]);	/* �\�� */
	printf("\n\n");
	
	for (num = 'A'; num <= 'Z'; num++)			/* �啶���̏o���p�x�� */
		printf("%c:%2d\t",  num, counter[num] );/* �\�� */
	printf("\n\n");
	
	printf("���s:%2d\n",counter[0]);
	printf("other:%2d\n",counter[1]);
	
	printf("\n");
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
	
	printf("�ϊ����ł�...\n");
	RemoveMark(fp);
	printf("�ϊ�����\n");
	
	
	if ((fp = fopen(file_name, "r")) == NULL) {		/* �t�@�C�����J���Ȃ���� */
		fprintf ( stderr, "Can't Open File\n" );
		exit (2);									/* �I�� */
	}
	printf("\n");
	printf("%s�̊e�����̏o���p�x�\\n",file_name);
	PrintResult();		/* �\������ */
	fclose(fp);			/* �t�@�C������� */
}
