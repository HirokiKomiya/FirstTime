//�t�@�C���ɏ������ނ����B

#include<stdio.h>

main(){

	FILE *fp;	//�t�@�C���̃|�C���^
	int result;
	char FileName[] = "data.t";
	char Name[] = "Data\\list.txt";
	
	//�t�@�C�����J��
	
	fp = fopen(FileName,"w"); 	//�t�@�C���̊J�������w��
	
	//�t�@�C���̏����o��
	result = fprintf(fp," "," ");
	
	if(result<0){
	} //�G���[�����̕��Bfprint�ł����Ɠǂݍ��߂Ȃ���-1���Ԃ����B
}


//�t�@�C���͊J������K�����悤�B


//�t�@�C���ɓǂݍ��ނ���
/*#include<stdio.h>

int main(){

	FILE *fp;	//�t�@�C���̃|�C���^
	int ID;
	char FileName[] = "text.txt";
	char Name[64];
	
	fp = fopen(FileName,"r");	//�t�@�C�����J��(�ǂݍ��݃��[�h)
	
	//�ǂݍ���
	fscanf(fp,"%d %s",&ID,NAME);
	
	
	fclose(fp);	//�t�@�C�������
	
	
	//�t�@�C�����J��*/