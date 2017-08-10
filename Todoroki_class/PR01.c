#include <stdio.h>
#include <stdlib.h>

#define n 1000

int main(){
  int i,icount;
  double x,y;
  srand(1);
  
  icount=0;
  for(i=1;i<=n;i++){
    x=(double)(rand())/RAND_MAX;
    y=(double)(rand())/RAND_MAX;
    if(x*x+y*y<=1) icount=icount+1;
  }
  printf("PI= %f",(double)(icount)/n*4);
    
return 0;
}


