
/*5月18日出題*/

#include<stdio.h>
#include<math.h>

main()
{
	while(1){
	int a,b,x,y,z;
	x = 1;
	
	    printf("\n演算子を選択して下さい。\n+、-、*、/、それ以外:計算しない\n");
	    z = getchar();
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
		printf("1以外を入力すると終了します。");
		scanf("%d",&x);
		if(x == 1)break;
		}
	}
}