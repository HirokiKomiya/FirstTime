#include <stdio.h>
#include<string.h>


//�e�֐��̒�`

//2

double get_x1_2(double x2)
{
	return((0-x2*2)/2);
}
double get_x2_2(double x1)
{
	return((0-x1*2)/2);
}

//3

double get_x1_3(double x2,double x3)
{
	return((17-x2*2-x3*4)/1);
}
double get_x2_3(double x1,double x3)
{
	return((13-x1*5-x3*2)/1);
}
double get_x3_3(double x1,double x2)
{
	return((16-x1*1-x2*6)/1);
}

//4

double get_x1_4(double x2,double x3,double x4)
{
	return((10-x2-x3-x4*0)/5);
}
double get_x2_4(double x1,double x3,double x4)
{
	return((16-x1-x3-x4)/4);
}
double get_x3_4(double x1,double x2,double x4)
{
	return((17-x1*2-x2-x4)/3);
}
double get_x4_4(double x1,double x2,double x3)
{
	return((12-x1-x2*(-2)-x3)/3);
}

//5

double get_x1_5(double x2,double x3,double x4,double x5)
{
	return((10-x2-x3-x4*0-x5*0)/5);
}
double get_x2_5(double x1,double x3,double x4,double x5)
{
	return((16-x1-x3-x4-x5*0)/4);
}
double get_x3_5(double x1,double x2,double x4,double x5)
{
	return((9-x1-x2*0-x4-x5*(-1))/3);
}
double get_x4_5(double x1,double x2,double x3,double x5)
{
	return((17-x1-x2*(-2)-x3-x5)/3);
}
double get_x5_5(double x1,double x2,double x3,double x4)
{
	return((18-x1*0-x2*(-2)-x3-x4)/3);
}

//6

double get_x1_6(double x2,double x3,double x4,double x5,double x6)
{
	return((14-x2-x3-x4-x5*0-x6*0)/5);
}
double get_x2_6(double x1,double x3,double x4,double x5,double x6)
{
	return((16-x1-x3-x4-x5*0-x6*0)/4);
}
double get_x3_6(double x1,double x2,double x4,double x5,double x6)
{
	return((9-x1-x2*0-x4-x5*(-1)-x6*0)/3);
}
double get_x4_6(double x1,double x2,double x3,double x5,double x6)
{
	return((23-x1-x2*(-2)-x3-x5-x6)/3);
}
double get_x5_6(double x1,double x2,double x3,double x4,double x6)
{
	return((24-x1*0-x2*(-2)-x3-x4-x6)/3);
}
double get_x6_6(double x1,double x2,double x3,double x4,double x5)
{
	return((27-x1*0-x2*0-x3*(-2)-x4-x5)/4);
}

//7

double get_x1_7(double x2,double x3,double x4,double x5,double x6,double x7)
{
	return((18-x2*3-x3-x4-x5*0-x6*0-x7*0)/5);
}
double get_x2_7(double x1,double x3,double x4,double x5,double x6,double x7)
{
	return((27-x1-x3-x4-x5-x6-x7*0)/4);
}
double get_x3_7(double x1,double x2,double x4,double x5,double x6,double x7)
{
	return((35-x1*2-x2-x4-x5-x6-x7)/3);
}
double get_x4_7(double x1,double x2,double x3,double x5,double x6,double x7)
{
	return((32-x1*0-x2-x3-x5-x6-x7*0)/4);
}
double get_x5_7(double x1,double x2,double x3,double x4,double x6,double x7)
{
	return((35-x1*0-x2*0-x3-x4*2-x6-x7*(-1))/5);
}
double get_x6_7(double x1,double x2,double x3,double x4,double x5,double x7)
{
	return((35-x1*0-x2*0-x3-x4*0.5-x5-x7)/3);
}
double get_x7_7(double x1,double x2,double x3,double x4,double x5,double x6)
{
	return((40-x1*0-x2*0-x3*0-x4*1.5-x5*0-x6)/4);
}

//8

double get_x1_8(double x2,double x3,double x4,double x5,double x6,double x7,double x8)
{
	return((18-x2*3-x3-x4-x5*0-x6*0-x7*0-x8*0)/5);
}
double get_x2_8(double x1,double x3,double x4,double x5,double x6,double x7,double x8)
{
	return((27-x1-x3-x4-x5-x6-x7*0-x8*0)/4);
}
double get_x3_8(double x1,double x2,double x4,double x5,double x6,double x7,double x8)
{
	return((35-x1*2-x2-x4-x5-x6-x7-x8*0)/3);
}
double get_x4_8(double x1,double x2,double x3,double x5,double x6,double x7,double x8)
{
	return((32-x1*0-x2-x3-x5-x6-x7*0-x8*0)/4);
}
double get_x5_8(double x1,double x2,double x3,double x4,double x6,double x7,double x8)
{
	return((35-x1*0-x2*0-x3-x4*2-x6-x7*(-1)-x8*0)/5);
}
double get_x6_8(double x1,double x2,double x3,double x4,double x5,double x7,double x8)
{
	return((35-x1*0-x2*0-x3-x4*0.5-x5-x7-x8*0)/3);
}
double get_x7_8(double x1,double x2,double x3,double x4,double x5,double x6,double x8)
{
	return((32-x1*0-x2*0-x3*0-x4*1.5-x5*0-x6-x8*(-1))/4);
}
double get_x8_8(double x1,double x2,double x3,double x4,double x5,double x6,double x7)
{
	return((37-x1*0-x2*0-x3*0-x4*0-x5-x6*(-1)-x7*2)/3);
}

