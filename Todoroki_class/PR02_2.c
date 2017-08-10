/* two dimensional ising model */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define lsize 24          /* linear lattice size */
#define mcs  10000       /* Monte Carlo steps  （サンプリング数、長いほうがいい）） */
#define irlx 10000       /* Relaxation time   (捨てる時間、長いほうがいい)  */
#define ccj  1.0          /* ccj  : exchange interaction */ 
#define tempMax 5	//この温度から0.1ずつ下げていく

int main(){
  int is[lsize][lsize]; /* ising spin variable */
  int ip[lsize], im[lsize], jp[lsize], jm[lsize];
  int w0[100];
  int i, j, istep;
  int ih;
  int r;               /* r    : for  random number */
  double w;            /* w    : transition probability */
  double temp=tempMax;
  double tempI;
/* physical quantities  */
  double eng, c, mag, chi;
  double e1, e2, e ;	//エネルギー
  double m1, m2, m ;	//磁化

/* initialized random number generator */
  srand(1);

   //printf("温度 平均エネルギー 平均磁化 帯磁率 %10f\n",temp, eng, mag, c, chi);

for(i=0;i<=8;i++){
		w0[i] = exp(-2*ccj*(i-4)/temp);
	}
	for(tempI=0;tempI<tempMax*10-1;tempI++){
  	temp=tempMax+tempI/(-10);
/* set neighboer site */
  for(i=0;i<lsize;i++){
    ip[i]=i+1;
    im[i]=i-1;
  }
  ip[lsize-1]=0;
  im[0]=lsize-1;

  for(j=0;j<lsize;j++){
    jp[j]=j+1;
    jm[j]=j-1;
  }
  jp[lsize-1]=0;
  jm[0]=lsize-1;

/* initial configuration */
  for(i=0;i<lsize;i++){
  for(j=0;j<lsize;j++){
    r=rand();
    is[i][j] = -1;
    if(r<=RAND_MAX/2) is[i][j] = 1;
  }}
  e1=0.0;
  e2=0.0;
  m1=0.0;
  m2=0.0;
  
  
	/* monte carlo step */
	  for(istep=1;istep<=mcs+irlx;istep++){
	    for(i=0;i<lsize;i++){
	    for(j=0;j<lsize;j++){
	      ih=is[im[i]][j]+is[ip[i]][j]+is[i][jm[j]]+is[i][jp[j]];	//周りスピンの和
	      w=w0[ih*is[i][j]+4];
	      r=rand();
	      if(r<=w*RAND_MAX) is[i][j] = -is[i][j];
	    }}
		
	    if(istep > irlx){
			/* mc sampling */
	        e=0.0;
			m=0.0;
	        for(i=0;i<lsize;i++){
	        for(j=0;j<lsize;j++){
	          e=e-ccj*is[i][j]*(is[im[i]][j]+is[ip[i]][j]+is[i][jm[j]]+is[i][jp[j]]);
			  m=m+is[i][j];
	        }}
	        e=e/2;
	        e1=e1+e;
	        e2=e2+e*e;
			m1=m1+m;
	        m2=m2+m*m;
	      }
		}
	    e1=e1/mcs;
	    e2=e2/mcs;
	    m1=m1/mcs;
	    m2=m2/mcs;
		
	    c   = (e2-e1*e1)/(temp*temp)/lsize/lsize;
	    chi = (m2-m1*m1)/(temp*temp)/lsize/lsize;
	    eng = e1/lsize/lsize;
	    mag = m1/lsize/lsize;
		
		printf("%10f\t %10f\t %10f\t %10f\t %10f\n",temp, eng, mag, c, chi);
	}
	return 0;
}
