#include <stdio.h>

int main(void){
		//�K���ɕϐ���錾
	int ID;
	char Name[] = "Wang-LAb.";
	int result;
	int ID1=0;
	char Name1[100];
	//�t�@�C���|�C���^
	FILE *fp;	//�t�@�C���̐擪�̃|�C���^���w��
	
	char FileName[] = "data.txt";
	
	//�t�@�C�����J��(�ǂ݂������[�h)
	fp = fopen(FileName,"r+");
	
	//�ǂݍ���
	fscanf(fp, "%d %s",&ID1, Name1);
	//�t�@�C�������
	fclose(fp);
	
	printf("ID: %d %s\n",ID1,Name1);
}
