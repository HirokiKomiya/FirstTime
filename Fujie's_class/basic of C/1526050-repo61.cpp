
#include<stdio.h>
#include<math.h>
main(){
	int sc[][3]={{90,80,70},{100,70,50},{80,90,100},{60,80,70},{80,70,60}};
	int sumJ,sumM,sumE,sumA,aveJ,aveM,aveE,aveA,suma,sumb,sumc,sumd,sume,avea,aveb,avec,aved,avee;
	/*J=Japanese, M=math, E=English, A=all*/
	int GP,GC=0;/*GP�͍��i�_�AGC�͍��i�l��*/
	sumJ = sc[0][0]+sc[1][0]+sc[2][0]+sc[3][0]+sc[4][0]+sc[5][0];
	aveJ = sumJ/5;/*����̕���*/
	sumM = sc[0][1]+sc[1][1]+sc[2][1]+sc[3][1]+sc[4][1]+sc[5][1];
	aveM = sumM/5;/*���w�̕���*/
	sumE = sc[0][2]+sc[1][2]+sc[2][2]+sc[3][2]+sc[4][2]+sc[5][2];
	aveE = sumE/5;/*�p��̕���*/
	suma = sc[0][0]+sc[0][1]+sc[0][2];
	avea = suma/3;/*��l�ڂ̕���*/
	sumb = sc[1][0]+sc[1][1]+sc[1][2];
	aveb = sumb/3;/*��l�ڂ̕���*/
	sumc = sc[2][0]+sc[2][1]+sc[2][2];
	avec = sumc/3;/*�O�l�ڂ̕���*/
	sumd = sc[3][0]+sc[3][1]+sc[3][2];
	aved = sumd/3;/*�l�l�ڂ̕���*/
	sume = sc[4][0]+sc[4][1]+sc[4][2];
	avee = sume/3;/*�ܐl�ڂ̕���*/
	sumA= sc[0][0]+sc[1][0]+sc[2][0]+sc[3][0]+sc[4][0]+sc[5][0]+sc[0][1]+sc[1][1]+sc[2][1]+sc[3][1]+sc[4][1]+sc[5][1]+sc[0][2]+sc[1][2]+sc[2][2]+sc[3][2]+sc[4][2]+sc[5][2];
	aveA = sumA/15;/*�S�̂̕���*/
	
	printf("����̕��ϓ_��%d\n",aveJ);
	printf("���w�̕��ϓ_��%d\n",aveM);
	printf("�p��̕��ϓ_��%d\n",aveE);
	printf("��l�ڂ̕��ϓ_��%d\n",avea);
	printf("��l�ڂ̕��ϓ_��%d\n",aveb);
	printf("�O�l�ڂ̕��ϓ_��%d\n",avec);
	printf("�l�l�ڂ̕��ϓ_��%d\n",aved);
	printf("�ܐl�ڂ̕��ϓ_��%d\n",avee);
	printf("�S�̂̕��ϓ_��%d\n",aveA);
	printf("����̍��i�_����͂��Ă��������B��");
	scanf("%d",&GP);
	{if(GP<=sc[0][0])
	GC=GC+1;}
	{if(GP<=sc[1][0])
	GC=GC+1;}
	{if(GP<=sc[2][0])
	GC=GC+1;}
	{if(GP<=sc[3][0])
	GC=GC+1;}
	{if(GP<=sc[4][0])
	GC=GC+1;}
	printf("���i�l���́A%d�l�ł��B\n",GC);
	GC=0;/*�J�E���g���Z�b�g*/
	printf("���w�̍��i�_����͂��Ă��������B��");
	scanf("%d�_",&GP);
	{if(GP<=sc[0][1])
	GC=GC+1;}
	{if(GP<=sc[1][1])
	GC=GC+1;}
	{if(GP<=sc[2][1])
	GC=GC+1;}
	{if(GP<=sc[3][1])
	GC=GC+1;}
	{if(GP<=sc[4][1])
	GC=GC+1;}
	printf("���i�l���́A%d�l�ł��B\n",GC);
	GC=0;/*�J�E���g���Z�b�g*/
	printf("�p��̍��i�_����͂��Ă��������B��");
	scanf("%d",&GP);
	{if(GP<=sc[0][2])
	GC=GC+1;}
	{if(GP<=sc[1][2])
	GC=GC+1;}
	{if(GP<=sc[2][2])
	GC=GC+1;}
	{if(GP<=sc[3][2])
	GC=GC+1;}
	{if(GP<=sc[4][2])
	GC=GC+1;}
	printf("���i�l���́A%d�l�ł��B\n",GC);
	GC=0;/*�J�E���g���Z�b�g*/
	printf("�O�Ȗڕ��ςł̍��i�_����͂��Ă��������B��");
	scanf("%d",&GP);
	{if(GP<avea)
	GC=GC+1;}
	{if(GP<=aveb)
	GC=GC+1;}
	{if(GP<=avec)
	GC=GC+1;}
	{if(GP<=aved)
	GC=GC+1;}
	{if(GP<=avee)
	GC=GC+1;}
	printf("���i�l���́A%d�l�ł��B\n",GC);
}	