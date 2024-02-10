#include<stdio.h>
#define MAX 10
int a[MAX], b[MAX], c[MAX];
int atop=-1, btop=-1, ctop=-1;
void selectrod(int k, int i);
void pusha(int i){
	printf("\npush A(%d)",i);
	a[++atop]=i;
}
int popa(){
	printf("\npop A()");
	return a[atop];
}
void pushb(int i){
	printf("\npush B(%d)",i);
	b[++btop]=i;
}
int popb(){
	printf("\npop B()");
	return b[btop];
}
void pushc(int i){
	printf("\npush C(%d)",i);
	c[++ctop]=i;
}
int popc(){
	printf("\npop C()");
	return c[ctop];
}
void push(int i, char rod){
	if(rod == 'A')
		pusha(i);
	else if(rod == 'B')
		pushb(i);
	else if(rod == 'C')
		pushc(i);
}
int pop(char rod){
	int k;
	if(rod == 'A'){
		k=popa();
		a[atop]=NULL;
		atop--;
	}
	else if(rod == 'B'){
		k=popb();
		b[btop]=NULL;
		btop--;
	}
	else if(rod == 'C'){
		k=popc();
		c[ctop]=NULL;
		ctop--;
	}
	return k;
}
void display(int n){
	for(int i=n-1;i>=0;i--){
		printf("\n%d\t%d\t%d",a[i],b[i],c[i]);
	}
	printf("\nA\tB\tC\t\n");
}
void gamestart(int n, int i, char from, char to, char aux){
	int k;
	if(n==1){
		k=pop(from);
		push(k, to);
		display(i);
		return;
	}
	gamestart(n-1, i, from, aux, to);
	k=pop(from);
	push(k, to);
	display(i);
	gamestart(n-1, i, aux, to, from);
}
int main(){
	int n;
	printf("\nProgram of TOWER OF HANOI\n");
	printf("Enter the number of disks: ");
	scanf("%d",&n);
	for(int i=n; i>=1; i--){
		pusha(i);
	}
	display(n);
	gamestart(n, n, 'A', 'B', 'C');
}
