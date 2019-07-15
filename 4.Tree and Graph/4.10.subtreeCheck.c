/*
4.10 ���� Ʈ�� Ȯ��
�� ���� Ŀ�ٶ� ���� Ʈ�� T1�� T2�� �ִٰ� ����.
T1�� T2���� �ξ� ũ�ٰ� ���� ��, T2�� T1�� ����Ʈ������ �Ǻ��ϴ� �˰����� �����. 
T1 �ȿ� �ִ� ��� n�� ���� Ʈ���� T2�� �����ϸ�, T2�� T1�� ���� Ʈ����. 
�ٽ� ����, T1���� ��Ʈ n�� �Ʒ����� ���� ���� �� �� ����� T2�� �����ؾ� �Ѵ�.
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

/*root1�� root2�� ��Ʈ�� ������ Ʈ������ ������ Ȯ��*/
Bool isSame(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL) //�� �� NULL�̸� ����.
		return true;

	if (root1 == NULL || root2 == NULL)
		return false;

	/* �� ��Ʈ�� �����Ͱ� ������ Ȯ��. �κ����� ������ Ȯ��. */
	return (root1->data == root2->data   &&
		isSame(root1->leftChild, root2->leftChild) &&
		isSame(root1->rightChild, root2->rightChild));
}


/*S�� T�� �κ�Ʈ���� true,�ƴϸ� false ��ȯ*/
Bool isSubtree(Node*T, Node *S)
{
	if (S == NULL) //�κ�Ʈ���̹Ƿ�
		return true;
	if (T == NULL)
		return false;

	/* ���� ���� ��Ʈ �� */
	if (isSame(T, S))
		return true;

	/* ���� ���� ��带 ��Ʈ���� Ʈ���� ����������
	���� ������ �κ�Ʈ���� ���� �ϳ��ϳ� ���� */
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
		printf("Tree 2�� Tree 1�� �κ�Ʈ���̴�.\n");
	else
		printf("Tree 2�� Tree 1�� �κ�Ʈ���� �ƴϴ�.\n");

	return 0;
}