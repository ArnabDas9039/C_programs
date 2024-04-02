#include<stdio.h>
#include<stdbool.h>
#define MAX 9
int a[MAX][MAX]/* = {
	{3,0,0,8,0,1,0,0,2},
	{2,0,1,0,3,0,6,0,4},
	{0,0,0,2,0,4,0,0,0},
	{8,0,9,0,0,0,1,0,6},
	{0,6,0,0,0,0,0,5,0},
	{7,0,2,0,0,0,4,0,9},
	{0,0,0,5,0,9,0,0,0},
	{9,0,4,0,8,0,7,0,5},
	{6,0,0,1,0,7,0,0,3},
}*/;
bool isSafe(int r, int c, int z){
	for(int i = 0; i < MAX; i++){
		if(a[i][c] == z){
			return false;
		}
		else if(a[r][i] == z){
			return false;
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(a[i + r - r % 3][j + c - c % 3] == z){
				return false;
			}
		}
	}
	return true;
}
void display(){
	int i, j;
	printf("\n");
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			printf(" %d ", a[i][j]);
		}
		printf("\n");
	}
}
int sudoku(int r, int c){
	if(r == MAX){
		display();
		return 1;
	}
	if(c == MAX){
		return sudoku(r + 1, 0);
	}
	if(a[r][c] != 0){
		return sudoku(r, c + 1);
	}
	for(int i = 1; i <= MAX; i++){
		if(isSafe(r, c, i)){
			a[r][c] = i;
			if(sudoku(r, c + 1)){
				return 1;
			}
			a[r][c] = 0;
		}
	}
	return 0;
}
int main(){
	printf("\n\nSUDOKU\n");
	//display();
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			scanf("%d",&a[i][j]);
		}
	}
	sudoku(0, 0);
	return 0;
}
