#include<stdio.h>
#include<string.h>

struct person{
	
	int id;
	char name[31];
	int namber[12];
	
};

main(){
	int i,j,g=0;
   	struct person student[51];
    while(1){
    	printf("\n新規登録なら1\nデータ参照なら2を入力してください\n\n");
    	scanf(" %d",&i);
    	switch(i){
	    	
			case 1:
			g++;
        	printf("名前を入力してください\n");
            scanf("%s",student[g].name);
			printf("番号を入力してください(縦書き)\n");
        	for(j=0;j<11;j++){
		        scanf("%1d",&student[g].namber[j]);
        	}
	    	printf("\n登録しました、IDは%dです\n",g);
	    	break;
	    	
	    	case 2:
			printf("\n呼び出すデータのIDを入力してください\n");
			scanf("%d",&g);
	    	printf("\n%s",student[g].name);
	    	for(j=0;j<11;j++){
		        printf("%d",student[g].namber[j]);
			}
	    	break;
     	}
	}
}