#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.1415926
main()
{
	int a=1,b;
	double c,w;
	char z,y,x;
	int ran,rana,d,t;										//���̑��̃��[�h�Ŏg�p����ϐ�
	
	while(a==1){
	    printf("\n���Z�q��I�����ĉ������B\n�����Z:+�A�����Z:-�A�|���Z:*�A����Z:/�A�֐��d��:a�AExtra���[�h:q\n");
	    scanf("\n%c",&z);
		ran = rand();
		switch(z){
			case'+':
				printf("a+b���v�Z���܂��Ba����͂��Ă��������B\n");
			    scanf("%d",&a);
			    printf("b����͂��Ă��������B\n");
			    scanf("%d",&b);
				c = a+b;
			    printf("%d+%d��%d�ł��B\n",a,b,a+b);
			break;
			case'-':
				printf("a-b���v�Z���܂��Ba����͂��Ă��������B\n");
			    scanf("%d",&a);
			    printf("b����͂��Ă��������B\n");
			    scanf("%d",&b);
				c = a-b;
			    printf("%d-%d��%d�ł��B\n",a,b,a-b);
			break;
			case'*':
				printf("a*b���v�Z���܂��Ba����͂��Ă��������B\n");
			    scanf("%d",&a);
			    printf("b����͂��Ă��������B\n");
			    scanf("%d",&b);
				c =a*b;
			    printf("%d*%d��%d�ł��B\n",a,b,a*b);
			break;
			case'/':
				printf("a/b���v�Z���܂��Ba����͂��Ă��������B\n");
			    scanf("%d",&a);
			    printf("b����͂��Ă��������B\n");
			    scanf("%d",&b);
				if(b != 0){
				c = a/b;
			    printf("%d/%d��%d�ł��B\n",a,b,a/b);
				}else
				printf("0�ł͊���܂���B\n");
			break;
			case'a':
				printf("�֐��d�샂�[�h�ł��B\nsin:s�Acos:c�Atan:t�A��:\n�s�������v�Z�ɍ��킹�ăR�����̌�̕�������͂��Ă��������B");
				scanf("\n%c",&z);
				switch(z){
					case's':
						printf("sina���v�Z���܂��Ba����͂��Ă��������B\n");
						scanf("%d",&a);
						c =  sin(a*PI/180);
						printf("sin%d��%lf�ł��B\n",a,c);
					break;
					case'c':
						printf("cosa���v�Z���܂��Ba����͂��Ă��������B\n");
						scanf("%d",&a);
						c =  cos(a*PI/180);
						printf("cos%d��%lf�ł��B\n",a,c);
					break;
					case't':
						printf("tana���v�Z���܂��Ba����͂��Ă��������B\n");
						scanf("%d",&a);
						c =  tan(a*PI/180);
						printf("tan%d��%lf�ł��B\n",a,c);
					break;
					case'r':
						printf("��a���v�Z���܂��Ba����͂��Ă��������B\n");
						scanf("%d",&a);
						c =  sqrt(a);
						printf("��%d��%lf�ł��B\n",a,c);
					break;
					default:
			        printf("���Z�q���Ԉ���Ă��܂�\n");
				}
			break;
			case'q':												//���̑��̃��[�h
				printf("Extra���[�h�ł��B\n�W�����P�����[�h:a�A�A���v�Z���[�h:b�A�����N�����[�h:c\n");
				scanf("\n%c",&x);
				switch(x){											//���̑��̃��[�h�U�蕪��
					case'a':
						while(x=='a'){									//�W�����P�����[�h
							printf("�W�����P�����[�h�ł��B\n");
							ran = rand();								//�����_���֐�
							rana = ran % 3;
							printf("�O�[:0�A�`���L:1�A�p�[:2\n");			//�������o����
							scanf("\n%d",&d);
							switch(rana){
								case 0:									//�G�̓O�[
									switch(d){
										case 0:
											printf("������\n");
										break;
										case 1:
											printf("���Ȃ��̕���\n");
										break;
										case 2:
											printf("���Ȃ��̏����ł�\n");
										break;
										default:
										printf("��������\n");
									}
								break;
								case 1 :									//�`���L
									switch(d){
											case 0 :
												printf("���Ȃ��̏����ł�\n");
											break;
											case 1 :
												printf("������\n");
											break;
											case 2 :
												printf("���Ȃ��̕����ł�\n");
											break;
											default:
											printf("��������\n");
										}
								break;
								case 2 :									//�p�[
									switch(d){
										case 0 :
											printf("���Ȃ��̕����ł�\n");
										break;
										case 1 :
											printf("���Ȃ��̏����ł�\n");
										break;
										case 2 :
											printf("�������ł�\n");
										break;
										default:
										printf("��������\n");
									}
								break;
							}
							printf("�����ăW�����P������ꍇ�́ha�h����͂��ĉ������B\n");
							scanf("\n%c",&x);
						}
						break;
						case'b':								//���̑��̃��[�h�Q
							printf("�A���v�Z���[�h�ł��B\n���̃��[�h�ł͎l�����Z�̂݁A�ꊇ�v�Z���ł��܂��B�������|���Z����Z�͗D�悳��܂���B");
							
							
							/*�z��d�������B*/
							
						break;
						case'c':								//���̑��̃��[�h�R
							printf("�����N���������܂����H\nyes:y�Ano:n\n");
							scanf("\n%c",&x);
							if(x != 'n'){
								for(t=1;t<=30000;t++)
									{
									printf("�����N����������܂����B\n");
									}
									while(1){
										ran = rand();
										printf("%d %c%c%d",ran,x,y,ran);
								}
							}else{
								printf("�����N�����ی�����܂����B\n");
							}
						break;
						default:
						printf("���̃��[�h�͂Ȃ���\n");
				}
			break;
			default:
			printf("���Z�q���Ԉ���Ă��܂�\n");
			}
			if(z != 'q' | z=='s'){
				printf("\n����̌v�Z���ʂ�p����ꍇ��a���A�p���Ȃ��ꍇ��I���������ꍇ�͂���ȊO����͂��Ă��������B");
				scanf("\n%c",&y);
				while(y == 'a'){
					printf("\n���Z�q��I�����ĉ������B\n�����Z:+�A�����Z:-�A�|���Z:*�A����Z:/�A�֐��d��:a\n");
			        scanf("\n%c",&z);
					switch(z){
						case'+':
							printf("%2f+b���v�Z���܂��B\n",c);
						    printf("b����͂��Ă��������B\n");
						    scanf("%d",&b);
							c = c+b;
						    printf("������%2f�ł��B\n",c);
						break;
						case'-':
							printf("%2f-b���v�Z���܂��B\n",c);
						    printf("b����͂��Ă��������B\n");
						    scanf("%d",&b);
							c = c-b;
						    printf("������%2f�ł��B\n",c);
						break;
						case'*':
							printf("%2f*b���v�Z���܂��B\n",c);
						    printf("b����͂��Ă��������B\n");
						    scanf("%d",&b);
							c =c*b;
						    printf("������%2f�ł��B\n",c);
						break;
						case'/':
							printf("%2f/b���v�Z���܂��B\n",c);
						    printf("b����͂��Ă��������B\n");
						    scanf("%d",&b);
							if(b != 0){
							c = c/b;
						    printf("������%2f�ł��B\n",c);		//����l��0�̎��ɂ̓u���C�N���悤
							}else
							printf("0�ł͊���܂���B\n");
						break;
						case'a':
							printf("�֐��d�샂�[�h�ł��B\nsin:s�Acos:c�Atan:t�A��:r\n�s�������v�Z�ɍ��킹�ăR�����̌�̕�������͂��Ă��������B");
							scanf("\n%c",&z);
							switch(z){
								case's':
									printf("sin%2f���v�Z���܂��B\n",c);
									c =  sin(c*PI/180);
									printf("������%lf�ł��B\n",c);
								break;
								case'c':
									printf("cos%2f���v�Z���܂��B\n",c);
									c =  cos(c*PI/180);
									printf("������%lf�ł��B\n",c);
								break;
								case't':
									printf("tan%2f���v�Z���܂��B\n",c);
									c =  tan(c*PI/180);
									printf("����%lf�ł��B\n",c);
								break;
								case'r':
									printf("��%2f���v�Z���܂��B\n",c);
									c =  sqrt(c);
									printf("������%lf�ł��B\n",c);
								break;
								default:
			                    printf("���Z�q���Ԉ���Ă��܂�\n");
							}
						break;
						default:
			            printf("���Z�q���Ԉ���Ă��܂�\n");
						}
					printf("\n����̌v�Z���ʂ�p����ꍇ��a���A�p���Ȃ��ꍇ��I���������ꍇ�͂���ȊO����͂��Ă��������B");
	            	scanf("%c",&y);
				}
				
		}else
		printf("�I�����܂����H\n1�ȊO�̐�������͂���ƏI�����܂��B");
		scanf("%d",&a);
		
	}
	printf("�I�����܂����H\n1�ȊO�̐�������͂���ƏI�����܂��B");
		scanf("%d",&a);
}