/*�����܂łɃN���A�����ۑ�
*
*�w��̐l����ID�▼�O����͂��A�����ۑ����邱�Ƃ��ł���B
*���[�h�U�蕪����ǉ�(�r��)�B
*
*/

#include<stdio.h>
#include<string.h>			//������������w�b�_�[

struct person{
	unsigned int id;
	char name[40];
	unsigned long phone; //unsigned��-�𖳎��B�ŏ���0�Ȃ�ǂ�����H
};
#define keitai 090



main(){
	
	int a=1;	//�t���O
	int h;		//���R�B
	int i=0,k=0;	//�J�E���^�[
	int j;		//���l������邩
	
	int result;	//���ʂ�]�����邽�߂̕ϐ�
	FILE *fp;	//�t�@�C���̃|�C���^
	char mode;	//���[�h�U�蕪��
	char FileName[] = "data.txt";
	//char Name[] = "Data\\list.txt";
	struct person student[100];		//person�Ƃ������O�̍\���̂�student100�����
	
	while(a==1){
		printf("���[�h�I���B�����̓��[�h:q �f�[�^�̓ǂݏo�����[�h:a\n");
		scanf("\n%c",&mode);
		switch(mode){
			
			case'q':
				//�t�@�C�����J��(�������݃��[�h)
				fp = fopen("data.txt","a+");		//a+�͒ǉ���������or�V�K�쐬�B�t�@�C���̊J���߂͌J��Ԃ��̊O�ɁB
				
				printf("���l���̏�����͂��܂����H\n");
				scanf("\n%d",&j);
				j=j-1;
				
				while(i<=j){  							//���l�����ꂽ����
						printf("ID ���O �d�b�ԍ�\n�̏��őł�����ł��������B\n");
						scanf("%d %s %ld",&student[i].id,student[i].name,&student[i].phone);
						result = fprintf(fp,"%d %s %ld",student[i].id,student[i].name,student[i].phone);
						/*
						if(result < 0)		�����Ɉُ펞�̏���
						*/
						
						//printf(" %d\n  %s\n   %ld\n",student[i].id,student[i].name,student[i].phone); //�z���&����Ȃ�
						
					i++;
				}
				//�t�@�C�������
				fclose(fp);
				
				
				
			break;
			
			case'a':
				fp = fopen("data.txt","r");
				printf("���Ԗڂ̃f�[�^��ǂݏo���܂����B\n");		//fscanf���g�����Bscan�͈�s�����ǂݍ��܂Ȃ��̂Œ���
				scanf("\n%d",&h);
				
				fscanf(fp,"%d %s %ld",&student[h-1].id,student[h-1].name,&student[h-1].phone); //h�Ԗڂ̃f�[�^��\��
				printf("%d,%s,%ld\n",student[h-1].id,student[h-1].name,student[h-1].phone);
				fclose(fp);
			break;
			
			case'c':
				printf("copy mode \n");
				
				//strcpy
				
			break;
		}
	printf("�p������ꍇ��1����͂��ĉ������B\n");
	scanf("\n%d",&a);
	}
}

/*�����܂ł̖��_�B
*
*�I�[�o�[�t���[�΍�����Ă��Ȃ��B
*�d�b�ԍ��Ȃǂōŏ����[���̏ꍇ�ǂݔ�΂����B
*�f�o�b�N�����Ă��Ȃ��B
*
*/

/*���ꂩ��̉ۑ�
*
*���O��ԍ��Ō������ł���悤�ɂ���B����̓R���s���[�^�[��b�̎������Q�ƁB
*�t�@�C���ɓǂݏ���������B
*
*extra
*�t�@�C������������B(�R����11��ڂ̎��Ƃ��Q��)
*
*/