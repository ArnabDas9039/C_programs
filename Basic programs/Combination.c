#include<stdio.h>
int factorial(int n){
	int i, f = 1;
	if(n > 0){
		for(i = n;i > 0;i--){
			f = f * i;
		}
	}
	else{
		if(n == 0){
			f = 1;
		}
	}
	return f;
}
int main(){
	int i, j, b, n, r, k, a;
	printf("Enter the value of n and r (with a space) ");
	scanf("%d %d", &i, &j);
	a = i - j;
	n = factorial(i);
	k = factorial(a);
	r = factorial(j);
	b = n / (r * k);
	printf("The value of %dC%d is %d.", i, j, b);
	return 0;
}
