#include <stdio.h>
#include<string.h>
#include<stdlib.h>

//coefficient matrix(�W���s��)��[11]������co1_1

//2
double get_x1_2(double x2,double co1_1,double co1_2,double y_1)
{
	return((y_1-x2*co1_2)/co1_1);
}
double get_x2_2(double x1,double co2_1,double co2_2,double y_2)
{
	return((y_2-x1*co2_1)/co2_2);
}

//3

double get_x1_3(double x2,double x3,double co1_1,double co1_2,double co1_3,double y_1)
{
	return((y_1-x2*co1_2-x3*co1_3)/co1_1);
}
double get_x2_3(double x1,double x3,double co2_1,double co2_2,double co2_3,double y_2)
{
	return((y_2-x1*co2_1-x3*co2_3)/co2_2);
}
double get_x3_3(double x1,double x2,double co3_1,double co3_2,double co3_3,double y_3)
{
	return((y_3-x1*co3_1-x2*co3_2)/co3_3);
}


int main(){
	int count=0;	//�J�E���^�[
	int times;	//���s��
	
	int flag_x1=0;	//��������̃��[�h
	int flag_x2=0;
	int flag_x3=0;
	
	double x1[1000],x2[1000],x3[1000];
	double dif_x1;	//x1�̍�
	double dif_x2;	//x2�̍�
	double dif_x3;	//x3�̍�
	
	FILE *fp;		//�t�@�C���̃|�C���^
	double result;
	char data[10][10];
	char data1[10][10];
	int i=0,j=0;
	int rst;
	int n[500];
	int nc;	//�J�E���^�[
	int row=10;
	char Name[] = "data3.txt";
	char Name1[] = "data_x1.txt";
	char Name2[] = "data_x2.txt";
	char Name3[] = "data_x3.txt";
	
	//�t�@�C�����Ȃ��ꍇ�͋����I�ɐV�K�쐬������B
	fp = fopen(Name,"a");
	fclose(fp);
	fp = fopen(Name,"r+");
	
	for(nc=0;nc<500;nc++){
		if(row==i)
			break;
		fscanf(fp,"%c",&data[i][j]);
		n[nc] = atoi(&data[i][j]);
		
		//������0��5�������Ȃ�����p���B
		
		if(n[nc]==0 && n[nc-1]==0 && n[nc-2]==0 && n[nc-3]==0&& n[nc-4]==0){
			
			i=i+1;
			row=j-5;	//�s�͗�-1�̐���
			j=0;
			//printf("nc=%d\n",n[nc]);
			
		}else{
			
			j=j+1;
		}
	}
	fclose(fp);
	printf("�@�ǂݍ��񂾌W���s��͈ȉ��̒ʂ�ł��B\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;++j){
			printf("(%c,[%d][%d])",data[i][j],i,j);
		}
		printf("\n");
	}
	
		
	//�`�F�b�N�p
	/*for(nc=0;nc<20;nc++){
		printf("n[%d]=%d\n",nc,n[nc]);
	}*/
	
	printf("\n�����ϐ��̌�����͂��ĉ������B(2����10�܂�)\n");
	printf("3\n");
	
	/*�����l����������*/
	printf("x1�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
	scanf("\n%lf",&x1[0]);
		fp = fopen(Name1,"a");
		result = fprintf(fp, "%12.10f\n",x1[0]);
		fclose(fp);
		
		fp = fopen(Name2,"a");
		printf("x2�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
		scanf("\n%lf",&x2[0]);
		result = fprintf(fp, "%12.10f\n",x2[0]);
		fclose(fp);
		
		fp = fopen(Name3,"a");
		printf("x3�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
		scanf("\n%lf",&x3[0]);
		result = fprintf(fp, "%12.10f\n",x3[0]);
		fclose(fp);
	/*�ő�񐔂̓���*/
	/*printf("�ő厎�s�񐔂���͂��Ă�������(1000��܂�)\n");
	scanf(" %d",&times);*/
	times=30;
		
	/*�����l�̏o��*/
	printf("round: 0 (%12.10f,%12.10f,%12.10f)\n",x1[0],x2[0],x3[0]);
	
	
	/*���s*/
	for(count=0;count<times;count++){
		x1[count+1]=get_x1_3(x2[count],x3[count],n[0],n[1],n[2],n[3]);
		fp = fopen(Name1,"a");
		result = fprintf(fp, "%12.10f\n",x1[count+1]);
		fclose(fp);
		
		x2[count+1]=get_x2_3(x1[count+1],x3[count],n[9],n[10],n[11],n[12]);
		fp = fopen(Name2,"a");
		result = fprintf(fp, "%12.10f\n",x2[count+1]);
		fclose(fp);
		
		x3[count+1]=get_x3_3(x1[count+1],x2[count+1],n[18],n[19],n[20],n[21]);
		fp = fopen(Name3,"a");
		result = fprintf(fp, "%12.10f\n",x3[count+1]);
		fclose(fp);
		
		printf("round:%2d (%12.10f,%12.10f,%12.10f)\n",count+1,x1[count+1],x2[count+1],x3[count+1]);
		
		dif_x1=x1[count]-x1[count+1];
		dif_x2=x2[count]-x2[count+1];
		dif_x3=x3[count]-x3[count+1];
		
		
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
		/*if(flag_x1==1 && flag_x2==1 && flag_x3==1){
			printf(" �������܂����B\n");
			printf(" ���s�񐔂́A%d��ł��B\n",count+1);
			break;
		}
		//���s�񐔏���ɂ��I��
		else{*/
			if(times==count+1){
				printf(" �������܂���ł����B\n");
				printf(" ���s�񐔂́A%d��ł��B\n",count+1);	//for���̊֌W�ŏ���܂Ŏ��s���Ȃ������ꍇ�񐔂�1���Ȃ��Ȃ�
			}
		//}
	}
}

/**********************************/
//�ۑ�͂����2�~2����10�~10�Ŏg����悤�ɁB
//�����O������ǂݍ��ނ悤�ɂ���Ɨǂ�
//���ꂢ�ɕ�����₷��������
//�������U���蕔�������邱�ƁE�E�EOK�I
//�\�[�X�R�[���s���ʁA���l��͂Ɋւ���l�@���܂߂邱��
/**********************************/
