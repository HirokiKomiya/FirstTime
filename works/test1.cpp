//************************************//
//
//����:sample.txt
//
//�e���p�����̌����J�E���g
//
//**********************************//


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define kaigyou 0
#define other 1


int counter[300]={0};
char file_name[] = "sample.txt";
char file_name1[]= "step1.txt";


FILE *fp;
FILE *fp1;

void henkan(FILE *fp)
{
	char num;
	
	/* �t�@�C���I�[�v�� */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	while ((num = getc(fp)) != EOF){
		if((fp1 = fopen(file_name1, "a+")) == NULL)
				fprintf(stderr,"%s", "error: can't read file.");
		if(mbscmp(�A,num)==0){
			fprintf(fp1,"%c",',');
			fclose(fp1);
		}else{
			if(strcmp(num,'�B')==0){
				fprintf(fp1,"%c",'.');
				fclose(fp1);
			}else{
				fprintf(fp1,"%c",num);
				fclose(fp1);
			}
		}
	}
	
	fclose(fp);
}



void main(void)
{
	FILE *fp;
	
	if ((fp = fopen(file_name, "r")) == NULL) {		/* �t�@�C�����J���Ȃ���� */
		fprintf ( stderr, "Can't Open File\n" );
		exit (2);									/* �I�� */
	}
	henkan(fp) ;		/* �����̏o���p�x�𒲂ׂ� */
	fclose(fp);			/* �t�@�C������� */
}
