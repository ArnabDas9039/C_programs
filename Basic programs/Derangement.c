#include<stdio.h>
long long int derangement(long long int n){
	if(n<= 1){
		return 0;
	}
	else if(n==2){
		return 1;
	}
	else{
		return (n-1)*(derangement(n-1)+derangement(n-2));
	}
}
int main(){
    long long int t;
    long long int D[21];
    scanf("%lld",&t);
    for(int i=0; i<21; i++){
    	D[i]=derangement(i);
	}
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",D[n] + n*D[n-1]);
    }
    return 0;
}
