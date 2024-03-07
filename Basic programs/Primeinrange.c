#include<stdio.h>
#include<conio.h>
#include<math.h>
int primechk(int a){
	int p = 2, r;
	if(a > 1){
		r = sqrt(a);
		while(p <= r){
			if(a % p == 0){
				return 0;
			}
			p++;
		}
	}
	else{
		return 0;
	}
}
int main(){
	int l, u, s, a = 0;
	printf("Enter the lower limit ");
	scanf("%d", &l);
	printf("Enter the upper limit ");
	scanf("%d", &u);
	if(l > u){
		printf("Please enter the limits correctly. %d", l);
		printf(" greator than %d", u);
		printf(" is not possible.");
	}
	while(l <= u){
		s = primechk(l);
		if(s != 0){
			printf("%d", l);
			printf("\n");
		}
		l++;
	}
	return 0;
}
