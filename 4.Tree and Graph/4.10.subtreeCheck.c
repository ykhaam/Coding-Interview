/*
4.10 하위 트리 확인
두 개의 커다란 이진 트리 T1과 T2가 있다고 하자.
T1이 T2보다 훨씬 크다고 했을 때, T2가 T1의 하위트리인지 판별하는 알고리즘을 만들라. 
T1 안에 있는 노드 n의 하위 트리가 T2와 동일하면, T2는 T1의 하위 트리다. 
다시 말해, T1에서 노트 n의 아래쪽을 끊어 냈을 때 그 결과가 T2와 동일해야 한다.
*/

#include <stdio.h> 
#include <stdlib.h> 

typedef int Bool;
#define true 1
#define false 0

typedef struct node
{
	int data;
	struct node* leftChild;
	struct node* rightChild;
}Node;

/*root1과 root2를 루트로 가지는 트리들이 같은지 확인*/
Bool isSame(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL) //둘 다 NULL이면 같음.
		return true;

	if (root1 == NULL || root2 == NULL)
		return false;

	/* 두 루트의 데이터가 같은지 확인. 부분집합 같은지 확인. */
	return (root1->data == root2->data   &&
		isSame(root1->leftChild, root2->leftChild) &&
		isSame(root1->rightChild, root2->rightChild));
}


/*S가 T의 부분트리면 true,아니면 false 반환*/
Bool isSubtree(Node*T, Node *S)
{
	if (S == NULL) //부분트리이므로
		return true;
	if (T == NULL)
		return false;

	/* 현재 노드와 루트 비교 */
	if (isSame(T, S))
		return true;

	/* 만약 현재 노드를 루트로한 트리가 같지않으면
	왼쪽 오른쪽 부분트리를 통해 하나하나 비교함 */
	return isSubtree(T->leftChild, S) ||
		isSubtree(T->rightChild, S);
}

Node *newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = NULL;
	node->rightChild = NULL;
	return node;
}


int main()
{
	// TREE 1 
	/* 
	   26
	  /    \
	 10      3
	/    \     \
   4      6      3
	 \
	  30

	*/
	Node *T = newNode(26);
	T->rightChild = newNode(3);
	T->rightChild->rightChild = newNode(3);
	T->leftChild = newNode(10);
	T->leftChild->leftChild = newNode(4);
	T->leftChild->leftChild->rightChild = newNode(30);
	T->leftChild->rightChild = newNode(6);

	// TREE 2 
	/* 
	  10
	/    \
	4      6
	 \
	  30

	*/
	Node *S = newNode(10);
	S->rightChild = newNode(6);
	S->leftChild = newNode(4);
	S->leftChild->rightChild = newNode(30);

	if (isSubtree(T, S))
		printf("Tree 2는 Tree 1의 부분트리이다.\n");
	else
		printf("Tree 2는 Tree 1의 부분트리가 아니다.\n");

	return 0;
}