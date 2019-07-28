#define _CRT_SECURE_NO_WARNINGS
/*
8.3 magic index
�迭A[0 ... n-1]���� A[i]=i�� �ε����� ���� �ε������ �����Ѵ�.
���ĵ� ������ �迭�� �־����� ��, ���� �ε����� �����Ѵٸ� �� ���� ����
�޼��带 �����Ͽ���. �迭 �ȿ� �ߺ��� ���� ����.
*/

#include <stdio.h>
#include <stdlib.h>

int magicIndex(int a[],int l, int r) {
	int mid = (l + r) / 2;
	if (mid > a[mid])
		magicIndex(a, mid + 1, r);
	else if (mid == a[mid]) return mid;
	else
		magicIndex(a,l,mid-1);
}

int main() {
	int *arr;
	int n;
	printf("�迭�� ũ�� : ");
	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*n);
	printf("���ĵ� �迭�� �Է��ϼ���\n");
	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	printf("magic index : %d\n",magicIndex(arr,0,n-1));
}