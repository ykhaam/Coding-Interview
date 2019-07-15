/* 
* 노드 사이의 경로
방향 그래프가 주어졌을 때 두 노드 사이에 경로가 존재하는가?
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct graph{//그래프를 생성함.
	int vertex;//정점의 개수
	int **matrix;//인접 행렬
}Graph;

Graph *NewGraph(int max_vertex); //그래프 생성
void printGraph(Graph *graph,int start, int dest); //그래프 출력
void addEdge(Graph *graph,int start,int dest); //그래프 edge 추가

int main() {
	Graph *graph;
	graph = NewGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 1);
	printGraph(graph, 0, 1);
	printGraph(graph, 0, 3);
	printGraph(graph, 2, 1);
}

Graph *NewGraph(int max_vertex) {
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->vertex = max_vertex;
	graph->matrix = (int**)malloc(sizeof(int*)*max_vertex);
	for (int i = 0; i < max_vertex; i++) {
		graph->matrix[i] = (int*)malloc(sizeof(int)*max_vertex);
		memset(graph->matrix[i], 0, sizeof(int)*max_vertex);
		//메모리 조작하는 함수. 
		//특정 메모리 블럭에서 원하는 크기만큼을 특정 문자 1개로 setting
	}
	return graph;
}

void printGraph(Graph *graph,int start,int dest) {
	if (graph->matrix[start][dest] == 1)
		printf("두 노드 %d와 %d 사이의 경로가 존재한다.\n", start, dest);
	else
		printf("두 노드 사이의 경로는 없다.\n");
}

void addEdge(Graph *graph, int start, int dest) {
	graph->matrix[start][dest] = 1;//edge set
}