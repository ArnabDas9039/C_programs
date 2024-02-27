#include<stdio.h>
void sortArr(int *a, int n){
    // int k;
    // for(int i=1; i<n; i++){
    //     k=arr[i];
	// 	int j=i-1;
    //     while(j>=0 && arr[j]>k){
    //             arr[j+1]=arr[j];
    //             j--;
    //     }
    //     arr[j+1]=k;
    // }
    // for(int i = 0; i < n; i++)
    //     printf("%d",arr[i]);
    // printf("\n");
    
}
int main(){
    int n;
	printf("Size ");
	scanf("%d",&n);
    int arr[n];   
	for(int i = 0; i < n; i++){
        printf("Array element at %d ",i);
		scanf("%d",&arr[i]);
	}
	sortArr(arr, n);
    //int v[] = sortArr(s, n);
        /*for(int i = 0; i < n; i++)
        	cout << s[i];
    	cout<<endl;*/
	return 0;
}
