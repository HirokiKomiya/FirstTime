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
    	printf("\n\n���[�h�I��\n�V�K�o�^:1\n�f�[�^�Q��:2\n�f�[�^�ꗗ:3\n\n");
    	scanf(" %d",&i);
    	switch(i){
	    	
			case 1:
		    printf("ID����͂��Ă�������\n");
			scanf("%d",&g);
        	printf("���O����͂��Ă�������\n");
            scanf("%s",student[g].name);
			printf("�ԍ�����͂��Ă�������\n");
        	for(j=0;j<11;j++){
		        scanf("%1d",&student[g].namber[j]);
        	}
			fp=fopen(fname,"a");
		    fprintf(fp,"\n%s\n",student[g].name);
		  	for(j=0;j<11;j++){
	            fprintf(fp,"%1d",student[g].namber[j]);
           	}
			fclose(fp);
	    	printf("\n�o�^���܂���\n",g);
	    	break;
	    	
	    	case 2:
			printf("\n�Ăяo���l�̖��O����͂��Ă�������\n");
			scanf("%s",&sn);
			fp=fopen(fname,"r+");
			t=1;
			while(fscanf(fp,"%s\n",&student[0].name) != EOF){
				e=strcmp(student[0].name,sn);
				if(e==0){
				    if(t%2==1){
				        printf("\n���O:");
	    			    printf("%s\n",student[0].name);
         				fscanf(fp,"%s\n",&student[0].name);
	    				printf("\n�ԍ�:");
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
			while(fscanf(fp,"%s\n",&student[0].name) != EOF){	//�Ō�܂œǂ݂ނ�EOF���Ԃ��Ă���
				printf("%d",t);
				if(t%2==1){
					printf("\n���O:");
				    printf("%s\n",student[0].name);
				}else{
					printf("\n�ԍ�:");
				    printf("%s\n",student[0].name);
				}
				t++;
			}
			fclose(fp);
			break;
     	}
	}
}