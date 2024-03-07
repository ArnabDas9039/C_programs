#include<stdio.h>
#include<math.h>
int main(){
	int a, p = 2, f = 0, r;
	printf("Enter a number ");
	scanf("%d", &a);
	if(a > 1){
		r = sqrt(a);
		while(p <= r){
			if(a % p == 0){
				f++;
			}
			p++;
		}
		if(f == 0){
			printf("This is a prime number.");
		}
		else{
			printf("This is not a prime number. The number of divisors are %d", f + 2);
		}
	}
	else{
		if(a < 0){
			printf("Please enter a positive number.");
		}
		else{
			printf("%d", a);
			printf(" is neither prime nor composite.");
		}
	}
	return 0;
}