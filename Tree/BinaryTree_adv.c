#include<stdio.h>
#include<stdlib.h>
void display(){

}
int main(){
    int choice;
    while(1){
        printf("\n\nBINARY TREE MENU\n");
        printf("\n Enter 0 to display ");
        printf("\n Enter 1 to insert ");
        printf("\n Enter 2 to delete ");
        printf("\n Enter 3 to find diameter ");
        printf("\n Enter 4 to find height ");
        printf("\n Enter 10 to exit\n ");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 0:
            display();
            break;
        }
    }
}