#include<stdio.h>
#include<math.h>
#include<string.h> //����Ɋւ��Ă̓O�O��

#define PI 3.1415926
main()
{
	double a[100];						//�����̔z��̐錾
	double *b = a;						//�����̎Q�Ɛݒ�
	char c[100];						//�����̔z��錾
	char *d = c; 						//���Z�q�̎Q�Ɛݒ�
	int i=0;							//����ڂ̂�
	double tashizan(double e, double f);	//�v���g�^�C�v�錾
	double hikizan(double e, double f);
	double kakezan(double e, double f);
	double warizan(double e, double f);
	double sina(double e);
	double cosa(double e);
	double tana(double e);
	double rutoa(double e);
	
	
	
	printf("����l��0����͂����ꍇ�́A���̊���Z�͌v�Z����܂���\n");
	
		while(*(d+i-1) != '='){
			scanf(" %lf",&*(b+i));
			//printf(" \n%f",*(b+i));
			scanf(" %c",&*(d+i));
			//printf("%c",*(d+i));
				if(i != 0){
					switch(*(d+i-1)){
						case'+':
						*(b+i) = tashizan(*(b+i-1),*(b+i));
						//printf(" \n");
						break;
						case'-':
						*(b+i) = hikizan(*(b+i-1),*(b+i));
						break;
						case'*':
						*(b+i) = kakezan(*(b+i-1),*(b+i)); 
						break;
						case'/':
						if(*(b+i) != 0){
						*(b+i) = warizan(*(b+i-1),*(b+i));		//����l��0�̎��ɂ̓u���C�N���悤
						}else
						*(b+i) = *(b+i-1);
						break;
						
						case' ':								//' '�����͂��ꂽ��֐����[�h
						scanf(" %c",&*(d+i));
							switch(*(d+i-1)){
							case's':
							printf("sin\n");
							*(b+i) != sin(*(b+i));
							}
						
						break;
						
						default:
						;
						
					}
				}else;
			i++;
			//printf("����i��%d\n",i);
		}
	i=i-1;
	printf("�v�Z���ʂ�%lf�ł��B\n",*(b+i) );
}

		//�ȉ��A�֐��錾

double tashizan(double e, double f){
	return f=e+f;
}
double hikizan(double e, double f){
	return f=e-f;
}
double kakezan(double e, double f){
	return f=e*f;
}
double warizan(double e, double f){
	return f=e/f;
}
double sina(double e){
	return e = sin(e*PI/180);
}
double cosa(double e){
	return e = cos(e*PI/180);
}
double tana(double e){
	return e = tan(e*PI/180);
}
double rutoa(double e){
	return e = sqrt(e);
}