#include<stdio.h>
#include<string.h>			//������������w�b�_�[

struct person{				//�\���̂̒�`
	int k;
	int id;
	char name[40];
	long phone; 			//�ŏ���0�Ȃ�ǂ�����H
};


main(){
	int flag;						//�t���O
	char mode1,mode2,mode3,mode4;	//���[�h�ؑ�
	char b;							//Y/N�A���T�[
	int h;							//���R�B
	int i,j=6,k=0;					//�J�E���^�[
	int pass=0;						//�p�X���[�h
	int pass1;						//�p�X���[�h����
	int Qes2;						//�閧�̎���̖��̏����l
	int Ans3;						//�閧�̎���̐����̏����l
	char Qes1[100]="";				//�閧�̎���̖��
	char Ans1[100]="";					//�閧�̎���̐���
	char Ans2[100];					//�閧�̎���̉�
	
	FILE *fp;						//�t�@�C���̃|�C���^
	char mode;						//���[�h�U�蕪��
	char FileName[] = "data1.txt";	//�f�[�^��ۑ�����t�@�C��
	char Name[] = "Pass.txt";		//�p�X���[�h��ۑ�����t�@�C��
	char Qes[] = "Qestion.txt";		//�閧�̎����ۑ�����t�@�C��
	char Ans[] = "Answer.txt";		//����̓�����ۑ�����t�@�C��
	
	struct person student[100];		//person�Ƃ������O�̍\���̂�student100�����
	int rst1,rst2;					//���O�����̌���
	int rst3;						//���b�N�����̌���
	int s1=0,s11=1;					//ID,Phone�����Ŏg�p
	char s2[100],s3[100];			//���O�̌����Ŏg�p
	
	
	/*�t�@�C�����Ȃ��ꍇ�͂��ꂼ�ꋭ���I�ɐV�K�쐬������B*/
	fp = fopen(Name,"r+");
	fscanf(fp,"%d",&pass);
	fclose(fp);
	fp = fopen(Name,"a");
	//printf("pass = %d\n",pass);		//�`�F�b�N�p
	if(pass==0)
	fprintf(fp,"1");
	fclose(fp);
	
	fp = fopen(Qes,"r+");
	fscanf(fp,"%s",&Qes1);
	fclose(fp);
	fp = fopen(Qes,"a");
	Qes2 = strcmp(Qes1,"");
	//printf("Qes2 = %d",Qes2);		//�`�F�b�N�p
	if(Qes2==0)
	fprintf(fp,"%s","�����l��0�ł��B");
	fclose(fp);
	
	fp = fopen(Ans,"r+");
	fscanf(fp,"%s",&Ans1);
	fclose(fp);
	fp = fopen(Ans,"a");
	Ans3 = strcmp(Ans1,"");
	//printf("Ans3 = %d\n",Ans3);		//�`�F�b�N�p
	if(Ans3==0)
	fprintf(fp,"%s","0");
	fclose(fp);
	/*�t�@�C�����Ȃ��ꍇ�̏����͂����܂�*/
	
	while(j>0){
		if(j != 6){				//�ŏ��̈��͏��O
			printf("�I������ꍇ��0����͂��Ă��������B");
			scanf("\n%d",&h);
			if(h==0)
			break;
		}
		
		flag=1;
		printf("\n�Ïؔԍ�����͂��ĉ������B�Ïؔԍ��̏����l��1�ł��B(�c��%d��)\n",j);
		printf("�܂��A�p�X���[�h��Y�ꂽ�ꍇ��'0'����͂��ĉ������B");
		
		scanf("\n%d",&pass1);
		if(pass1==0){
			printf("�閧�̎����\�����܂��B\n");
			fp = fopen(Qes,"r+");
			fscanf(fp,"%s",Qes1);
			printf("%s",Qes1);
			fclose(fp);
			
			printf("\n�������𓚂���͂��ĉ������B");
			scanf("%s",Ans2);
			fp = fopen(Ans,"r+");
			fscanf(fp,"%s",Ans1);
			fclose(fp);
			
			rst3 = strcmp(Ans1,Ans2);		//strcmp:�𓚂Ɛ����������Ȃ�0��Ԃ��B
		}else{
			fp = fopen(Name,"r+");
			fscanf(fp,"%d",&pass);
			fclose(fp);
		}
		
		if(pass==pass1 | rst3==0){		//���͂��ꂽ�p�X���[�h�������Ă���Ȃ�E�E�E
			
			while(flag==1){
				j=5;			//�p�X���[�h���͉\�񐔂�5�ɖ߂��B
				printf("\n q:�f�[�^�̓o�^�Aa:�f�[�^�̕\���Az:�f�[�^�̌����Ad;�f�[�^�̍폜�Ap:�p�X���[�h�̕ύX�B");
				scanf("\n%c",&mode1);
				printf("\n");
				
				switch(mode1){
					
					//�f�[�^�̓o�^
					case'q':
						printf("�f�[�^��o�^���܂��BID�A���O�A�d�b�ԍ��̏��ɓ��͂��Ă��������B\n");
						fp = fopen(FileName,"a+");		/*�����̓t�@�C���̖��O���Ⴞ�߁B*/
						scanf("\n%d %s %d",&student[0].id,student[0].name,&student[0].phone);
						fprintf(fp,"%d %s %d\n",student[0].id,student[0].name,student[0].phone);
						fclose(fp);
						k=k+1; //�����ꂽ���J�E���g�B
						printf("�o�^���܂����B\n");
					break;
					
					//�f�[�^�̕\��
					case'a':
						printf("q:����ǉ��������̂�\���Aa:����܂łɒǉ��������̂�\���B");
						scanf("\n%c",&mode2);
						switch(mode2){
							case'q':
								printf("�ȉ��A������͂������̂̈ꗗ�\���B\n");
								if(k==0){
									printf("����ǉ��������̂͂���܂���B\n");
								}else{
								fp = fopen(FileName,"r+");
									for(i=0;i<k;i++){
										fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
										printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
									}
								fclose(fp);
								}
							break;
							
							//�ꗗ�\��
							case'a':
								printf("�ȉ��A����܂łɓ��͂������̂̈ꗗ�\���B\n");	/*�@�s���S���ӁI�I�@*/
								fp = fopen(FileName,"r+");
								while(1){
									fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
									if(student[0].id==s1)		//����������������I��
										break;
									//break��printf�̑O�ɓ���Ȃ��ƍŌ�̂����o�Ă���B
									printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
									s1=student[0].id;
								}
								fclose(fp);
							break;
						}
					break;
					
					
					//�����@�\
					case'z':
						printf("�������[�h�ł��B\n�������������̂��w�肵�Ă��������BID�ԍ�:q���O:a�d�b�ԍ�:z\n");
						scanf("\n%c",&mode2);
						
						switch(mode2){
							case'q':
								printf("ID�Ō������܂��B\nID����͂��ĉ������B\n");
								scanf("\n%d",&s11);
								fp = fopen(FileName,"r+");
								while(1){
									fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
									if(student[0].id == s11){
										printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
										break;
									}
									if(student[0].id == s1){
										printf("�Y��������̂͂���܂���ł����B\n");
										break;
									}
									s1=student[0].id;
								}
								fclose(fp);
							break;
							
							//���O�Ō���
							case'a':
								printf("NAME�Ō������܂��B\nNAME����͂��ĉ������B\n");
								scanf("\n%s",s3);
								fp = fopen(FileName,"r+");
								while(1){
									fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
									rst1 = strcmp(student[0].name,s3);
									rst2 = strcmp(student[0].name,s2);
									if(rst1 == 0){
										printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
										break;		//�������̂���������o�͂��ďI��
									}
									if(rst2 == 0){	//���������炸�ɍŌ�܂ł�������E�E�E
										printf("�Y��������̂͂���܂���ł����B\n");
										break;
									}
									strcpy(student[0].name,s2);
								}
								fclose(fp);
							
							break;
							
							
							//�d�b�ԍ�����
							case'z':
								printf("PhoneNumber�Ō������܂��B\nID����͂��ĉ������B\n");
								scanf("\n%d",&s11);
								fp = fopen(FileName,"r+");
								while(1){
									fscanf(fp,"%d %s %d",&student[0].id,student[0].name,&student[0].phone);
									if(student[0].phone==s11){
										printf("%d %s %d\n",student[0].id,student[0].name,student[0].phone);
										break;
									}
									if(student[0].phone==s1){
										printf("�Y��������̂͂���܂���ł����B\n");
										break;
									}
									s1 = student[0].phone;
								}
								fclose(fp);
							break;
						}
					break;
					//���������܂ŁB
					
					
					case'd':
						printf("�S�Ẵf�[�^���폜���܂��B\n��낵����΁hy�h����͂��ĉ������B\n");
							if(b=='y'){
							fopen(FileName,"w");
							fclose(fp);
							}else
							
					break;
					
					//�p�X���[�h�ύX
					case'p':
						printf("�p�X���[�h��閧�̎����ҏW�ł��܂��B\n�ύX������̂�I�����Ă��������B\n");
						printf("�p�X���[�h:p�A�閧�̎���:q�A�ύX���Ȃ�:n");
						scanf(" %c",&mode4);
						switch(mode4){
							case'p':
								printf("�p�X���[�h��ύX���܂����Hy:YES");
								scanf(" %c",&b);
								if(b=='y'){
									printf("\n�V�����p�X���[�h����͂��ĉ������B\n");
									scanf("\n%d",&pass);
									fp = fopen(Name,"w");
									fprintf(fp,"%d\n",pass);
									fclose(fp);
									printf("�p�X���[�h��ύX���܂����B\n�V�����p�X���[�h��%d�ł��B\n\n",pass);
								}
							break;
							
							case'q':
								printf("�閧�̎����ύX���܂����Hy:YES");
								scanf(" %c",&b);
								if(b=='y'){
									printf("\n�V�����閧�̎������͂��ĉ������B");
									scanf("\n%s",Qes1);
									fp = fopen(Qes,"w");
									fprintf(fp,"%s\n",Qes1);
									fclose(fp);
									
									printf("�閧�̎���̉񓚂���͂��ĉ������B");
									scanf("\n%s",Ans1);
									fp = fopen(Ans,"w");
									fprintf(fp,"%s\n",Ans1);
									fclose(fp);
									
									printf("�ύX���������܂����B\n�V��������́h%s�h�ł��B\n",Qes1);
									printf("�܂��A�V�����𓚂́h%s�h�ł��B\n",Ans1);
								}
							break;
						}
					break;
					//�p�X���[�h�ύX�����܂ŁB
				}
				printf("\n�ȍ~�͔��p�œ��͂��Ă��������B\n");
				printf("�p��:1�A���b�N��ʂɖ߂�:���̑��̐���");
				scanf("\n%d",&flag);
			}
		printf("\n");
		}else{		//���͂��ꂽ�p�X���[�h���������E�E�E
		printf("\n�p�X���[�h�܂��͉𓚂��Ⴂ�܂��B\n");
		j=j-1;		//�p�X���[�h�̓��͉\�񐔂����炷
		}
	}
}


			/*�i����*/
	/*��{����*/
