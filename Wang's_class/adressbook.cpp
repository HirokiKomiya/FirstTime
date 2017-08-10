#include<stdio.h>
#include<string.h>

struct person{
	
	int id;
	char name[30];
	int namber[12];
};

main(){
	int e,t,i,j,d,g=0;
	int pnamber[12];
   	struct person student[50];
	FILE *fp;
	char c[31],fname[]="data.txt";
	char sn[30];
    while(1){
    	printf("\n\nモード選択\n新規登録:1\nデータ参照:2\nデータ一覧:3\n\n");
    	scanf(" %d",&i);
    	switch(i){
	    	
			case 1:
		    printf("IDを入力してください\n");
			scanf("%d",&g);
        	printf("名前を入力してください\n");
            scanf("%s",student[g].name);
			printf("番号を入力してください\n");
        	for(j=0;j<11;j++){
		        scanf("%1d",&student[g].namber[j]);
        	}
			fp=fopen(fname,"a");
		    fprintf(fp,"\n%s\n",student[g].name);
		  	for(j=0;j<11;j++){
	            fprintf(fp,"%1d",student[g].namber[j]);
           	}
			fclose(fp);
	    	printf("\n登録しました\n",g);
	    	break;
	    	
	    	case 2:
			printf("\n呼び出す人の名前を入力してください\n");
			scanf("%s",&sn);
			fp=fopen(fname,"r+");
			t=1;
			while(fscanf(fp,"%s\n",&student[0].name) != EOF){
				e=strcmp(student[0].name,sn);
				if(e==0){
				    if(t%2==1){
				        printf("\n名前:");
	    			    printf("%s\n",student[0].name);
         				fscanf(fp,"%s\n",&student[0].name);
	    				printf("\n番号:");
					    printf("%s\n",student[0].name);
					}
					t++;
				}
    		}
			fclose(fp);
	    	break;
			
			case 3:
			fp=fopen(fname,"r+");
			t=1;
			while(fscanf(fp,"%s\n",&student[0].name) != EOF){	//最後まで読みむとEOFが返ってくる
				printf("%d",t);
				if(t%2==1){
					printf("\n名前:");
				    printf("%s\n",student[0].name);
				}else{
					printf("\n番号:");
				    printf("%s\n",student[0].name);
				}
				t++;
			}
			fclose(fp);
			break;
     	}
	}
}