#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int a[5];
int top = -1;
void display(){
    for(int i = 0; i <= top; i++){
        printf("%d ",a[i]);
    }
}
void push(){
    if(top == MAX-1){
        printf("Stack Overflow.");
    }
    else{
        printf("Enter data: ");
        scanf("%d",&a[++top]);
    }
}
void pop(){
    if(top < 0){
        printf("Stack Underflow.");
    }
    else{
        printf("%d is removed.",a[top]);
        top--;
    }
}
int main(void){
    int choice;
    while(1){
        printf("\n\nSTACK MENU\n");
        printf("\nEnter 0 to display");
        printf("\nEnter 1 to push");
        printf("\nEnter 2 to pop");
        printf("\nEnter 10 to exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                display();
                break;
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 10:
                exit(1);
            default:
                printf("\nPlease enter a valid choice.");
        }
    }
    return 0;
}