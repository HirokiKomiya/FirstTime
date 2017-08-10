#include<stdio.h>
main()

{
	int a=10;/*32ビット＝4バイト*/
	int b=20;
	int* ptr;/*　ptrは勝手につけたポインタの名前*/
	ptr = &a;
	printf("a@%x = %d, b`%x = %d, ptr = %x, *ptr=%d\n,",&a,a,&b,b,ptr,*ptr);
	
	*ptr =100;/*　ptrがさしている先に代入していてptr自体は変わってない　*/
	printf("a@%x = %d, b`%x = %d, ptr = %x, *ptr = %d\n",&a,a,&b,b,ptr,*ptr);
	
	ptr =&b;/*　ptrの指す先を変える*/
	printf("a@%x = %d, b`%x = %d, ptr = %x ,*ptr = %d\n",&a,a,&b,b,ptr,*ptr);

	*ptr =200;
	printf("a@%x = %d, b`%x = %d, ptr = %x, *ptr = %d\n",&a,a,&b,b,ptr,*ptr);
}
/*ポインタ変数はアドレス値。アドレスを扱うためにポインタを使う。*/