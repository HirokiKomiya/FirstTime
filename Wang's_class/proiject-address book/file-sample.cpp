#include<stdio.h>
#include<string.h>			//������������w�b�_�[

struct person{
	int k;
	unsigned int id;
	char name[40];
	long phone; //unsigned��-�𖳎��B�ŏ���0�Ȃ�ǂ�����H
};

main(){
	int a=1;	//�t���O
	int h;		//���R�B
	int i=0,k=0;	//�J�E���^�[
	
	FILE *fp;	//�t�@�C���̃|�C���^
	char mode;	//���[�h�U�蕪��
	char FileName[] = "data.txt";
	//char Name[] = "Data\\list.txt";
	struct person student[100];
	
	while(a==1){
		fp = fopen(FileName,"a");
		scanf("\n%d %s %d",&student[0].id,student[0].name,&student[0].phone);
		fprintf(fp,"%d %s %d\n",student[0].id,student[0].name,student[0].phone);
		fclose(fp);
		fp = fopen(FileName,"r+");		/*�����̓t�@�C���̖��O���Ⴞ�߁B*/
		fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
		printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
		fclose(fp);
		k=k+1; //�����ꂽ���J�E���g�B

		//�ꗗ�\��
		printf("�ȉ��A������͂������̂̈ꗗ�\���B\n");
		fp = fopen(FileName,"r+");
		for(i=0;i<k;i++){
			fscanf(fp,"%d %s %d",&(student+i)->id,(student+i)->name,&(student+i)->phone);
			printf("%d %s %d\n",(student+i)->id,(student+i)->name,(student+i)->phone);
		}
		fclose(fp);

		printf("�p��:1\n");
		scanf("\n%d",&a);
	}
}

/********************* ���_�A���ӓ_ ***********************/
//�ǉ��͌��ɒǉ����Ă邾���B
//�ǂݍ��݂͈�Ԗڂ̃f�[�^�����ǂ߂Ȃ��B
//������̑����strcmp���g����
//	if(strcmp(name,"Taro")==0)	�������񂪓����Ȃ�^
/************************************************************/