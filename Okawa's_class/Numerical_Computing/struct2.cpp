#include <stdio.h>

 struct x{
 int a[10][10];
 };

 //struct x a[100];
 
 int main(void)
 {
 struct x a[2][2] = {1,2,3,4};

 
 printf("%d\n", a[1][1]);
 return 0;
 }