/*
4.5 BST ����
�־��� ���� Ʈ���� ���� Ž�� Ʈ������ Ȯ���ϴ� �Լ� �ۼ��϶�.
1. ������ ��尡 �ڽź��� �۾ƾ� ��.
2. �������� ��尡 �ڽź��� Ŀ�� ��.
3. ���ʰ� �������� �κ� Ʈ���� ���� Ž�� Ʈ������ �Ѵ�.
->��� ��� : �ּҰ��� �ִ밪�� �Ѱ��ָ鼭 ��ͷ� ȣ���ϴ� ��� ���.

���ʿ� �ִ� �κ� Ʈ���� Ž���� ���� �ִ밪�� �ڱ� �ڽ��� �ְ�(����)
�����ʿ� �ִ� �κ� Ʈ���� Ž���� ���� �ּҰ����� �ڽ��� ��.
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

/* �־��� Ʈ���� ����Ž��Ʈ���̸� True */

/* �־��� Ʈ���� ����Ž��Ʈ���̰� value�� ������ ������ True ��ȯ 
������ ���� ������ False ��ȯ */
Bool isBST(Node* node, int min, int max)
{
	if (node == NULL)
		return True;
	if (node->data < min || node->data > max)
		return False;
	return
		isBST(node->leftChild, min, node->data - 1) &&  isBST(node->rightChild, node->data + 1, max); 
	//���� �κ�Ʈ���� ������ �����ϸ� true ��ȯ.
}

Node* newNode(int data) //test�� ���
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
		printf("BST�� ����!\n");
	else
		printf("BST�� �ƴ�!\n");
}