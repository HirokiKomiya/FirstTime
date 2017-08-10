#include<stdio.h>

struct person{
	int id;
	char name[40];
	unsigned long phone; //unsignedは-を無視
};

main(){
	
	int i=0;	//カウンター
	int j;		//何人分入れるか
	
	printf("何人分の情報を入力しますか？\n");
	scanf("\n%d",&j);
	j=j-1;
	while(i<=j){  							//何人分入れたいか
		
			struct person student[100];		//適当に大きさを定義
			printf("ID 名前 電話番号\nの順で打ち込んでください。\n");
			scanf("%d %s %ld",&student[i].id,student[i].name,&student[i].phone);
			printf(" %d\n  %s\n   %ld\n",student[i].id,student[i].name,student[i].phone); //配列は&いらない
		i++;
	}
}
