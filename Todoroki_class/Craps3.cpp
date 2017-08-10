/******************************************************/
//�@
//�@InGold	:��������
//�@Inpay	:�ŏ��̓q����
//�@Multi	:��������ɓq���������{�ɂ��邩
//�@n		:���s�����
//�@Mode	:���[�h�Ɋւ��Ă͈ȉ����Q��
//�@MaxPay	:���̕����o�������̕����o���𒴂�����I��
//�@MaxRatio:���̎��x�����𒴂�����I������

//�@�����[�h�̐�����
//�@
//�@mode0:���s�񐔏���܂Ŏ��s
//�@mode1:�������s������I��
//�@mode2:���������̔����ȏ�̕����o���ŏI��
//�@mode3:mode1+mode2
//�@mode4:mode1+MaxPay�ȏ�̕����o���ŏI��
//�@mode5:mode1+MaxRatio�ȏ�̎��x�����ŏI��
//�@
/******************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define InGold 1000000	//��������
#define InPay 1	//�����q����
#define n 1000	//���s�񐔏��
#define Multi 2	//�|�����̏搔
#define Mode 0	//���s���[�h
#define MaxPay 10000
#define MaxRatio 1.0003

#define Max 6		//�����̏���i�ύX�s�j
#define Min 1

int main(){
	int r;
	int pay;	//�|����
	int gold;	//������
	int sum1;	//��������̍��v
	int sum2;	//�|�C���g���̂�������̍��v
	int dice1;	//��������1
	int dice2;	//��������2
	int count=0;//�J�E���^�[
	int TotalWon=0;	//������
	int flag=0;		//�I���t���O
	double WinPercet;	//����
	double IncomeRatio;	//���x����
	
	srand((int)time(NULL));
	
	pay=InPay;
	gold=InGold - InPay;
	
	printf("ROUND�F%4d�C�������F%5d�C�|�����F%5d\n",count,gold,pay);
	
	switch(Mode){
		case 0:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//�i�`�������i�����j
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//�N���b�v�X�i�����j
					r=0;
				}else{	//�|�C���g�i����������j
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
					pay=1;
					printf("ROUND�F%4d�C�������F%5d�C���s�F�����C���Q�[���̊|����:%7d\n",count+1,gold,pay);
					TotalWon=TotalWon++;
				}else{
					gold = gold - pay;
					pay = pay*Multi;
					printf("ROUND�F%4d�C�������F%5d�C���s�F�����C���Q�[���̊|����:%7d\n",count+1,gold,pay);
				}
				
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n�@���s���ʂ܂Ƃ߁@\n");
			printf("�@���������F%d\n",InGold);
			printf("�@�������F%3d�C",TotalWon);
			printf("�@�����F%3f%�@\n",WinPercet);
			printf("�@���x�{���F%3f�{\n�@",IncomeRatio);
			printf("\n");
		break;
		
		case 1:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//�i�`�������i�����j
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//�N���b�v�X�i�����j
					r=0;
				}else{	//�|�C���g�i����������j
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
					pay=1;
					printf("ROUND�F%4d�C�������F%5d�C���s�F�����C���Q�[���̊|����:%7d\n",count+1,gold,pay);
					TotalWon=TotalWon++;
				}else{
					gold = gold - pay;
					pay = pay*Multi;
					printf("ROUND�F%4d�C�������F%5d�C���s�F�����C���Q�[���̊|����:%7d\n",count+1,gold,pay);
				}
				
				if(gold<0){
					printf("���������s���܂���\n");
					break;
				}
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n�@���s���ʂ܂Ƃ߁@\n");
			printf("�@���������F%d\n",InGold);
			printf("�@�������F%3d�C",TotalWon);
			printf("�@�����F%3f%�@\n",WinPercet);
			printf("�@���x�{���F%3f�{\n�@",IncomeRatio);
			printf("\n");
			
		break;
		
		case 2:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//�i�`�������i�����j
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//�N���b�v�X�i�����j
					r=0;
				}else{	//�|�C���g�i����������j
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
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
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n�@���s���ʂ܂Ƃ߁@\n");
			printf("�@���������F%d\n",InGold);
			printf("�@�搔%d�{\n",Multi);
			printf("�@�������F%3d�C",TotalWon);
			printf("�@�����F%3f%�@\n",WinPercet);
			printf("�@���x�{���F%3f�{\n�@",IncomeRatio);
			printf("\n");
		break;
		
		case 3:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//�i�`�������i�����j
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//�N���b�v�X�i�����j
					r=0;
				}else{	//�|�C���g�i����������j
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
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
				if(gold<0){
					printf("���������s���܂���\n");
					break;
				}
				if(flag)
					break;
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n�@���s���ʂ܂Ƃ߁@\n");
			printf("�@���������F%d\n",InGold);
			printf("�@�搔%d�{\n",Multi);
			printf("�@�������F%3d�C",TotalWon);
			printf("�@�����F%3f%�@\n",WinPercet);
			printf("�@���x�{���F%3f�{\n�@",IncomeRatio);
			printf("\n");
		break;
		case 4:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//�i�`�������i�����j
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//�N���b�v�X�i�����j
					r=0;
				}else{	//�|�C���g�i����������j
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
					if(pay>=MaxPay){
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
				if(gold<0){
					printf("���������s���܂���\n");
					break;
				}
				if(flag)
					break;
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n�@���s���ʂ܂Ƃ߁@\n");
			printf("�@���������F%d\n",InGold);
			printf("�@�搔%d�{\n",Multi);
			printf("�@�������F%3d�C",TotalWon);
			printf("�@�����F%3f%�@\n",WinPercet);
			printf("�@���x�{���F%3f�{\n�@",IncomeRatio);
			printf("\n");
		break;
		case 5:
			for(count=0;count<n;count++){
				dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
				
				sum1 = dice1 + dice2;
				
				if(sum1==7 | sum1==11){	//�i�`�������i�����j
					r=0;
				}else if(sum1==2 | sum1==3 | sum1==12){	//�N���b�v�X�i�����j
					r=0;
				}else{	//�|�C���g�i����������j
					sum2=0;
					r=0;
					while(sum2 != 7){
						dice1=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						dice2=Min + (int)( rand() * (Max - Min + 1.0) / (1.0 + RAND_MAX) );
						sum2=dice1 + dice2;
						if(sum2==sum1){
							r=1;
							break;
						}
					}
				}
				if(r){
					gold = gold - pay + pay*2;
					pay=1;
					printf("ROUND�F%4d�C�������F%5d�C���s�F�����C���Q�[���̊|����:%7d\n",count+1,gold,pay);
					TotalWon=TotalWon++;
					IncomeRatio=(double)(gold)/InGold;
					if(IncomeRatio>MaxRatio){
						flag=1;
					}
				}else{
					gold = gold - pay;
					pay = pay*Multi;
					printf("ROUND�F%4d�C�������F%5d�C���s�F�����C���Q�[���̊|����:%7d\n",count+1,gold,pay);
				}
				if(gold<0){
					printf("���������s���܂���\n");
					break;
				}
				if(flag)
					break;
			}
			WinPercet=(double)(TotalWon)/count*100;
			IncomeRatio=(double)(gold)/InGold;
			printf("\n�@���s���ʂ܂Ƃ߁@\n");
			printf("�@���������F%d\n",InGold);
			printf("�@�搔%d�{\n",Multi);
			printf("�@�������F%3d�C",TotalWon);
			printf("�@�����F%3f%�@\n",WinPercet);
			printf("�@���x�{���F%3f�{\n�@",IncomeRatio);
			printf("\n");
		break;
		
		default:
			printf("ModeError");
			exit(0);
		break;
	}
}


