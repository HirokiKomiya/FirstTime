/*変数の計算*/

#include<stdio.h>

main()
{
	int a[] ={67,25,41,78,30,92,16,58,83,90},max,i;	
	
	max = a[0]; 
	for(i=1;i<10;++i){
		if(a[i]>max){
			max = a[i];}
	}
	printf("最大値は%dです。" ,max);
}