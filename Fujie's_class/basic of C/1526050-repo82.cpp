/*������̔z�񁨃|�C���^�z��*/
#include<stdio.h>
main(){
	char* str[] ={"iron blue","ivy green","ivory","ash gray","apple green","apricot","amber","yellow","yellow ocher","wistaria",0};
	int i=0,t=0;
	while(t < 10){
		if(str[i] == 0){
			break;}/*���ׂĂ̔��ʂ��I�������while���甲����*/
		if(str[i][0] == 'y' && str[i][1] == 'e' && str[i][2] == 'l' && str[i][3] == 'l' && str[i][4] == 'o' && str[i][5] == 'w'){
			}else{/*yellow�������Ă�Ƃ��͉������Ȃ��A����ȊO��*/
				printf("%s\n",str[i]);
			}
		i++;
	}
}
	
	
	
	
	/*�ȍ~�͂���ł��ł���Ǝv���������̃v���O�����ł��B
	while(t < 10){
		i=0;
		if(str[t][i] == 0x79){}
		else{
			i++;
			if(i!=0,str[t][i] == 0x65){}
			else{
				i++;
				if(str[t][i] == 0x6c){}
				else{
					i++;
					if(str[t][i] == 0x6c){}
					else{
						i++;
						if(str[t][i] == 0x6f){}
						else{
							i++;
							if(str[t][i] == 0x77){}else{
								printf("%s\n",str[t]);
								}
							}
						}
					}
				}
			}
	t++;}
}*/
/*yellow == 0x79,0x65,0x6c,0x6c,0x6f,0x77*/