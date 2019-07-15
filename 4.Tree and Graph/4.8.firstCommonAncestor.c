#define _CRT_SECURE_NO_WARNINGS
/*
4.8 첫번째 공통 조상

이진 트리에서 노드 두 개가 주어졌을 때 이 노드의 첫번째
공통 조상을 찾는 알고리즘을 설계하고 그 코드를 작성하라.
자료구조 내에 추가로 노드를 저장해 두면 안된다.
반드시 이진 탐색 트리일 필요는 없다.

->해당 코드에서는 이진 탐색 트리 기준으로 구현.
*/


#include <stdio.h> 
#include <stdlib.h> 

typedef struct node
{
	int data;
	struct node *leftChild;
	struct node *rightChild;
}Node;

Node *commAncestor(Node* root, int n1, int n2)
{
	if (root == NULL) return NULL;

	/*root보다 n1,n2가 더 작으면 왼쪽 부분트리에 공통 조상 있음*/
	if (root->data > n1 && root->data > n2)
		return commAncestor(root->leftChild, n1, n2);
	/*root보다 n1,n2가 더 크면 오른쪽 부분트리에 공통 조상 있음*/
	if (root->data < n1 && root->data < n2)
		return commAncestor(root->rightChild, n1, n2);

	/*아니면 서로 겹치는 것은 root노드 뿐*/
	return root;
}

Node* newNode(int data) //for test
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = node->rightChild = NULL;
	return(node);
}

int main()
{
	Node *root = newNode(19);
	root->leftChild = newNode(8);
	root->rightChild = newNode(32);
	root->leftChild->leftChild = newNode(3);
	root->leftChild->rightChild = newNode(11);
	root->leftChild->rightChild->leftChild = newNode(10);
	root->leftChild->rightChild->rightChild = newNode(12);

	int n1,n2;
	printf("노드 두개 입력하시오 : ");
	scanf("%d %d", &n1, &n2);
	Node *t = commAncestor(root, n1, n2);
	printf("%d번 노드와 %d번 노드의 첫번째 공통 조상은 %d 이다.\n", n1, n2, t->data);
}