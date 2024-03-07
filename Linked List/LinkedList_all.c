#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node* link;
} node;
node* head = NULL;
node* link = NULL;
void display(){
	node* value;
	value = head;
	printf("The list is: START =>");
	while(value != NULL){
		printf(" %d =>", value->data);
		value = value->link;
	}
	printf(" END");
}
void insertfirst(){
	int k;
	node* value = malloc(sizeof(node));
	printf("Enter value: ");
	scanf("%d", &k);
	value->data = k;
	if(head == NULL){
		head = value;
		head->link = NULL;
		printf("%d inserted.", value->data);
	}
	else{
		value->link = head;
		head = value;
		printf("%d inserted.", value->data);
	}
}
void insertlast(){
	int k;
	node* value = malloc(sizeof(node)), * s;
	printf("Enter value: ");
	scanf("%d", &k);
	value->data = k;
	value->link = NULL;
	if(head == NULL){
		head = value;
		printf("%d inserted.", value->data);
	}
	else{
		s = head;
		while(s->link != NULL)
			s = s->link;
		s->link = value;
		printf("%d inserted.", value->data);
	}
}
void insertany(){
	int a, k, i = 1;
	node* value = malloc(sizeof(node)), * s, * p;
	printf("Enter value: ");
	scanf("%d", &a);
	value->data = a;
	value->link = NULL;
	if(head == NULL){
		head = value;
		printf("%d inserted.", a);
	}
	else{
		if(head->link == NULL){
			head->link = value;
			printf("%d inserted.", a);
		}
		else{
			printf("Enter the position after which you want to insert :");
			scanf("%d", &k);
			s = head;
			while(i <= k){
				if(s == NULL){
					printf("Position doesn't exist.");
					return;
				}
				else{
					p = s;
					s = s->link;
					i++;
				}
			}
			p->link = value;
			value->link = s;
			printf("%d inserted.", a);
		}
	}
}
void insertorder(){
	int k;
	node* value = malloc(sizeof(node));
	printf("Enter value: ");
	scanf("%d", &k);
	value->data = k;
	value->link = NULL;
	if(head == NULL){
		head = value;
		printf("%d inserted.", value->data);
	}
	else if(value->data < head->data){
		value->link = head;
		head = value;
		printf("%d inserted.", value->data);
	}
	else{
		for(node* s = head; s != NULL; s = s->link){
			if(s->link == NULL){
				s->link = value;
				break;
			}
			else if(value->data < s->link->data){
				value->link = s->link;
				s->link = value;
				break;
			}
		}
		printf("%d inserted.", value->data);
	}
}
void delend(){
	node* value, * s;
	if(head == NULL){
		printf("The list is empty.");
	}
	else{
		if(head->link == NULL){
			s = head;
			head = NULL;
			printf("Deleted element is: %d", s->data);
			free(s);
		}
		else{
			s = head;
			while(s->link != NULL){
				value = s;
				s = s->link;
			}
			value->link = NULL;
			printf("Deleted element is: %d", s->data);
			free(s);
		}
	}
}
void deleteany(){
	int k, i = 1;
	node* value, * s;
	if(head == NULL){
		printf("The list is empty.");
	}
	else{
		if(head->link == NULL){
			s = head;
			head = NULL;
			printf("Deleted element is: %d", s->data);
			free(s);
		}
		else{
			printf("Enter the position you want to delete :");
			scanf("%d", &k);
			s = head;
			while(i < k){
				if(s->link == NULL){
					printf("Position doesn't exist.");
					return;
				}
				else{
					value = s;
					s = s->link;
					i++;
				}
			}
			value->link = s->link;
			printf("Deleted element is: %d", s->data);
			free(s);
		}
	}
}
void reverselist(){
	node* rhead;
	node* s = head;
	while(s->link != NULL){
		s = s->link;
	}
	rhead = s;
	while(head->link != NULL){
		node* pre1 = head;
		while(s->link != NULL){
			pre1 = s;
			s = s->link;
		}
		s->link = pre1;
		pre1->link = NULL;
	}
	head = rhead;
	printf("The list is reversed.");
}
void convertlist(){
	node* s = head;
	while(s->link != NULL){
		s = s->link;
	}
	s->link = head;
	printf("The list is converted to circular. Do not press 0.");
}
int main(){
	int choice;
	while(1){
		printf("\n\nLINKED LIST MENU\n");
		printf("\n Enter 0 to display ");
		printf("\n Enter 1 to insert first ");
		printf("\n Enter 2 to insert last ");
		printf("\n Enter 3 to insert at any position ");
		printf("\n Enter 4 to insert in sorted order ");
		printf("\n Enter 5 to delete from end ");
		printf("\n Enter 6 to delete any position ");
		printf("\n Enter 7 to delete any value ");
		printf("\n Enter 8 to reverse list ");
		printf("\n Enter 9 to convert into circular list ");
		printf("\n Enter 10 to exit\n ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 0:
			display();
			break;
		case 1:
			insertfirst();
			break;
		case 2:
			insertlast();
			break;
		case 3:
			insertany();
			break;
		case 4:
			insertorder();
			break;
		case 5:
			delend();
			break;
		case 6:
			deleteany();
			break;
		case 7:
			reverselist();
			break;
		case 8:
			convertlist();
			break;
		case 10:
			exit(0);
		default:
			printf("\nPlease enter a valid choice");
		}
	}
	return 0;
}