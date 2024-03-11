#include<stdio.h>
// This program has both functions of linear and binary search. Please use array sorted in increasing order to perform binary search 
int search(int* a, int n, int k){
	for(int i = 0; i < n; i++){
		if(a[i] == k){
			return i+1;
		}
	}
	return 0;
}
int binarysearch(int* a, int low, int high, int k){
	if(low > high){
		return -1;
	}
	int mid = (low+high)/2;
	if(a[mid] == k){
		return mid;
	}
	else if(k < a[mid]){
		return binarysearch(a, low, mid, k);
	}
	else{
		return binarysearch(a, mid+1, high, k);
	}
}
int main(){
	int a[] = {2,9,5,4,7,1,8,6,0,3};
	// int a[] = {0,1,2,3,4,5,6,7,8,9};
	int n = sizeof(a) / sizeof(a[0]);
	printf("The array is: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	int k;
	printf("Enter a key to search: ");
	scanf("%d",&k);
	if(search(a, n, k)){
		printf("Found at position %d\n",search(a,n,k));
	}
	else{
		printf("Not Found\n");
	}
	// printf("Binarysearch: %d",binarysearch(a,0,n-1,k));
	return 0;
}
