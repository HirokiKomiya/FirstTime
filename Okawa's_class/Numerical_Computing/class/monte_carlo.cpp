
//EVAL�@���
//sum�@������W�𔭐���������
//in�@if���̏����𖞂���(�~�̓���)�ꍇ��1�𑫂�

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVAL 1000000000   // bil.
#define STEP 100000		//���̒l���Ƃɏo��

double rand01()
{
	return( (double)rand() / (double)RAND_MAX );
}

int main()
{
	int i, sum = 0, in = 0;
	double x, y, p;

	srand( (unsigned)time(NULL) );
	for( i = 0; i < EVAL; i++ )
	{
		x = rand01();
		y = rand01();

		sum++;
		if( (x-0.5)*(x-0.5)+(y-0.5)*(y-0.5) <= 0.25 )
			in++;
		if(!( i % STEP ))
		{
			// in/sum(S), in/sum/0.5/0.5(pi)
			p = (double)in / (double)sum / 0.25;
			printf( "%10d\t%20.18lf\n", i, p );
		}
	}
	return 0;
}
