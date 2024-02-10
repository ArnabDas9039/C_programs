#include<stdio.h>
#include<math.h>
int main(){
	int a, p=0, r, m; 
	printf("Enter a number ");
	scanf("%d",&a);
	m=a;
	while(a>0){
		r=a%10;
		p=p+pow(r,3);
		a=floor(a/10);
	}
	if (m==p){
		printf("This is an armstrong number.");
	}
	else{
		printf("This is not an armstrong number.");
	}
	return 0;
}

