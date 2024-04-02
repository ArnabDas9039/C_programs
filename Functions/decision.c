#include<stdio.h>
int count = 0, count2 = 0, count3 = 0;
void foo(int n){
    //Time O(sum(1^n))
    printf("foo called %d times\n",++count);
    if(n == 1){
        return;
    }
    foo(n-1);
}
void foo2(int n){
    //Time O(sum(2^(n-1))) = O((2^n)-1) ~= O(2^n)
    printf("foo2 called %d times\n",++count2);
    if(n == 1){
        printf("Branch ended %d times\n",++count3);
        return;
    }
    foo2(n-1);
    foo2(n-1);
}
int main(){
    int n = 4;
    foo(n);
    printf("\n");
    foo2(n);
}