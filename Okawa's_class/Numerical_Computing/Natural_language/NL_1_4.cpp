//************************************//
//
//����:sample.txt
//
//�e���p�����̌����J�E���g
//
//�@�\��1_3�Ɠ��l
//
//�ǉ��@�\
// , . ! ?�𕪂���
//**********************************//


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define zentai 0
#define kaigyou 1
#define kanma 2
#define piriod 3
#define ekus 4
#define kues 5
#define space 6
#define other 7


int counter[300]={0};
char file_name[] = "sample.txt";


void mojicount(FILE *fp)
{
	int num;
	
	/* �t�@�C���I�[�v�� */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	
	while ((num = getc(fp)) != EOF){
		counter[zentai]++;
		
		if(isalpha(num)){
			counter[num]++;
		}else{
			if(num==' '){
				counter[space]++;
			}else{
				if(num=='.'){
					counter[piriod]++;
				}else{
					if(num==','){
						counter[kanma]++;
					}else{
						if(num=='!'){
							counter[ekus]++;
						}else{
							if(num=='?'){
								counter[kues]++;
							}else{
								if(num=='\n'){
									counter[kaigyou]++;
								}else{
									counter[other]++;
								}
							}
						}
					}
				}
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
	
	printf(",:%2d\n",counter[kanma]);
	printf(".:%2d\n",counter[piriod]);
	printf("!:%2d\n",counter[ekus]);
	printf("?:%2d\n",counter[kues]);
	printf(" :%2d\n",counter[space]);
	printf("���s:%2d\n",counter[kaigyou]);
	printf("other:%2d\n",counter[other]);
	
	printf("�S�̂̕�����(���p):%2d\n",counter[zentai]);
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
