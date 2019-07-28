#define _CRT_SECURE_NO_WARNINGS
/*
8.2 grid상의 로봇
행의 개수는 r, 열의 개수는 c인 격자판의 왼쪽 꼭짓점에 로봇이 놓여 있다.
이 로봇은 오른쪽 아니면 아래 쪽으로만 이동할 수 있다.
어떤 cell은 '금지 구역'으로 지정되어 있어서 로봇이 접근할 수 없다.
왼쪽 상단 꼭짓점에서 오른쪽 하단으로의 경로를 찾는 알고리즘을 설계하라.
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

	printf("행의 개수와 열의 개수를 입력하시오 : ");
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

		printf("접근 금지 cell의 행과 열을 입력하시오 (-1,-1) to quit ");
		scanf("%d %d", &ban_c, &ban_r);
		arr[ban_c][ban_r] = -1;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}

	printf("왼쪽 상단 꼭짓점에서 오른쪽 하단으로의 경로는 ");
	printf("%d\n",findPath(arr,r-1,c-1));
}