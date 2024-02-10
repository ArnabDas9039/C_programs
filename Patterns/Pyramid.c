#include<stdio.h>
int main(){
	int n, i, j, k, a=0;
	/*printf("Enter the number of rows: ");
	scanf("%d",&n);*/
	n=5;
	for(i=1; i<=n; i++){
		/*for(k=n-i; k>=1; k--){
			printf(" ");
		}*/
		for(j=1; j<=i; j++){
			printf("%d ",++a);
			/*if(j==1 || j==i)
				printf("* ");
			else
				printf("  ");*/
		}
		printf("\n");
	}
	/*for(j=1; j<=n; j++){
		printf("* ");
	}
	for(i=1; i<=n; i++){
		if(i==1 || i==n){
			for(j=1; j<=n; j++){
				printf("* ");
			}
			printf("\n");
		}
		else{
			for(j=1; j<=n; j++){
				if(j==1 || j==n){
					printf("* ");
				}
				else{
					printf("  ");
				}
			}
			printf("\n");
		}
	}*/
	return 0;
}