//	�t�@�C���̍쐬					�E�E�E�����ꍇ�͎����쐬�B�p�X���[�h�����l�ݒ�ς�
//	switch�ɂ�郂�[�h�ؑ�			�E�E�E����(break������̂��m�F�ς�)
//	�t���O�ɂ��p�������̊Ǘ�		�E�E�E����

	/*�m���}*/
//	�t�@�C���ւ̏������݁A�ǂݏo��	�E�E�E����
//	�o�^�����f�[�^�̈ꗗ�\��		�E�E�E����
//	�����@�\						�E�E�E����

	/*�G�N�X�g��*/
//	�p�X���[�h�ɂ��ی�			�E�E�E����
//	�O���[�v����					�E�E�E�����\��Ȃ�
//	��������						�E�E�E�ʓr�쐬��
//	���̑�							�E�E�E�閧�̎���̎�������

			/*���ӓ_*/

//�ǉ��͌��ɒǉ����Ă邾���B�ꏊ��I��Œǉ����Ă���킯�ł͂Ȃ��B
//fscanf�͔���p�ӂ��ē˂�����ł邾���B
//

			/*���P�_*/
//	�����̃t�@�C�����Ȃ����̏���	�E�E�E�����I�ɍ쐬���邱�Ƃŉ����ς�
//	������v������ǉ�����			�E�E�E�쐬��
//	�I��������					�E�E�EOK!
//	�I���̃^�C�~���O��ς���		�E�E�EOK!
//	����ID���A�����ē��͂���邱�Ƃ�z�肵�Ă��Ȃ����ʏ킠�肦�Ȃ��̂Ŗ���
//	�Ïؔԍ���Y�ꂽ�Ƃ��p�̏����������	�E�E�E����
//	�ŏ���0�̎����ǂ߂�悤�ɂ���	�E�E�E������(�쐬�ς�)
//	�I�o�[�t���[�΍�				�E�E�E�����􌟓���
//	�f�o�b�N����					�E�E�E�����ς݂̕����͂قڊ���(12/13���_)

