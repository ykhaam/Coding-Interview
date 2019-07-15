/* 
* ��� ������ ���
���� �׷����� �־����� �� �� ��� ���̿� ��ΰ� �����ϴ°�?
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct graph{//�׷����� ������.
	int vertex;//������ ����
	int **matrix;//���� ���
}Graph;

Graph *NewGraph(int max_vertex); //�׷��� ����
void printGraph(Graph *graph,int start, int dest); //�׷��� ���
void addEdge(Graph *graph,int start,int dest); //�׷��� edge �߰�

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
		//�޸� �����ϴ� �Լ�. 
		//Ư�� �޸� ������ ���ϴ� ũ�⸸ŭ�� Ư�� ���� 1���� setting
	}
	return graph;
}

void printGraph(Graph *graph,int start,int dest) {
	if (graph->matrix[start][dest] == 1)
		printf("�� ��� %d�� %d ������ ��ΰ� �����Ѵ�.\n", start, dest);
	else
		printf("�� ��� ������ ��δ� ����.\n");
}

void addEdge(Graph *graph, int start, int dest) {
	graph->matrix[start][dest] = 1;//edge set
}