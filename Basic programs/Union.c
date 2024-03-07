/*What is union?
Union is type of structure with some differences. Keyword is "union".
Memory is allocated to the largest data type. Others share the memory with the largest one.
Replace "struct" in place of all the "union" in the program to see the differences.*/
//.c -> .obj -> .exe
#include<stdio.h>
#include<conio.h>
union student{
	//name of variables
	int roll;
	char name[50];
	//char *name; is more preferable.
	float mark;
};
int main(){
	union student s;
	printf("Size of stucture is %d", sizeof(s));//sizeof calculates the memory allocated size of the datatype
	return 0;
	getch();
}
