
#include<stdio.h>
#include<math.h>
main(){
	int sc[][3]={{90,80,70},{100,70,50},{80,90,100},{60,80,70},{80,70,60}};
	int sumJ,sumM,sumE,sumA,aveJ,aveM,aveE,aveA,suma,sumb,sumc,sumd,sume,avea,aveb,avec,aved,avee;
	/*J=Japanese, M=math, E=English, A=all*/
	int GP,GC=0;/*GPは合格点、GCは合格人数*/
	sumJ = sc[0][0]+sc[1][0]+sc[2][0]+sc[3][0]+sc[4][0]+sc[5][0];
	aveJ = sumJ/5;/*国語の平均*/
	sumM = sc[0][1]+sc[1][1]+sc[2][1]+sc[3][1]+sc[4][1]+sc[5][1];
	aveM = sumM/5;/*数学の平均*/
	sumE = sc[0][2]+sc[1][2]+sc[2][2]+sc[3][2]+sc[4][2]+sc[5][2];
	aveE = sumE/5;/*英語の平均*/
	suma = sc[0][0]+sc[0][1]+sc[0][2];
	avea = suma/3;/*一人目の平均*/
	sumb = sc[1][0]+sc[1][1]+sc[1][2];
	aveb = sumb/3;/*二人目の平均*/
	sumc = sc[2][0]+sc[2][1]+sc[2][2];
	avec = sumc/3;/*三人目の平均*/
	sumd = sc[3][0]+sc[3][1]+sc[3][2];
	aved = sumd/3;/*四人目の平均*/
	sume = sc[4][0]+sc[4][1]+sc[4][2];
	avee = sume/3;/*五人目の平均*/
	sumA= sc[0][0]+sc[1][0]+sc[2][0]+sc[3][0]+sc[4][0]+sc[5][0]+sc[0][1]+sc[1][1]+sc[2][1]+sc[3][1]+sc[4][1]+sc[5][1]+sc[0][2]+sc[1][2]+sc[2][2]+sc[3][2]+sc[4][2]+sc[5][2];
	aveA = sumA/15;/*全体の平均*/
	
	printf("国語の平均点は%d\n",aveJ);
	printf("数学の平均点は%d\n",aveM);
	printf("英語の平均点は%d\n",aveE);
	printf("一人目の平均点は%d\n",avea);
	printf("二人目の平均点は%d\n",aveb);
	printf("三人目の平均点は%d\n",avec);
	printf("四人目の平均点は%d\n",aved);
	printf("五人目の平均点は%d\n",avee);
	printf("全体の平均点は%d\n",aveA);
	printf("国語の合格点を入力してください。→");
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
	printf("合格人数は、%d人です。\n",GC);
	GC=0;/*カウントリセット*/
	printf("数学の合格点を入力してください。→");
	scanf("%d点",&GP);
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
	printf("合格人数は、%d人です。\n",GC);
	GC=0;/*カウントリセット*/
	printf("英語の合格点を入力してください。→");
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
	printf("合格人数は、%d人です。\n",GC);
	GC=0;/*カウントリセット*/
	printf("三科目平均での合格点を入力してください。→");
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
	printf("合格人数は、%d人です。\n",GC);
}	