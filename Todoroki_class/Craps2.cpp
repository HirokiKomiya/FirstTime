#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define InGold 10000	//��������
#define InPay 1	//�����|����
#define n 1000	//���s�񐔏��
#define m 6	//�����̏��
#define Multi 5	//�|�����̏搔


int main(){
	int r;
	int pay;	//�|����
	int gold;	//������
	int sum1;
	int sum2;
	int dice1;
	int dice2;
	int count=0;	//�J�E���^�[
	int score;
	int TotalWon=0;
	int flag=0;	//�I���t���O
	double WinPercet;
	double IncomeRatio;
	
	srand((int)time(NULL));
	
	pay=InPay;
	gold=InGold - InPay;
	
	printf("ROUND�F%4d�C�������F%5d�C�|�����F%5d\n",count,gold,pay);
	
	for(count=0;count<n;count++){
		dice1=(int)( rand() / (double)RAND_MAX * m);
		dice2=(int)( rand() / (double)RAND_MAX * m);
		
		sum1 = dice1 + dice2;
		
		if(sum1==7 | sum1==11){	//�i�`�������i�����j
			r=0;
		}else if(sum1==2 | sum1==3 | sum1==12){	//�N���b�v�X�i�����j
			r=0;
		}else{	//�|�C���g�i����������j
			sum2=0;
			r=0;
			while(sum2 != 7){
				dice1=(int)( rand() / (double)RAND_MAX * m);
				dice2=(int)( rand() / (double)RAND_MAX * m);
				sum2=dice1 + dice2;
				if(sum2==sum1){
					r=1;
					break;
				}
			}
		}
		if(r){
			gold = gold + pay*2;
			if(pay>=InGold/2){
				flag=1;
			}
			pay=1;
			printf("ROUND�F%4d�C�������F%5d�C���s�F�����C���Q�[���̊|����:%7d\n",count+1,gold,pay);
			TotalWon=TotalWon++;
			
		}else{
			gold = gold - pay;
			pay = pay*Multi;
			printf("ROUND�F%4d�C�������F%5d�C���s�F�����C���Q�[���̊|����:%7d\n",count+1,gold,pay);
		}
		
		if(flag)
			break;
		
	}
	WinPercet=(double)(TotalWon)/n*100;
	IncomeRatio=(double)(gold)/InGold;
	printf("\n�@���s���ʂ܂Ƃ߁@\n");
	printf("�@���������F%d\n",InGold);
	printf("�@�搔%d�{\n",Multi);
	printf("�@�������F%3d�C",TotalWon);
	printf("�@�����F%3f%�@\n",WinPercet);
	printf("�@���x�{���F%3f�{\n�@",IncomeRatio);
	printf("\n");
}


