#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
	int number;
	struct node *left;
	struct node *right;
} node;
node *root = NULL;
int front = -1, rear = -1;
int top = -1;
int maximum(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
void enqueue(node **q, node *s)
{
	if (front == -1)
	{
		front = 0;
	}
	q[++rear] = s;
	return;
}
node *dequeue(node **q)
{
	node *ptr = *q;
	for (int i = 1; i <= rear; i++)
	{
		q[i - 1] = q[i];
	}
	rear--;
	return ptr;
}
bool isempty(node **q)
{
	for (int i = 0; i < rear; i++)
	{
		if (q[i] != NULL)
		{
			return false;
		}
	}
	return true;
}
int count(node *s)
{
	if (s != NULL)
	{
		return count(s->left) + count(s->right) + 1;
	}
	else
	{
		return 0;
	}
}
int height(node *s)
{
	if (s == NULL)
	{
		return 0;
	}
	if (height(s->left) > height(s->right))
	{
		return height(s->left) + 1;
	}
	else
	{
		return height(s->right) + 1;
	}
}
int calcdiameter(node *s)
{
	if (s == NULL)
	{
		return 0;
	}
	return maximum(maximum(diameter(s->left), diameter(s->right)), height(s->left) + height(s->right) + 1);
}
void displaypreorder(node *s)
{
	if (s == NULL)
	{
		printf("-1, ");
		return;
	}
	printf("%d, ", s->number);
	displaypreorder(s->left);
	displaypreorder(s->right);
}
void displayinorder(node *s)
{
	if (s == NULL)
	{
		printf("-1, ");
		return;
	}
	displayinorder(s->left);
	printf("%d, ", s->number);
	displayinorder(s->right);
}
void displaylevelorder(node *s, node **q)
{
	printf("\nLevelorder: ");
	enqueue(q, s);
	enqueue(q, NULL);
	while (!isempty(q))
	{
		node *curr = dequeue(q);
		if (curr == NULL)
		{
			if (isempty(q))
			{
				break;
			}
			enqueue(q, NULL);
		}
		else
		{
			printf("%d ", curr->number);
			if (curr->left != NULL)
			{
				enqueue(q, curr->left);
			}
			if (curr->right != NULL)
			{
				enqueue(q, curr->right);
			}
		}
	}
}
void displaylvlorder(node *s)
{
	node **q = malloc(count(s) * sizeof(node));
	displaylevelorder(s, q);
}
node *insertrec(int *a)
{
	top++;
	if (a[top] == -1)
	{
		return NULL;
	}
	node *ptr = malloc(sizeof(node));
	ptr->number = a[top];
	ptr->left = insertrec(a);
	ptr->right = insertrec(a);
}
void insertpreorder()
{
	int n, *a;
	printf("Enter the height: ");
	scanf("%d", &n);
	a = malloc(n * sizeof(int));
	printf("Enter the preorder array: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", (a + i));
	}
	root = insertrec(a);
}
int main()
{
	int choice;
	while (1)
	{
		printf("\n\nBINARY TREE MENU\n");
		printf("\n Enter 0 to display inorder ");
		printf("\n Enter 1 to display preorder ");
		printf("\n Enter 2 to display postorder ");
		printf("\n Enter 3 to display levelorder ");
		printf("\n Enter 4 to insert at an empty position ");
		printf("\n Enter 5 to insert at specific position ");
		printf("\n Enter 6 to insert by an inorder array ");
		printf("\n Enter 7 to delete any position ");
		printf("\n Enter 8 to delete any value ");
		printf("\n Enter 9 to find diameter ");
		printf("\n Enter 10 to exit\n ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			displayinorder(root);
			break;
		case 1:
			displaypreorder(root);
			break;
		case 2:
			displaypostorder(root);
			break;
		case 3:
			displaylvlorder(root);
			break;
		case 4:
			insertrand();
			break;
		case 5:
			insertspec();
			break;
		case 6:
			insertpreorder();
			break;
		case 7:
			deleteanypos();
			break;
		case 8:
			deleteanyval();
			break;
		case 9:
			diameter();
			break;
		case 10:
			exit(0);
		default:
			printf("\nPlease enter a valid choice");
		}
	}
	return 0;
}