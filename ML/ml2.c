#include<stdio.h>
#include<math.h>
#define output 10
#define input 7
/*float weight = output * (input);
float bias = output;*/
float wb[output][input+1];
float a[input];
float b1[output];
float b2[output];
float gradc[output][input+1];
void displayb(){
	printf("\nDisplaying b1 ... ");
	for(int i=0; i<output; i++){
		printf("%f ",b1[i]);
	}
	printf("\n");
}
/*
void displayb2(){
	printf("\nDisplaying b2 ... ");
	for(int i=0; i<output; i++){
		printf("%f ",b2[i]);
	}
	printf("\n");
}
void displaywb(){
	printf("\nDisplaying wb ...\n");
	for(int i=0; i<output; i++){
		for(int j=0; j<=input; j++){
			printf("%f ",wb[i][j]);
		}
		printf("\n");
	}
}*/
float calculateb(int i){
	float z=0;
	for(int j=0; j<input; j++){
		z=z+(a[j]*wb[i][j]);
	}
	return 1/(1+exp(-(z+wb[i][input])));
}
void createb(){
	for(int i=0; i<output; i++) {
		b1[i]=calculateb(i);
	}
	//displayb();
}
float costfunction(){
	float c=0;
	for(int i=0; i<output; i++){
		c=c+pow((b1[i]-b2[i]),2);
	}
	//printf("\nCost = %f",c);
	return c;
}
void gradientc(){
	float c1=costfunction();
	float c2;
	for(int i=0; i<output; i++){
		for(int j=0; j<=input; j++){
			float x=wb[i][j], y=b1[i];
			wb[i][j]=wb[i][j]+0.00001;
			b1[i]=calculateb(i);
			c2=costfunction();
			gradc[i][j]=(c2-c1)/0.00001;
			wb[i][j]=x;
			b1[i]=y;
		}
	}
}
void backprop(){
	createb();
	gradientc();
	for(int i=0; i<output; i++){
		for(int j=0; j<=input; j++){
			wb[i][j]=wb[i][j]-gradc[i][j];
		}
	}
}
int answer(){ 
	int index;
	createb();
	float MAX=0;
	for(int i=0; i<output; i++){
		if(b1[i]>MAX){
			MAX=b1[i];
			index=i;
		}
	}
	return index;
}
int main(){
	int n, training=10000;
	//Automatic training
	while(training>0){
		//0
		a[0]=1;
		a[1]=1;
		a[2]=1;
		a[3]=0;
		a[4]=1;
		a[5]=1;
		a[6]=1;
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[0]=1;
		backprop();
		//1
		a[0]=0;
		a[1]=0;
		a[2]=1;
		a[3]=0;
		a[4]=0;
		a[5]=0;
		a[6]=1;
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[1]=1;
		backprop();
		//2
		a[0]=0;
		a[1]=1;
		a[2]=1;
		a[3]=1;
		a[4]=1;
		a[5]=1;
		a[6]=0;
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[2]=1;
		backprop();
		//3
		a[0]=0;
		a[1]=1;
		a[2]=1;
		a[3]=1;
		a[4]=0;
		a[5]=1;
		a[6]=1;
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[3]=1;
		backprop();
		//4
		a[0]=1;
		a[1]=0;
		a[2]=1;
		a[3]=1;
		a[4]=0;
		a[5]=0;
		a[6]=1;
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[4]=1;
		backprop();
		//5
		a[0]=1;
		a[1]=1;
		a[2]=0;
		a[3]=1;
		a[4]=0;
		a[5]=1;
		a[6]=1;
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[5]=1;
		backprop();
		//6
		a[0]=1;
		a[1]=1;
		a[2]=0;
		a[3]=1;
		a[4]=1;
		a[5]=1;
		a[6]=1;
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[6]=1;
		backprop();
		//7
		a[0]=0;
		a[1]=1;
		a[2]=1;
		a[3]=0;
		a[4]=0;
		a[5]=0;
		a[6]=1;
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[7]=1;
		backprop();
		//8
		a[0]=1;
		a[1]=1;
		a[2]=1;
		a[3]=1;
		a[4]=1;
		a[5]=1;
		a[6]=1;
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[8]=1;
		backprop();
		//9
		a[0]=1;
		a[1]=1;
		a[2]=1;
		a[3]=1;
		a[4]=0;
		a[5]=1;
		a[6]=1;
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[9]=1;
		backprop();
		n++;
		training--;
	}
	printf("Trained the model for %d times.",n);
	/*printf("Manual Training starts: \n");
	while(1){
		printf("\nEnter input sequence: ");
		scanf("%f %f",&a[0], &a[1]);
		if(a[0]>1 || a[1]>1){
			break;
		}
		printf("\nEnter answer: ");
		scanf("%d",&n);
		for(int i=0; i<output; i++){
			b2[i]=0;
		}
		b2[n]=1;
		backprop();
	}
	*/
	printf("\nTesting starts: ");
	while(1){
		printf("\nEnter input sequence: ");
		scanf("%f %f %f %f %f %f %f", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]);
		if(a[0]>1 || a[1]>1){
			break;
		}
		printf("\nThe probable answer is: %d",answer());
		displayb();
	}
	return 0;
}
