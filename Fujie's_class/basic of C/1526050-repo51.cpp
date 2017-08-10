/*人数を指定して合計、平均を求める*/
#include<stdio.h>
#include<math.h>

main(){
	int sc[];
	int sum,ave;
	int i,h,j;
	sum =0;/*sumの初期化*/
	
	printf("何人の点数をいれますか？\n");
	scanf("%d",&h);
	
	printf("点数を入力してください。\n");
	
	for(j=0;j<h;j++){
	scanf("%d",&sc[j]);
	}
	
	for(i=0;i<h;i++){
	sum += sc[j];
	}
		ave = sum/h;
	printf("合計、%d\n",sum);
    printf("平均、%d\n",ave);
}


/* scanf("%d",&a);
			    printf("。\n");
			    scanf("%d",&b);
			    printf("%d+%dは%dです。\n",a,b,a+b);}
		printf("。\n");
	}*/