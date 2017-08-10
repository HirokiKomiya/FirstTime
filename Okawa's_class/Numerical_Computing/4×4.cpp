#include <stdio.h>
#include <math.h>

#define PI 3.14159265926535


double a[4][4];
double b[4][4];
double c[4][4];

double get_1_1(double a[1][1],double b[1][1],double a[1][2],double b[2][1],double a[1][3],double b[3][1],double a[1][4],double b[4][1])
{
	return(a[1][1]*b[1][1]+a[1][2]*b[2][1]+a[1][3]*b[3][1]+a[1][4]*b[4][1]);
}
double get_[1][2](double a[1][1],double b[1][2],double a[1][2],double b[2][2],double a[1][3],double b[3][2],double a[1][4],double b[4][2])
{
	return(a[1][1]*b[1][2]+a[1][2]*b[2][2]+a[1][3]*b[3][2]+a[1][4]*b[4][2]);
}
double get_[1][3](double a[1][1],double b[1][3],double a[1][2],double b[2][3],double a[1][3],double b[3][3],double a[1][4],double b[4][3])
{
	return(a[1][1]*b[1][3]+a[1][2]*b[2][3]+a[1][3]*b[3][3]+a[1][4]*b[4][3]);
}
double get_[1][4](double a[1][1],double b[1][4],double a[1][2],double b[2][4],double a[1][3],double b[3][4],double a[1][4],double b[4][4])
{
	return(a[1][1]*b[1][4]+a[1][2]*b[2][4]+a[1][3]*b[3][4]+a[1][4]*b[4][4]);
}

double get_[2][1](double a[2][1],double b[1][1],double a[2][2],double b[2][1],double a[2][3],double b[3][1],double a[2][4],double b[4][1])
{
	return(a[2][1]*b[1][1]+a[2][2]*b[2][1]+a[2][3]*b[3][1]+a[2][4]*b[4][1]);
}
double get_[2][2](double a[2][1],double b[1][2],double a[2][2],double b[2][2],double a[2][3],double b[3][2],double a[2][4],double b[4][2])
{
	return(a[1][1]*b[1][2]+a[1][2]*b[2][2]+a[1][3]*b[3][2]+a[1][4]*b[4][2]);
}
double get_[2][3](double a[2][1],double b[1][3],double a[2][2],double b[2][3],double a[2][3],double b[3][3],double a[2][4],double b[4][3])
{
	return(a[2][1]*b[1][3]+a[2][2]*b[2][3]+a[2][3]*b[3][3]+a[2][4]*b[4][3]);
}
double get_[2][4](double a[2][1],double b[1][4],double a[2][2],double b[2][4],double a[2][3],double b[3][4],double a[2][4],double b[4][4])
{
	return(a[2][1]*b[1][4]+a[2][2]*b[2][4]+a[2][3]*b[3][4]+a[2][4]*b[4][4]);
}

double get_[3][1](double a[3][1],double b[1][1],double a[3][2],double b[2][1],double a[3][3],double b[3][1],double a[3][4],double b[4][1])
{
	return(a[3][1]*b[1][1]+a[3][2]*b[2][1]+a[3][3]*b[3][1]+a[3][4]*b[4][1]);
}
double get_[3][2](double a[3][1],double b[1][2],double a[3][2],double b[2][2],double a[3][3],double b[3][2],double a[3][4],double b[4][2])
{
	return(a[3][1]*b[1][2]+a[3][2]*b[2][2]+a[3][3]*b[3][2]+a[3][4]*b[4][2]);
}
double get_[3][3](double a[3][1],double b[1][3],double a[3][2],double b[2][3],double a[3][3],double b[3][3],double a[3][4],double b[4][3])
{
	return(a[3][1]*b[1][3]+a[3][2]*b[2][3]+a[3][3]*b[3][3]+a[3][4]*b[4][3]);
}
double get_[3][4](double a[3][1],double b[1][4],double a[3][2],double b[2][4],double a[3][3],double b[3][4],double a[3][4],double b[4][4])
{
	return(a[3][1]*b[1][4]+a[3][2]*b[2][4]+a[3][3]*b[3][4]+a[3][4]*b[4][4]);
}

double get_[4][1](double a[4][1],double b[1][1],double a[4][2],double b[2][1],double a[4][3],double b[3][1],double a[4][4],double b[4][1])
{
	return(a[4][1]*b[1][1]+a[4][2]*b[2][1]+a[4][3]*b[3][1]+a[4][4]*b[4][1]);
}
double get_[4][2](double a[4][1],double b[1][2],double a[4][2],double b[2][2],double a[4][3],double b[3][2],double a[4][4],double b[4][2])
{
	return(a[4][1]*b[1][2]+a[4][2]*b[2][2]+a[4][3]*b[3][2]+a[4][4]*b[4][2]);
}
double get_[4][3](double a[4][1],double b[1][3],double a[4][2],double b[2][3],double a[4][3],double b[3][3],double a[4][4],double b[4][3])
{
	return(a[4][1]*b[1][3]+a[4][2]*b[2][3]+a[4][3]*b[3][3]+a[4][4]*b[4][3]);
}
double get_[4][4](double a[4][1],double b[1][4],double a[4][2],double b[2][4],double a[4][3],double b[3][4],double a[4][4],double b[4][4])
{
	return(a[4][1]*b[1][4]+a[4][2]*b[2][4]+a[4][3]*b[3][4]+a[4][4]*b[4][4]);
}

int main(){
	int i;
	a[0][0]=1;
	a[0][1]=0;
	a[0][2]=0;
	a[0][3]=0;
	a[1][0]=0;
	a[1][1]=1;
	a[1][2]=0;
	a[1][3]=0;
	a[2][0]=0;
	a[2][1]=0;
	a[2][2]=1;
	a[2][3]=0;
	a[3][0]=0;
	a[3][1]=0;
	a[3][2]=0;
	a[3][3]=1;
	
	b[0][0]=1;
	b[0][1]=2;
	b[0][2]=3;
	b[0][3]=4;
	b[1][0]=0;
	b[1][1]=1;
	b[1][2]=2;
	b[1][3]=3;
	b[2][0]=0;
	b[2][1]=2;
	b[2][2]=4;
	b[2][3]=6;
	b[3][0]=0;
	b[3][1]=0;
	b[3][2]=0;
	b[3][3]=1;
	
	c[0][0]=get_[1][1](double a[1][1],double b[1][1],double a[1][2],double b[2][1],double a[1][3],double b[3][1],double a[1][4],double b[4][1]);
	c[0][1]=get_[i][2](double a[1][1],double b[1][2],double a[1][2],double b[2][2],double a[1][3],double b[3][2],double a[1][4],double b[4][2]);
	
}
