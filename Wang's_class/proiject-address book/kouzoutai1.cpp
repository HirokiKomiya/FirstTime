#include<stdio.h>

struct person{
	int id;
	char name[40];
	long phone;
};
main(){
	struct person student1;
	
	scanf("%d %s %ld",&student1.id,student1.name,&student1.phone);
	printf("%d %s %ld\n",student1.id,student1.name,student1.phone); //”z—ñ‚Í&‚¢‚ç‚È‚¢
}
