#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void display(int* a, int n){
	printf("\nThe array is: ");
	for(int i = 0;i < n;i++){
		printf(" %d", a[i]);
	}
	printf("\n");
}
void function(int* a, int n){
	//Write function here
	display(a, n);
}
int main(){
	int i, choice;
	int a[] = {2,9,5,4,7,1,8,6,0,3};
	int n = sizeof(a) / sizeof(a[0]);
	while(1){
		printf("\n\nARRAY MENU\n");
		printf("\n Enter 0 to display ");
		printf("\n Enter 1 to perform function ");
		printf("\n Enter 10 to exit\n ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 0:	display(a, n);break;
		case 1: function(a, n);break;
		case 10: exit(0);
		default: printf("\nPlease enter a valid choice");
		}
	}
	return 0;
}