/*
4.3
이진 트리가 주어졌을 때 같은 깊이에 있는 노드를
연결리스트로 연결해주는 알고리즘을 설계하여라.
*/
/*
pre-order - 자식 노드보다 현재 노드를 먼저 읽음.
root를 먼저 방문함.
*/

#include <stdio.h> 
#include <stdlib.h> 

typedef struct node
{
	int data;
	struct node *leftChild;
	struct node *rightChild;
	struct node *next;
}NODE;


/*
루트 노드의 next 설정 후
다른 노드들도 재귀적으로 설정함.
*/
void rootMake(NODE *node);
void rootNext(NODE *root)
{
	root->next = NULL;
	rootMake(root);
}

/*root 노드의 자식들의 next들을 설정함*/
void rootMake(NODE *node)
{
	if (node==NULL)
		return;
	if (node->leftChild)
		node->leftChild->next = node->rightChild;
	if (node->rightChild)
		node->rightChild->next = (node->next) ? node->next->leftChild : NULL;
	//node->next가 존재한다면 node->next->left=node->next->left
	//아니라면 node->right->next에 NULL = 끝

	//재귀적으로 다른 노드들에도 적용.
	rootMake(node->leftChild);
	rootMake(node->rightChild);
}

NODE* newnode(int data)
{
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->data = data;
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->next = NULL;
	return(node);
}

int main()
{
	/* 트리 모양

	    10
	  /   \
     8     2
	/ \   /
   3   7 3 

	*/
	NODE *root = newnode(10);
	root->leftChild = newnode(8);
	root->rightChild = newnode(2);
	root->leftChild->leftChild = newnode(3);
	root->leftChild->rightChild = newnode(7);
	root->rightChild->leftChild = newnode(3);

	rootNext(root);
	
	printf("트리의 next pointer 리스트 : "
		"next pointer 없으면 -1을 출력한다. \n");
	printf("next pointer of %d is %d \n", root->data,
		root->next ? root->next->data : -1);
	printf("next pointer of %d is %d \n", root->leftChild->data,
		root->leftChild->next ? root->leftChild->next->data : -1);
	printf("next pointer of %d is %d \n", root->rightChild->data,
		root->rightChild->next ? root->rightChild->next->data : -1);
	printf("next pointer of %d is %d \n", root->leftChild->leftChild->data,
		root->leftChild->leftChild->next ? root->leftChild->leftChild->next->data : -1);
	printf("next pointer of %d is %d \n", root->leftChild->rightChild->data,
		root->leftChild->rightChild->next ? root->leftChild->rightChild->next->data : -1);
	printf("next pointer of %d is %d \n", root->rightChild->leftChild->data,
		root->rightChild->leftChild->next ? root->rightChild->leftChild->next->data : -1);
		
	return 0;
}