/*�o�^�Ɖ{��*/

#include<stdio.h>
#include<string.h>

struct person{
	char	name[40];
	char	address[100];
	long	phone;
};


int main(void)
{
	struct person student[100];
	int mode, l, i = 0, n = 1;
	int lan = 0;
	
	FILE  *fp, *pw;
	char  filename[] = "data_test.txt";
	
	char  pass[100];
	char  type[100];
	char  Npass[100] = "NewPass";
	char  Cpass[100];
	
	int   key = 0;
	int   k = 0;
	int   end = 0;
	
	char  str1[100]  = {'\0'};
	char  str2[40]   = "name";
	long  str3       = {'\0'};
	char  str4[100]  = {'\0'}; //(��)
	char  str5[40]   = {'\0'}; //(��)
	long  str6       = {'\0'}; //(��)
	
	printf("�o�^�� �{��\n\n");
	
	printf("�y English:1 ���{��:2 ����:3 �z\n");
	printf("Language:");
	scanf("%d", &lan);
	
	if(lan == 0){
	scanf(" %s",type);
	}
	for(k=0;k<4;k++){
		pw = fopen("password.txt", "r");
		fscanf(pw, "%s", pass);
		
		switch(lan){
			case 1:
				printf("\n***�y NewPass �zChange Password Key ***\n\n");
				printf("Password:");
			break;
			
			case 2:
				printf("\n***�y NewPass �z�p�X���[�h�ύX�L�[ ***\n\n");
				printf("�p�X���[�h:");
			break;
			
			case 3:
				printf("\n***�y NewPass �z�����X���֌� ***\n\n");
				printf("����:");
			break;
			
			default:
				printf("\n***�y NewPass �zChange Password Key ***\n\n");
				printf("Password:");
			break;
		}
		
		scanf("%s", &type);
		
		if(strcmp(pass, type)==0){//�p�X���[�h����
			switch(lan){
				case 1:
					printf("\n\n��  H E L L O  ��\n\n");
				break;
				
				case 2:
					printf("\n\n��  �� �� �� ��  ��\n\n");
				break;
				
				case 3:
					printf("\n\n��  �� �}   ��\n\n");
				break;
				
				default:
					printf("\n\n��  H E L L O  ��\n\n");
				break;
			}
			
			key = 1;
			k = 5;
		}else if(strcmp(Npass, type)==0){//�V�K�p�X���[�h
			//���p�X���[�h�m�F
			switch(lan){
				case 1:
					printf("\nOld Password:");
				break;
				
				case 2:
					printf("\n���p�X���[�h:");
				break;
				
				case 3:
					printf("\n������:");
				break;
				
				default:
					printf("\nOld Password:");
				break;
			}
			
			scanf("%s", &type);
			//�m�F����
			if(strcmp(pass, type)==0){
				fclose(pw);
				pw = fopen("password.txt", "w");
				
				switch(lan){
					case 1:
						printf("\n***�y NewPass �zNot Available! ***\n\n");
						printf("New Password:");
					break;
					
					case 2:
						printf("\n***�y NewPass �z�̓p�X���[�h�Ɏg�p�ł��Ȃ� ***\n\n");
						printf("�V�p�X���[�h:");
					break;
					
					case 3:
						printf("\n***�y NewPass �z���s�\�ݖ������g�p! ***\n\n");
						printf("�V����:");
					break;
					
					default:
						printf("\n***�y NewPass �zNot Available! ***\n\n");
						printf("New Password:");
					break;
				}
				
				scanf("%s", &pass);
				
				switch(lan){
					case 1:
						printf("\nConfirm Password:");
					break;
					
					case 2:
						printf("\n�m�F�p�X���[�h:");
					break;
					
					case 3:
						printf("\n�m�F����:");
					break;
					
					default:
						printf("\nOld Password:");
					break;
				}
				
				scanf("%s", &Cpass);
				
				if(strcmp(Cpass, pass)==0){
					switch(lan){
						case 1:
							printf("\n�� Complete ��\n");
						break;
						
						case 2:
							printf("\n�� �o�^���� ��\n");
						break;
						
						case 3:
							printf("\n�� �������� ��\n");
						break;
						
						default:
							printf("\n�� Complete ��\n");
						break;
					}
					
					fprintf(pw, "%s", pass);
					k = 0;
				}else{
					//�O�񎸔s����ƏI��
					switch(lan){
						case 1:
							printf("\n�� Different ��\n");
						break;
						
						case 2:
							printf("\n�� �m�F�ł��܂��� ��\n");
						break;
						
						case 3:
							printf("\n�� ���@暛� ��\n");
						break;
						
						default:
							printf("\n�� Different ��\n");
						break;
					}
					
					
				}
			//�m�F�s��
			}else{
				switch(lan){
					case 1:
						printf("\n�� Different ��\n");
					break;
					
					case 2:
						printf("\n�� �m�F�ł��܂��� ��\n");
					break;
					
					case 3:
						printf("\n�� ���@暛� ��\n");
					break;
					
					default:
						printf("\n�� Different ��\n");
					break;
				}
			}
			
		}else{
			switch(k){
				case 0:
					switch(lan){
						case 1:
							printf("\n\n�@ �@�@�Q�Q�Q�Q�@\n�@�@�^�@    �\   �_\n�@�^ �m�@�@ ( ��)�@�_\n �b�@( ��)�@�@�@��  |\n �b�@�@�i__�m�P�@�@ /�@Who are U?-3-\n �b�@�@�@�@�@�@�@  /\n�@�_�Q�@�@�@���R���_\n�@�@�@/�L�@�@(,�Q�_.�_\n�@ �@/   �@�@ �_�Q�m\n\n");
						break;
						
						case 2:
							printf("\n\n�@ �@�@�Q�Q�Q�Q�@\n�@�@�^�@    �\   �_\n�@�^ �m�@�@ ( ��)�@�_\n �b�@( ��)�@�@�@��  |\n �b�@�@�i__�m�P�@�@ /�@�ǂ���l�ł���?-3-\n �b�@�@�@�@�@�@�@  /\n�@�_�Q�@�@�@���R���_\n�@�@�@/�L�@�@(,�Q�_.�_\n�@ �@/   �@�@ �_�Q�m\n\n");
						break;
						
						case 3:
							printf("\n\n�@ �@�@�Q�Q�Q�Q�@\n�@�@�^�@    �\   �_\n�@�^ �m�@�@ ( ��)�@�_\n �b�@( ��)�@�@�@��  |\n �b�@�@�i__�m�P�@�@ /�@�N?-3-\n �b�@�@�@�@�@�@�@  /\n�@�_�Q�@�@�@���R���_\n�@�@�@/�L�@�@(,�Q�_.�_\n�@ �@/   �@�@ �_�Q�m\n\n");
						break;
						
						default:
							printf("\n\n�@ �@�@�Q�Q�Q�Q�@\n�@�@�^�@    �\   �_\n�@�^ �m�@�@ ( ��)�@�_\n �b�@( ��)�@�@�@��  |\n �b�@�@�i__�m�P�@�@ /�@Who are U?-3-\n �b�@�@�@�@�@�@�@  /\n�@�_�Q�@�@�@���R���_\n�@�@�@/�L�@�@(,�Q�_.�_\n�@ �@/   �@�@ �_�Q�m\n\n");
						break;
					}
					
				break;
				
				case 1:
					switch(lan){
						case 1:
							printf("\n\n�@�@   �^�P�P�P�P�_\n�@  �^�@���@�@  ��  �_\n  �^�@ �i���j�@ �i���j�_  Are U fooling me?-2-\n |�@�@�@ �i__�l__�j     |\n  �_�@�@�@ �M �܁L�@�@�^\n �^�@�@�@�@�@�@�@     �_\n");
						break;
						
						case 2:
							printf("\n\n�@�@   �^�P�P�P�P�_\n�@  �^�@���@�@  ��  �_\n  �^�@ �i���j�@ �i���j�_  ������Ɗ��ق��Ă���������... -2-\n |�@�@�@ �i__�l__�j     |\n  �_�@�@�@ �M �܁L�@�@�^\n �^�@�@�@�@�@�@�@     �_\n");
						break;
						
						case 3:
							printf("\n\n�@�@   �^�P�P�P�P�_\n�@  �^�@���@�@  ��  �_\n  �^�@ �i���j�@ �i���j�_  �Y�������I?-2-\n |�@�@�@ �i__�l__�j     |\n  �_�@�@�@ �M �܁L�@�@�^\n �^�@�@�@�@�@�@�@     �_\n");
						break;
						
						default:
							printf("\n\n�@�@   �^�P�P�P�P�_\n�@  �^�@���@�@  ��  �_\n  �^�@ �i���j�@ �i���j�_  Are U fooling me?-2-\n |�@�@�@ �i__�l__�j     |\n  �_�@�@�@ �M �܁L�@�@�^\n �^�@�@�@�@�@�@�@     �_\n");
						break;
					}
					
				break;
				
				case 2:
					switch(lan){
						case 1:
							printf("\n\n      _�Q�Q__________\n�@�@�^�@�@        �@ �_\n  �^�@�@�@_�m�@   �R�A_�_\n�^ �@�@ �i���j �@�i���j  |\n|�@ �@�@ �@ �i__�l__�j�@ |  Are U silly�H-1-\n /�@�@�@�@ ���m ���@   �^\n(�@ �_�@�^ �Q�m�@|�@|\n.�_�@�g�@�@�^�Q�Q|�@|  \n�@ �_   �^  �Q�Q�Q �^ \n");
						break;
						
						case 2:
							printf("\n\n      _�Q�Q__________\n�@�@�^�@�@        �@ �_\n  �^�@�@�@_�m�@   �R�A_�_\n�^ �@�@ �i���j �@�i���j  |\n|�@ �@�@ �@ �i__�l__�j�@ |  �����肳��A���z�ł��B-1-\n /�@�@�@�@ ���m ���@   �^\n(�@ �_�@�^ �Q�m�@|�@|\n.�_�@�g�@�@�^�Q�Q|�@|  \n�@ �_   �^  �Q�Q�Q �^ \n");
						break;
						
						case 3:
							printf("\n\n      _�Q�Q__________\n�@�@�^�@�@        �@ �_\n  �^�@�@�@_�m�@   �R�A_�_\n�^ �@�@ �i���j �@�i���j  |\n|�@ �@�@ �@ �i__�l__�j�@ |  ���... -1-\n /�@�@�@�@ ���m ���@   �^\n(�@ �_�@�^ �Q�m�@|�@|\n.�_�@�g�@�@�^�Q�Q|�@|  \n�@ �_   �^  �Q�Q�Q �^ \n");
						break;
						
						default:
							printf("\n\n      _�Q�Q__________\n�@�@�^�@�@        �@ �_\n  �^�@�@�@_�m�@   �R�A_�_\n�^ �@�@ �i���j �@�i���j  |\n|�@ �@�@ �@ �i__�l__�j�@ |  Are U silly�H-1-\n /�@�@�@�@ ���m ���@   �^\n(�@ �_�@�^ �Q�m�@|�@|\n.�_�@�g�@�@�^�Q�Q|�@|  \n�@ �_   �^  �Q�Q�Q �^ \n");
						break;
					}
					
				break;
			}
		}
		fclose(pw);
	}
	
	while(key){
		printf("\n\n");
		printf("***************************************************************************\n");
		printf("\n");
		switch(lan){
			case 1:
				printf("�y Writing:1 Reading:2 Serching:3 Delete:4 �z\n�y End:0 �z \n\n");
				printf("Select:");
			break;
			
			case 2:
				printf("�y �o�^:1 �{��:2 ����:3 �z\n�y �I��:0 �z \n\n");
				printf("�I��:");
			break;
			
			case 3:
				printf("�y ���:1 �g�T:2 �r:3 �z\n�y ��:0 �z \n\n");
				printf("�I��:");
			break;
			
			default:
				printf("�y Writing:1 Reading:2 Serching:3 �z\n�y End:0 �z \n\n");
				printf("Select:");
			break;
		}
		
		scanf("%d", &mode);
		
		switch(mode){
			//�I��
			case 0:
				key = 0;
				end = 1;
			break;
			//��������
			case 1:
				l=1;
				
				switch(lan){
					case 1:
						printf("\n��New Account��\n\n");
					break;
					
					case 2:
						printf("\n��V�K�o�^��\n\n");
					break;
					
					case 3:
						printf("\n��V������\n\n");
					break;
					
					default:
						printf("\n��New Account��\n\n");
					break;
				}
				
				while(l){
					fp = fopen(filename, "a");
					
					switch(lan){
						case 1:
							printf("name:");
						break;
						
						case 2:
							printf("���O:");
						break;
						
						case 3:
							printf("����:");
						break;
						
						default:
							printf("name:");
						break;
					}
					
					scanf("%s", &student[i].name);
					
					switch(lan){
						case 1:
							printf("address:");
						break;
						
						case 2:
							printf("�A�h���X:");
						break;
						
						case 3:
							printf("�Z��:");
						break;
						
						default:
							printf("address:");
						break;
					}
					
					scanf("%s", &student[i].address);
					
					switch(lan){
						case 1:
							printf("phone number:");
						break;
						
						case 2:
							printf("�d�b�ԍ�:");
						break;
						
						case 3:
							printf("�d�b�j��:");
						break;
						
						default:
							printf("phone number:");
						break;
					}
					
					scanf("%ld", &student[i].phone);
					
					fprintf(fp, "%s %s %ld\n", student[i].name, student[i].address, student[i].phone);
					
					fclose(fp);
					
					switch(lan){
						case 1:
							printf("\n�y Countinue:1 End:0 �z\n");
							printf("Select:");
						break;
						
						case 2:
							printf("\n�y ���͂𑱂���:1 �I��:0 �z\n");
							printf("�I��:");
						break;
						
						case 3:
							printf("\n�y ���:1 ��:0 �z\n");
							printf("�I��:");
						break;
						
						default:
							printf("\n�y Countinue:1 End:0 �z\n");
							printf("Select:");
						break;
					}
					
					scanf("%d", &l);
					
					i++;
					
					switch(lan){
						case 1:
							printf("\n�� Complete ��\n\n");
						break;
						
						case 2:
							printf("\n�� �o�^���� ��\n\n");
						break;
						
						case 3:
							printf("\n�� �������� ��\n\n");
						break;
						
						default:
							printf("\n�� Complete ��\n\n");
						break;
					}
					
				}
			break;
			//�{��
			case 2:
				switch(lan){
					case 1:
						printf("\n�� Display ��\n\n");
					break;
					
					case 2:
						printf("\n�� �{�� ��\n\n");
					break;
					
					case 3:
						printf("\n�� �g�T ��\n\n");
					break;
					
					default:
						printf("\n�� Display ��\n\n");
					break;
				}
				
				
				fp = fopen(filename, "r");
				
				n=1;
				
				while(n){
					fscanf(fp, "%s %s %ld", str1, str2, &str3);
					
					//����adress���ǂ�������
					if(strcmp(str2, str5)==0){
						n = 0;
					}else{
						printf("%s %s %ld\n", str1, str2, str3);
					}
					
					strcpy(str2, str5);
					
				}
				
				fclose(fp);
			break;
			//����
			case 3:
				//name����
				switch(lan){
					case 1:
						printf("Searching name:");
					break;
					
					case 2:
						printf("���O����:");
					break;
					
					case 3:
						printf("���i����:");
					break;
					
					default:
						printf("Searching name:");
					break;
				}
				
				scanf("%s", &str4);
				
				switch(lan){
					case 1:
						printf("\n�� Result ��\n\n");
					break;
					
					case 2:
						printf("\n�� �������� ��\n\n");
					break;
					
					case 3:
						printf("\n�� �r������ ��\n\n");
					break;
					
					default:
						printf("\n�� Result ��\n\n");
					break;
				}
				
				fp = fopen(filename, "r");
				
				n=1;
				
				while(n){
					fscanf(fp, "%s %s %ld", str1, str2, &str3);
					
					//str1�̒�����str4�ɂ�����������邩����
					if(strstr(str1, str4) != NULL && fscanf(fp,"%s ", str1) != EOF){
						printf("%s %s %ld\n", str1, str2, str3);
						n=1;
						printf("\n%s",str2);
					}else if(strcmp(str2,str5) == 0  | fscanf(fp,"%s",str1) == EOF){
						switch(lan){
							case 1:
								printf("�� None... ��");
							break;
							
							case 2:
								printf("�� �Y���Ȃ�... ��");
							break;
							
							case 3:
								printf("�� �s�K�p... ��");
							break;
							
							default:
								printf("�� None... ��");
							break;
						}
						
						n = 0;
						printf("\n%s",str2);
					}
					
					strcpy(str2, str5);
					
					
				}
				
				fclose(fp);
			break;
			
			default:
				switch(lan){
					case 1:
						printf("Error\n\n");
					break;
					
					case 2:
						printf("�Ή��o���܂���\n\n");
					break;
					
					case 3:
						printf("����\n\n");
					break;
				}
			break;
		}
	}
	if(end == 1){
		//���K�I��
		switch(lan){
			case 1:
				printf("\n	  �@ ________\n�@�@�@�@�@/�@�@�@�@�@�@�_\n�@ _�@ �^ ��           �܁_ \n�@( | /   -==�A       (��)�R  �@Thank U for playing�I \n�@| |�b   ��    (_�l_) ��  | \n|�P)�R�_         �R�m     �m \n|�P) | /�@�@      �@�@�@�_\n");
			break;
			
			case 2:
				printf("\n	  �@ ________\n�@�@�@�@�@/�@�@�@�@�@�@�_\n�@ _�@ �^ ��           �܁_ \n�@( | /   -==�A       (��)�R  �@�܂��A���ł��J���Ă���I \n�@| |�b   ��    (_�l_) ��  | \n|�P)�R�_         �R�m     �m \n|�P) | /�@�@      �@�@�@�_\n");
			break;
			
			case 3:
				printf("\n	  �@ ________\n�@�@�@�@�@/�@�@�@�@�@�@�_\n�@ _�@ �^ ��           �܁_ \n�@( | /   -==�A       (��)�R  �@�ӎ�, �Č��I \n�@| |�b   ��    (_�l_) ��  | \n|�P)�R�_         �R�m     �m \n|�P) | /�@�@      �@�@�@�_\n");
			break;
			
			default:
				printf("\n	  �@ ________\n�@�@�@�@�@/�@�@�@�@�@�@�_\n�@ _�@ �^ ��           �܁_ \n�@( | /   -==�A       (��)�R  �@Thank U for playing�I \n�@| |�b   ��    (_�l_) ��  | \n|�P)�R�_         �R�m     �m \n|�P) | /�@�@      �@�@�@�_\n");
			break;
		}
	}else{
		//�s���I��
		switch(lan){
			case 1:
				printf("     �Q�Q�Q�Q�Q\n�@ �^ �@�@�@�@  �_\n �^�@ �� �@�@ �\ �R�@Overe the rainbow...\n|�@�i ���j �i ���j\n|�@�@�@�i_�l_�j�@ |\n �_�@�@�@�@�@�@�@�^\n �^�@�@�@�@�@�@�@�R( :3\n �@�@�@�@�@�@�@�@(;�@:3\n �@�@ i�@�@�^�Or �P�Pi\n �@�@ l�@ /�@ �m�A�Q�m\n �@�@ l �^�@�@r �@�@l");
			break;
			
			case 2:
				printf("     �Q�Q�Q�Q�Q\n�@ �^ �@�@�@�@  �_\n �^�@ �� �@�@ �\ �R�@���ƂƂ�����\n|�@�i ���j �i ���j\n|�@�@�@�i_�l_�j�@ |\n �_�@�@�@�@�@�@�@�^\n �^�@�@�@�@�@�@�@�R( :3\n �@�@�@�@�@�@�@�@(;�@:3\n �@�@ i�@�@�^�Or �P�Pi\n �@�@ l�@ /�@ �m�A�Q�m\n �@�@ l �^�@�@r �@�@l");
			break;
			
			case 3:
				printf("     �Q�Q�Q�Q�Q\n�@ �^ �@�@�@�@  �_\n �^�@ �� �@�@ �\ �R�@�M�\n|�@�i ���j �i ���j\n|�@�@�@�i_�l_�j�@ |\n �_�@�@�@�@�@�@�@�^\n �^�@�@�@�@�@�@�@�R( :3\n �@�@�@�@�@�@�@�@(;�@:3\n �@�@ i�@�@�^�Or �P�Pi\n �@�@ l�@ /�@ �m�A�Q�m\n �@�@ l �^�@�@r �@�@l");
			break;
			
			default:
				printf("     �Q�Q�Q�Q�Q\n�@ �^ �@�@�@�@  �_\n �^�@ �� �@�@ �\ �R�@Overe the rainbow...\n|�@�i ���j �i ���j\n|�@�@�@�i_�l_�j�@ |\n �_�@�@�@�@�@�@�@�^\n �^�@�@�@�@�@�@�@�R( :3\n �@�@�@�@�@�@�@�@(;�@:3\n �@�@ i�@�@�^�Or �P�Pi\n �@�@ l�@ /�@ �m�A�Q�m\n �@�@ l �^�@�@r �@�@l");
			break;
		}
	}
	
	return 0;
}