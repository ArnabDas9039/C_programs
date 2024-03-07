#include<stdio.h>
#include<math.h>
#include<float.h>
int main(){
	float x1, y1, x2, y2, slope;
	printf("enter the coordinates of point 1 : ");
	scanf("\n%f,\n%f", &x1, &y1);
	printf("enter the coordinates of point 2 : ");
	scanf("\n%f,\n%f", &x2, &y2);
	printf("\n(%f, %f), (%f, %f)", x1, y1, x2, y2);
	slope = (y1 - y2) / (x1 - x2);
	float intercept_y;
	intercept_y = y1 - (slope * x1);
	printf("the equation of the straight line connecting 1 and 2 is\n y=%fx+%f", slope, intercept_y);
	return 0;
}