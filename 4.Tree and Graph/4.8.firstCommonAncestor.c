#define _CRT_SECURE_NO_WARNINGS
/*
4.8 ù��° ���� ����

���� Ʈ������ ��� �� ���� �־����� �� �� ����� ù��°
���� ������ ã�� �˰����� �����ϰ� �� �ڵ带 �ۼ��϶�.
�ڷᱸ�� ���� �߰��� ��带 ������ �θ� �ȵȴ�.
�ݵ�� ���� Ž�� Ʈ���� �ʿ�� ����.

->�ش� �ڵ忡���� ���� Ž�� Ʈ�� �������� ����.
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

	/*root���� n1,n2�� �� ������ ���� �κ�Ʈ���� ���� ���� ����*/
	if (root->data > n1 && root->data > n2)
		return commAncestor(root->leftChild, n1, n2);
	/*root���� n1,n2�� �� ũ�� ������ �κ�Ʈ���� ���� ���� ����*/
	if (root->data < n1 && root->data < n2)
		return commAncestor(root->rightChild, n1, n2);

	/*�ƴϸ� ���� ��ġ�� ���� root��� ��*/
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
	printf("��� �ΰ� �Է��Ͻÿ� : ");
	scanf("%d %d", &n1, &n2);
	Node *t = commAncestor(root, n1, n2);
	printf("%d�� ���� %d�� ����� ù��° ���� ������ %d �̴�.\n", n1, n2, t->data);
}