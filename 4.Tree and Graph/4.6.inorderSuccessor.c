/*
4.6 후속자
이진 탐색 트리에서 주어진 노드의 다음 노드를 찾는 알고리즘.
각 노드에는 부모 노드를 가리키는 링크가 존재한다고 가정.
중위 후속자를 구할 것.

중위 : left tree->root->right tree
1. 만약 오른쪽 부분트리의 노드가 NULL이 아니면 후속자는
오른쪽 부분트리에 있을 것이다.
2. 만약 오른쪽 부분트리의 노드가 NULL이면 후속자는
부모 노드 중 하나일 것이다.
-> succ포인터를 두고, 부모의 leftChild노드를 만날 때까지 거슬러 올라감.
*/

#include <stdio.h> 
#include <stdlib.h> 

typedef struct node
{
	int data;
	struct node *leftChild;
	struct node *rightChild;
	struct node *succ; //parent pointer
}Node;

Node *minValue(Node* node);

Node *inOrderSuccessor(Node *root, Node *node)
{
	/*1. 만약 오른쪽 부분트리의 노드가 NULL이 아니면 
	후속자는 오른쪽 부분트리에 있을 것.*/
	if (node->rightChild != NULL)
		return minValue(node->rightChild);

	/*2. 만약 오른쪽 부분트리의 노드가 NULL이면 후속자는
	부모 노드 중 하나일 것.*/
	Node *nodeSucc= node->succ;
	while (nodeSucc != NULL && node == nodeSucc->rightChild)
	{
		node = nodeSucc;
		nodeSucc = nodeSucc->succ;
	}
	return nodeSucc;
}

/* Given a non-empty binary search tree, return the minimum data
value found in that tree. Note that the entire tree does not need
to be searched. */
Node * minValue(Node* node) {
	Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->leftChild != NULL) {
		current = current->leftChild;
	}
	return current;
}

Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->succ = NULL;
	return(node);
} //test

/*

*/
Node* insert(Node* node, int data)
{
	/* 1. tree가 비어있으면 새로 만듬 */
	if (node == NULL)
		return(newNode(data));
	else
	{
		Node *temp;
		/* 2. 비어있지 않으면 재귀적으로 이진탐색트리 만듬. */
		if (data <= node->data) //더 작은 것 왼쪽 부분 트리
		{
			temp = insert(node->leftChild, data);
			node->leftChild = temp;
			temp->succ = node;//부모 트리 저장
		}
		else //큰 것 오른쪽 부분 트리
		{
			temp = insert(node->rightChild, data);
			node->rightChild = temp;
			temp->succ = node;
		}
		return node;
	}
}

int main()
{
	Node* root = NULL, *temp, *succ;
	/*
			  20
		8	    	22
	4	  12     
	    10    14

	*/
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 14);
	temp = root->leftChild->rightChild; //주어진 노드.
	succ = inOrderSuccessor(root, temp);
	if (succ != NULL)
		printf("%d 노드의 후속자는 %d 노드이다.\n", temp->data, succ->data);
	else
		printf("후속자가 존재하지 않는다. \n");
	printf("\n");
	return 0;
}