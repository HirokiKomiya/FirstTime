#include <stdio.h>
#include<stdlib.h>
#define n 10	//—”‚ÌŒÂ”
#define m 10	//—”‚ÌãŒÀ

int main(){
	int i, x;
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<n;i++){
		x = (int)( rand() / (double)RAND_MAX * m);
		printf("%d\n",x);
	}
	return 0;
}
