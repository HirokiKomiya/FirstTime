/* 
 * C����̃T���v���v���O���� - Webkaru 
 * - �z��Ɋi�[�������l�������\�[�g - 
*/ 

#include <stdio.h> 

int main(void){
	int i, j, tmp; 
	
	/* ���l���i�[����z�� */ 
	int number[100]; 
	/* ���l�̑�������� */ 
	int total; 
	printf("���͂��鐔�l�̑��� = "); 
	scanf("%d", &total); 
	
	/* �z��Ɋi�[���鐔�l����� */ 
	printf("%d�̐��l����� \n", total); 
	
	for (i=0; i<total; ++i) 
		scanf("%d", &number[i]); 
	
	/* ���l�������Ƀ\�[�g */ 
	for(i=0; i<total; ++i) { 
		for(j=i+1; j<total; ++j) { 
			if(number[i] > number[j]) {
	  		tmp =  number[i]; 
			number[i] = number[j]; 
			number[j] = tmp; 
		} 
	} 
} 

  /* �����\�[�g�������l���o�� */ 
  printf("�����\�[�g�������l\n"); 
  for (i=0; i<total; ++i) 
    printf("%d\n", number[i]); 
}
