typedef struct {
	double real;
	double image;
} dcomplex_t;

typedef struct {
	double *firdfcoef;
	double *firdfx;
	int firdflen;
	int ptr;
} firdf_t;

/*#define WORKSIZE 256
#define FREQDSIZE (WORKSIZE/2)+1*/

#ifndef M_PI
#define M_PI 3.14159265358979
#endif
