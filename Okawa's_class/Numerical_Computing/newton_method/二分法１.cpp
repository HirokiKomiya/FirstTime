#include <stdio.h>
#include <math.h>

 /* �֐� f(x) */
 double f(double x) {
return (x+1)*(x-1);
 }

 /* �񕪖@ �����l x1<x2 �� �덷���E eps ����� */
double bisec(double x1, double x2, double eps) {
double x;
while (x2 - x1 >= eps) {
	x = (x1+x2)/2.0; /* ���_�v�Z */
if (f(x1)*f(x) > 0.0) { /* ������������ */
	x1 = x;
	}else{
	x2 = x;
	}
}
return (x1+x2)/2.0;
}

 int main(void) {
double eps=0.00001;
printf("%lf %lf\n",bisec(-2,0,eps), bisec(0,2,eps));

return 0;
}
