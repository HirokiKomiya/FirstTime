//************************************//
//
//����:NoMarkSample.txt
//
//
//NL1_2�Ɠ��l�̋@�\�B
//���̓t�@�C���̋L������菜��
//���̌��ʂ��o�̓t�@�C���ɃR�s�[����
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

struct eitango{
	char tango[100];
	int kosu;
};

int counter[1000];
char file_name[] = "NoMarkSample.txt";
char file_name1[]= "NoMarkSample.txt";

int a=0;

void mojicount(FILE *fp)
{
	char num;
	int i=0,j=0;
	char tyukan[100];	
	int mojisu;
	char check_word[100];
	
	struct eitango word;
	
	
	printf("check%d\n",a);
	a++;
	
	/* �t�@�C���I�[�v�� */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	printf("check%d\n",a);
	a++;
	
	while ((num = getc(fp)) != EOF){
		printf("whilecheck1\n");
		
		if(num != ' '){
			printf("whilecheck2\n");
			
			//�X�y�[�X������܂Œ��Ԃɕ�������
			tyukan[i] = num;
			i++;
		}
		
		check_word=tyukan;
		
		for (j = 0; ; j++){ 
			//�����P�ꂾ�����當���̃J�E���g�𑝂₷ 
			if ( strcmp(word[j].tango,check_word) == 0){
				word[j].kosu++;
				break;
			}
		//���܂łɂȂ��P�ꂾ������V�����\���̂ɕۑ� 
		if (j == i){ 
			strcpy(word[i].tango, check_word); 
			word[j].kosu++;
			i++;
			break;
		}
		
		printf("%s",tyukan);
	}
	
	printf("check%d\n",a);
	a++;
	
	fclose(fp);
}


void main(void)
{
	int a=0;
	printf("\n");
	printf("%s�̊e�����̏o���p�x�\\n",file_name);
	mojicount(fp) ;		/* �����̏o���p�x�𒲂ׂ� */
	//PrintResult();		/* �\������ */
	fclose(fp);			/* �t�@�C������� */
}
