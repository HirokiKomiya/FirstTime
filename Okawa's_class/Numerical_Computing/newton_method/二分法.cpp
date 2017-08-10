#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 1.0e-5              //収束条件

double f(double x);
void nibun(void); 

int main()
{
        nibun();

        return 0;
}

void nibun(void)
{
        int count;
        double a,b,m;

        count=0;

        printf("範囲の左の値を入力してください.\n");
        scanf("%lf",&a);
        printf("範囲の右の値を入力してください.\n");
        scanf("%lf",&b);

        do {
                count++;
                m=(a+b)/2.0;
                if(f(m)*f(a)<0) b=m;
                else a=m;

//１０００回繰り返して解が収束しなかったらプログラムを終了させる
                if(count==1000) {
                        printf("収束しませんでした.\n");
                        exit(1);
                }
        } while (!(fabs(a-b)<eps));             //解が収束したらループを終了

        printf("解の値は %f\n収束するのに %d 回かかりました.",m,count);

}

double f(double x)
{
        return(x-1)*(x+1);
}