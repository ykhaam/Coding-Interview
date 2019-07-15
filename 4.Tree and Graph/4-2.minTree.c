/*
������������ ���ĵ� �迭�� �ִ�.
�迭 �ȿ��� �ߺ����� ���� �������� �����Ѵ�.
���̰� �ּҰ� �Ǵ� ���� Ž�� Ʈ���� ����� �˰���.
*/
#define MAX 20
#define ARR_LEN 10

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
	struct tree *leftChild;
	struct tree *rightChild;
}Tree;

Tree *createTree(int arr[], int start, int end);
Tree *insertTree(Tree *tree, int data);
void printTree(Tree* tree);

int main() {
	int num[MAX] = { 1,3,4,5,7,9,10,11 };
	printTree(createTree(num, 0, ARR_LEN));
}

Tree *insertTree(Tree *tree,int x) {
	printf("����?\n");
	Tree *newTree = (Tree*)malloc(sizeof(Tree));
	if (tree == NULL) {
		newTree->data = x;
		newTree->leftChild = NULL;
		newTree->rightChild = NULL;
		return newTree;
	}
	else if (x < tree->data) tree->leftChild = insertTree(tree->leftChild, x);
	else if (x > tree->data) tree->rightChild = insertTree(tree->rightChild, x);
	else printf("\n �̹� ����Ű�� �ֽ��ϴ�! \n");

	return tree;
}

Tree *createTree(int arr[], int start, int end) {
	if (start > end) return NULL;
	int mid = (start + end+1) / 2;
	Tree *newTree=(Tree*)malloc(sizeof(Tree));
	printf("Array %d \/ Start : %d, End : %d\n",arr[mid],start,end);
	newTree=insertTree(newTree,arr[mid]);
	newTree->leftChild = createTree(arr, start, mid - 1);
	newTree->rightChild = createTree(arr, mid + 1, end);
	return newTree;
}

void printTree(Tree* tree) { 
	printf("printTree start\n");

	if (tree = NULL)
		return;
	printf("%d : ", tree->data);
	if (tree->leftChild != NULL)
		printf("Left %d ",tree->leftChild->data);
	if (tree->rightChild != NULL)
		printf("Right %d ", tree->rightChild->data);
	printf("\n");
	if(tree->leftChild!=NULL)
		printTree(tree->leftChild);
	if(tree->rightChild!=NULL)
		printTree(tree->rightChild);
}