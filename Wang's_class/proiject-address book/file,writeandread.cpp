#include <stdio.h>

int main(void){
		//�K���ɕϐ���錾
	int ID = 123456789;
	char Name[] = "Wang-LAb.";
	int result;
	//�t�@�C���|�C���^
	FILE *fp;

	char FileName[] = "data.txt";
	//char Name[] = "Data\\list.txt";

	//�t�@�C�����J��
	fp = fopen(FileName, "a+");	//w�͐V�K�쐬or�㏑���Ba+�Œǉ���������or�V�K�쐬

	/*
	�����ɃG���[����
	*/

    //�t�@�C���ɏ����o��
	result = fprintf(fp, "%d %c\n", ID, Name);
	//result = fprintf(fp, Name);

	/*
	if(result < 0)
	*/

	//�t�@�C�������
	fclose(fp);
	
	//�t�@�C�����J��(�ǂ݂������[�h)
	fp = fopen(FileName,"r");

	//�ǂݍ���
	fscanf(fp, "%d %s",&ID, Name);

	//�t�@�C�������
	fclose(fp);

	printf("ID: %d\n",ID);
}
