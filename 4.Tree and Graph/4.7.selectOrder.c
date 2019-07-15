#define _CRT_SECURE_NO_WARNINGS
/*
4.7 순서 정하기
프로젝트의 리스트와 프로젝트들 간의 종속 관계
(즉, 프로젝트 쌍이 리스트로 주어지면 각 프로젝트 쌍에서 두번째
프로젝트가 첫번째 프로젝트에 종속되어 있다는 뜻)가 주어졌을 때,
프로젝트를 수행해 나가는 순서를 찾아라.
유효한 순서가 존재하지 않으면 에러를 반환한다.

input :  a,b,c,d,e,f
		(a,d), (f,b),(b,d),(f,a),(d,c)
output : f,e,a,b,d,c
*/

/*
1. 각 프로젝트가 선행 프로젝트의 개수를 알아야 함.
2. 그래프로 바꿔서 생각해보기.
3. BFS를 통해 푼다.
4. 선행 프로젝트가 없는 프로젝트를 queue에 담는다.
5. queue 안의 프로젝트를 list에 넣고 check한다.
6. 종속되어 있는 프로젝트의 선행 프로젝트 개수 하나씩 줄임.
선행 프로젝트가 0개가 되면 또 queue에 담는다.
7. queue가 빌 때까지 이를 반복하고
8. 마지막에 모든 프로젝트 check되면 list 반환함.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct queue {
	int items[10];
	int front;
	int rear;
}Q;

typedef struct node {
	int vertex;
	struct node *next;
}Node;

struct Graph
{
	int numVertices;
	struct node** adjLists;
	int* visited;
};

Node* createNode(int);
Q *createQueue();
void enqueue(Q *q,int);
int dequeue(Q *q);
void printQueue(Q *q);
int isEmpty(Q *q);

int main() {
	printf("프로젝트 : a,b,c,d,e,f\n");
	printf("종속관계 : (a,d), (f,b),(b,d),(f,a),(d,c)");
	char project[7] = {'a','b','c','d','e','f'};
}

Q *createQueue() {
	Q* q = (Q*)malloc(sizeof(Q));
	q->front = -1;
	q->rear = -1;
	return q;
}

void enqueue(Q *q, int value) {
	if (q->rear == SIZE - 1)
		printf("\nQueue is Full!!");
	else {
		if (q->front == -1)
			q->front = 0;
		q->rear++;
		q->items[q->rear] = value;
	}
}
int dequeue(Q *q) {
	int item;
	if (isEmpty(q)) {
		printf("Queue is empty");
		item = -1;
	}
	else {
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear) {
			printf("Resetting queue");
			q->front = q->rear = -1;
		}
	}
	return item;
}
void printQueue(Q *q) {
	int i = q->front;
	if (isEmpty(q)) {
		printf("Queue is empty");
	}
	else {
		printf("\nQueue contains \n");
		for (i = q->front; i < q->rear + 1; i++) {
			printf("%d ", q->items[i]);
		}
	}
}
int isEmpty(Q *q) {

}

Node* createNode(int) {

}