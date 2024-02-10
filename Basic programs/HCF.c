#include<stdio.h>
int main(){
	int a, b, n, f;
	printf("Enter 1st number ");
	scanf("%d",&a);
	printf("Enter 2nd number ");
	scanf("%d",&b);
	for(n=1; n<=a||n<=b; n++){
		if(a%n==0 && b%n==0){
			f=n;
		}
	}
	printf("The GCD is %d",f);
	return 0;
}
