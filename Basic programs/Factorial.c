#include<stdio.h>
int main(){
	int a, p = 1;
	printf("Enter a number ");
	scanf("%d", &a);
	while(a > 0){
		p = p * a;
		a--;
	}
	printf("%d", p);
	return 0;
}