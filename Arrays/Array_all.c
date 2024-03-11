#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
void display(int* a, int n){
	printf("\nThe array is: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void linearsearch(int* a, int n, int k){
	int idx = -1;
	for(int i = 0; i < n; i++){
		if(a[i] == k){
			idx = i;
		}
	}
	if(idx != -1){
		printf("Found at Index: %d\n", idx);
	}
	else{
		printf("NOT found\n");
	}
}
int binarysearch(int* a, int low, int high, int k){
	int mid = (low + high) / 2;
	if(low >= high){
		return -1;
	}
	else if(a[mid] == k){
		return mid;
	}
	else if(a[mid] > k){
		return binarysearch(a, low, mid, k);
	}
	else{
		return binarysearch(a, mid + 1, high, k);
	}
}
void reverse(int* a, int n){
	for(int i = 0; i < n / 2; i++){
		swap(&a[i], &a[n - i - 1]);
	}
	printf("Array reversed\n");
}
void selectionsort(int* a, int n){
	int k;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[i]){
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	printf("Array Sorted\n");
}
void bubblesort(int* a, int n){
	int k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1]){
				k = a[j + 1];
				a[j + 1] = a[j];
				a[j] = k;
			}
		}
	}
	printf("Array Sorted\n");
}
void insertionsort(int* a, int n){
	int k, j;
	for(int i = 0; i < n; i++){
		k = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > k){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}
	printf("Array Sorted\n");
}
void merge(int* a, int low, int mid, int high){
	int b[high - low], btop = -1, i = low, j = mid + 1;
	while(i <= mid && j <= high){
		if(a[i] <= a[j]){
			b[++btop] = a[i++];
		}
		else{
			b[++btop] = a[j++];
		}
	}
	while(i <= mid){
		b[++btop] = a[i++];
	}
	while(j <= high){
		b[++btop] = a[j++];
	}
	btop = 0;
	for(int i = low; i <= high; i++){
		a[i] = b[btop++];
	}
}
void mergesort(int* a, int low, int high){
	int mid = (low + high) / 2;
	if(low < high){
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}
int partition(int* a, int low, int high){
	int pivot = a[high], atop = low;
	for(int i = low; i < high; i++){
		if(a[i] < pivot){
			swap(&a[atop++], &a[i]);
		}
	}
	swap(&a[high], &a[atop]);
	return atop;
}
void quicksort(int* a, int low, int high){
	if(low < high){
		int pidx = partition(a, low, high);
		quicksort(a, low, pidx - 1);
		quicksort(a, pidx + 1, high);
	}
}
void unsort(int* a, int* b, int n){
	for(int i = 0; i < n; i++){
		a[i] = b[i];
	}
}
void subarray(int* a, int n){
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			for(int k = i; k <= j; k++){
				printf("%d ",a[k]);
			}
			printf("\n");
		}
	}
}
void subseq(int* a, int n){
	int p = pow(2, n);
	for(int i = 0; i <= p; i++){
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				printf("%d ", a[j]);
			}
		}
		printf("\n");
	}
}
void rec_subseq(int* a, int low, int n, int* b, int btop){
	if(low >= n){
		for(int i = 0; i < btop; i++){
			printf("%d ", b[i]);
		}
		printf("\n");
		return;
	}
	rec_subseq(a, low + 1, n, b, btop);
	b[btop++] = a[low];
	rec_subseq(a, low + 1, n, b, btop);
}
void initrec_subseq(int* a, int n){
	int b[n];
	rec_subseq(a, 0, n, b, 0);
}
void subseq_size(int* a, int n){
	int p = pow(2, n);
	for(int k = 1; k <= n; k++){
		for(int i = 0; i <= p; i++){
			int sum = 0;
			for(int j = 0; j < n; j++){
				if(i & (1 << j)){
					sum += 1;
				}
			}
			if(sum == k){
				for(int j = 0; j < n; j++){
					if(i & (1 << j)){
						printf("%d ", a[j]);
					}
				}
				printf("\n");
			}
		}
	}
}
int main(){
	int choice, n, k;
	printf("INITIALIZING ARRAY ...\n");
	printf("\nEnter size of the array: ");
	scanf("%d", &n);
	int a[n], b[n];
	printf("Enter %d elements: ", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	while(1){
		printf("\n\nARRAY MENU\n");
		printf("\n Enter 0 to display ");
		printf("\n Enter 1 to search using linear search");
		printf("\n Enter 2 to search using binary search");
		printf("\n Enter 3 to reverse the array ");
		printf("\n Enter 4 to sort using bubble sort ");
		printf("\n Enter 5 to sort using selection sort ");
		printf("\n Enter 6 to sort using insertion sort ");
		printf("\n Enter 7 to sort using merge sort ");
		printf("\n Enter 8 to sort using quick sort ");
		printf("\n Enter 9 to unsort ");
		printf("\n Enter 10 to generate all subarrays ");
		printf("\n Enter 11 to generate all subsequences ");
		printf("\n Enter 12 to generate all subsequences using recursion ");
		printf("\n Enter 13 to generate all subsequences in order of size ");
		printf("\n Enter 20 to exit\n ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 0:
			display(a, n);
			break;
		case 1:
			printf("Enter value to search: ");
			scanf("%d", &k);
			linearsearch(a, n, k);
			break;
		case 2:
			printf("Enter value to search: ");
			scanf("%d", &k);
			int idx = binarysearch(a, 0, n - 1, k);
			if(idx != -1){
				printf("Found at Index: %d\n", idx);
			}
			else{
				printf("NOT found\n");
			}
			break;
		case 3:
			reverse(a, n);
			break;
		case 4:
			bubblesort(a, n);
			break;
		case 5:
			selectionsort(a, n);
			break;
		case 6:
			insertionsort(a, n);
			break;
		case 7:
			mergesort(a, 0, n - 1);
			printf("Array Sorted\n");
			break;
		case 8:
			quicksort(a, 0, n - 1);
			printf("Array Sorted\n");
			break;
		case 9:
			unsort(a, b, n);
			break;
		case 10:
			subarray(a, n);
			break;
		case 11:
			subseq(a, n);
			break;
		case 12:
			initrec_subseq(a, n);
			break;
		case 13:
			subseq_size(a, n);
			break;
		case 20:
			exit(0);
		default: printf("\nPlease enter a valid choice");
		}
	}
	return 0;
}