#include<stdio.h>
#define MAX 50
char a[MAX];
void sort(char s[MAX], int i, int n){
	bool flag=true;
	if(s[i]!=NULL){
		for(int j=-1; j<i; j++){
			if(s[i]==s[j]){
				flag=false;
				break;
			}
		}
		if(flag==true){
			a[++n]=s[i];
		}
		sort(s, i+1, n);
	}
	else{
		printf("%s",a);
		return;
	}
}
int main(){
	char s[MAX]="abacad";
	printf("%s\n",s);
	sort(s, 0, -1);
	return 0;
}
