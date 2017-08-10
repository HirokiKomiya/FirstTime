#include <stdio.h>
#include <math.h>

#define PI 3.14159265926535

//1
double get_1_1(double a_1_1,double b_1_1,double a_1_2,double b_2_1,double a_1_3,double b_3_1,double a_1_4,double b_4_1)
{
	return(a_1_1*b_1_1+a_1_2*b_2_1+a_1_3*b_3_1+a_1_4*b_4_1);
}
double get_1_2(double a_1_1,double b_1_2,double a_1_2,double b_2_2,double a_1_3,double b_3_2,double a_1_4,double b_4_2)
{
	return(a_1_1*b_1_2+a_1_2*b_2_2+a_1_3*b_3_2+a_1_4*b_4_2);
}
double get_1_3(double a_1_1,double b_1_3,double a_1_2,double b_2_3,double a_1_3,double b_3_3,double a_1_4,double b_4_3)
{
	return(a_1_1*b_1_3+a_1_2*b_2_3+a_1_3*b_3_3+a_1_4*b_4_3);
}
 double get_1_4(double a_1_1,double b_1_4,double a_1_2,double b_2_4,double a_1_3,double b_3_4,double a_1_4,double b_4_4)
{
	return(a_1_1*b_1_4+a_1_2*b_2_4+a_1_3*b_3_4+a_1_4*b_4_4);
}

//2
double get_2_1(double a_2_1,double b_1_1,double a_2_2,double b_2_1,double a_2_3,double b_3_1,double a_2_4,double b_4_1)
{
	return(a_2_1*b_1_1+a_2_2*b_2_1+a_2_3*b_3_1+a_2_4*b_4_1);
}
double get_2_2(double a_2_1,double b_1_2,double a_2_2,double b_2_2,double a_2_3,double b_3_2,double a_2_4,double b_4_2)
{
	return(a_2_1*b_1_2+a_2_2*b_2_2+a_2_3*b_3_2+a_2_4*b_4_2);
}
double get_2_3(double a_2_1,double b_1_3,double a_2_2,double b_2_3,double a_2_3,double b_3_3,double a_2_4,double b_4_3)
{
	return(a_2_1*b_1_3+a_2_2*b_2_3+a_2_3*b_3_3+a_2_4*b_4_3);
}
 double get_2_4(double a_2_1,double b_1_4,double a_2_2,double b_2_4,double a_2_3,double b_3_4,double a_2_4,double b_4_4)
{
	return(a_2_1*b_1_4+a_2_2*b_2_4+a_2_3*b_3_4+a_2_4*b_4_4);
}

//3
double get_3_1(double a_3_1,double b_1_1,double a_3_2,double b_2_1,double a_3_3,double b_3_1,double a_3_4,double b_4_1)
{
	return(a_3_1*b_1_1+a_3_2*b_2_1+a_3_3*b_3_1+a_3_4*b_4_1);
}
double get_3_2(double a_3_1,double b_1_2,double a_3_2,double b_2_2,double a_3_3,double b_3_2,double a_3_4,double b_4_2)
{
	return(a_3_1*b_1_2+a_3_2*b_2_2+a_3_3*b_3_2+a_3_4*b_4_2);
}
double get_3_3(double a_3_1,double b_1_3,double a_3_2,double b_2_3,double a_3_3,double b_3_3,double a_3_4,double b_4_3)
{
	return(a_3_1*b_1_3+a_3_2*b_2_3+a_3_3*b_3_3+a_3_4*b_4_3);
}
double get_3_4(double a_3_1,double b_1_4,double a_3_2,double b_2_4,double a_3_3,double b_3_4,double a_3_4,double b_4_4)
{
	return(a_3_1*b_1_4+a_3_2*b_2_4+a_3_3*b_3_4+a_3_4*b_4_4);
}

//4
double get_4_1(double a_4_1,double b_1_1,double a_4_2,double b_2_1,double a_4_3,double b_3_1,double a_4_4,double b_4_1)
{
	return(a_4_1*b_1_1+a_4_2*b_2_1+a_4_3*b_3_1+a_4_4*b_4_1);
}
double get_4_2(double a_4_1,double b_1_2,double a_4_2,double b_2_2,double a_4_3,double b_3_2,double a_4_4,double b_4_2)
{
	return(a_4_1*b_1_2+a_4_2*b_2_2+a_4_3*b_3_2+a_4_4*b_4_2);
}
double get_4_3(double a_4_1,double b_1_3,double a_4_2,double b_2_3,double a_4_3,double b_3_3,double a_4_4,double b_4_3)
{
	return(a_4_1*b_1_3+a_4_2*b_2_3+a_4_3*b_3_3+a_4_4*b_4_3);
}
 double get_4_4(double a_4_1,double b_1_4,double a_4_2,double b_2_4,double a_4_3,double b_3_4,double a_4_4,double b_4_4)
{
	return(a_4_1*b_1_4+a_4_2*b_2_4+a_4_3*b_3_4+a_4_4*b_4_4);
}


