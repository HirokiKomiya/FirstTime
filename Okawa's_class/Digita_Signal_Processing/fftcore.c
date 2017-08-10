#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "common.h"
#include "fftcore.h"

static double *sintable;
static double *costable;
static int *bitrev;

static void *getmemory(size_t size)
{
	char *error="memory not available\n";
	void *ptr;
	ptr=malloc(size);
	if (ptr==NULL) {
		fprintf(stderr,error);
		exit(1);
	}
	return ptr;
}


static char *fileerror="file[%s] can't open\n";

/*実数配列のファイルへの書き出し*/
/* 実数配列double r[]（配列の有効長さはsize）を
   ファイル名前fnameを付けて，ファイルへ書き出す．*/
void savereal(double r[],int size,char *fname)
{
	FILE *fp;
	int i;
	fp=fopen(fname,"w");
	if (fp==NULL) {
		fprintf(stderr,fileerror,fname);
		exit(1);
	}
	for (i=0;i<size;i++) {
		fprintf(fp,"%4d\t%e\n",i,r[i]);
	}
	fclose(fp);
}

/*複素数数配列のファイルへの書き出し*/
/* 複素数配列double r[]（配列の有効長さはsize）を
   ファイル名前fnameを付けて，ファイルへ書き出す．*/
void savecmp(dcomplex_t c[],int size,char *fname)
{
	FILE *fp;
	int i;
	fp=fopen(fname,"w");
	if (fp==NULL) {
		fprintf(stderr,fileerror,fname);
		exit(1);
	}
	for (i=0;i<size;i++) {
		fprintf(fp,"%4d\t%e\t%e\n",i,c[i].real,c[i].image);
	}
	fclose(fp);
}

/*実数配列の複素数配列へのコピー*/
/* 実数配列double r[]を複素数配列dcomplex_t c[]へコピーする．
   コピーする個数はsizeである．
   複素数配列の虚数部には０が入る．*/
void real2cmp(double r[],dcomplex_t c[],int size)
{
	int i;
	for (i=0;i<size;i++) {
		c[i].real=r[i];
		c[i].image=0.0;
	}
}

/*複素数配列の実数配列へのコピー*/
/* 複素数配列dcomplex_t c[]を実数配列double r[]へコピーする．
   コピーする個数はsizeである．
   複素数配列の虚数部は捨てられる．*/
void cmp2real(dcomplex_t c[],double r[],int size)
{
	int i;
	for (i=0;i<size;i++) {
		r[i]=c[i].real;
	}
}

/*複素数配列間のコピー*/
/* 複素数配列dcomplex_t s[]を複素数配列dcomplex_t d[]へコピーする．
   コピーする個数はsizeである．
*/
void movecmp(dcomplex_t s[],dcomplex_t d[],int size)
{
	int i;
	for (i=0;i<size;i++) {
		d[i]=s[i];
	}
}

/*実数配列間のコピー*/
/* 実数配列dcomplex_t s[]を実数配列dcomplex_t d[]へコピーする．
   コピーする個数はsizeである．
*/
void movereal(double s[],double d[],int size)
{
	int i;
	for (i=0;i<size;i++) {
		d[i]=s[i];
	}
}

void compress(dcomplex_t x[],int size)
/*compress frequency domain data using symmetry*/
{
	int half,i;
	half=size>>1;
	for (i = 1; i<half; i++) {
		x[i].real=(x[i].real+x[size-i].real)/2.0;
		x[i].image=(x[i].image-x[size-i].image)/2.0;
	}
}

void expand(dcomplex_t x[],int size)
/*expand frequency domain data using symmetry*/
{
	int half,i;
	half=size>>1;
	for (i = 1; i<half; i++) {
		x[size-i].real=x[i].real;
		x[size-i].image=-x[i].image;
	}
}

void makepower(dcomplex_t s[],double pow[],int size,int mode)
/* s: spectrum          (input) */
/* pow: power spectrum (output) */
/* size:size of data */
/* mode -1:clear&calc, 0:calc&add, 0<m:calc,add&normarize by m */
{
	int i;
	double div;
	
	if (mode==-1) {
		for (i=0; i<size; i++) pow[i]=0.0;
	}
	for (i = 0; i<size; i++) {
		pow[i]+=s[i].real*s[i].real+s[i].image*s[i].image;
	}
	if (0<mode) {
		div=1./(double)mode;
		for (i = 0; i<size; i++) {
			pow[i]*=div;
		}
	}
}

void makecross(dcomplex_t x[],dcomplex_t y[],dcomplex_t crs[],int size,int mode)
/* x,y: spectrum        (input) */
/* crs: cross spectrum (output) */
/* size:size of data */
/* mode -1:clear&calc, 0:calc&add, 0<m:calc,add&normarize by m */
/* cross=y*conj(x)=(yr+j*yi)(xr-j*xi) = (xr*yr+xi*yi) + j*(xr*yi-xi*yr) */ 
{
	int i;
	double div;
	static dcomplex_t zero={0.0,0.0};
	
	if (mode==-1) {
		for (i = 0; i<size; i++) crs[i]=zero;
	}
	for (i = 0; i<size; i++) {
		crs[i].real+=x[i].real*y[i].real+x[i].image*y[i].image;
		crs[i].image+=x[i].real*y[i].image-x[i].image*y[i].real;
	}
	if (0<mode) {
		div=1./(double)mode;
		for (i = 0; i<size; i++) {
			crs[i].real*=div;
			crs[i].image*=div;
		}
	}
}

