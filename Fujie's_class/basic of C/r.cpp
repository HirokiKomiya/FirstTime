
#include<stdio.h>

main()

{int a = 0x5a12,b = 0x1112,c = 0x5a90,d = 0x5b98,e = 0x0abb;

	if(a>>8 == 0x005a){
		printf("%x\n",a);
	}
	if(b>>8 == 0x005a){
		printf("%x\n",b);
	}
	if(c>>8 == 0x005a){
		printf("%x\n",c);
	}
	if(d>>8 == 0x005a){
		printf("%x\n",d);
	}
	if(e>>8 == 0x005a){
		printf("%x\n",e);
	}
}