//9

double get_x1_9(double x2,double x3,double x4,double x5,double x6,double x7,double x8,double x9)
{
	return((21-x2-x3-x4-x5*0-x6*0-x7*0-x8*0-x9*0)/5);
}
double get_x2_9(double x1,double x3,double x4,double x5,double x6,double x7,double x8,double x9)
{
	return((9-x1-x3*(-1)-x4-x5-x6*0-x7*0-x8*0-x9*0)/4);
}
double get_x3_9(double x1,double x2,double x4,double x5,double x6,double x7,double x8,double x9)
{
	return((36-x1*2-x2*(-2)-x4*(-2)-x5-x6-x7*0-x8*0-x9*0)/5);
}
double get_x4_9(double x1,double x2,double x3,double x5,double x6,double x7,double x8,double x9)
{
	return((17-x1*0-x2-x3*(-1)-x5-x6-x7-x8*0-x9*0)/4);
}
double get_x5_9(double x1,double x2,double x3,double x4,double x6,double x7,double x8,double x9)
{
	return((24-x1*0-x2*0-x3-x4*2-x6*(-1)-x7-x8*0-x9*0)/5);
}
double get_x6_9(double x1,double x2,double x3,double x4,double x5,double x7,double x8,double x9)
{
	return((30-x1*0-x2*0-x3*(-2)-x4-x5-x7-x8*(-1)-x9*0)/4);
}
double get_x7_9(double x1,double x2,double x3,double x4,double x5,double x6,double x8,double x9)
{
	return((25-x1*0-x2*0-x3*0-x4*2-x5*(-1)-x6-x8-x9)/4);
}
double get_x8_9(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x9)
{
	return((14-x1*0-x2*0-x3*0-x4*0-x5-x6*(-1)-x7*2-x9*(-2))/4);
}
double get_x9_9(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x8)
{
	return((10-x1*0-x2*0-x3*0-x4*0-x5*0-x6*(-2)-x7-x8)/4);
}


//10

double get_x1_10(double x2,double x3,double x4,double x5,double x6,double x7,double x8,double x9,double x10)
{
	return((18-x2*3-x3-x4-x5*0-x6*0-x7*0-x8*0-x9*0-x10*0)/5);
}
double get_x2_10(double x1,double x3,double x4,double x5,double x6,double x7,double x8,double x9,double x10)
{
	return((27-x1-x3-x4-x5-x6-x7*0-x8*0-x9*0-x10*0)/4);
}
double get_x3_10(double x1,double x2,double x4,double x5,double x6,double x7,double x8,double x9,double x10)
{
	return((35-x1*2-x2-x4-x5-x6-x7-x8*0-x9*0-x10*0)/3);
}
double get_x4_10(double x1,double x2,double x3,double x5,double x6,double x7,double x8,double x9,double x10)
{
	return((32-x1*0-x2-x3-x5-x6-x7*0-x8*0-x9*0-x10*0)/4);
}
double get_x5_10(double x1,double x2,double x3,double x4,double x6,double x7,double x8,double x9,double x10)
{
	return((35-x1*0-x2*0-x3-x4*2-x6-x7*(-1)-x8*0-x9*0-x10*0)/5);
}
double get_x6_10(double x1,double x2,double x3,double x4,double x5,double x7,double x8,double x9,double x10)
{
	return((35-x1*0-x2*0-x3-x4*0.5-x5-x7-x8*0-x9*0-x10*0)/3);
}
double get_x7_10(double x1,double x2,double x3,double x4,double x5,double x6,double x8,double x9,double x10)
{
	return((32-x1*0-x2*0-x3*0-x4*1.5-x5*0-x6-x8*(-1)-x9*0-x10*0)/4);
}
double get_x8_10(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x9,double x10)
{
	return((35-x1*0-x2*0-x3*0-x4*0-x5-x6*0-x7*2-x9*(-2)-x10)/3);
}
double get_x9_10(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x8,double x10)
{
	return((27-x1*0-x2*0-x3*0-x4*0-x5*0-x6*0-x7*(-1)-x8-x10*(-1))/4);
}
double get_x10_10(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x8,double x9)
{
	return((18-x1*0-x2*0-x3*0-x4*0-x5*0-x6-x7-x8*(-2)-x9*(-1))/3);
}

//�֐���`�����܂�


