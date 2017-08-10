#include <stdio.h>
#include <math.h>

main(){
	double theta;
	int s,c,t;
	for(theta = 0.0; theta <= 2.0*M_PI; theta += M_PI/2000){
	s = sin(theta);
	c = cos(theta);
	t = tan(theta);
	printf("%lf %lf %lf %lf %lf %lf %lf",theta,s,c,t,s*s,c*c,s/c);
	}
	return 0;
}
/*floor ¨Ø‚èŽÌ‚ÄB*/