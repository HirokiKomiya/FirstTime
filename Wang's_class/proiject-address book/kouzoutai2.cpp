#include<stdio.h>

struct person{
	int id;
	char name[40];
	unsigned long phone; //unsigned��-�𖳎�
};

main(){
	
	int i=0;	//�J�E���^�[
	int j;		//���l������邩
	
	printf("���l���̏�����͂��܂����H\n");
	scanf("\n%d",&j);
	j=j-1;
	while(i<=j){  							//���l�����ꂽ����
		
			struct person student[100];		//�K���ɑ傫�����`
			printf("ID ���O �d�b�ԍ�\n�̏��őł�����ł��������B\n");
			scanf("%d %s %ld",&student[i].id,student[i].name,&student[i].phone);
			printf(" %d\n  %s\n   %ld\n",student[i].id,student[i].name,student[i].phone); //�z���&����Ȃ�
		i++;
	}
}
