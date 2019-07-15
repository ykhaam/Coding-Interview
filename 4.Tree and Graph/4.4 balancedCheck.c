/*
4.4 균형 확인
이진 트리가 균형잡혀있는지 확인하는 함수 작성.
균형 잡힌 트리 : 모든 노드에 대해서 왼쪽 부분 트리의 높이와
오른쪽 부분 트리의 높이의 차이가 최대 하나인 트리를 의미함.
*/

/*
왼쪽과 오른쪽 부분트리 계속해서 재귀적으로 height 측정함.
1보다 적게 차이나면 true 반환 아니면 false반환
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

/* balaced tree면 True 아니면 False 반환하는 함수 
height에는 높이 저장 */
bool isBalanced(Node *root, int* height)
{
	int left_h = 0, right_h = 0; //각 부분트리의 높이 변수
	int left = 0, right = 0; //balanced인지 체크

	if (root == NULL){
		*height = 0;
		return True;
	}
	/* 재귀적으로 높이 저장 */
	left = isBalanced(root->leftChild, &left_h);
	right = isBalanced(root->rightChild, &right_h);
	/* 현재 노드의 높이 = 왼쪽 부분트리와 오른쪽 부분트리 중 더 큰 것 +1 */
	*height = (left_h > right_h ? left_h : right_h) + 1;

	/* 2보다 더 큰 차이가 날 때는 return false */
	if ((left_h - right_h >= 2) || (right_h - left_h >= 2))
		return False;

	/* 현재 노드와 모든 부분트리가 다 balanced하다면 return true */
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