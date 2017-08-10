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

#define kaigyou 0
#define other 1


int counter[300]={0};
char file_name[] = "sample.txt";


void mojicount(FILE *fp)
{
	int num;
	
	/* �t�@�C���I�[�v�� */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	
	while ((num = getc(fp)) != EOF){
		if(isalpha(num)){
			counter[num]++;
		}else{
			if(num=='\n'){
				counter[kaigyou]++;
			}else{
				counter[other]++;
			}
		}
	}
	
	fclose(fp);
}

void PrintResult(void){
	int i,j,tmp;
	int num;
	
	for (num = 'a'; num <= 'z'; num++)
		printf("%c:%2d\t",  num, counter[num]);	/* �\�� */
	printf("\n\n");
	
	for (num = 'A'; num <= 'Z'; num++)			/* �啶���̏o���p�x�� */
		printf("%c:%2d\t",  num, counter[num] );	/* �\�� */
	printf("\n\n");
	
	printf("���s:%2d\n",counter[kaigyou]);
	printf("other:%2d\n",counter[other]);
	
	printf("\n");
}

void WriteForText(void){
	
}

void main(void)
{
	FILE *fp;
	
	if ((fp = fopen(file_name, "r")) == NULL) {		/* �t�@�C�����J���Ȃ���� */
		fprintf ( stderr, "Can't Open File\n" );
		exit (2);									/* �I�� */
	}
	printf("\n");
	printf("%s�̊e�����̏o���p�x�\\n",file_name);
	mojicount(fp) ;		/* �����̏o���p�x�𒲂ׂ� */
	PrintResult();		/* �\������ */
	fclose(fp);			/* �t�@�C������� */
}
