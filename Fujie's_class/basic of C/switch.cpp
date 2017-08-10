#include <stdio.h>
main(){
char sw;

while(1){	
scanf("\n%c",&sw);
switch(sw){

	case'+':
	printf("+\n");
	break;
	
	case'-':
	printf("-\n");
	break;
	
	case'*':
	printf("*\n");
	break;
	
	case'/':
	printf("/\n");
	break;
	
	default:
	printf("other\n");
}
}
}