int main(void){
	int i,j=0;
	int size=4;
	double a[4][4];
	double T1[4][4];
	double T2[4][4];
	double T3[4][4];
	double TE[4][4];
	//ç°âÒÇÕ4Å~4ÇÃçsóÒ
	
	a[0][0]=0;
	a[0][1]=0;
	a[0][2]=2;
	a[0][3]=0;
	
	a[1][0]=0;
	a[1][1]=0;
	a[1][2]=0;
	a[1][3]=0;	//É∆ÇP
	
	a[2][0]=0;
	a[2][1]=90;
	a[2][2]=0;
	a[2][3]=0;	//É∆ÇQ
	
	a[3][0]=2;
	a[3][1]=0;
	a[3][2]=0;
	a[3][3]=0;	//É∆ÇR
	
	a[4][0]=2;
	a[4][1]=0;
	a[4][2]=0;
	a[4][3]=0;
	
	//[0][0] = a
	//[0][1] = Éø
	//[0][2] = d
	//[0][3] = É∆
	
	//0T1
	T1[0][0] = cos(a[0][3]*PI/180);
	T1[0][1] = -sin(a[0][3]*PI/180);
	T1[0][2] = 0;
	T1[0][3] = a[0][0];
	
	T1[1][0] = cos(a[0][1]*PI/180)*sin(a[0][3]*PI/180);
	T1[1][1] = cos(a[0][1]*PI/180)*cos(a[0][3]*PI/180);
	T1[1][2] = -sin(a[0][1]*PI/180);
	T1[1][3] = -sin(a[0][1]*PI/180)*a[0][2];
	
	T1[2][0] = sin(a[0][1]*PI/180)*sin(a[0][3]*PI/180);
	T1[2][1] = sin(a[0][1]*PI/180)*cos(a[0][3]*PI/180);
	T1[2][2] = cos(a[0][1]*PI/180);
	T1[2][3] = cos(a[0][1]*PI/180)*a[0][2];
	
	T1[3][0] = 0;
	T1[3][1] = 0;
	T1[3][2] = 0;
	T1[3][3] = 1;
	
	/*1T2*/
	T2[0][0] = cos(a[1][3]*PI/180);
	T2[0][1] = -sin(a[1][3]*PI/180);
	T2[0][2] = 0;
	T2[0][3] = a[1][0];
	
	T2[1][0] = cos(a[1][1]*PI/180)*sin(a[1][3]*PI/180);
	T2[1][1] = cos(a[1][1]*PI/180)*cos(a[1][3]*PI/180);
	T2[1][2] = -sin(a[1][1]*PI/180);
	T2[1][3] = -sin(a[1][1]*PI/180)*a[1][2];
	
	T2[2][0] = sin(a[1][1]*PI/180)*sin(a[1][3]*PI/180);
	T2[2][1] = sin(a[1][1]*PI/180)*cos(a[1][3]*PI/180);
	T2[2][2] = cos(a[1][1]*PI/180);
	T2[2][3] = cos(a[1][1]*PI/180)*a[1][2];
	
	T2[3][0] = 0;
	T2[3][1] = 0;
	T2[3][2] = 0;
	T2[3][3] = 1;
	
	/*2T3*/
	T3[0][0] = cos(a[3][3]*PI/180);
	T3[0][1] = -sin(a[3][3]*PI/180);
	T3[0][2] = 0;
	T3[0][3] = a[3][0];
	
	T3[1][0] = cos(a[3][1]*PI/180)*sin(a[3][3]*PI/180);
	T3[1][1] = cos(a[3][1]*PI/180)*cos(a[3][3]*PI/180);
	T3[1][2] = -sin(a[3][1]*PI/180);
	T3[1][3] = -sin(a[3][1]*PI/180)*a[3][2];
	
	T3[2][0] = sin(a[3][1]*PI/180)*sin(a[3][3]*PI/180);
	T3[2][1] = sin(a[3][1]*PI/180)*cos(a[3][3]*PI/180);
	T3[2][2] = cos(a[3][1]*PI/180);
	T3[2][3] = cos(a[3][1]*PI/180)*a[3][2];
	
	T3[3][0] = 0;
	T3[3][1] = 0;
	T3[3][2] = 0;
	T3[3][3] = 1;
	
	/*3TE*/
	TE[0][0] = cos(a[4][3]*PI/180);
	TE[0][1] = -sin(a[4][3]*PI/180);
	TE[0][2] = 0;
	TE[0][3] = a[4][0];
	
	TE[1][0] = cos(a[4][1]*PI/180)*sin(a[4][3]*PI/180);
	TE[1][1] = cos(a[4][1]*PI/180)*cos(a[4][3]*PI/180);
	TE[1][2] = -sin(a[4][1]*PI/180);
	TE[1][3] = -sin(a[4][1]*PI/180)*a[4][2];
	
	TE[2][0] = sin(a[4][1]*PI/180)*sin(a[4][3]*PI/180);
	TE[2][1] = sin(a[4][1]*PI/180)*cos(a[4][3]*PI/180);
	TE[2][2] = cos(a[4][1]*PI/180);
	TE[2][3] = cos(a[4][1]*PI/180)*a[4][2];
	
	TE[3][0] = 0;
	TE[3][1] = 0;
	TE[3][2] = 0;
	TE[3][3] = 1;
	
	//ïœä∑çsóÒÇ±Ç±Ç‹Ç≈
	/****************************/
	
	
	
	
	
	/*àÍçsàÍóÒê¨ï™ÇÕa[0][0]ÅAÇQçsÇQóÒê¨ï™ÇÕa[1][1]Ç…ì¸ÇÈ*/
	
	printf("\nçsóÒ0T1ÇÕ\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
		printf("%f ",T1[i][j]);
		}
		printf("\n");
	}
	printf("èIÇÌÇË\n");
}
