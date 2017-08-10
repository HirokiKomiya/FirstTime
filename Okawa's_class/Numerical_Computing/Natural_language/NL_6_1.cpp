//************************************//
//
//����:NoMarakSample.txt
//
//�e���p�����̌����J�E���g
//
//�@�\��1_3�Ɠ��l
//
//�ǉ��@�\
//���p�X�y�[�X�̂ݕ�����
//**********************************//


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define zentai 0
#define space 6
#define other 7


int counter[300]={0};
char file_name[] = "6_1test.txt";

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
	
	printf(" :%2d\n",counter[space]);
	printf("other:%2d\n",counter[other]);
	
	printf("�S�̂̕�����(���p):%2d\n",counter[zentai]);
	printf("\n");
}

void PrintWord(void){
	int A,B;
	int i;
	int mojisu;
	
	mojisu = counter[zentai] - counter[other];
	
	printf("\n�m���Ɋ�Â������̍쐬\n");
	
	printf("������:%d\n",mojisu);
	for(i=0;i<=10;i++){
		
		A=rand();
		B = A % mojisu;
		
		//printf("\nB=%d",B);
		if(0<=B && B<counter['a']){
			printf("%d",B);
			printf("a\n");
		}else{
			if(counter['a']<=B && B<counter['a']+counter['b']){
					printf("%d",B);
					printf("b\n");
			}else{
				if(counter['a']+counter['b']<=B && B<counter['a']+counter['b']+counter['c']){
					printf("%d",B);
					printf("c\n");
				}else{
					if(counter['a']+counter['b']+counter['c']<=B && B<counter['a']+counter['b']+counter['c']+counter['d']){
						printf("%d",B);
						printf("d\n");
					}
				}
			}
		}
	}
	
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
	PrintWord();
}
