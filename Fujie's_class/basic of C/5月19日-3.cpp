#include<stdio.h>
main()

{
	int a=10;/*32�r�b�g��4�o�C�g*/
	int b=20;
	int* ptr;/*�@ptr�͏���ɂ����|�C���^�̖��O*/
	ptr = &a;
	printf("a@%x = %d, b`%x = %d, ptr = %x, *ptr=%d\n,",&a,a,&b,b,ptr,*ptr);
	
	*ptr =100;/*�@ptr�������Ă����ɑ�����Ă���ptr���͕̂ς���ĂȂ��@*/
	printf("a@%x = %d, b`%x = %d, ptr = %x, *ptr = %d\n",&a,a,&b,b,ptr,*ptr);
	
	ptr =&b;/*�@ptr�̎w�����ς���*/
	printf("a@%x = %d, b`%x = %d, ptr = %x ,*ptr = %d\n",&a,a,&b,b,ptr,*ptr);

	*ptr =200;
	printf("a@%x = %d, b`%x = %d, ptr = %x, *ptr = %d\n",&a,a,&b,b,ptr,*ptr);
}
/*�|�C���^�ϐ��̓A�h���X�l�B�A�h���X���������߂Ƀ|�C���^���g���B*/