#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int a[MAX + 1];
int rear = -1, front = -1;
void enqueue(){
	int n;
	if((rear + 2) % (MAX + 1) == front){
		printf("Queue overflow.");
	}
	else{
		if(front == -1){
			front++;
		}
		printf("Enter data: ");
		scanf("%d", &n);
		rear++;
		if(rear > MAX){
			rear %= (MAX + 1);
		}
		a[rear] = n;
	}
}
void dequeue(){
	if((rear + 1) % (MAX + 1) == front){
		printf("Queue underflow.");
	}
	else{
		printf("%d is removed.", a[front]);
		// for(int i = 0;i <= rear;i++){
		// 	a[i] = a[i + 1];
		// }
		// rear--;
		front++;
		if(front > MAX){
			front %= (MAX + 1);
		}
	}
}
void display(){
	if((rear + 1) % (MAX + 1) == front){
		return;
	}
	int i = front;
	while(1){
		if(i > MAX){
			i %= (MAX + 1);
		}
		printf("%d ", a[i]);
		if(i == rear){
			break;
		}
		i++;
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
