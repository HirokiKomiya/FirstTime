/*0802A��*/
#include<stdio.h>

main()
{
	char a[99];/*�g�𑽂߂ɂƂ�B*/
	int i = 0;
	printf("10�ȓ��̕������́F");
	do{
		a[i] = getchar();
	}while(a[i++] != 0x0a);
	i = 0;
		printf("�ǂݍ��񂾕�����@�@�F");
     while(1){
		putchar(a[i]);
		i++;
		if(i>=9){break;}}/*�P�O���ǂݍ��񂾂�J��Ԃ��𔲂���*/
}
