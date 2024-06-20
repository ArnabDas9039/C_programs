#include<stdio.h>
int gridtravel_rec(int r, int c){

    if(r == 0 || c == 0){
        return 0;
    }
    if(r == 1 && c == 1){
        return 1;
    }

    return gridtravel_rec(r, c - 1) + gridtravel_rec(r - 1, c);
}

int gridtravel_memo(int r, int c, int a[r + 1][c + 1]){

    if(a[r][c] != -1){
        return a[r][c];
    }
    if(r == 1 && c == 1){
        return 1;
    }
    if(r == 0 || c == 0){
        return 0;
    }
    a[r][c] = gridtravel_memo(r, c - 1, a) + gridtravel_memo(r - 1, c, a);

    return a[r][c];
}

int gridtravel_tab(int r, int c){
    int b[r + 1][c + 1];

    for(int i = 0; i <= r; i++){
        for(int j = 0; j <= c; j++){
            b[i][j] = 0;
        }
    }

    b[1][1] = 1;

    for(int i = 0; i <= r; i++){
        for(int j = 0; j <= c; j++){
            if(i != r){
                b[i + 1][j] += b[i][j];
            }
            if(j != c){
                b[i][j + 1] += b[i][j];
            }
        }
    }

    return b[r][c];
}

int main(){
    int r, c;
    // printf("Enter number rows and columns: ");
    // scanf("%d %d",&r,&c);
    r = 3, c = 3;
    int a[r + 1][c + 1];


    for(int i = 0; i <= r; i++){
        for(int j = 0; j <= c; j++){
            a[i][j] = -1;
        }
    }

    printf("Count is %d\n", gridtravel_rec(r, c));
    printf("Count is %d\n", gridtravel_memo(r, c, a));
    printf("Count is %d\n", gridtravel_tab(r, c));
}
