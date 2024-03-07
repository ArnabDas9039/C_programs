#include<stdio.h>
int main(){
	int i, n;
	printf("Enter the number of values ");
	scanf("%d", &n);
	n = n - 1;
	int a[n];
	for(i = 0;i <= n;i++){
		printf("Enter the value of array[%d] ", i);
		scanf("%d", &a[i]);
	}
	printf("The values of the array are-");
	for(i = 0;i <= n;i++){
		printf(" %d", a[i]);
	}
	return 0;
}
