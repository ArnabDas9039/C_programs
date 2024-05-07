#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
void display(int* a, int n){
	printf("\nThe array is: ");
	for(int i = 0;i < n;i++){
		printf(" %d", a[i]);
	}
	printf("\n");
}
void sortArr(int* a, int n){
	// Write test function here
	int k, swapped = 1;
	for(int i = 0; i < n && swapped; i++){
		swapped = 0;
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1]){
				k = a[j + 1];
				a[j + 1] = a[j];
				a[j] = k;
				swapped = 1;
			}
			display(a, n);
		}
	}
	printf("Array Sorted\n");
}
int partition(int* a, int low, int high){
	int p = a[high];
	int j = low - 1;
	for(int i = low; i < high; i++){
		if(a[i] < p){
			j++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[++j], &a[high]);
	return j;
}
void quicksort(int* a, int low, int high){
	if(low < high){
		int pidx = partition(a, low, high);
		quicksort(a, low, pidx - 1);
		quicksort(a, pidx + 1, high);
	}
}
void function(int* a, int n){
	sortArr(a, n);
	display(a, n);
	quicksort(a, 0, n-1);
	printf("\nOriginal Answer:");
	display(a, n);
}
void unsort(int* a, int n, int* b){
	for(int i = 0; i < n; i++){
		a[i] = b[i];
	}
	printf("Array Unsorted\n");
}
int main(){
	int i, choice;
	// int a[] = { 2,9,5,4,7,1,8,6,0,3 };
	int a[] = { 2,1,0,3 };
	int n = sizeof(a) / sizeof(a[0]);
	int b[n];
	for(int i = 0; i < n; i++){
		b[i] = a[i];
	}
	while(1){
		printf("\n\nARRAY MENU\n");
		printf("\n Enter 0 to display ");
		printf("\n Enter 1 to perform function ");
		printf("\n Enter 2 to unsort ");
		printf("\n Enter 10 to exit\n ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 0:	display(a, n);break;
		case 1: function(a, n);break;
		case 2: unsort(a, n, b); break;
		case 10: exit(0);
		default: printf("\nPlease enter a valid choice");
		}
	}
	return 0;
}
