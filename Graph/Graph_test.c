#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
typedef struct edge{
	int src;
	int dest;
	struct edge* link;
}edge;
edge* graph[7];
edge* q[14];
edge* s[14];
int n = 7;
int rear = -1, top = -1;
bool visit[] = { false, false, false, false, false, false, false };
unsigned int dist[] = { UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX };
void enqueue(edge** q, edge* node){
	q[++rear] = node;
	// if(q[rear]==NULL){
	// 	printf("\nenqueue(-1)");
	// }
	// else{
	// 	printf("\nenqueue(%d)",q[rear]->dest);
	// }
	return;
}
edge* dequeue(edge** q){
	edge* ptr = q[0];
	for(int i = 1; i <= rear; i++){
		q[i - 1] = q[i];
	}
	q[rear] = NULL;
	rear--;
	// if(ptr==NULL){
	// 	printf("\ndequeue(-1)");
	// }
	// else{
	// 	printf("\ndequeue(%d)",ptr->dest);
	// }
	return ptr;
}
bool isqempty(){
	if(rear == -1){
		return true;
	}
	return false;
}
void push(edge** s, edge* node){
	s[++top] = node;
	// if(s[top]==NULL){
	// 	printf("\npush(-1)");
	// }
	// else{
	// 	printf("\npush(%d)",s[top]->dest);
	// }
	return;
}
edge* pop(edge** s){
	edge* ptr = s[top];
	// if(ptr==NULL){
	// 	printf("\npop(-1)");
	// }
	// else{
	// 	printf("\npop(%d)",ptr->dest);
	// }
	s[top] = NULL;
	top--;
	return ptr;
}
bool issempty(){
	if(top == -1){
		return true;
	}
	return false;
}
void qdisplay(){
	printf("\nQ: ");
	for(int i = 0; i <= rear; i++){
		if(q[i] == NULL){
			printf("-1 ");
		}
		else{
			printf("%d ", q[i]->dest);
		}
	}
}
void sdisplay(){
	printf("\nS: ");
	for(int i = 0; i <= top; i++){
		if(s[i] == NULL){
			printf("-1 ");
		}
		else{
			printf("%d ", s[i]->dest);
		}
	}
}
void append(int src, int dest){
	edge* p = malloc(sizeof(edge));
	p->src = src;
	p->dest = dest;
	p->link = NULL;
	if(graph[src] == NULL){
		edge* vertex = malloc(sizeof(edge));
		vertex->src = src;
		vertex->dest = src;
		vertex->link = p;
		graph[src] = vertex;
	}
	else if(p->dest < graph[src]->link->dest){
		p->link = graph[src]->link;
		graph[src]->link = p;
	}
	else{
		for(edge* list = graph[src]->link; list != NULL; list = list->link){
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
	edge* value;
	for(int i = 0; i < n; i++){
		value = graph[i];
		while(value != NULL){
			printf("%d => ", value->dest);
			value = value->link;
		}
		printf("END\n");
	}
}
void dfs_rec(edge* vertex){
	if(visit[vertex->dest] == true){
		return;
	}
	printf("%d ", vertex->dest);
	visit[vertex->dest] = true;
	edge* value = graph[vertex->dest];
	while(value != NULL){
		dfs_rec(value);
		value = value->link;
	}
}
void dfs(edge* vertex){
	push(s, graph[vertex->dest]);
	while(!issempty()){
		edge* value = pop(s);
		if(visit[value->dest] == false){
			printf("%d ", value->dest);
			visit[value->dest] = true;
			value = graph[value->dest];
			while(value != NULL){
				push(s, value);
				value = value->link;
			}
		}
	}
}
void bfs(edge* vertex){
	enqueue(q, graph[vertex->dest]);
	while(!isqempty()){
		edge* value = dequeue(q);
		if(visit[value->dest] == false){
			printf("%d ", value->dest);
			visit[value->dest] = true;
			value = graph[value->dest];
			while(value != NULL){
				enqueue(q, value);
				value = value->link;
			}
		}
	}
	return;
}
bool cycle_detect(edge* vertex, int parent){
	printf("\nIndex is: %d, Parent is %d", vertex->dest, parent);
	if(visit[vertex->dest] == true){
		printf("\n%d is visited. Trying to reach %d from %d but parent is %d", vertex->dest, vertex->dest, vertex->src, parent);
		if(parent != vertex->dest){
			return true;
		}
		return false;
	}
	visit[vertex->dest] = true;
	edge* value = graph[vertex->dest]->link;
	while(value != NULL){
		if(cycle_detect(value, vertex->src)){
			return true;
		}
		value = value->link;
	}
	return false;
}
void short_path(edge* vertex){
	enqueue(q, graph[vertex->dest]);
	dist[vertex->dest] = 0;
	while(!isqempty()){
		edge* value = dequeue(q);
		if(visit[value->dest] == false){
			visit[value->dest] = true;
			value = graph[value->dest];
			while(value != NULL){
				if(dist[value->src] + 1 < dist[value->dest]){
					dist[value->dest] = dist[value->src] + 1;
					enqueue(q, value);
				}
				value = value->link;
			}
		}
	}
	for(int i = 0; i < 7; i++){
		printf("%d ", dist[i]);
	}
	return;
}
void bellmanford(edge* vertex){
	dist[vertex->dest] = 0;
	for(int i = 0; i < 7; i++){
		edge *value = graph[i];
		while(value != NULL){
			if(dist[value->src] != UINT_MAX && dist[value->src] + 1 < dist[value->dest]){
				dist[value->dest] = dist[value->src] + 1;
			}
			value = value->link;
		}
	}
	for(int i = 0; i < 7; i++){
		printf("%d ", dist[i]);
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
	// dfs(graph[0]);
	// bfs(graph[0]);
	// dfs_rec(graph[0]);
	printf("\n%d",cycle_detect(graph[0],-1));
	// short_path(graph[0]);
	// bellmanford(graph[1]);
	return 0;
}
