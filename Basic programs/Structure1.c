//write a program to input details of three students and display them
#include<stdio.h>
#include<conio.h>
//input of structure
struct student{
	//naming of variables
	int roll;
	char name[50];
	//char *name; is more preferable.
	float mark;
	/*The following are applicable for a 16 bit compiler
	6 bytes for int and float and 50 bytes for char data type
	whereas for the second case --
	6 bytes for int and float and for char the memory will be allocated during run time*/
};
int main(){
	struct student s[3];//preferable for large inputs
	//struct student s1, s2, s3;
	int i;
	//input of data 3 times
	for(i = 0;i <= 2;i++){
		printf("Enter student roll = ");
		scanf("%d", &s[i].roll);
		printf("Enter the student name = ");
		fflush(stdin);//clear of buffer memory stdin->standard input
		gets(s[i].name);
		printf("Enter the marks = ");
		scanf("%f", &s[i].mark);
	}
	printf("\n Student details are ");
	//output of data 3 times
	for(i = 0;i <= 2;i++){
		printf("\n%d	%s	%f", s[i].roll, s[i].name, s[i].mark);
	}
	//return 0;
	getch();
}
