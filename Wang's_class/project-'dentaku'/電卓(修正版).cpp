#include<stdio.h>
#include<math.h>

main()
{
	while(1){
	int a,b;
	char z;
	
	    printf("\n���Z�q��I�����ĉ������B\n+�A-�A*�A/�A����ȊO:�v�Z���Ȃ�\n");
	    scanf("\n%c",&z);
		    {if(z == 0x2b){
			    printf("a+b���v�Z���܂��Ba����͂��Ă��������B\n");
			    scanf("%d",&a);
			    printf("b����͂��Ă��������B\n");
			    scanf("%d",&b);
			    printf("%d+%d��%d�ł��B\n",a,b,a+b);}
		    if(z == 0x2d){
			    printf("a-b���v�Z���܂��Ba����͂��Ă��������B\n");
			    scanf("%d",&a);
			    printf("b����͂��Ă��������B\n");
			    scanf("%d",&b);
			    printf("%d-%d��%d�ł��B\n",a,b,a-b);}
	        if(z == 0x2a){
			    printf("a*b���v�Z���܂��Ba����͂��Ă��������B\n");
			    scanf("%d",&a);
			    printf("b����͂��Ă��������B\n");
			    scanf("%d",&b);
			    printf("%d*%d��%d�ł��B\n",a,b,a*b);}
		    if(z == 0x2f){
			    printf("a/b���v�Z���܂��Ba����͂��Ă��������B\n");
			    scanf("%d",&a);
			    printf("b����͂��Ă��������B\n");
			    scanf("%d",&b);
			    printf("%d/%d��%d�ł��B\n",a,b,a/b);}
		}
		printf("1�ȊO����͂���ƏI�����܂��B");
		scanf("%d",&a);
		if(a == 1)break;
	}
}