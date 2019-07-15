/*
오름차순으로 정렬된 배열이 있다.
배열 안에는 중복되지 않은 정수값만 존재한다.
높이가 최소가 되는 이진 탐색 트리를 만드는 알고리즘.
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
	printf("오나?\n");
	Tree *newTree = (Tree*)malloc(sizeof(Tree));
	if (tree == NULL) {
		newTree->data = x;
		newTree->leftChild = NULL;
		newTree->rightChild = NULL;
		return newTree;
	}
	else if (x < tree->data) tree->leftChild = insertTree(tree->leftChild, x);
	else if (x > tree->data) tree->rightChild = insertTree(tree->rightChild, x);
	else printf("\n 이미 같은키가 있습니다! \n");

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