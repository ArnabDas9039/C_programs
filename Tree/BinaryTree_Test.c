#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct node{
	int number;
	struct node *left;
	struct node *right;
}node;
int front = -1, rear = -1;
int top = -1;
int maximum(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}
void enqueue(node **q, node *s){
	if(front == -1){
		front=0;
	}
	q[++rear] = s;
	return;
}
node *dequeue(node **q){
	node *ptr = *q;
	for(int i=1; i<=rear; i++){
		q[i-1]=q[i];
	}
	rear--;
	return ptr;
}
bool isempty(node **q){
	for(int i=0; i<rear; i++){
		if(q[i] != NULL){
			return false;
		}
	}
	return true;
}
int count(node *s){
	if(s!=NULL){
		return count(s->left)+count(s->right)+1;
	}
	else{
		return 0;
	}
}
int height(node *s){
	if(s==NULL){
		return 0;
	}
	if(height(s->left)>height(s->right)){
		return height(s->left)+1;
	}
	else{
		return height(s->right)+1;
	}
}
int diameter(node *s){
	if(s==NULL){
		return 0;
	}
	return maximum(maximum(diameter(s->left), diameter(s->right)), height(s->left)+height(s->right)+1);
}
void displaypreorder(node *s){
	if(s == NULL){
		printf("-1, ");
		return;
	}
	printf("%d, ",s->number);
	displaypreorder(s->left);
	displaypreorder(s->right);
}
void displayinorder(node *s){
	if(s == NULL){
		printf("-1, ");
		return;
	}
	displayinorder(s->left);
	printf("%d, ",s->number);
	displayinorder(s->right);
}
void displaylevelorder(node *s, node **q){
	printf("\nLevelorder: ");
	enqueue(q, s);
	enqueue(q, NULL);
	while(!isempty(q)){
		node *curr=dequeue(q);
		if(curr == NULL){
			if(isempty(q)){
				break;
			}
			enqueue(q, NULL);
		}
		else{
			printf("%d ",curr->number);
			if(curr->left != NULL){
				enqueue(q, curr->left);
			}
			if(curr->right != NULL){
				enqueue(q, curr->right);
			}
		}
	}
}
node *insertpreorder(int *a){
	top++;
	if(a[top]==-1){
		return NULL;	
	}
	node *ptr = malloc(sizeof(node));
	ptr->number=a[top];
	ptr->left= insertpreorder(a);
	ptr->right= insertpreorder(a);
}
int main(void){
	int a[]={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	printf("\nProgram started");
	int size = sizeof(a)/sizeof(a[0]);
	node *q[size];
	node *root = insertpreorder(a);
	printf("\nThe list is: %d, %d, %d, %d, %d, %d\n",root->number, root->left->number, root->right->number, root->left->left->number, root->left->right->number, root->right->right->number);
	displaypreorder(root);
	printf("\n");
	displayinorder(root);
	displaylevelorder(root, q);
	printf("\nNumber of nodes: %d",count(root));
	printf("\nHeight of tree: %d",height(root));
	printf("\nDiameter of tree: %d",diameter(root));
	return 0;
}