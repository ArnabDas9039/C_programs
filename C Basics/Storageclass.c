#include<stdio.h>
int n=40;
void abc(int n){
//void abc(){
	printf("\n%d",n);
}
int main(){
	int n=20;
	printf("\nThe original value of n defined outside main function: %d",::n);
	printf("\nThe original value of n of main function: %d",n);
	::n=::n+10;
	n=n+10;
	printf("\nThe added 10 value of n defined outside main function: %d",::n);
	printf("\nThe added 10 value of n of main function: %d",n);
	n=::n+10;
	::n=n+10;
	printf("\nThe interchangebly added 10 value of n defined outside main function: %d",::n);
	printf("\nThe interchangebly  added 10 value of n of main function: %d",n);
	abc(n);
	return 0;
}
