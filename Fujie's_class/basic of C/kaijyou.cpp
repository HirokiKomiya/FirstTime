#include<stdio.h>
/*12�܂ł����ł��Ȃ�*/
main()
{
	int a=1,i,n;
	printf("�K����v�Z���܂��B\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a = a*i;
	}
	i = i-1;
	printf("%d�̊K���%ld\n",i,a);
}