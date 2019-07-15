/*
4.5 BST 검증
주어진 이진 트리가 이진 탐색 트리인지 확인하는 함수 작성하라.
1. 왼쪽의 노드가 자신보다 작아야 함.
2. 오른쪽의 노드가 자신보다 커야 함.
3. 왼쪽과 오른쪽의 부분 트리도 이진 탐색 트리여야 한다.
->재귀 사용 : 최소값과 최대값을 넘겨주면서 재귀로 호출하는 방법 사용.

왼쪽에 있는 부분 트리를 탐색할 때는 최대값을 자기 자신을 주고(기준)
오른쪽에 있는 부분 트리를 탐색할 때는 최소값으로 자신을 줌.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

#define True 1
#define False 0
#define Bool int

typedef struct node
{
	int data;
	struct node* leftChild;
	struct node* rightChild;
}Node;

int isBST(Node* node, int min, int max);

/* 주어진 트리가 이진탐색트리이면 True */

/* 주어진 트리가 이진탐색트리이고 value의 범위가 맞으면 True 반환 
범위에 맞지 않으면 False 반환 */
Bool isBST(Node* node, int min, int max)
{
	if (node == NULL)
		return True;
	if (node->data < min || node->data > max)
		return False;
	return
		isBST(node->leftChild, min, node->data - 1) &&  isBST(node->rightChild, node->data + 1, max); 
	//만약 부분트리도 조건을 만족하면 true 반환.
}

Node* newNode(int data) //test용 노드
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = NULL;
	node->rightChild = NULL;
	return(node);
}

int main()
{
	/*
		4
	  /   \
	 2     5
	/ \
   1   7

	*/
	Node *root = newNode(4);
	root->leftChild = newNode(2);
	root->rightChild = newNode(5);
	root->leftChild->leftChild = newNode(1);
	root->leftChild->rightChild = newNode(7);

	if (isBST(root, INT_MIN, INT_MAX))
		printf("BST가 맞음!\n");
	else
		printf("BST가 아님!\n");
}