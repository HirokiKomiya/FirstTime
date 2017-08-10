#include <stdio.h>

main(){
int i=0,keta=0,phone[100];

	
	printf("番号を入力して下さい。末尾に数字以外を入力して確定します。\n");
	while(1){
		scanf("%1d",&phone[i]);
		if(phone[i] > 9 | phone[i] < 0)
		break;
		i++;
	}
	
	keta=i-1;
	
	printf("桁数は%d\n",keta);
	
	for(i=0;i<keta;i++){
		printf("%d",phone[i]);
	}
	printf("\n");
}
