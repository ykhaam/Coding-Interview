/*
4.6 �ļ���
���� Ž�� Ʈ������ �־��� ����� ���� ��带 ã�� �˰���.
�� ��忡�� �θ� ��带 ����Ű�� ��ũ�� �����Ѵٰ� ����.
���� �ļ��ڸ� ���� ��.

���� : left tree->root->right tree
1. ���� ������ �κ�Ʈ���� ��尡 NULL�� �ƴϸ� �ļ��ڴ�
������ �κ�Ʈ���� ���� ���̴�.
2. ���� ������ �κ�Ʈ���� ��尡 NULL�̸� �ļ��ڴ�
�θ� ��� �� �ϳ��� ���̴�.
-> succ�����͸� �ΰ�, �θ��� leftChild��带 ���� ������ �Ž��� �ö�.
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
	/*1. ���� ������ �κ�Ʈ���� ��尡 NULL�� �ƴϸ� 
	�ļ��ڴ� ������ �κ�Ʈ���� ���� ��.*/
	if (node->rightChild != NULL)
		return minValue(node->rightChild);

	/*2. ���� ������ �κ�Ʈ���� ��尡 NULL�̸� �ļ��ڴ�
	�θ� ��� �� �ϳ��� ��.*/
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
	/* 1. tree�� ��������� ���� ���� */
	if (node == NULL)
		return(newNode(data));
	else
	{
		Node *temp;
		/* 2. ������� ������ ��������� ����Ž��Ʈ�� ����. */
		if (data <= node->data) //�� ���� �� ���� �κ� Ʈ��
		{
			temp = insert(node->leftChild, data);
			node->leftChild = temp;
			temp->succ = node;//�θ� Ʈ�� ����
		}
		else //ū �� ������ �κ� Ʈ��
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
	temp = root->leftChild->rightChild; //�־��� ���.
	succ = inOrderSuccessor(root, temp);
	if (succ != NULL)
		printf("%d ����� �ļ��ڴ� %d ����̴�.\n", temp->data, succ->data);
	else
		printf("�ļ��ڰ� �������� �ʴ´�. \n");
	printf("\n");
	return 0;
}