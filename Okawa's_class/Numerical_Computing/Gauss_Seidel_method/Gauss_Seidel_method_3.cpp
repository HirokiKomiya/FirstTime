#include <stdio.h>
#include<string.h>

double get_x1(double x2,double x3)
{
	return((10-x2-x3)/5);
}
double get_x2(double x1,double x3)
{
	return((12-x1-x3)/4);
}
double get_x3(double x1,double x2)
{
	return((13-x1*2-x2)/3);
}

int main(){
	int i=0;	//�J�E���^�[
	int times;	//���s��
	
	int flag_x1=0;	//��������̃��[�h
	int flag_x2=0;
	int flag_x3=0;
	
	double x1[1000],x2[1000],x3[1000];
	double dif_x1;	//x1�̍�
	double dif_x2;	//x2�̍�
	double dif_x3;	//x3�̍�
	
	FILE *fp;		//�t�@�C���̃|�C���^
	
	char FileName[] = "data1.txt";
	
	//�t�@�C�����Ȃ��ꍇ�͋����I�ɐV�K�쐬������B
	fp = fopen(FileName,"a");
	fscanf(fp,"%d",);
	fclose(fp);
	
	/*�����l����������*/
	printf("x1�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
	scanf("\n%lf",&x1[0]);
	printf("x2�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
	scanf("\n%lf",&x2[0]);
	printf("x3�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
	scanf("\n%lf",&x3[0]);
	
	/*�ő�񐔂̓���*/
	printf("�ő厎�s�񐔂���͂��Ă�������(1000��܂�)\n");
	scanf(" %d",&times);
	
	/*�����l�̏o��*/
	printf("round: 0 (%12.10f,%12.10f,%12.10f)\n",x1[0],x2[0],x3[0]);
	
	/*���s*/
	for(i=0;i<times;i++){
		x1[i+1]=get_x1(x2[i],x3[i]);
		x2[i+1]=get_x2(x1[i+1],x3[i]);
		x3[i+1]=get_x3(x1[i+1],x2[i+1]);
		printf("round:%2d (%12.10f,%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1],x3[i+1]);
		
		dif_x1=x1[i]-x1[i+1];
		dif_x2=x2[i]-x2[i+1];
		dif_x3=x3[i]-x3[i+1];
		
		
		/*���������𔻒�*/
		if(dif_x1<=0.0000000001 && dif_x1>=-0.0000000001){
				flag_x1=1;
		}
		if(dif_x2<=0.0000000001 && dif_x2>=-0.0000000001){
				flag_x2=1;
		}
		if(dif_x3<=0.0000000001 && dif_x3>=-0.0000000001){
				flag_x3=1;
		}
		
		/*���ׂĂ̎��������𖞂����ΏI��*/
		if(flag_x1==1 && flag_x2==1 && flag_x3==1){
			printf(" �������܂����B\n");
			printf(" ���s�񐔂́A%d��ł��B\n",i);
			break;
		}
		//���s�񐔏���ɂ��I��
		else{
			if(times==i+1){
				printf(" �������܂���ł����B\n");
				printf(" ���s�񐔂́A%d��ł��B\n",i+1);	//for���̊֌W�ŏ���܂Ŏ��s���Ȃ������ꍇ�񐔂�1���Ȃ��Ȃ�
			}
		}
	}

}

/**********************************/
//�ۑ�͂����2�~2����10�~10�Ŏg����悤�ɁB
//�����O������ǂݍ��ނ悤�ɂ���Ɨǂ�
//���ꂢ�ɕ�����₷��������
//�������U���蕔�������邱�ƁE�E�EOK�I
//�\�[�X�R�[���s���ʁA���l��͂Ɋւ���l�@���܂߂邱��
/**********************************/
