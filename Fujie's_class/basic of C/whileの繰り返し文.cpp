/* 100�͂���t������ŏ��̎��̔{���@*/

#include<stdio.h>
main()
{
	int a, b,c,d;
	
	a = 7;
	b = 0;
	d = 1;
	
			
	while(b < 100)
	{printf("%3d��ځA%3d\n",d,b);
		b = b + a;
		d = 1 + d;}
	while(100 < b < 106);
		printf("%3d��ځA%3d\n",d,b);
		b = b + a;
		d = 1 + d;
	}
	
	printf("100�����߂Ē�����V�̔{���́A%3d�ł��B\n", b);
}
