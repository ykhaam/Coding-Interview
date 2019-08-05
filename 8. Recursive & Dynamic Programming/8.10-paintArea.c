#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
8.10 영역 칠하기
이미지 편집 프로그램에서 흔히 쓰이는 '영역 칠하기' 함수를 구현하라.
영역 칠하기 함수는 화면과 그 화면상의 한 지점, 그리고 새로운 색상이 주어졌을 때
주어진 지점과 색이 같은 주변 영역을 새로운 색상으로 다시 색칠한다.

구현 : 
nxn 배열을 random한 난수를 입력한 후,
같은 숫자를 가진 배열의 수를 새로운 숫자로 입력하여 바꾼다.

같은 색을 가진 영역을 찾는 알고리즘 : 
재귀 함수를 통해 주변 4개의 cell을 확인한다. (위 아래 왼 오)
*/

int isRange(int x, int y, int n) {
	if (x > n || y > n || x < 0 || y < 0) {
		return FALSE;
	}
	else
		return TRUE;
}

void paint(int **arr, int arr_n, int x, int y, int color, int prev) {
	if (isRange(x, y, arr_n) == FALSE)
		return;
	if (arr[x][y] != prev)
		return;
	arr[x][y] = color;
	//printf("arr[%d][%d] = %d를 color %d로 바꿈.\n",x,y,prev,color);
	paint(arr, arr_n, x - 1, y, color, prev);//왼
	paint(arr, arr_n, x + 1, y , color, prev);//오
	paint(arr, arr_n, x , y + 1, color, prev);//위
	paint(arr, arr_n, x , y - 1, color, prev);//아래
}

void printArr(int **arr,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

int main() {
	int arr_n, x, y,color;
	srand(time(NULL));
	printf("배열의 크기를 입력하세요 : ");
	scanf("%d",&arr_n);
	getchar();
	int **arr = (int**)malloc(sizeof(int*)*arr_n);
	for (int i = 0; i < arr_n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*arr_n);
	}
	for (int i = 0; i < arr_n; i++) {
		for (int j = 0; j < arr_n; j++) {
			arr[i][j] = (rand() % 3) + 1;
		}
	}
	printf("원래 영역\n");
	printArr(arr,arr_n);
	printf("새로운 색상(숫자)을 입력할 좌표와 색을 입력하세요 : ");
	scanf("%d %d %d",&x,&y,&color);
	paint(arr,arr_n,x,y,color,arr[x][y]);
	printArr(arr, arr_n);
}