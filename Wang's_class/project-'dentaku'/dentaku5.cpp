#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.1415926
main()
{
	int a=1,b;												//a�͑��s�t���O
	double c,w;												//���ڈȍ~�̌v�Z�Ŏg�p�B
	char z,y,x;												//y�͌v�Z���ʂ��g�����̃t���O�Bx,z�̓��[�h�U�蕪����switch�Ɏg�p�B
	int ran,rana,d,t;										//Extra���[�h�Ŏg�p����ϐ�
	double e[100];												//Extra���[�h�̎l�����Z�Ŏg�p�����
	char ex[100];												//���Be�͐����Aex�͉��Z�q������B
	int i=0;														//i�͉���ڂ��̃J�E���g������B
	
	while(a==1){
	    printf("\n���Z�q��I�����ĉ������B\n�����Z:+�A�����Z:-�A�|���Z:*�A����Z:/�A�֐��d��:a�AExtra���[�h:q\n");
	    scanf("\n%c",&z);
		ran = rand();
		switch(z){											//�P��ڂ̌v�Z�̃��[�h�U�蕪��
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
			case'a':								//�֐��d�샂�[�h(����)
				printf("�֐��d�샂�[�h�ł��B\nsin:s�Acos:c�Atan:t�A��:r\n�s�������v�Z�ɍ��킹�ăR�����̌�̕�������͂��Ă��������B");
				scanf("\n%c",&x);
				switch(x){							//�֐��d�샂�[�h�̒��̃��[�h�U�蕪��
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
					default:					//�֐��d�샂�[�h�̒��̗�O����
			        printf("���Z�q���Ԉ���Ă��܂�\n");
				}
			break;
			case'q':												//Extra���[�h
				printf("Extra���[�h�ł��B\n�W�����P�����[�h:a�A�A���v�Z���[�h:b�A�����N�����[�h:c\n");
				scanf("\n%c",&x);
				switch(x){											//Extra���[�h�U�蕪��
					case'a':										//���̃P�[�X�ɓ��������_�Ńt���Ox�͗����Ă���B
						while(x=='a'){									//�ȉ��A�W�����P�����[�h
							printf("\n�W�����P�����[�h�ł��B\n");
							ran = rand();								//�����_���֐�
							rana = ran % 3;								//rana��0��1��2
							printf("�O�[:0�A�`���L:1�A�p�[:2\n");		//�������o���ڂ�I��
							scanf("\n%d",&d);
							switch(rana){								//
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
							scanf("\n%c",&x);					//�t���Ox�̔���
						}
						break;
						case'b':								//���̑��̃��[�h�Q
							i=0;
							printf("\n�A���v�Z���[�h�ł��B\n���̃��[�h�ł͎l�����Z�̂݁A'='�����͂����܂ňꊇ�v�Z���ł��܂��B�������|���Z����Z�͗D�悳��܂���B\n");
							while(ex[i-1] != '='){
								scanf("\n%lf",&e[i]);	//������ǂݍ���
								
								scanf("\n%c",&ex[i]);	//������ǂݍ��݁B�����ƕ�����łP�Z�b�g
								
								if(i !=0){				//i��1����v�Z���J�n����B
									switch(ex[i-1]){
										case'+':
										e[i] = e[i-1] + e[i];
										break;
										case'-':
										e[i] = e[i-1] - e[i];
										break;
										case'*':
										e[i] = e[i-1] * e[i]; 
										break;
										case'/':
										if(e[i] != 0){
										e[i] = e[i-1] / e[i];		//����l��0�̎��ɂ͌v�Z���Ȃ�
										}else
										e[i] = e[i-1];
										break;
										default:
										e[i] = e[i-1];
									}
								}else;
							i++;					//�J�E���g�𑝂₷�B
							}
						printf("�v�Z���ʂ�%lf�ł��B\n",e[i-1]);			//�]����1�������J�E���g�������ē������o�́B
						break;
						case'c':								//���̑��̃��[�h�R�B���|�̎����N�����[�h�B
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
							}else
								printf("�����N�����ی�����܂����B\n");
							
						break;
						default:								//Extra���[�h�̗�O����
						printf("���̃��[�h�͂Ȃ���\n");
				}
			break;
			default:											//���Z�q�I���̗�O����
			printf("���Z�q���Ԉ���Ă��܂�\n");
			}													//���ڂ̌v�Z�����܂ŁB
			if(z == '+' | z == '-' | z == '*' | z == '/' | z == 'a'){				//���ڂŌv�Z���s�����Ƃ��̂ݓ��ڂ̌v�Z�ɐi�ށB
				printf("\n����̌v�Z���ʂ�p����ꍇ��a���A�p���Ȃ��ꍇ��I���������ꍇ�͂���ȊO����͂��Ă��������B");
				scanf("\n%c",&y);													//�t���Oy�𗧂Ă邩�ۂ�
				while(y == 'a'){													//��������Q��ڈȍ~�̌v�Z�B�O�̌v�Z���ʂ�ϐ�c�ɕۑ����A�����p�����v�Z������B
					printf("\n���Z�q��I�����ĉ������B\n�����Z:+�A�����Z:-�A�|���Z:*�A����Z:/�A�֐��d��:a\n");
			        scanf("\n%c",&z);												//���Z�q�̑I��
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
						    printf("������%2f�ł��B\n",c);			//����l��0�̎��͌v�Z���Ȃ�
							}else
							printf("0�ł͊���܂���B\n");
						break;
						case'a':									//�֐����[�h
							printf("�֐��d�샂�[�h�ł��B\nsin:s�Acos:c�Atan:t�A��:r\n�s�������v�Z�ɍ��킹�ăR�����̌�̕�������͂��Ă��������B");
							scanf("\n%c",&z);
							switch(z){								//�֐����[�h�̐U�蕪��
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
								default:							//�֐����[�h�̗�O����
			                    printf("���Z�q���Ԉ���Ă��܂�\n");
							}
						break;
						default:									//���Z�q�I���̗�O����
			            printf("���Z�q���Ԉ���Ă��܂�\n");
						}
					printf("\n����̌v�Z���ʂ�p����ꍇ��a���A�p���Ȃ��ꍇ��I���������ꍇ�͂���ȊO����͂��Ă��������B");
	            	scanf("\n%c",&y);								//�J��Ԃ����ǂ����̃t���O����
				}
				
		}else;
		printf("�I�����܂����H\n1�ȊO�̐�������͂���ƏI�����܂��B");
		scanf("%d",&a);						//�t���Oa�𗧂Ă邩�ۂ�
		
	}
}