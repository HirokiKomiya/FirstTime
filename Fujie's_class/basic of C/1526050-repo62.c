/*7.2A*/

#include<stdio.h>

main()
{
	int a[10] ={67,25,41,78,30,92,16,58,83,90},max,i,min,sen,k,j;	
	
	max = a[0]; 
	for(i=1;i<10;++i){
		if(a[i]>max){
			max = a[i];}
	}
	printf("最大値は%dです。\n",max);
	
	min = a[0];
	for(i=1;i<10;i++){
		if(a[i]<min){
			min = a[i];}

	}
	printf("最小値は%dです。\n",min);
	sen = a[0];/*初期化*/
	for(i=1;i<10;i++){
		for(j = 0;j<10-i;j++){
		   if(a[j]>a[j+1]){
		   	  k = a[j];
			  a[j] = a[a+1];
			  a[j+1] = k;
			  }
		}
	}
	sen = a[10-1/2];
    printf("中央値は%dです。\n",sen);
}