void makecohe(double psx[], double psy[], dcomplex_t crs[],double cohe[],int size)
/* psx,psy: power spectrum, crs: cross spectrum  (input) */
/* cohe:    coherence                           (output) */
/* size:    size of data */
{
	int i;
	double tmp0,tmp1;
	for (i = 0; i<size; i++) {
		tmp0=psx[i]*psy[i];
		if (tmp0!=0.0) {
			tmp1=crs[i].real*crs[i].real+crs[i].image*crs[i].image;
			cohe[i]=tmp1/tmp0;
		} else {
			cohe[i]=0.0;
		}
	}
}

void makecoheop(double pow[],double cohe[],double cohepow[],int size)
/* pow:     power                               (input) */
/* cohe:    coherence                           (input) */
/* cohepow: coherence output power             (output) */
/* size:    size of data */
{
	int i;
	for (i = 0; i<size; i++) {
		cohepow[i]=pow[i]*cohe[i];
	}
}

void makexfunc(double psx[], dcomplex_t crs[], dcomplex_t trans[],int size)
/* psx: power spectrum, crs: cross spectrum  (input) */
/* trans:    transfer function              (output) */
/* size:    size of data */
{
	int i;
	for (i = 0; i<size; i++) {
		if (psx[i]!=0.0) {
			trans[i].real=crs[i].real/psx[i];
			trans[i].image=crs[i].image/psx[i];
		} else {
			trans[i].real=0.0;
			trans[i].image=0.0;
		}
	}
}

/*hanning window*/
/* dcomplex_t data[size]にハニング窓をかける．*/
void hanning(dcomplex_t data[],int size)
{
	int i;
	for (i = 0; i<size; i++) {
		/*data[i].real*=0.5-0.5*cos(omg*i);*/
		data[i].real*=0.5-0.5*costable[i];
	}
}

/*hamming window*/
/* dcomplex_t data[size]にハミング窓をかける．*/
void hamming(dcomplex_t data[],int size)
{
	int i;
	for (i = 0; i<size; i++) {
		/*data[i].real*=0.54-0.46*cos(omg*i);*/
		data[i].real*=0.54-0.46*costable[i];
	}
}

/*rectangle window*/
/* dcomplex_t data[size]に矩形窓をかける．
   ０から数えてlowerlimit番目からupperlimit番目までのデータが残る．*/
void rectwindow(dcomplex_t data[],int size,int lowerlimit,int upperlimit)
{
	int i;
	for (i = 0; i<lowerlimit; i++) {
		data[i].real=0.0;
		data[i].image=0.0;
	}
	for (i = upperlimit+1; i<size; i++) {
		data[i].real=0.0;
		data[i].image=0.0;
	}
}

static int staticsize;

void fft(int cdir,dcomplex_t x[],int size)
/* ==============================================
:												:
:	Fast Fourier Transform						:
:	cdir=1 ......  normal FFT					:
:	cdir=-1 .....  inverse FFT					:
:	cdir=-2 .....  inverse FFT(1/FFTSIZE)		:
:	cdir=2 ......  normal FFT(*FFTSIZE)			:
:												:
=============================================== */
{
	int npow=0,tmp=1,mask1;
	int i,j,l,le,le1,ip,omg,unit;
	double wr,wi,tr,ti,sr,si;
	double *xri,*xrj,*xii,*xij;
	double dvd;
	dcomplex_t ctmp;
	
	if (staticsize!=size) {
		printf("The size is different from the size defined in initfft function\n");
		exit(1);
	}
	dvd=1.0/(double)size;
	while (tmp<size) {
		tmp<<=1;
		npow++;
	}
	mask1=size-1;

	#ifdef DEBUG
		printf("fft\n");
	#endif
	#ifdef DEBUG
		for (i = 0; i<size; i++) printf("%6f %6f   ",x[i].real,x[i].image);
		printf("\n");
	#endif
	for (l=1;l<=npow;l++){
		le=2<<(npow-l);
		le1=le>>1;
		unit=1<<(l-1);
		omg=0;
		for (ip=0;ip<le1;ip++){
			wr=costable[(omg)&mask1];
			/*wr=indexcos(omg);*/
			wi=sintable[omg&mask1];
			/*wi=indexsin(omg);*/
			if (cdir>0) wi=-wi;
			for (i=ip;i<size;i+=le){
				j=i+le1;
				tr=*(xri=&x[i].real)+*(xrj=&x[j].real);
				ti=*(xii=&x[i].image)+*(xij=&x[j].image);
				sr=*xri-*xrj;
				si=*xii-*xij;
				*xri=tr;
				*xii=ti;
				*xrj=sr*wr-si*wi;
				*xij=sr*wi+si*wr;
			}
			omg+=unit;
		}
	}

	/*  bit reversal  */
	for (i=1;i<size-1;i++){
		j=bitrev[i];
		if (i<j){
			ctmp=x[j];
			x[j]=x[i];
			x[i]=ctmp;
		}
	}
	
	/* shift */
	if ((cdir==1)||(cdir==-2)){
		for (i = 0; i<size; i++){
			x[i].real*=dvd;
			x[i].image*=dvd;
		}
	}
}

/*FFT演算ルーチンの初期化*/
void initfft(int fftsize)
{
	int i,nv2,j,k;
	
	sintable=getmemory(fftsize*sizeof(double));
	costable=getmemory(fftsize*sizeof(double));
	bitrev=getmemory(fftsize*sizeof(int));

	for (i=0;i<fftsize;i++) {
		sintable[i]=sin((double)i*2.0*M_PI/(double)fftsize);
		costable[i]=cos((double)i*2.0*M_PI/(double)fftsize);
	}
	
	nv2=fftsize>>1;
	j=0;
	for (i=1;i<fftsize-1;i++){
		k=nv2;
		while (k<=j){
			j-=k;
			k>>=1;
		}
		j+=k;
		bitrev[i]=j;
	}
	bitrev[0]=0;
	bitrev[fftsize-1]=fftsize-1;
	staticsize=fftsize;
}
