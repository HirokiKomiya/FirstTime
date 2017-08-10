void savereal(double r[],int size,char *fname);
void savecmp(dcomplex_t c[],int size,char *fname);
void real2cmp(double r[],dcomplex_t c[],int size);
void cmp2real(dcomplex_t c[],double r[],int size);
void movecmp(dcomplex_t s[],dcomplex_t d[],int size);
void movereal(double s[],double d[],int size);
void compress(dcomplex_t x[],int size);
void expand(dcomplex_t x[],int size);
void makepower(dcomplex_t s[],double pow[],int size,int mode);
void makecross(dcomplex_t x[],dcomplex_t y[],dcomplex_t crs[],int size,int mode);
void makecohe(double psx[], double psy[], dcomplex_t crs[],double cohe[],int size);
/* mode -1:clear&calc, 0:calc&add, 0<m:calc,add&normarize by m */
void makecoheop(double pow[],double cohe[],double cohepow[],int size);
void makexfunc(double psx[], dcomplex_t crs[], dcomplex_t trans[],int size);
void hanning(dcomplex_t data[],int size);
void hamming(dcomplex_t data[],int size);
void rectwindow(dcomplex_t data[],int size,int lowerlimit,int upperlimit);
void fft(int cdir,dcomplex_t x[],int size);
void initfft(int fftsize);
void windowout(void);






