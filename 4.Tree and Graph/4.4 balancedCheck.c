/*
4.4 ���� Ȯ��
���� Ʈ���� ���������ִ��� Ȯ���ϴ� �Լ� �ۼ�.
���� ���� Ʈ�� : ��� ��忡 ���ؼ� ���� �κ� Ʈ���� ���̿�
������ �κ� Ʈ���� ������ ���̰� �ִ� �ϳ��� Ʈ���� �ǹ���.
*/

/*
���ʰ� ������ �κ�Ʈ�� ����ؼ� ��������� height ������.
1���� ���� ���̳��� true ��ȯ �ƴϸ� false��ȯ
*/

#include<stdio.h> 
#include<stdlib.h> 
#define bool int 
#define True 1
#define False 0

typedef struct node
{
	int data;
	struct node* leftChild;
	struct node* rightChild;
}Node;

/* balaced tree�� True �ƴϸ� False ��ȯ�ϴ� �Լ� 
height���� ���� ���� */
bool isBalanced(Node *root, int* height)
{
	int left_h = 0, right_h = 0; //�� �κ�Ʈ���� ���� ����
	int left = 0, right = 0; //balanced���� üũ

	if (root == NULL){
		*height = 0;
		return True;
	}
	/* ��������� ���� ���� */
	left = isBalanced(root->leftChild, &left_h);
	right = isBalanced(root->rightChild, &right_h);
	/* ���� ����� ���� = ���� �κ�Ʈ���� ������ �κ�Ʈ�� �� �� ū �� +1 */
	*height = (left_h > right_h ? left_h : right_h) + 1;

	/* 2���� �� ū ���̰� �� ���� return false */
	if ((left_h - right_h >= 2) || (right_h - left_h >= 2))
		return False;

	/* ���� ���� ��� �κ�Ʈ���� �� balanced�ϴٸ� return true */
	else return left&&right;
}

Node* newNode(int data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = NULL;
	node->rightChild = NULL;
	return(node);
}

int main()
{
	int height = 0;

	/* 
	     1
	  /     \
	 2       3
 	/  \    /
   4    5  6
  /
 7

	*/
	Node *root = newNode(1);
	root->leftChild = newNode(2);
	root->rightChild = newNode(3);
	root->leftChild->leftChild = newNode(4);
	root->leftChild->rightChild = newNode(5);
	root->rightChild->leftChild = newNode(6);
	root->leftChild->leftChild->leftChild = newNode(7);

	if (isBalanced(root, &height))
		printf("Tree is balanced\n");
	else
		printf("Tree is not balanced\n");
	return 0;
}