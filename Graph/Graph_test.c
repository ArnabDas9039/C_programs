#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct edge{
	int src;
	int dest;
	struct edge *link;
}edge;
typedef struct graph{
	
}
int n=7;
int front=-1, rear=-1;
bool visit[7];
edge *graph[7];
int q[14];
void enqueue(int *q, edge *s){
	if(front == -1){
		front=0;
	}
	q[++rear] = s->dest;
	printf("\nenqueue(%d). Rear is %d",s->dest,rear);
	return;
}
int dequeue(int *q){
	int x = q[0];
	for(int i=1; i<=rear; i++){
		q[i-1]=q[i];
	}
	rear--;
	printf("\ndequeue(%d). Rear is %d",x,rear);
	return x;
}
bool isempty(int *q){
	if(rear==-1){
		return false;
	}
	return true;
}
void qdisplay(int *q){
	printf("\nQ: ");
	for(int i=0; i<=rear; i++){
		printf("%d->(%d) ",i,q[i]);
	}
}
void append(int src, int dest){
	edge *p = malloc(sizeof(edge));
	p->src=src;
	p->dest=dest;
	p->link=NULL;
	if(graph[src]==NULL){
		graph[src]=p;
	}
	else if(p->dest < graph[src]->dest){
		p->link = graph[src];
		graph[src]=p;
	}
	else{
		for(edge *list = graph[src]; list != NULL; list=list->link){
			if(list->link == NULL){
				list->link = p;
				break;
			}
			else if(p->dest < list->link->dest){
				p->link = list->link;
				list->link = p;
				break;
			}
		}
	}
	return;
}
void addedge(int u, int v){
	append(u, v);
	return;
}
void display(){
	edge *value;
	for(int i=0; i<n; i++){
		printf("%d => ",i);
		value = graph[i];
		while(value!=NULL){
			printf("%d => ",value->dest);
			value=value->link;
		}
		printf("END\n");
	}
}
void dfs(int index){
	if(visit[index]==true){
		return;
	}
	printf("%d ",index);
	visit[index]=true;
	edge *value = graph[index];
	while(value!=NULL){
		dfs(value->dest);
		value = value->link;
	}
}
void bfs(int *q){
	enqueue(q, graph[0]);
	qdisplay(q);
	while(!isempty(q)){
		printf("\nQueue isn't empty.");
		int dq = dequeue(q);
		edge *value = graph[dq];
		qdisplay(q);
		if(visit[dq] == false){
			printf("%d ", value->dest);
			visit[dq] = true;
			qdisplay(q);
			while(value->link!=NULL){
				value = value->link;
				enqueue(q, value);
				qdisplay(q);
			}
		}
		free(value);
	}
	return;
}
int main(){
	//edge *graph[n];
	//0
	addedge(0, 0);
	addedge(0, 1);
	addedge(0, 2);
	//printf("0 => %d",graph[0]->dest);
	//printf("0 => %d => %d\n",graph[0]->dest, graph[0]->link->dest);
	//1
	addedge(1, 1);
	addedge(1, 0);
	addedge(1, 3);
	//2
	addedge(2, 2);
	addedge(2, 0);
	addedge(2, 4);
	//3
	addedge(3, 3);
	addedge(3, 1);
	addedge(3, 4);
	addedge(3, 5);
	//4
	addedge(4, 4);
	addedge(4, 2);
	addedge(4, 3);
	addedge(4, 5);
	//5
	addedge(5, 5);
	addedge(5, 3);
	addedge(5, 4);
	addedge(5, 6);
	//6
	addedge(6, 6);
	addedge(6, 5);
	display();
	bfs(q);
	return 0;
}
