#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head = NULL;
void display(){
	struct node *value;
	value=head;
	printf("The list is: START =>");
	while(value!=NULL){
		printf(" %d =>",value->data);
		value=value->link;
	}
	printf(" END");
}
void insert(){
	int k;
	struct node *p=(struct node*)malloc(sizeof(struct node));
	printf("Enter value: ");
	scanf("%d",&k);
	p->data=k;
	p->link=NULL;
	if(head==NULL){
		head=p;
	}
	else{
		struct node *s=head;
		while(s->link!=NULL){
			s=s->link;
		}
		s->link=p;
	}
	display();
}
void function(){
	struct node *f=head, *s=head, *p=head;
    int size=1;
    while(s->link!=NULL){
        s=s->link;
        size++;
    }
    s=head;
	for(int n=1; n<=size/2; n++){
		while(f->link!=NULL){
		    s=s->link;
		    f=f->link;
		}
		if(s->data!=p->data){
			printf("\nnot palindrome");
			return;
		}
		f=p;
		s=head;
		f=f->link;
		p=p->link;
	}
	printf("\nPalindrome");
}
int main(){
	int choice;
	while(1){
		printf("\n\nLINKED LIST MENU\n");
		printf("\n Enter 0 to display ");
		printf("\n Enter 1 to insert ");
		printf("\n Enter 2 to perform function ");
		printf("\n Enter 3 to exit ");
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 0:	display();break;
			case 1: insert();break;
			case 2: function();	break;
			case 3: exit(0);					
			default: printf("\nPlease enter a valid choice");
		}
	}
	return 0;
}
