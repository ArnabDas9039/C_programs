#include<stdio.h>
int binary[32];
int top = -1;
void dectobinary(int n){
	while(n > 0){
		binary[++top] = n % 2;
		n = n / 2;
	}
}
void display(){
	for(int i = top; i >= 0; i--){
		printf("%d", binary[i]);
	}
	printf("\n%d", top);
}
int main(){
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	dectobinary(n);
	display();
	return 0;
}
