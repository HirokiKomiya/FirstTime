/*�l�����w�肵�č��v�A���ς����߂�*/
#include<stdio.h>
#include<math.h>

main(){
	int sc[];
	int sum,ave;
	int i,h,j;
	sum =0;/*sum�̏�����*/
	
	printf("���l�̓_��������܂����H\n");
	scanf("%d",&h);
	
	printf("�_������͂��Ă��������B\n");
	
	for(j=0;j<h;j++){
	scanf("%d",&sc[j]);
	}
	
	for(i=0;i<h;i++){
	sum += sc[j];
	}
		ave = sum/h;
	printf("���v�A%d\n",sum);
    printf("���ρA%d\n",ave);
}


/* scanf("%d",&a);
			    printf("�B\n");
			    scanf("%d",&b);
			    printf("%d+%d��%d�ł��B\n",a,b,a+b);}
		printf("�B\n");
	}*/