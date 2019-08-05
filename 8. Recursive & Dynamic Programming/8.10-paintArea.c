#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
8.10 ���� ĥ�ϱ�
�̹��� ���� ���α׷����� ���� ���̴� '���� ĥ�ϱ�' �Լ��� �����϶�.
���� ĥ�ϱ� �Լ��� ȭ��� �� ȭ����� �� ����, �׸��� ���ο� ������ �־����� ��
�־��� ������ ���� ���� �ֺ� ������ ���ο� �������� �ٽ� ��ĥ�Ѵ�.

���� : 
nxn �迭�� random�� ������ �Է��� ��,
���� ���ڸ� ���� �迭�� ���� ���ο� ���ڷ� �Է��Ͽ� �ٲ۴�.

���� ���� ���� ������ ã�� �˰��� : 
��� �Լ��� ���� �ֺ� 4���� cell�� Ȯ���Ѵ�. (�� �Ʒ� �� ��)
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
	//printf("arr[%d][%d] = %d�� color %d�� �ٲ�.\n",x,y,prev,color);
	paint(arr, arr_n, x - 1, y, color, prev);//��
	paint(arr, arr_n, x + 1, y , color, prev);//��
	paint(arr, arr_n, x , y + 1, color, prev);//��
	paint(arr, arr_n, x , y - 1, color, prev);//�Ʒ�
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
	printf("�迭�� ũ�⸦ �Է��ϼ��� : ");
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
	printf("���� ����\n");
	printArr(arr,arr_n);
	printf("���ο� ����(����)�� �Է��� ��ǥ�� ���� �Է��ϼ��� : ");
	scanf("%d %d %d",&x,&y,&color);
	paint(arr,arr_n,x,y,color,arr[x][y]);
	printArr(arr, arr_n);
}