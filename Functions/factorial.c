#include<stdio.h>
int facto(int n){
    // Time O(n)
    // Space O(n) recursion stack otherwise 0
    if(n == 0){
        return 1;
    }
    return n*facto(n-1);
}
int main(){
    int n = 5, f = 1;
    printf("f(%d) is: %d\n",n,facto(n));
    for(int i = n; i > 0; i--){
        // Time O(n)
        // Space O(1)
        f *= i; 
    }
    printf("f(%d) is: %d\n",n,f);
}