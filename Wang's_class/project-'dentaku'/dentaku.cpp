#include<stdio.h>
#include<math.h>

main()
{
	int a=1,b;
	double c,w;
	char z,y;
	printf("���߂Ɏ���ł��B\n���̓d���2�̃��[�h����\������Ă��܂��B\n��ڂɎl�����Z���[�h�B����͓ǂ�Ŏ��̂��Ƃ��ł��B\n��ڂɊ֐��d�샂�[�h�B�O�p�֐����̌v�Z���s���܂��B\n�܂��A���̓d��͑O��̌v�Z���ʂ��L�����Ă���̂ł����p�����v�Z���\�ł��B\n");
	
	while(a==1){
	    printf("\n���Z�q��I�����ĉ������B\n�����Z:+�A�����Z:-�A�|���Z:*�A����Z:/�A�֐��d��:a\n");
	    scanf("\n%c",&z);
		if(z == 0x2b){
		    printf("a+b���v�Z���܂��Ba����͂��Ă��������B\n");
		    scanf("%d",&a);
		    printf("b����͂��Ă��������B\n");
		    scanf("%d",&b);
			c = a+b;
		    printf("%d+%d��%d�ł��B\n",a,b,a+b);}
	    if(z == 0x2d){
		    printf("a-b���v�Z���܂��Ba����͂��Ă��������B\n");
		    scanf("%d",&a);
		    printf("b����͂��Ă��������B\n");
		    scanf("%d",&b);
			c = a-b;
		    printf("%d-%d��%d�ł��B\n",a,b,a-b);}
        if(z == 0x2a){
		    printf("a*b���v�Z���܂��Ba����͂��Ă��������B\n");
		    scanf("%d",&a);
		    printf("b����͂��Ă��������B\n");
		    scanf("%d",&b);
			c =a*b;
		    printf("%d*%d��%d�ł��B\n",a,b,a*b);}
	    if(z == 0x2f){
		    printf("a/b���v�Z���܂��Ba����͂��Ă��������B\n");
		    scanf("%d",&a);
		    printf("b����͂��Ă��������B\n");
		    scanf("%d",&b);
			c = a/b;
		    printf("%d/%d��%d�ł��B\n",a,b,a/b);}
		if(z == 'a'){
			printf("�֐��d�샂�[�h�ł��B\nsin:s�Acos:t�Atan:t�A��:r\n�s�������v�Z�ɍ��킹�ăR�����̌�̕�������͂��Ă��������B");
			scanf("\n%c",&z);
			if(z == 's'){
				printf("sina���v�Z���܂��Ba����͂��Ă��������B\n");
				scanf("%d",&a);
				c =  sin(a);
				printf("sin%d��%lf�ł��B\n",a,c);}
			if(z == 'c'){
				printf("cosa���v�Z���܂��Ba����͂��Ă��������B\n");
				scanf("%d",&a);
				c =  cos(a);
				printf("cos%d��%lf�ł��B\n",a,c);}
			if(z == 't'){
				printf("tana���v�Z���܂��Ba����͂��Ă��������B\n");
				scanf("%d",&a);
				c =  tan(a*PI/180);
				printf("tan%d��%lf�ł��B\n",a,c);}/**/
			if(z == 'r'){
				printf("��a���v�Z���܂��Ba����͂��Ă��������B\n");
				scanf("%d",&a);
				c =  sqrt(a);
				printf("��%d��%lf�ł��B\n",a,c);}
		}
		
		/*�����̊Ԃɍŏ��Ɏw�肳�ꂽ�����ȊO�����͂��ꂽ�ꍇ�̓��������*/
		
			printf("\n����̌v�Z���ʂ�p����ꍇ��a���A�p���Ȃ��ꍇ��I���������ꍇ�͂���ȊO����͂��Ă��������B");
			scanf("\n%c",&y);
			while(y == 'a'){
				printf("\n���Z�q��I�����ĉ������B\n�����Z:+�A�����Z:-�A�|���Z:*�A����Z:/�A�֐��d��:a\n");
		        scanf("\n%c",&z);{
				if(z == 0x2b){
				    printf("%2f+b���v�Z���܂��B\n",c);
				    printf("b����͂��Ă��������B\n");
				    scanf("%d",&b);
					c = c + b;
				    printf("������%2f�ł��B\n",c);}
			    if(z == 0x2d){
				    printf("%2f-b���v�Z���܂��B\n",c);
				    printf("b����͂��Ă��������B\n");
				    scanf("%d",&b);
					c = c - b;
				    printf("������%2f�ł��B\n",c);}
		        if(z == 0x2a){
				    printf("%2f*b���v�Z���܂��B\n",c);
				    printf("b����͂��Ă��������B\n");
				    scanf("%d",&b);
					c = c * b;
				    printf("������%2f�ł��B\n",c);}
			    if(z == 0x2f){
				    printf("%2f/b���v�Z���܂��B\n",c);
				    printf("b����͂��Ă��������B\n");
				    scanf("%d",&b);
					c = c / b;
				    printf("������%2f�ł��B\n",c);}
					/*�ȉ��A�l�����Z�ȊO*/
				if(z == 'a'){
					printf("\n�֐��d�샂�[�h�ł��B\nsin:s�Acos:t�Atan:t�A��:r\n�s�������v�Z�ɍ��킹�ăR�����̌�̕�������͂��Ă��������B\n");
					scanf("\n%c",&z);
					if(z == 's'){
						printf("sin%2f���v�Z���܂��B\n",c);
						c =  sin(c);
						printf("������%lf�ł��B\n",c);}
					if(z == 'c'){
						printf("cos%2f���v�Z���܂��B\n",c);
						c =  cos(c);
						printf("������%lf�ł��B\n",c);}
					if(z == 't'){
						printf("tan%2f�v�Z���܂��B\n",c);
						c =  tan(c);
						printf("������%lf�ł��B\n",c);}
					if(z == 'r'){
						printf("��%2f���v�Z���܂��B\n",c);
						c =  sqrt(c);
						printf("������%lf�ł��B\n",c);}
				}
				
				/*�����̊ԂɎw�肳�ꂽ�����ȊO�����͂��ꂽ��̋���������*/
				
			printf("\n����̌v�Z���ʂ�p����ꍇ��a���A�p���Ȃ��ꍇ��I���������ꍇ�͂���ȊO����͂��Ă��������B");
			scanf("\n%c",&y);
			}
		}
		printf("�I�����܂����H\n1�ȊO�̐�������͂���ƏI�����܂��B");
		scanf("%d",&a);
	}
}
