/*
4.3
���� Ʈ���� �־����� �� ���� ���̿� �ִ� ��带
���Ḯ��Ʈ�� �������ִ� �˰����� �����Ͽ���.
*/
/*
pre-order - �ڽ� ��庸�� ���� ��带 ���� ����.
root�� ���� �湮��.
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
��Ʈ ����� next ���� ��
�ٸ� ���鵵 ��������� ������.
*/
void rootMake(NODE *node);
void rootNext(NODE *root)
{
	root->next = NULL;
	rootMake(root);
}

/*root ����� �ڽĵ��� next���� ������*/
void rootMake(NODE *node)
{
	if (node==NULL)
		return;
	if (node->leftChild)
		node->leftChild->next = node->rightChild;
	if (node->rightChild)
		node->rightChild->next = (node->next) ? node->next->leftChild : NULL;
	//node->next�� �����Ѵٸ� node->next->left=node->next->left
	//�ƴ϶�� node->right->next�� NULL = ��

	//��������� �ٸ� ���鿡�� ����.
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
	/* Ʈ�� ���

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
	
	printf("Ʈ���� next pointer ����Ʈ : "
		"next pointer ������ -1�� ����Ѵ�. \n");
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