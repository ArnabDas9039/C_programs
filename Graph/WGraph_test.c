#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
typedef struct edge{
	int src;
	int dest;
    int weight;
	struct edge* link;
}edge;
edge* graph[7];
edge* q[14];
int n = 7;
int rear = -1, drear = -1;
bool visit[] = { false, false, false, false, false, false, false };
unsigned int dist[] = {UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX};
int dist2[] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
void swap(edge** a, edge** b){
	edge* t = *a;
	*a = *b;
	*b = t;
}
int partition(edge** a, int low, int high){
	int p = dist[a[high]->dest];
	int j = low - 1;
	for(int i = low; i < high; i++){
		if(dist[a[i]->dest] < p){
			j++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[++j], &a[high]);
	return j;
}
void quicksort(edge** q, int low, int high){
	if(low < high){
		int pidx = partition(q, low, high);
		quicksort(q, low, pidx - 1);
		quicksort(q, pidx + 1, high);
	}
}
void enqueue(edge** q, edge* s){
    q[++rear] = s;
	// if(q[rear]==NULL){
	// 	printf("\nenqueue(-1)");
	// }
	// else{
	// 	printf("\nenqueue(%d)",q[rear]->dest);
	// }
    quicksort(q, 0, rear);
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
bool isempty(){
	if(rear == -1){
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
void appendweight(int src, int dest, int weight){
	edge* p = malloc(sizeof(edge));
	p->src = src;
	p->dest = dest;
    p->weight = weight;
	p->link = NULL;
	if(graph[src] == NULL){
		edge* vertex = malloc(sizeof(edge));
		vertex->src = src;
		vertex->dest = src;
        vertex->weight = 0;
		vertex->link = p;
		graph[src] = vertex;
	}
	else if(p->weight < graph[src]->link->weight){
		p->link = graph[src]->link;
		graph[src]->link = p;
	}
	else{
		for(edge* list = graph[src]->link; list != NULL; list = list->link){
			if(list->link == NULL){
				list->link = p;
				break;
			}
			else if(p->weight < list->link->weight){
				p->link = list->link;
				list->link = p;
				break;
			}
		}
	}
	return;
}
void append(int src, int dest, int weight){
	edge* p = malloc(sizeof(edge));
	p->src = src;
	p->dest = dest;
    p->weight = weight;
	p->link = NULL;
	if(graph[src] == NULL){
		edge* vertex = malloc(sizeof(edge));
		vertex->src = src;
		vertex->dest = src;
        vertex->weight = 0;
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
void addedge(int u, int v, int w){
	append(u, v, w);
	return;
}
void display(){
	edge* value;
	for(int i = 0; i < n; i++){
		value = graph[i];
		while(value != NULL){
			printf("%d(%d) => ", value->dest, value->weight);
			value = value->link;
		}
		printf("END\n");
	}
}
void dfs(edge* vertex){
	if(visit[vertex->dest] == true){
		return;
	}
	printf("%d ", vertex->dest);
	visit[vertex->dest] = true;
	edge* value = graph[vertex->dest];
	while(value != NULL){
		dfs(value);
		value = value->link;
	}
}
void bfs(edge *vertex){
	enqueue(q, graph[vertex->dest]);
	while(!isempty()){
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
bool cycle_detect(edge *vertex, int parent){
	printf("\nIndex is: %d, Parent is %d",vertex->dest, parent);
	if(visit[vertex->dest] == true){
		printf("\n%d is visited. Trying to reach %d from %d but parent is %d",vertex->dest,vertex->dest,vertex->src,parent);
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
void shortest_path(edge *vertex){
	enqueue(q, graph[vertex->dest]);
    // qdisplay();
    dist[vertex->dest] = 0;
	while(!isempty()){
		edge* value = dequeue(q);
        // qdisplay();
		if(visit[value->dest] == false){
			visit[value->dest] = true;
			value = graph[value->dest];
			while(value != NULL){
				if(dist[value->src] + value->weight < dist[value->dest]){
					dist[value->dest] = dist[value->src] + value->weight;
                    // printf("\nDistance %d updated for %d",dist[value->dest],value->dest);
					enqueue(q, value);
                    // qdisplay();
				}
				value = value->link;
			}
		}
	}
	for(int i = 0; i < 7; i++){
		printf("%d ",dist[i]);
	}
	return;
}
void bellmanford(edge* vertex){
	dist2[vertex->dest] = 0;
	for(int j = 0; j < 5; j++){
		for(int i = 0; i < 6; i++){
			edge *value = graph[i];
			while(value != NULL){
				if(dist2[value->src] != INT_MAX && dist2[value->src] + value->weight < dist2[value->dest]){
					dist2[value->dest] = dist2[value->src] + value->weight;
				}
				value = value->link;
			}
		}
	}
	for(int i = 0; i < 7; i++){
		printf("%d ", dist2[i]);
	}
	return;
}
int main(){
	// //0
	// addedge(0, 1, 2);
	// addedge(0, 2, 4);
	// //1
	// addedge(1, 0, 2);
	// addedge(1, 3, 7);
    // addedge(1, 2, 1);
	// //2
	// addedge(2, 0, 4);
    // addedge(2, 1, 1);
	// addedge(2, 4, 3);
	// //3
	// addedge(3, 1, 7);
	// addedge(3, 4, 2);
	// addedge(3, 5, 1);
	// //4
	// addedge(4, 2, 3);
	// addedge(4, 3, 2);
	// addedge(4, 5, 5);
	// //5
	// addedge(5, 3, 1);
	// addedge(5, 4, 5);
	// addedge(5, 6, 1);
	// //6
	// addedge(6, 5, 1);
	// display();

	addedge(0,1,10);addedge(0,5,8);
	addedge(1,3,2);
	addedge(2,1,1);
	addedge(3,2,-2);
	addedge(4,1,-4);addedge(4,3,-1);
	addedge(5,4,1);
	display();

	// dfs(graph[0]);
	// bfs(graph[0]);
	// printf("\n%d",cycle_detect(graph[0],-1));
	// shortest_path(graph[0]);
	bellmanford(graph[0]);
	return 0;
}

