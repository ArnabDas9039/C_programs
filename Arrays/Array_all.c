#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int a[MAX];
int top=-1;
int sizecalc(){
	int n=0;
	for(int i=0; a[i]!=NULL; i++){
		n++;
	}
	return n;
}
void display(){
	printf("\nThe array is: ");
	for(int i=0;i<sizecalc();i++){
		printf(" %d",a[i]);
	}
	printf("\n");
}
void insert(){
	if(top==MAX){
		printf("Array overflow");
	}
	else{
		int n;
		printf("Enter value: ");
		scanf("%d",&n);
		a[++top]=n;
	}
}
void del(){
	if(top==-1){
		printf("Array underflow.");
	}
	else{
		
	}
}
void selectionsort(){
	int k;
	for(int i=0; i<sizecalc(); i++){
		for(int j=i+1; j<sizecalc();j++){
			if(a[j]<a[i]){
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}	
}
void bubblesort(){
	int k;
	for(int i=0; i<sizecalc()-1; i++){
		for(int j=0; j<sizecalc()-i-1; j++){
			if(a[j]>a[j+1]){
				k=a[j+1];
				a[j+1]=a[j];
				a[j]=k;
			}
		}
	}
	display();
}
void insertionsort(){
	int k, j;
	for(int i=0; i<sizecalc(); i++){
		k=a[i];
		j=i-1;
		while(j>=0 && a[j]>k){
			a[j+1]=a[j];
			j--;
			display();
			printf("i is %d.\n",i);
		}
		a[j+1]=k;
	}
	display();
}
int main(){
	int i, choice;
	while(1){
		printf("\n\nARRAY MENU\n");
		printf("\n Enter 0 to display ");
		printf("\n Enter 1 to enter value ");
		printf("\n Enter 2 to sort using selection sort ");
		printf("\n Enter 3 to sort using bubble sort ");
		printf("\n Enter 4 to reverse the array ");
		printf("\n Enter 10 to exit\n ");
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 0:	display();break;
			case 1: insert();break;
			case 2: selectionsort();break;
			case 3: bubblesort();break;
			//case 4: reverse();break;
			case 10: exit(0);					
			default: printf("\nPlease enter a valid choice");
		}
	}
	return 0;
}
