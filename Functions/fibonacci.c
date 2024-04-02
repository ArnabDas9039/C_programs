#include<stdio.h>
#include<stdlib.h>
long unsigned int fibo(int n){
    int a = 0, b = 1, c = 1, count = 0;
    while(--n){
        //printf("%d ",c);
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
long unsigned int rec_fibo(int n){
    if(n <= 2){
        return 1;
    }
    return rec_fibo(n - 1) + rec_fibo(n - 2);
}
long unsigned int memo_rec_fibo(int i, long unsigned int *a){
    if(a[i] != 0){
        return a[i];
    }
    if(i <= 1){
        return 1;
    }
    a[i] = memo_rec_fibo(i-1, a) + memo_rec_fibo(i-2, a);
    return a[i];
}
int main(){
    int n = 50;
    long unsigned int a[n];
    for(int i = 0; i < n; i++){
        a[i] = 0;
    }
    printf("%lu\n", fibo(n));
    printf("%lu\n", memo_rec_fibo(n-1, a));
    printf("%lu\n", rec_fibo(n));
}