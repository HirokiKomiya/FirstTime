#include <stdio.h>
#include <math.h>
#define SIZE 256
#include <stdlib.h>

/*FILE *fp;
char name[] = "sample1.txt";
*/

#define other 0

int counter[1000];
char file_name[] = "sample.txt";


void mojicount(FILE *fp)
{
	int num = 0;
	
	/* �t�@�C���I�[�v�� */
	if((fp = fopen(file_name, "r")) == NULL) 
		fprintf(stderr, "%s\n", "error: can't read file.");
	
	
	while ((num = getc(fp)) != EOF){
		if(num>='a' && num<='z' || num>='A' && num<='Z'){
			counter[c]++;
		}else{
		counter[other]++:
		}
	}
	
	fclose(fp);
}

void PrintResult(void){
	int c;
	
	for (c = 'a'; c <= 'z'; c++)			/* �������̏o���p�x�� */
		printf("%c:%d\n",  c, counter[c]);	/* �\�� */
		printf("\n");
	for (c = 'A'; c <= 'Z'; c++){			/* �啶���̏o���p�x�� */
		printf("%c:%d\n",  c, counter[c] );	/* �\�� */
		printf("\n");
	}
}

void WriteForText{
	
}
	
void main(void)
{
    FILE *fp;
	
    if ((fp = fopen(file_name, "r")) == NULL) {   /* �t�@�C�����J���Ȃ���� */
                                                    /* ���b�Z�[�W��\������ */
        fprintf ( stderr, "Can't Open File\n" );
        exit (2);                                   /* �I�� */
    }
    printf("�o���p�x�\\n");
    CountLett(fp) ;        /* �����̏o���p�x�𒲂ׂ� */
    PrintResult();       /* �\������ */
    fclose(fp);            /* �t�@�C������� */
 }
