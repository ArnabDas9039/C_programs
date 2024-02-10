#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
typedef struct node{
    int number;
    struct node *left;
    struct node *right;
}node;
vector<node *> q;
int top=-1;
void displaypreorder(node *s){
	if(s == NULL){
		printf("-1, ");
		return;
	}
	printf("%d, ",s->number);
	displaypreorder(s->left);
	displaypreorder(s->right);
}
node *insertpreorder(int *a){
	top++;
	if(a[top]==-1){
		return NULL;	
	}
	node *ptr = (node *) malloc(sizeof(node));
	ptr->number=a[top];
	ptr->left= insertpreorder(a);
	ptr->right= insertpreorder(a);
}
void displaylevelorder(node *s){
	printf("\nLevelOrder: \n");
	q.push_back(s);
	q.push_back(NULL);
	while(!q.empty()){
		node *curr= q.front();
        q.erase(q.begin());
		if(curr == NULL){
			printf("\n");
			if(q.empty()){
				break;
			}
			q.push_back(NULL);
		}
		else{
			printf("%d, ",curr->number);
			if(curr->left != NULL){
				q.push_back(curr->left);
			}
			if(curr->right != NULL){
				q.push_back(curr->right);
			}
		}
	}
}
int main(){
    int a[]={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	printf("\nProgram started");
	int size = sizeof(a)/sizeof(a[0]);
	node *root = insertpreorder(a);
	printf("\nThe list is: %d, %d, %d, %d, %d, %d\n",root->number, root->left->number, root->right->number, root->left->left->number, root->left->right->number, root->right->right->number);
	displaypreorder(root);
    displaylevelorder(root);
}
