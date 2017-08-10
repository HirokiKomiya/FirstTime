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


int counter[1000];
char file_name[] = "NoMarkSample.txt";
int mojisu=0;
int mojinomi=0;

void mojicount(FILE *fp)
{
	int num;
	
	/* �t�@�C���I�[�v�� */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	
	while ((num = getc(fp)) != EOF){
		mojisu++;
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
	
	mojinomi=mojisu-other;
}

void PrintResult(void){
	int num;
	
	
	for (num = 'a'; num <= 'z'; num++)			/* �������̏o���p�x�� */
		printf("%c:%2d\t",  num, counter[num]);	/* �\�� */
	printf("\n\n");
	
	for (num = 'A'; num <= 'Z'; num++)			/* �啶���̏o���p�x�� */
		printf("%c:%2d\t",  num, counter[num] );	/* �\�� */
	printf("\n\n");
	
	printf("���s:%2d\n",counter[0]);
	printf("other:%2d\n",counter[1]);
	
	printf("�S��(�󔒂��܂�):%2d\n",mojisu);
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
