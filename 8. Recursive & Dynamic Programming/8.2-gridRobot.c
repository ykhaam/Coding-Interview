#define _CRT_SECURE_NO_WARNINGS
/*
8.2 grid���� �κ�
���� ������ r, ���� ������ c�� �������� ���� �������� �κ��� ���� �ִ�.
�� �κ��� ������ �ƴϸ� �Ʒ� �����θ� �̵��� �� �ִ�.
� cell�� '���� ����'���� �����Ǿ� �־ �κ��� ������ �� ����.
���� ��� ���������� ������ �ϴ������� ��θ� ã�� �˰����� �����϶�.
*/

#include <stdio.h>
#include <stdlib.h>

int row_f,col_f;

int findPath(int **arr, int r, int c) {
	if (r == row_f || c == col_f || r < 0 || c < 0 || arr[r][c] < 0)
		return 0;
	if (r == 0 && c == 0) return 1;
	return findPath(arr,r-1,c)+findPath(arr,r,c-1);
}

int main() {
	int r, c;
	int temp = 0;
	int ban_r, ban_c;
	int **arr;

	printf("���� ������ ���� ������ �Է��Ͻÿ� : ");
	scanf("%d %d",&r,&c);
	
	row_f = r;
	col_f = c;

	arr = (int**)malloc(sizeof(int*)*r);
	for (int i = 0; i < c; i++) {
		arr[i] = (int*)malloc(sizeof(int)*c);
	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			arr[i][j] = 0;

		printf("���� ���� cell�� ��� ���� �Է��Ͻÿ� (-1,-1) to quit ");
		scanf("%d %d", &ban_c, &ban_r);
		arr[ban_c][ban_r] = -1;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}

	printf("���� ��� ���������� ������ �ϴ������� ��δ� ");
	printf("%d\n",findPath(arr,r-1,c-1));
}