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
    	printf("\n�V�K�o�^�Ȃ�1\n�f�[�^�Q�ƂȂ�2����͂��Ă�������\n\n");
    	scanf(" %d",&i);
    	switch(i){
	    	
			case 1:
			g++;
        	printf("���O����͂��Ă�������\n");
            scanf("%s",student[g].name);
			printf("�ԍ�����͂��Ă�������(�c����)\n");
        	for(j=0;j<11;j++){
		        scanf("%1d",&student[g].namber[j]);
        	}
	    	printf("\n�o�^���܂����AID��%d�ł�\n",g);
	    	break;
	    	
	    	case 2:
			printf("\n�Ăяo���f�[�^��ID����͂��Ă�������\n");
			scanf("%d",&g);
	    	printf("\n%s",student[g].name);
	    	for(j=0;j<11;j++){
		        printf("%d",student[g].namber[j]);
			}
	    	break;
     	}
	}
}