// Bisection Method
#include<stdio.h>
#include<math.h>
int main(){
    int t = 20;
    double a = 3, b = 4, c;
    while(t--){
        c = (a + b) / 2;
        if(sin(c) > 0){
            a = c;
        }
        else if(sin(c) < 0){
            b = c;
        }
        else{
            break;
        }
        printf("c is %.20lf\n",c);
    }
    printf("Final c is %.20lf\n",c);
    return 0;
}