/*�����܂łɃN���A�����ۑ�
*
*�w��̐l����ID�▼�O����͂��A�����ۑ����邱�Ƃ��ł���B
*���[�h�U�蕪����ǉ�(�r��)�B
*
*/

#include<stdio.h>

struct person{
	unsigned int id;
	char name[40];
	unsigned long phone; //unsigned��-�𖳎��B�ŏ���0�Ȃ�ǂ�����H
};

main(){
	
	int i=0;	//�J�E���^�[
	int j;		//���l������邩
	char mode;
	printf("���[�h�I���B�����̓��[�h:q\n");
	scanf("\n%c",&mode);
	switch(mode){
		case'q':
			printf("���l���̏�����͂��܂����H\n");
			scanf("\n%d",&j);
			j=j-1;
			struct person student[100];		//�K���ɑ傫�����`
			while(i<=j){  							//���l�����ꂽ����
					printf("ID ���O �d�b�ԍ�\n�̏��őł�����ł��������B\n");
					scanf("%d %s %ld",&student[i].id,student[i].name,&student[i].phone);
					printf(" %d\n  %s\n   %ld\n",student[i].id,student[i].name,student[i].phone); //�z���&����Ȃ�
				i++;
			}
		break;
		case'a':
			
		break;
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
*�t�@�C������������B(�R����11��ڂ̎��Ƃ��Q��)
*
*/