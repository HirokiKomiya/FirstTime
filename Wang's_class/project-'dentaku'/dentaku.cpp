#include<stdio.h>
#include<math.h>

main()
{
	int a=1,b;
	double c,w;
	char z,y;
	printf("初めに取説です。\nこの電卓は2つのモードから構成されています。\n一つ目に四則演算モード。これは読んで字のごとくです。\n二つ目に関数電卓モード。三角関数や√の計算が行えます。\nまた、この電卓は前回の計算結果を記憶しているのでそれを用いた計算が可能です。\n");
	
	while(a==1){
	    printf("\n演算子を選択して下さい。\n足し算:+、引き算:-、掛け算:*、割り算:/、関数電卓:a\n");
	    scanf("\n%c",&z);
		if(z == 0x2b){
		    printf("a+bを計算します。aを入力してください。\n");
		    scanf("%d",&a);
		    printf("bを入力してください。\n");
		    scanf("%d",&b);
			c = a+b;
		    printf("%d+%d＝%dです。\n",a,b,a+b);}
	    if(z == 0x2d){
		    printf("a-bを計算します。aを入力してください。\n");
		    scanf("%d",&a);
		    printf("bを入力してください。\n");
		    scanf("%d",&b);
			c = a-b;
		    printf("%d-%d＝%dです。\n",a,b,a-b);}
        if(z == 0x2a){
		    printf("a*bを計算します。aを入力してください。\n");
		    scanf("%d",&a);
		    printf("bを入力してください。\n");
		    scanf("%d",&b);
			c =a*b;
		    printf("%d*%d＝%dです。\n",a,b,a*b);}
	    if(z == 0x2f){
		    printf("a/bを計算します。aを入力してください。\n");
		    scanf("%d",&a);
		    printf("bを入力してください。\n");
		    scanf("%d",&b);
			c = a/b;
		    printf("%d/%d＝%dです。\n",a,b,a/b);}
		if(z == 'a'){
			printf("関数電卓モードです。\nsin:s、cos:t、tan:t、√:r\n行いたい計算に合わせてコロンの後の文字を入力してください。");
			scanf("\n%c",&z);
			if(z == 's'){
				printf("sinaを計算します。aを入力してください。\n");
				scanf("%d",&a);
				c =  sin(a);
				printf("sin%d＝%lfです。\n",a,c);}
			if(z == 'c'){
				printf("cosaを計算します。aを入力してください。\n");
				scanf("%d",&a);
				c =  cos(a);
				printf("cos%d＝%lfです。\n",a,c);}
			if(z == 't'){
				printf("tanaを計算します。aを入力してください。\n");
				scanf("%d",&a);
				c =  tan(a*PI/180);
				printf("tan%d＝%lfです。\n",a,c);}/**/
			if(z == 'r'){
				printf("√aを計算します。aを入力してください。\n");
				scanf("%d",&a);
				c =  sqrt(a);
				printf("√%d＝%lfです。\n",a,c);}
		}
		
		/*ここの間に最初に指定された文字以外が入力された場合の動作を入れる*/
		
			printf("\n今回の計算結果を用いる場合はaを、用いない場合や終了したい場合はそれ以外を入力してください。");
			scanf("\n%c",&y);
			while(y == 'a'){
				printf("\n演算子を選択して下さい。\n足し算:+、引き算:-、掛け算:*、割り算:/、関数電卓:a\n");
		        scanf("\n%c",&z);{
				if(z == 0x2b){
				    printf("%2f+bを計算します。\n",c);
				    printf("bを入力してください。\n");
				    scanf("%d",&b);
					c = c + b;
				    printf("答えは%2fです。\n",c);}
			    if(z == 0x2d){
				    printf("%2f-bを計算します。\n",c);
				    printf("bを入力してください。\n");
				    scanf("%d",&b);
					c = c - b;
				    printf("答えは%2fです。\n",c);}
		        if(z == 0x2a){
				    printf("%2f*bを計算します。\n",c);
				    printf("bを入力してください。\n");
				    scanf("%d",&b);
					c = c * b;
				    printf("答えは%2fです。\n",c);}
			    if(z == 0x2f){
				    printf("%2f/bを計算します。\n",c);
				    printf("bを入力してください。\n");
				    scanf("%d",&b);
					c = c / b;
				    printf("答えは%2fです。\n",c);}
					/*以下、四則演算以外*/
				if(z == 'a'){
					printf("\n関数電卓モードです。\nsin:s、cos:t、tan:t、√:r\n行いたい計算に合わせてコロンの後の文字を入力してください。\n");
					scanf("\n%c",&z);
					if(z == 's'){
						printf("sin%2fを計算します。\n",c);
						c =  sin(c);
						printf("答えは%lfです。\n",c);}
					if(z == 'c'){
						printf("cos%2fを計算します。\n",c);
						c =  cos(c);
						printf("答えは%lfです。\n",c);}
					if(z == 't'){
						printf("tan%2f計算します。\n",c);
						c =  tan(c);
						printf("答えは%lfです。\n",c);}
					if(z == 'r'){
						printf("√%2fを計算します。\n",c);
						c =  sqrt(c);
						printf("答えは%lfです。\n",c);}
				}
				
				/*ここの間に指定された文字以外が入力された場の挙動を入れる*/
				
			printf("\n今回の計算結果を用いる場合はaを、用いない場合や終了したい場合はそれ以外を入力してください。");
			scanf("\n%c",&y);
			}
		}
		printf("終了しますか？\n1以外の数字を入力すると終了します。");
		scanf("%d",&a);
	}
}
