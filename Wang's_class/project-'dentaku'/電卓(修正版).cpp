#include<stdio.h>
#include<math.h>

main()
{
	while(1){
	int a,b;
	char z;
	
	    printf("\n演算子を選択して下さい。\n+、-、*、/、それ以外:計算しない\n");
	    scanf("\n%c",&z);
		    {if(z == 0x2b){
			    printf("a+bを計算します。aを入力してください。\n");
			    scanf("%d",&a);
			    printf("bを入力してください。\n");
			    scanf("%d",&b);
			    printf("%d+%dは%dです。\n",a,b,a+b);}
		    if(z == 0x2d){
			    printf("a-bを計算します。aを入力してください。\n");
			    scanf("%d",&a);
			    printf("bを入力してください。\n");
			    scanf("%d",&b);
			    printf("%d-%dは%dです。\n",a,b,a-b);}
	        if(z == 0x2a){
			    printf("a*bを計算します。aを入力してください。\n");
			    scanf("%d",&a);
			    printf("bを入力してください。\n");
			    scanf("%d",&b);
			    printf("%d*%dは%dです。\n",a,b,a*b);}
		    if(z == 0x2f){
			    printf("a/bを計算します。aを入力してください。\n");
			    scanf("%d",&a);
			    printf("bを入力してください。\n");
			    scanf("%d",&b);
			    printf("%d/%dは%dです。\n",a,b,a/b);}
		}
		printf("1以外を入力すると終了します。");
		scanf("%d",&a);
		if(a == 1)break;
	}
}