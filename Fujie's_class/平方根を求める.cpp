/*5��18���o��*/

#include<stdio.h>
#include<math.h>

main()
{
	int a,b,x,y;
	char z;
	x = 1;
	while(x == 1){
	    printf("\n���Z�q��I�����ĉ������B\n+�A-�A*�A/�A����ȊO:�v�Z���Ȃ�\n");
	    z = getchar();
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
		printf("������ꍇ��1,�~�߂�ꍇ��0����͂���ƏI�����܂��B\n");
		scanf("%d",&x);
	}
}
