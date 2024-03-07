#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct circle{
	float a, b, c, r;
};
struct circle* c1;
struct circle* c2;
float radiuscalc(struct circle* c){
	c->r = sqrt(pow(c->a / 2, 2) + pow(c->b / 2, 2) - c->c);
	return c->r;
}
float circdistcalc(){
	return sqrt(pow((c1->a - c2->a) / 2, 2) + pow((c1->b - c2->b) / 2, 2));
}
float ptdist(float x1, float y1, float x2, float y2){
	//printf("(%f, %f)",x1, y1);
	//printf("(%f, %f)",x2, y2);
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
int main(){
	float d;
	printf("The equation of circle is x^2 + y^2 + ax + by + c = 0\n");
	while(1){
		c1 = malloc(sizeof(struct circle));
		c2 = malloc(sizeof(struct circle));
		printf("\nEnter the respective values of a,b & c for CIRCLE 1: ");
		scanf("%f %f %f", &c1->a, &c1->b, &c1->c);
		printf("\n%f %f %f", c1->a, c1->b, c1->c);
		if(pow(c1->a, 2) + pow(c1->b, 2) >= 4 * c1->c){
			printf("\nCenter is: (%f,%f).", -c1->a / 2, -c1->b / 2);
			printf("\nRadius is: %f.", radiuscalc(c1));
			break;
		}
		printf("\nCircle can not exist. Please enter correct values.");
	}
	while(1){
		printf("\nEnter the respective values of a,b & c for CIRCLE 2: ");
		scanf("%f %f %f", &c2->a, &c2->b, &c2->c);
		if(pow(c2->a, 2) + pow(c2->b, 2) >= 4 * c2->c){
			printf("\nCenter is: (%f,%f).", -c2->a / 2, -c2->b / 2);
			printf("\nRadius is: %f.", radiuscalc(c2));
			break;
		}
		printf("\nCircle can not exist. Please enter correct values.");
	}
	d = circdistcalc();
	printf("\n\n");
	if(c1->a == c2->a && c1->b == c2->b && c1->c == c2->c){
		printf("Circles are same.");
	}
	else if(c1->r + c2->r < d){
		printf("Circles do not intersect.");
	}
	else if(c1->r + c2->r == d || c1->r - c2->r == d){
		printf("Circles touch each other at a single point.");
	}
	else if(c1->r + c2->r > d && (c1->r - c2->r > d || c2->r - c1->r > d)){
		printf("One circle is within another.");
	}
	else if(c1->r + c2->r > d){
		printf("Circles intersect at two distinct points.");
	}
	float x1, y1;
	printf("\nEnter a point in (x, y): ");
	scanf("%f %f", &x1, &y1);
	printf("\n");
	if(ptdist(x1, y1, -c1->a / 2, -c1->b / 2) <= c1->r){
		printf("\nThe point is inside the circle c1.");
	}
	else{
		printf("\nThe point is outside the circle c1.");
	}
	if(ptdist(x1, y1, -c2->a / 2, -c2->b / 2) <= c2->r){
		printf("\nThe point is inside the circle c2.");
	}
	else{
		printf("\nThe point is outside the circle c2.");
	}
	if(ptdist(x1, y1, -c2->a / 2, -c2->b / 2) + ptdist(x1, y1, -c1->a / 2, -c1->b / 2) == d){
		printf("\nThe point lies on the line joining centers of the circles.");
	}
	else{
		printf("\nThe point doesn't lie on the line joining centers of the circles.");
	}
	if(ptdist(x1, y1, -c1->a / 2, -c1->b / 2) < ptdist(x1, y1, -c2->a / 2, -c2->b / 2)){
		printf("\nThe point lies nearer to circle c1");
	}
	else if(ptdist(x1, y1, -c1->a / 2, -c1->b / 2) > ptdist(x1, y1, -c2->a / 2, -c2->b / 2)){
		printf("\nThe point lies nearer to circle c2");
	}
	else{
		printf("\nThe point lies equally distant to both circles.");
	}
}
