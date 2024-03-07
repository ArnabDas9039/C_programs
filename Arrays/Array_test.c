#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX];
int sizecalc(){
	int n = 0;
	for(int i = 0; a[i] != NULL; i++){
		n++;
	}
	return n;
}
void display(){
	printf("\nThe array is: ");
	for(int i = 0;i < sizecalc();i++){
		printf(" %d", a[i]);
	}
	printf("\n");
}
void selectionsort(int i){
	int k;
	for(int j = i + 2; j < sizecalc(); j = j + 2){
		if(a[j] < a[i]){
			k = a[i];
			a[i] = a[j];
			a[j] = k;
		}
	}
}
void function(){
	int k, j;
	for(int i = 0; i < sizecalc(); i++){
		if(i % 2 == 0){
			selectionsort(i);
		}
		else{
			selectionsort(i);
		}
	}
	display();
}
int main(){
	int i, choice;
	a[2] = 32; a[1] = 21; a[3] = 43; a[4] = 10; a[0] = 54; a[5] = 76; a[6] = 98; a[7] = 65; a[8] = 87;
	while(1){
		printf("\n\nARRAY MENU\n");
		printf("\n Enter 0 to display ");
		printf("\n Enter 1 to perform function ");
		printf("\n Enter 2 to exit\n ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 0:	display();break;
		case 1: function();break;
		case 2: exit(0);
		default: printf("\nPlease enter a valid choice");
		}
	}
	return 0;
}
