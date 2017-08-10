#include <stdio.h>

 struct x{
 struct y{
 struct z{
 int c;
 }z;
 int b;
 }y;
 int a;
 };

 int main(void)
 {
 struct x x = {{{3},2}, 1};

 printf("x.a == %d\n", x.a);
 printf("x.y.b == %d\n", x.y.b);
 printf("x.y.z.c == %d\n", x.y.z.c);
 return 0;
 }