#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int a[MAX];
int front = -1;
int rear = -1;
void enqueue(){
	int n;
	if(rear == MAX - 1){
		printf("Queue overflow.");
	}
	else{
		printf("Enter data: ");
		scanf("%d", &n);
		a[++rear] = n;
		if(front == -1){
			front++;
		}
	}
}
void dequeue(){
	if(rear == -1){
		printf("Queue underflow.");
	}
	else{
		printf("%d is removed.", a[front]);
		for(int i = 0;i <= rear;i++){
			a[i] = a[i + 1];
		}
		rear--;
	}
}
void display(){
	for(int i = front;i <= rear;i++){
		printf("%d ", a[i]);
	}
}
int main(){
	int choice;
	while(1){
		printf("\n\nQUEUE MENU\n");
		printf("\n Enter 0 to display ");
		printf("\n Enter 1 to enqueue ");
		printf("\n Enter 2 to dequeue ");
		printf("\n Enter 3 to exit ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 0:	display();break;
		case 1: enqueue();break;
		case 2: dequeue();break;
		case 3: exit(0);
		default: printf("\nPlease enter a valid choice");
		}
	}
	return 0;
}
