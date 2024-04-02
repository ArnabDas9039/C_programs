// Gauss Jacobi and Gauss Siedel Methods
#include<stdio.h>
#define n 3
int a[][n] = {{5,-2,3},{-3,9,1},{2,-1,-7}};
// int a[][n] = {{2,1},{5,7}};
int b[] = {-1, 2, 3};
// int b[] = {11, 13};
int main(){
    int k = 0, t = 30;
    printf("A is: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\nB is: ");
    for(int j = 0; j < n; j++){
        printf("%d ",b[j]);
    }
    float x1[n][t+1];
    float x2[n][t+1];
    x1[0][0] = 0;
    x1[1][0] = 0;
    x1[2][0] = 0;
    x2[0][0] = 0;
    x2[1][0] = 0;
    x2[2][0] = 0;
    while(k<t){
        for(int i = 0; i < n; i++){
            float s1 = 0, s2 = 0;
            for(int j = 0; j < n; j++){
                if(j != i){
                    s1 = s1 + (a[i][j] * x1[j][k]);
                    s2 = s2 + (a[i][j] * x2[j][k]);
                }
            }
            x1[i][k+1] = (b[i] - s1) / a[i][i];
            x2[i][k+1] = (b[i] - s2) / a[i][i];
            x2[i][k] = x2[i][k+1];
        }
        k++;
    }
    printf("\nX1 is: \n");
    for(int i = 0; i <= t; i++){
        for(int j = 0; j < n; j++){
            printf("%7.4f\t",x1[j][i]);
        }
        printf("\n");
    }
    printf("\nX2 is: \n");
    for(int i = 0; i <= t; i++){
        for(int j = 0; j < n; j++){
            printf("%7.4f\t",x2[j][i]);
        }
        printf("\n");
    }
}