int main(){
	int i;	//�J�E���^�[
	int times;	//���s��
	int var;	//�ϐ��̌�
	
	int flag_x1=0;	//��������̃t���O
	int flag_x2=0;
	int flag_x3=0;
	int flag_x4=0;
	int flag_x5=0;
	int flag_x6=0;
	int flag_x7=0;
	int flag_x8=0;
	int flag_x9=0;
	int flag_x10=0;
	
	double x1[1000],x2[1000],x3[1000],x4[1000],x5[1000],x6[1000],x7[1000],x8[1000],x9[1000],x10[1000];
	double dif_x1;	//x1�̍�
	double dif_x2;	//x2�̍�
	double dif_x3;	//x3�̍�
	double dif_x4;
	double dif_x5;
	double dif_x6;
	double dif_x7;
	double dif_x8;
	double dif_x9;
	double dif_x10;
	
	double A=0.0000000001;	//�덷���e
	
	double result;
	
	FILE *fp;		//�t�@�C���̃|�C���^
	
	char Name1[] = "datax1.txt";
	char Name2[] = "datax2.txt";
	char Name3[] = "datax3.txt";
	char Name4[] = "datax4.txt";
	char Name5[] = "datax5.txt";
	char Name6[] = "datax6.txt";
	char Name7[] = "datax7.txt";
	char Name8[] = "datax8.txt";
	char Name9[] = "datax9.txt";
	char Name10[] = "datax10.txt";
	
	//�t�@�C�����Ȃ��ꍇ�͋����I�ɐV�K�쐬������B
	fp = fopen(Name1,"a");
	fclose(fp);
	
	
	printf("�����ϐ��̌�����͂��ĉ������B(2����10�܂�)\n");
	scanf("\n%d",&var);
	
	if(var>10 | var<2){
		printf("�����ϐ��̐����K��͈͊O�ł��B\n");
	}else{
		/*�����l����������*/
		printf("x1�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
		scanf("\n%lf",&x1[0]);
		fp = fopen(Name1,"a");
		result = fprintf(fp, "%12.10f\n",x1[0]);
		fclose(fp);
		
		printf("x2�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
		scanf("\n%lf",&x2[0]);
		fp = fopen(Name2,"a");
		result = fprintf(fp, "%12.10f\n",x2[0]);
		fclose(fp);
		
		if(var>2){
			printf("x3�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
			scanf("\n%lf",&x3[0]);
			fp = fopen(Name3,"a");
			result = fprintf(fp, "%12.10f\n",x3[0]);
			fclose(fp);
		if(var>3){
			printf("x4�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
			scanf("\n%lf",&x4[0]);
			fp = fopen(Name4,"a");
			result = fprintf(fp, "%12.10f\n",x4[0]);
			fclose(fp);
		if(var>4){
			printf("x5�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
			scanf("\n%lf",&x5[0]);
			fp = fopen(Name5,"a");
			result = fprintf(fp, "%12.10f\n",x5[0]);
			fclose(fp);
		if(var>5){
			printf("x6�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
			scanf("\n%lf",&x6[0]);
			fp = fopen(Name6,"a");
			result = fprintf(fp, "%12.10f\n",x6[0]);
			fclose(fp);
		if(var>6){
			printf("x7�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
			scanf("\n%lf",&x7[0]);
			fp = fopen(Name7,"a");
			result = fprintf(fp, "%12.10f\n",x7[0]);
			fclose(fp);
		if(var>7){
			printf("x8�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
			scanf("\n%lf",&x8[0]);
			fp = fopen(Name8,"a");
			result = fprintf(fp, "%12.10f\n",x8[0]);
			fclose(fp);
		if(var>8){
			printf("x9�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
			scanf("\n%lf",&x9[0]);
			fp = fopen(Name9,"a");
			result = fprintf(fp, "%12.10f\n",x9[0]);
			fclose(fp);
		if(var>9){
			printf("x10�̏����l����͂��Ă��������B(������7�����l�̌ܓ����܂��B)\n");
			scanf("\n%lf",&x10[0]);
			fp = fopen(Name10,"a");
			result = fprintf(fp, "%12.10f\n",x10[0]);
			fclose(fp);
		}}}}}}}}
		
		/*�ő�񐔂̓���*/
		printf("�ő厎�s�񐔂���͂��Ă�������(1000��܂�)\n");
		scanf(" %d",&times);
		
		
		/*���[�U�[�̓��͂͂����܂�*/
		
		
		/*�����l�̏o��*/
		printf("round: 0 (");
		printf("%12.10f",x1[0]);
		printf(",%12.10f",x2[0]);
		if(var>2){
			printf(",%12.10f",x3[0]);
		if(var>3){
			printf(",%12.10f",x4[0]);
		if(var>4){
			printf(",%12.10f",x5[0]);
		if(var>5){
			printf(",%12.10f",x6[0]);
		if(var>6){
			printf(",%12.10f",x7[0]);
		if(var>7){
			printf(",%12.10f",x8[0]);
		if(var>8){
			printf(",%12.10f",x9[0]);
		if(var>9){
			printf(",%12.10f",x10[0]);
		}}}}}}}}
		
		printf(")\n");
		
		switch(var){
			case 2:
			for(i=0;i<times;i++){
				fp = fopen(Name1,"a");
				x1[i+1]=get_x1_2(x2[i]);
				result = fprintf(fp, "%12.10f\n",x1[i+1]); fclose(fp);
				fp = fopen(Name2,"a");
				x2[i+1]=get_x2_2(x1[i+1]);
				result = fprintf(fp, "%12.10f\n",x2[i+1]); fclose(fp);
				
				printf("round:%2d (%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1]);
				
				
				dif_x1=x1[i]-x1[i+1];
				dif_x2=x2[i]-x2[i+1];
				
				/*���������𔻒�*/
				if(dif_x1<=A && dif_x1>=-A)
						flag_x1=1;
				if(dif_x2<=A && dif_x2>=-A)
						flag_x2=1;
				
				/*���ׂĂ̎��������𖞂����ΏI��*/
				if(flag_x1==1 && flag_x2==1){
					printf(" �������܂����B\n");
					printf(" ���s�񐔂́A%d��ł��B\n",i+1);
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
			break;
			
			case 3:
			for(i=0;i<times;i++){
				fp = fopen(Name1,"a");
				x1[i+1]=get_x1_3(x2[i],x3[i]);
				result = fprintf(fp, "%12.10f\n",x1[i+1]); fclose(fp);
				fp = fopen(Name2,"a");
				x2[i+1]=get_x2_3(x1[i+1],x3[i]);
				result = fprintf(fp, "%12.10f\n",x2[i+1]); fclose(fp);
				fp = fopen(Name3,"a");
				x3[i+1]=get_x3_3(x1[i+1],x2[i+1]);
				result = fprintf(fp, "%12.10f\n",x3[i+1]); fclose(fp);
				
				printf("round:%2d (%12.10f,%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1],x3[i+1]);
				
				dif_x1=x1[i]-x1[i+1];
				dif_x2=x2[i]-x2[i+1];
				dif_x3=x3[i]-x3[i+1];
				
				
				/*���������𔻒�*/
				if(dif_x1<=A && dif_x1>=-A)
						flag_x1=1;
				if(dif_x2<=A && dif_x2>=-A)
						flag_x2=1;
				if(dif_x3<=A && dif_x3>=-A)
						flag_x3=1;
				
				/*���ׂĂ̎��������𖞂����ΏI��*/
				if(flag_x1==1 && flag_x2==1 && flag_x3==1){
					printf(" �������܂����B\n");
					printf(" ���s�񐔂́A%d��ł��B\n",i+1);
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
			break;
			
			case 4:
			for(i=0;i<times;i++){
				fp = fopen(Name1,"a");
				x1[i+1]=get_x1_4(x2[i],x3[i],x4[i]);
				result = fprintf(fp, "%12.10f\n",x1[i+1]); fclose(fp);
				fp = fopen(Name2,"a");
				x2[i+1]=get_x2_4(x1[i+1],x3[i],x4[i]);
				result = fprintf(fp, "%12.10f\n",x2[i+1]); fclose(fp);
				fp = fopen(Name3,"a");
				x3[i+1]=get_x3_4(x1[i+1],x2[i+1],x4[i]);
				result = fprintf(fp, "%12.10f\n",x3[i+1]); fclose(fp);
				fp = fopen(Name4,"a");
				x4[i+1]=get_x4_4(x1[i+1],x2[i+1],x3[i+1]);
				result = fprintf(fp, "%12.10f\n",x4[i+1]); fclose(fp);
				
				printf("round:%2d (%12.10f,%12.10f,%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1],x3[i+1],x4[i+1]);
				
				dif_x1=x1[i]-x1[i+1];
				dif_x2=x2[i]-x2[i+1];
				dif_x3=x3[i]-x3[i+1];
				dif_x4=x4[i]-x4[i+1];
				
				
				/*���������𔻒�*/
				if(dif_x1<=A && dif_x1>=-A)
						flag_x1=1;
				if(dif_x2<=A && dif_x2>=-A)
						flag_x2=1;
				if(dif_x3<=A && dif_x3>=-A)
						flag_x3=1;
				if(dif_x4<=A && dif_x4>=-A)
						flag_x4=1;
				
				/*���ׂĂ̎��������𖞂����ΏI��*/
				if(flag_x1==1 && flag_x2==1 && flag_x3==1 && flag_x4==1){
					printf(" �������܂����B\n");
					printf(" ���s�񐔂́A%d��ł��B\n",i+1);
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
			break;
			
			case 5:
			for(i=0;i<times;i++){
				fp = fopen(Name1,"a");
				x1[i+1]=get_x1_5(x2[i],x3[i],x4[i],x5[i]);
				result = fprintf(fp, "%12.10f\n",x1[i+1]); fclose(fp);
				fp = fopen(Name2,"a");
				x2[i+1]=get_x2_5(x1[i+1],x3[i],x4[i],x5[i]);
				result = fprintf(fp, "%12.10f\n",x2[i+1]); fclose(fp);
				fp = fopen(Name3,"a");
				x3[i+1]=get_x3_5(x1[i+1],x2[i+1],x4[i],x5[i]);
				result = fprintf(fp, "%12.10f\n",x3[i+1]); fclose(fp);
				fp = fopen(Name4,"a");
				x4[i+1]=get_x4_5(x1[i+1],x2[i+1],x3[i+1],x5[i]);
				result = fprintf(fp, "%12.10f\n",x4[i+1]); fclose(fp);
				fp = fopen(Name5,"a");
				x5[i+1]=get_x5_5(x1[i+1],x2[i+1],x3[i+1],x4[i+1]);
				result = fprintf(fp, "%12.10f\n",x5[i+1]); fclose(fp);
				
				printf("round:%2d (%12.10f,%12.10f,%12.10f,%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1]);
				
				dif_x1=x1[i]-x1[i+1];
				dif_x2=x2[i]-x2[i+1];
				dif_x3=x3[i]-x3[i+1];
				dif_x4=x4[i]-x4[i+1];
				dif_x5=x5[i]-x5[i+1];
								
				/*���������𔻒�*/
				if(dif_x1<=A && dif_x1>=-A)
						flag_x1=1;
				if(dif_x2<=A && dif_x2>=-A)
						flag_x2=1;
				if(dif_x3<=A && dif_x3>=-A)
						flag_x3=1;
				if(dif_x4<=A && dif_x4>=-A)
						flag_x4=1;
				if(dif_x5<=A && dif_x5>=-A)
						flag_x5=1;
				
				/*���ׂĂ̎��������𖞂����ΏI��*/
				if(flag_x1==1 && flag_x2==1 && flag_x3==1 && flag_x4==1 && flag_x5==1){
					printf(" �������܂����B\n");
					printf(" ���s�񐔂́A%d��ł��B\n",i+1);
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
			break;
			
			case 6:
			for(i=0;i<times;i++){
				fp = fopen(Name1,"a");
				x1[i+1]=get_x1_6(x2[i],x3[i],x4[i],x5[i],x6[i]);
				result = fprintf(fp, "%12.10f\n",x1[i+1]); fclose(fp);
				fp = fopen(Name2,"a");
				x2[i+1]=get_x2_6(x1[i+1],x3[i],x4[i],x5[i],x6[i]);
				result = fprintf(fp, "%12.10f\n",x2[i+1]); fclose(fp);
				fp = fopen(Name3,"a");
				x3[i+1]=get_x3_6(x1[i+1],x2[i+1],x4[i],x5[i],x6[i]);
				result = fprintf(fp, "%12.10f\n",x3[i+1]); fclose(fp);
				fp = fopen(Name4,"a");
				x4[i+1]=get_x4_6(x1[i+1],x2[i+1],x3[i+1],x5[i],x6[i]);
				result = fprintf(fp, "%12.10f\n",x4[i+1]); fclose(fp);
				fp = fopen(Name5,"a");
				x5[i+1]=get_x5_6(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x6[i]);
				result = fprintf(fp, "%12.10f\n",x5[i+1]); fclose(fp);
				fp = fopen(Name6,"a");
				x6[i+1]=get_x6_6(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1]);
				result = fprintf(fp, "%12.10f\n",x6[i+1]); fclose(fp);
				
				printf("round:%2d (%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1]);
				
				dif_x1=x1[i]-x1[i+1];
				dif_x2=x2[i]-x2[i+1];
				dif_x3=x3[i]-x3[i+1];
				dif_x4=x4[i]-x4[i+1];
				dif_x5=x5[i]-x5[i+1];
				dif_x6=x6[i]-x6[i+1];
				
				
				/*���������𔻒�*/
				if(dif_x1<=A && dif_x1>=-A)
						flag_x1=1;
				if(dif_x2<=A && dif_x2>=-A)
						flag_x2=1;
				if(dif_x3<=A && dif_x3>=-A)
						flag_x3=1;
				if(dif_x4<=A && dif_x4>=-A)
						flag_x4=1;
				if(dif_x5<=A && dif_x5>=-A)
						flag_x5=1;
				if(dif_x6<=A && dif_x6>=-A)
						flag_x6=1;
				
				/*���ׂĂ̎��������𖞂����ΏI��*/
				if(flag_x1==1 && flag_x2==1 && flag_x3==1 && flag_x4==1 && flag_x5==1 && flag_x6==1){
					printf(" �������܂����B\n");
					printf(" ���s�񐔂́A%d��ł��B\n",i+1);
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
			break;
			
			case 7:
			for(i=0;i<times;i++){
				fp = fopen(Name1,"a");
				x1[i+1]=get_x1_7(x2[i],x3[i],x4[i],x5[i],x6[i],x7[i]);
				result = fprintf(fp, "%12.10f\n",x1[i+1]); fclose(fp);
				fp = fopen(Name2,"a");
				x2[i+1]=get_x2_7(x1[i+1],x3[i],x4[i],x5[i],x6[i],x7[i]);
				result = fprintf(fp, "%12.10f\n",x2[i+1]); fclose(fp);
				fp = fopen(Name3,"a");
				x3[i+1]=get_x3_7(x1[i+1],x2[i+1],x4[i],x5[i],x6[i],x7[i]);
				result = fprintf(fp, "%12.10f\n",x3[i+1]); fclose(fp);
				fp = fopen(Name4,"a");
				x4[i+1]=get_x4_7(x1[i+1],x2[i+1],x3[i+1],x5[i],x6[i],x7[i]);
				result = fprintf(fp, "%12.10f\n",x4[i+1]); fclose(fp);
				fp = fopen(Name5,"a");
				x5[i+1]=get_x5_7(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x6[i],x7[i]);
				result = fprintf(fp, "%12.10f\n",x5[i+1]); fclose(fp);
				fp = fopen(Name6,"a");
				x6[i+1]=get_x6_7(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x7[i]);
				result = fprintf(fp, "%12.10f\n",x6[i+1]); fclose(fp);
				fp = fopen(Name7,"a");
				x7[i+1]=get_x7_7(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1]);
				result = fprintf(fp, "%12.10f\n",x7[i+1]); fclose(fp);
				
				printf("round:%2d (%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x7[i+1]);
				
				dif_x1=x1[i]-x1[i+1];
				dif_x2=x2[i]-x2[i+1];
				dif_x3=x3[i]-x3[i+1];
				dif_x4=x4[i]-x4[i+1];
				dif_x5=x5[i]-x5[i+1];
				dif_x6=x6[i]-x6[i+1];
				dif_x7=x7[i]-x7[i+1];
				
				
				/*���������𔻒�*/
				if(dif_x1<=A && dif_x1>=-A)
						flag_x1=1;
				if(dif_x2<=A && dif_x2>=-A)
						flag_x2=1;
				if(dif_x3<=A && dif_x3>=-A)
						flag_x3=1;
				if(dif_x4<=A && dif_x4>=-A)
						flag_x4=1;
				if(dif_x5<=A && dif_x5>=-A)
						flag_x5=1;
				if(dif_x6<=A && dif_x6>=-A)
						flag_x6=1;
				if(dif_x7<=A && dif_x7>=-A)
						flag_x7=1;
				
				/*���ׂĂ̎��������𖞂����ΏI��*/
				if(flag_x1==1 && flag_x2==1 && flag_x3==1 && flag_x4==1 && flag_x5==1 && flag_x6==1 && flag_x7==1){
					printf(" �������܂����B\n");
					printf(" ���s�񐔂́A%d��ł��B\n",i+1);
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
			break;
			
			case 8:
			for(i=0;i<times;i++){
				fp = fopen(Name1,"a");
				x1[i+1]=get_x1_8(x2[i],x3[i],x4[i],x5[i],x6[i],x7[i],x8[i]);
				result = fprintf(fp, "%12.10f\n",x1[i+1]); fclose(fp);
				fp = fopen(Name2,"a");
				x2[i+1]=get_x2_8(x1[i+1],x3[i],x4[i],x5[i],x6[i],x7[i],x8[i]);
				result = fprintf(fp, "%12.10f\n",x2[i+1]); fclose(fp);
				fp = fopen(Name3,"a");
				x3[i+1]=get_x3_8(x1[i+1],x2[i+1],x4[i],x5[i],x6[i],x7[i],x8[i]);
				result = fprintf(fp, "%12.10f\n",x3[i+1]); fclose(fp);
				fp = fopen(Name4,"a");
				x4[i+1]=get_x4_8(x1[i+1],x2[i+1],x3[i+1],x5[i],x6[i],x7[i],x8[i]);
				result = fprintf(fp, "%12.10f\n",x4[i+1]); fclose(fp);
				fp = fopen(Name5,"a");
				x5[i+1]=get_x5_8(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x6[i],x7[i],x8[i]);
				result = fprintf(fp, "%12.10f\n",x5[i+1]); fclose(fp);
				fp = fopen(Name6,"a");
				x6[i+1]=get_x6_8(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x7[i],x8[i]);
				result = fprintf(fp, "%12.10f\n",x6[i+1]); fclose(fp);
				fp = fopen(Name7,"a");
				x7[i+1]=get_x7_8(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x8[i]);
				result = fprintf(fp, "%12.10f\n",x7[i+1]); fclose(fp);
				fp = fopen(Name8,"a");
				x8[i+1]=get_x8_8(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x7[i+1]);
				result = fprintf(fp, "%12.10f\n",x8[i+1]); fclose(fp);
				
				printf("round:%2d (%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x7[i+1],x8[i+1]);
				
				dif_x1=x1[i]-x1[i+1];
				dif_x2=x2[i]-x2[i+1];
				dif_x3=x3[i]-x3[i+1];
				dif_x4=x4[i]-x4[i+1];
				dif_x5=x5[i]-x5[i+1];
				dif_x6=x6[i]-x6[i+1];
				dif_x7=x7[i]-x7[i+1];
				dif_x8=x8[i]-x8[i+1];
				
				
				/*���������𔻒�*/
				if(dif_x1<=A && dif_x1>=-A)
						flag_x1=1;
				if(dif_x2<=A && dif_x2>=-A)
						flag_x2=1;
				if(dif_x3<=A && dif_x3>=-A)
						flag_x3=1;
				if(dif_x4<=A && dif_x4>=-A)
						flag_x4=1;
				if(dif_x5<=A && dif_x5>=-A)
						flag_x5=1;
				if(dif_x6<=A && dif_x6>=-A)
						flag_x6=1;
				if(dif_x7<=A && dif_x7>=-A)
						flag_x7=1;
				if(dif_x8<=A && dif_x8>=-A)
						flag_x8=1;
				
				/*���ׂĂ̎��������𖞂����ΏI��*/
				if(flag_x1==1 && flag_x2==1 && flag_x3==1 && flag_x4==1 && flag_x5==1 && flag_x6==1 && flag_x7==1 && flag_x8==1){
					printf(" �������܂����B\n");
					printf(" ���s�񐔂́A%d��ł��B\n",i+1);
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
			break;
			
			case 9:
			for(i=0;i<times;i++){
				fp = fopen(Name1,"a");
				x1[i+1]=get_x1_9(x2[i],x3[i],x4[i],x5[i],x6[i],x7[i],x8[i],x9[i]);
				result = fprintf(fp, "%12.10f\n",x1[i+1]); fclose(fp);
				fp = fopen(Name2,"a");
				x2[i+1]=get_x2_9(x1[i+1],x3[i],x4[i],x5[i],x6[i],x7[i],x8[i],x9[i]);
				result = fprintf(fp, "%12.10f\n",x2[i+1]); fclose(fp);
				fp = fopen(Name3,"a");
				x3[i+1]=get_x3_9(x1[i+1],x2[i+1],x4[i],x5[i],x6[i],x7[i],x8[i],x9[i]);
				result = fprintf(fp, "%12.10f\n",x3[i+1]); fclose(fp);
				fp = fopen(Name4,"a");
				x4[i+1]=get_x4_9(x1[i+1],x2[i+1],x3[i+1],x5[i],x6[i],x7[i],x8[i],x9[i]);
				result = fprintf(fp, "%12.10f\n",x4[i+1]); fclose(fp);
				fp = fopen(Name5,"a");
				x5[i+1]=get_x5_9(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x6[i],x7[i],x8[i],x9[i]);
				result = fprintf(fp, "%12.10f\n",x5[i+1]); fclose(fp);
				fp = fopen(Name6,"a");
				x6[i+1]=get_x6_9(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x7[i],x8[i],x9[i]);
				result = fprintf(fp, "%12.10f\n",x6[i+1]); fclose(fp);
				fp = fopen(Name7,"a");
				x7[i+1]=get_x7_9(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x8[i],x9[i]);
				result = fprintf(fp, "%12.10f\n",x7[i+1]); fclose(fp);
				fp = fopen(Name8,"a");
				x8[i+1]=get_x8_9(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x7[i+1],x9[i]);
				result = fprintf(fp, "%12.10f\n",x8[i+1]); fclose(fp);
				fp = fopen(Name9,"a");
				x9[i+1]=get_x9_9(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x7[i+1],x8[i+1]);
				result = fprintf(fp, "%12.10f\n",x9[i+1]); fclose(fp);
				
				printf("round:%2d (%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x7[i+1],x8[i+1],x9[i+1]);
				
				dif_x1=x1[i]-x1[i+1];
				dif_x2=x2[i]-x2[i+1];
				dif_x3=x3[i]-x3[i+1];
				dif_x4=x4[i]-x4[i+1];
				dif_x5=x5[i]-x5[i+1];
				dif_x6=x6[i]-x6[i+1];
				dif_x7=x7[i]-x7[i+1];
				dif_x8=x8[i]-x8[i+1];
				dif_x9=x9[i]-x9[i+1];
				
				
				/*���������𔻒�*/
				if(dif_x1<=A && dif_x1>=-A)
						flag_x1=1;
				if(dif_x2<=A && dif_x2>=-A)
						flag_x2=1;
				if(dif_x3<=A && dif_x3>=-A)
						flag_x3=1;
				if(dif_x4<=A && dif_x4>=-A)
						flag_x4=1;
				if(dif_x5<=A && dif_x5>=-A)
						flag_x5=1;
				if(dif_x6<=A && dif_x6>=-A)
						flag_x6=1;
				if(dif_x7<=A && dif_x7>=-A)
						flag_x7=1;
				if(dif_x8<=A && dif_x8>=-A)
						flag_x8=1;
				if(dif_x9<=A && dif_x9>=-A)
						flag_x9=1;
				
				/*���ׂĂ̎��������𖞂����ΏI��*/
				if(flag_x1==1 && flag_x2==1 && flag_x3==1 && flag_x4==1 && flag_x5==1 && flag_x6==1 && flag_x7==1 && flag_x8==1 && flag_x9==1){
					printf(" �������܂����B\n");
					printf(" ���s�񐔂́A%d��ł��B\n",i+1);
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
			break;
			
			/*���s*/
			case 10:
			for(i=0;i<times;i++){
				fp = fopen(Name1,"a");
				x1[i+1]=get_x1_10(x2[i],x3[i],x4[i],x5[i],x6[i],x7[i],x8[i],x9[i],x10[i]);
				result = fprintf(fp, "%12.10f\n",x1[i+1]); fclose(fp);
				fp = fopen(Name2,"a");
				x2[i+1]=get_x2_10(x1[i+1],x3[i],x4[i],x5[i],x6[i],x7[i],x8[i],x9[i],x10[i]);
				result = fprintf(fp, "%12.10f\n",x2[i+1]); fclose(fp);
				fp = fopen(Name3,"a");
				x3[i+1]=get_x3_10(x1[i+1],x2[i+1],x4[i],x5[i],x6[i],x7[i],x8[i],x9[i],x10[i]);
				result = fprintf(fp, "%12.10f\n",x3[i+1]); fclose(fp);
				fp = fopen(Name4,"a");
				x4[i+1]=get_x4_10(x1[i+1],x2[i+1],x3[i+1],x5[i],x6[i],x7[i],x8[i],x9[i],x10[i]);
				result = fprintf(fp, "%12.10f\n",x4[i+1]); fclose(fp);
				fp = fopen(Name5,"a");
				x5[i+1]=get_x5_10(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x6[i],x7[i],x8[i],x9[i],x10[i]);
				result = fprintf(fp, "%12.10f\n",x5[i+1]); fclose(fp);
				fp = fopen(Name6,"a");
				x6[i+1]=get_x6_10(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x7[i],x8[i],x9[i],x10[i]);
				result = fprintf(fp, "%12.10f\n",x6[i+1]); fclose(fp);
				fp = fopen(Name7,"a");
				x7[i+1]=get_x7_10(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x8[i],x9[i],x10[i]);
				result = fprintf(fp, "%12.10f\n",x7[i+1]); fclose(fp);
				fp = fopen(Name8,"a");
				x8[i+1]=get_x8_10(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x7[i+1],x9[i],x10[i]);
				result = fprintf(fp, "%12.10f\n",x8[i+1]); fclose(fp);
				fp = fopen(Name9,"a");
				x9[i+1]=get_x9_10(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x7[i+1],x8[i+1],x10[i]);
				result = fprintf(fp, "%12.10f\n",x9[i+1]); fclose(fp);
				fp = fopen(Name10,"a");
				x10[i+1]=get_x10_10(x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x7[i+1],x8[i+1],x9[i+1]);
				result = fprintf(fp, "%12.10f\n",x10[i+1]);
				fclose(fp);
				
				printf("round:%2d (%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f,%12.10f)\n",i+1,x1[i+1],x2[i+1],x3[i+1],x4[i+1],x5[i+1],x6[i+1],x7[i+1],x8[i+1],x9[i+1],x10[i+1]);
				
				dif_x1=x1[i]-x1[i+1];
				dif_x2=x2[i]-x2[i+1];
				dif_x3=x3[i]-x3[i+1];
				dif_x4=x4[i]-x4[i+1];
				dif_x5=x5[i]-x5[i+1];
				dif_x6=x6[i]-x6[i+1];
				dif_x7=x7[i]-x7[i+1];
				dif_x8=x8[i]-x8[i+1];
				dif_x9=x9[i]-x9[i+1];
				dif_x10=x10[i]-x10[i+1];
				
				
				/*���������𔻒�*/
				if(dif_x1<=A && dif_x1>=-A)
						flag_x1=1;
				if(dif_x2<=A && dif_x2>=-A)
						flag_x2=1;
				if(dif_x3<=A && dif_x3>=-A)
						flag_x3=1;
				if(dif_x4<=A && dif_x4>=-A)
						flag_x4=1;
				if(dif_x5<=A && dif_x5>=-A)
						flag_x5=1;
				if(dif_x6<=A && dif_x6>=-A)
						flag_x6=1;
				if(dif_x7<=A && dif_x7>=-A)
						flag_x7=1;
				if(dif_x8<=A && dif_x8>=-A)
						flag_x8=1;
				if(dif_x9<=A && dif_x9>=-A)
						flag_x9=1;
				if(dif_x10<=A && dif_x10>=-A)
						flag_x10=1;
				
				/*���ׂĂ̎��������𖞂����ΏI��*/
				if(flag_x1==1 && flag_x2==1 && flag_x3==1 && flag_x4==1 && flag_x5==1 && flag_x6==1 && flag_x7==1 && flag_x8==1 && flag_x9==1 && flag_x10==1){
					printf(" �������܂����B\n");
					printf(" ���s�񐔂́A%d��ł��B\n",i+1);
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
			break;
			
			default:
			printf("\n�G���[");
			break;
		}
	}
}

/******************************************************/
//�ۑ�͂����2�~2����10�~10�Ŏg����悤�ɁB�E�E�EOK�I
//�����O������ǂݍ��ނ悤�ɂ���Ɨǂ�		�E�E�E������
//���ꂢ�ɕ�����₷��������(�C���f���g������Ȃ�)
//�������U���蕔�������邱��				�E�E�EOK�I
//�\�[�X�R�[���s���ʁA���l��͂Ɋւ���l�@���܂߂邱��
/******************************************************/
