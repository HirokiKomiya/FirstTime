#include <stdio.h>

int main(void){
	
	/*�܂��͉�����*/
	//1.�K���ɕK�v�ȕϐ�������
	int ID;
	char Name[] = "Wang-LAb.";
	int result;

	//2.�t�@�C���|�C���^�̎w��
	FILE *fp;	//�t�@�C���̐擪�̃|�C���^���w��
	
	//3.�ۑ���̃t�@�C�����O���w��
	char FileName[] = "data.txt";
	/*�����͂����܂�*/
	
	
	/*�t�@�C���ɏ������݂����ꍇ*/
	//1.�t�@�C�����J��
	fp = fopen(FileName, "a+");	//w�͐V�K�쐬or�㏑���Ba+�Œǉ���������or�V�K�쐬
	
	//��̓�s�͂܂Ƃ߂���B fp = fopen("data.txt","a+");
	
	/*
	�����ɐ���ɊJ���Ȃ������ꍇ�̃G���[����
	*/
	
	//2.�������݂�����������͂�����B
	printf("writte ID");
	scanf("\n%d",&ID);

    	//3.���͂��ꂽ�������t�@�C���ɏ����o��
	result = fprintf(fp, "%d %c\n", ID, Name);
	//result = fprintf(fp, Name);
	
	/*
	if(result < 0)	//�����ɃG���[����
	*/
	
	//4.�t�@�C�������
	fclose(fp);
	/*�t�@�C���ɏ������ޏꍇ�͂����܂�*/
		
	
	/*�t�@�C������ǂݏo�������ꍇ*/
	//1.�t�@�C�����J��
	fp = fopen(FileName,"r+");
	
	//2.�ǂ݂���
	fscanf(fp, "%d %s",&ID, Name);

	//3.�t�@�C�������
	fclose(fp);

	//4.���ۂɏo�͂�����
	printf("ID: %d\n",ID);
	/*�t�@�C������ǂݏo�������ꍇ�͂����܂�*/
}

/*************************** ���ӎ����Ȃ� **************************************/
//�t�@�C���͊J������K�����邱�ƁB
//fopen��fclose���ŏ��ɃZ�b�g�ŏ����āA���̊Ԃɏ��������Ă����Ȃ�����Ɨǂ�����
//����������邽�߂����������ɊJ���Ȃ����ƁB
/*******************************************************************************/