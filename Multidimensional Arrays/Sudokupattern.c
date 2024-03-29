#include<stdio.h>
#include<stdbool.h>
#define MAX 9
int a[MAX][MAX];
bool isSafe(int r, int c, int z){
	int i;
	for(i = 0; i < MAX; i++){
		if(a[i][c] == z){
			return false;
		}
		else if(a[r][i] == z){
			return false;
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
void solve(int r, int c, int z);
void reset(int r, int c){
	int k = a[r][c - 1];
	a[r][c - 1] = 0;
	solve(r, c - 1, k + 1);
}
void nextbox(int r, int c){
	//printf("\nNext box function.");
	if(c < MAX - 1){
		//printf("\nnext column");
		solve(r, c + 1, 1);
	}
	else{
		//printf("\nnext row");
		solve(r + 1, 0, 1);
	}
}
void solve(int r, int c, int z){
	if(c >= MAX || r >= MAX){
		//printf("\nCondition satisfied for print.");
		display();
	}
	else if(a[r][c] == 0 && z <= MAX && z > 0){
		//printf("\nCondition satisfied for empty space.");
		if(isSafe(r, c, z) == true){
			//printf("\nCondition satisfied for safe. Safe number is %d.",z);
			a[r][c] = z;
			nextbox(r, c);
		}
		else if(isSafe(r, c, z) == false){
			//printf("\nCondition satisfied for not safe. Moving to next number. Not safe number is %d",z);
			solve(r, c, z + 1);
		}
	}
	else if(z >= MAX){
		//printf("\nCondition satisfied for none of the numbers are possible.");
		reset(r, c);
	}
	else{
		nextbox(r, c);
	}
}
int main(){
	printf("\n\nSUDOKU");
	solve(0, 0, 1);
	//display();
	return 0;
}
