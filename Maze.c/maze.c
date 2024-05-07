#include<stdio.h>
#include<stdlib.h>
// #include "parse.h"
#define MAX 10

typedef struct list{
    int x, y;
    struct list* next;
}list;

list queue;
list stack;

int main(int argc, char* argv[]){

    if(argc != 2){
        printf("Usage: a.exe maze.txt\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if(file == NULL){
        printf("Couldn't open file\n");
        return 1;
    }

    char maze[10][10];

    int ch = getc(file), r = 0, c = 0;

    while(ch != EOF){
        // printf("%c", ch);
    
        if(ch == '\n'){
            r++;
            c = 0;
            continue;
        }
        maze[r][c++] = ch;
        if(ch == '#'){
        }
        else if(ch == ' '){
        }
        else if(ch == 'A'){
        }
        else if(ch == 'B'){
        }
        else{
            printf("File is incompatible.\n");
            return 1;
        }
        ch = getc(file);
    }

    printf("\nMaze is: %d %d\n",r,c);
    // for(int i = 0; i <= r; i++){
    //     for(int j = 0; j < c; j++){
    //         printf("%c",maze[i][j]);
    //     }
    //     printf("\n");
    // }

    
    return 0;
}