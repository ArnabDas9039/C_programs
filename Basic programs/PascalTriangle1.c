#include<stdio.h>
long factorial(long n){
	long i, f=1;
	if(n>0){
		for(i=n;i>0;i--){
			f=f*i;
		}
	}
	else{
		if(n==0){
			f=1;
		}
	}
	//printf("%d",f);
	return f;
}
long binomial(long i, long j){
	long b, n, r, k, a;
	a=i-j;
	n=factorial(i);
	r=factorial(j);
	k=factorial(a);
	b=n/(r*k);
	return b;
}
int main(){
	long i, n, j, a;
	printf("Enter the number of rows ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++){
		for(j=0;j<=i;j++){
			//printf("%d",i);
			//printf("%d",j);
			//a=binomial(i, j);
			//printf("%d ",a);
			printf("%dC%d ",i,j);
		}
		printf("\n");
	}
	return 0;
}
