#define _CRT_SECURE_NO_WARNINGS
/*
4.7 ���� ���ϱ�
������Ʈ�� ����Ʈ�� ������Ʈ�� ���� ���� ����
(��, ������Ʈ ���� ����Ʈ�� �־����� �� ������Ʈ �ֿ��� �ι�°
������Ʈ�� ù��° ������Ʈ�� ���ӵǾ� �ִٴ� ��)�� �־����� ��,
������Ʈ�� ������ ������ ������ ã�ƶ�.
��ȿ�� ������ �������� ������ ������ ��ȯ�Ѵ�.

input :  a,b,c,d,e,f
		(a,d), (f,b),(b,d),(f,a),(d,c)
output : f,e,a,b,d,c
*/

/*
1. �� ������Ʈ�� ���� ������Ʈ�� ������ �˾ƾ� ��.
2. �׷����� �ٲ㼭 �����غ���.
3. BFS�� ���� Ǭ��.
4. ���� ������Ʈ�� ���� ������Ʈ�� queue�� ��´�.
5. queue ���� ������Ʈ�� list�� �ְ� check�Ѵ�.
6. ���ӵǾ� �ִ� ������Ʈ�� ���� ������Ʈ ���� �ϳ��� ����.
���� ������Ʈ�� 0���� �Ǹ� �� queue�� ��´�.
7. queue�� �� ������ �̸� �ݺ��ϰ�
8. �������� ��� ������Ʈ check�Ǹ� list ��ȯ��.
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
	printf("������Ʈ : a,b,c,d,e,f\n");
	printf("���Ӱ��� : (a,d), (f,b),(b,d),(f,a),(d,c)");
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