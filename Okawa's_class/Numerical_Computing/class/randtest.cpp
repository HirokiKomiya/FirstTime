#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVAL 2140000000   //ãŒÀ@2140000000
#define STEP 100000000		//‚±‚Ì’l‚²‚Æ‚Éo—Í

double a,b;
int i;

main()
{
	for(i=0;i<100;i++){
		
		a=(double)rand();
		b=(double)RAND_MAX;
		printf("a:%f b:%f\n",a,b);
	}
}