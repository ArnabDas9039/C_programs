#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct edge{
	int src;
	int dest;
	struct edge *link;
}edge;
int n=7;
int rear=-1;
bool visit[] = {false, false, false, false, false, false, false};
edge *graph[7];
edge *q[14];
void enqueue(edge **q, edge *s){
	q[++rear] = s;
	// if(q[rear]==NULL){
	// 	printf("\nenqueue(-1)");
	// }
	// else{
	// 	printf("\nenqueue(%d)",q[rear]->dest);
	// }
	return;
}
edge *dequeue(edge **q){
	edge *ptr = q[0];
	for(int i=1; i<=rear; i++){
		q[i-1]=q[i];
	}
	q[rear]=NULL;
	rear--;
	// if(ptr==NULL){
	// 	printf("\ndequeue(-1)");
	// }
	// else{
	// 	printf("\ndequeue(%d)",ptr->dest);
	// }
	return ptr;
}
bool isempty(){
	if(rear==-1){
		return true;
	}
	return false;
}
void qdisplay(){
	printf("\nQ: ");
	for(int i=0; i<=rear; i++){
		if(q[i]==NULL){
			printf("-1 ");
		}
		else{
			printf("%d ",q[i]->dest);
		}
	}
}
void append(int src, int dest){
	edge *p = malloc(sizeof(edge));
	p->src=src;
	p->dest=dest;
	p->link=NULL;
	if(graph[src]==NULL){
		edge *vertex = malloc(sizeof(edge));
		vertex->src = src;
		vertex->dest = src;
		vertex->link = p;
		graph[src]=vertex;
	}
	else if(p->dest < graph[src]->link->dest){
		p->link = graph[src]->link;
		graph[src]->link=p;
	}
	else{
		for(edge *list = graph[src]->link; list != NULL; list=list->link){
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
void bfs(int index){
	enqueue(q, graph[index]);
	while(!isempty()){
		edge *value = dequeue(q);
		if(visit[value->dest] == false){
			printf("%d ", value->dest);
			visit[value->dest] = true;
			value = graph[value->dest];
			while(value!=NULL){
				enqueue(q, value);
				value = value->link;
			}
		}
	}
	return;
}
int main(){
	//edge *graph[n];
	//0
	addedge(0, 1);
	//printf("0 => %d => %d\n",graph[0]->dest, graph[0]->link->dest);
	addedge(0, 2);
	//printf("0 => %d",graph[0]->dest);
	//1
	addedge(1, 0);
	addedge(1, 3);
	//2
	addedge(2, 0);
	addedge(2, 4);
	//3
	addedge(3, 1);
	addedge(3, 4);
	addedge(3, 5);
	//4
	addedge(4, 2);
	addedge(4, 3);
	addedge(4, 5);
	//5
	addedge(5, 3);
	addedge(5, 4);
	addedge(5, 6);
	//6
	addedge(6, 5);
	display();
	//dfs(0);
	bfs(1);
	return 0;
}
