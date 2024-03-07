#include<stdio.h>
int main(){
	int a, m;
	printf("Enter a number ");
	scanf("%d", &a);
	if(a > 0){
		do{
			m = a;
			if(a % 2 == 0){
				a = a / 2;
				printf("\n%d / 2 = %d", m, a);
			}
			else{
				a = 3 * a + 1;
				printf("\n3 x %d + 1 = %d", m, a);
			}
		} while(a > 1);
	}
	return 0;
}
