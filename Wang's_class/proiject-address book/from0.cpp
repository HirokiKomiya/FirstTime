#include <stdio.h>

main(){
int i=0,keta=0,phone[100];

	
	printf("�ԍ�����͂��ĉ������B�����ɐ����ȊO����͂��Ċm�肵�܂��B\n");
	while(1){
		scanf("%1d",&phone[i]);
		if(phone[i] > 9 | phone[i] < 0)
		break;
		i++;
	}
	
	keta=i-1;
	
	printf("������%d\n",keta);
	
	for(i=0;i<keta;i++){
		printf("%d",phone[i]);
	}
	printf("\n");
}
