#include<stdio.h>
struct pair{
    long long int min;
    long long int max;
};
struct pair getMinMax(long long int arr[], long long int n){
    struct pair p;
    p.min = arr[0], p.max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] < p.min){
            p.min = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] > p.max){
            p.max = arr[i];
        }
    }
    return p;
}
int main(){
    long long int t, n, a[100002], i;
    struct pair minmax;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for(i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        minmax = getMinMax(a, n);
        printf("%lld %lld\n", minmax.min, minmax.max);
    }
    return 0;
}