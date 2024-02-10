#include<stdio.h>
//void spiralprint(){}
int main(){
	int i, j, r=3, c=3;
	printf("Enter the number of rows and columns(with a space) ");
	scanf("%d %d",&r,&c);
	printf("\n");
	int a[r][c];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("Enter the value of matrix in position [%d, %d] ",i,j);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	printf("\nThe values of the matrix are- \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf(" %d",a[i][j]);
		}
		printf("\n");
	}
	i=j=0;
	int k;
	while(i<r && j<c){
		for(k=j; k<c; k++){
			printf("%d ",a[i][k]);
		}
		i++;
		for(k=i; k<r; k++){
			printf("%d ",a[k][c-1]);
		}
		c--;
		if(i<r){
			for(k=c-1; k>=j; k--){
				printf("%d ",a[r-1][k]);
			}
			r--;
		}
		if(j<c){
			for(k=r-1; k>=i; k--){
				printf("%d ",a[k][j]);
			}
			j++;
		}
	}
	return 0;
}
