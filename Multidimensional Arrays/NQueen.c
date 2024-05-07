#include<stdio.h>
#include<stdbool.h>
#define MAX 8
int n;
int a[MAX][MAX];
bool isSafe(int r, int c){
	int i;
	for(i = 0; i < n; i++){
		if(a[i][c] == 1 || a[r][i] == 1 || (a[r + i][c + i] == 1 && r + i <= n && c + i <= n) || (a[r + i][c - i] == 1 && r + i <= n && c - i >= 0) || (a[r - i][c - i] == 1 && r - i >= 0 && c - i >= 0) || (a[r - i][c + i] == 1 && r - i >= 0 && c + i <= n)){
			return false;
		}
	}
	return true;
}
void display(){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf(" %d ", a[i][j]);
		}
		printf("\n");
	}
}
int rec_nqueen(int r, int c){
	display();
	printf("\n");
	if(r >= n){
		return 1;
	}
	if(c >= n){
		return 0;
	}
	if(isSafe(r,c)){
		a[r][c] = 1;
		if(rec_nqueen(r+1,0)){
			return 1;
		}
		a[r][c] = 0;
	}
	return rec_nqueen(r, c+1);
}
int rec_nqueen2(int r){
	if(r >= n){
		return 1;
	}
	for(int i = 0; i < n; i++){
		if(isSafe(r,i)){
			a[r][i] = 1;
			if(rec_nqueen2(r+1)){
				return 1;
			}
			a[r][i] = 0;
		}
	}
	return 0;
}
void solve2(){
	if(!rec_nqueen(0,0)){
		printf("Solution doesn't exist.");
		return;
	}
	display();
}
int reset(int r){
	for(int i = 0; i < n; i++){
		if(a[r][i] == 1){
			a[r][i] = 0;
			return i;
		}
	}
}
void solve(int r, int c, int k){
	int z;
	if(k >= n && (c >= n || r >= n)){
		display();
	}
	else if(k < n && (c >= n || r >= n)){
		z = reset(r - 1);
		solve(r - 1, z + 1, k - 1);
	}
	else if(isSafe(r, c) == true){
		a[r][c] = 1;
		solve(r + 1, 0, k + 1);
	}
	else if(isSafe(r, c) == false){
		solve(r, c + 1, k);
	}
}
int main(){
	printf("Enter the number of Queens: ");
	scanf("%d", &n);
	solve2();
	//solve(0, 0, 0);
	return 0;
}
