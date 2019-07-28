#define _CRT_SECURE_NO_WARNINGS
/*
8.3 magic index
배열A[0 ... n-1]에서 A[i]=i인 인덱스를 마술 인덱스라고 정의한다.
정렬된 상태의 배열이 주어졌을 때, 마술 인덱스가 존재한다면 그 값을 갖는
메서드를 정의하여라. 배열 안에 중복된 값은 없다.
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
	printf("배열의 크기 : ");
	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*n);
	printf("정렬된 배열을 입력하세요\n");
	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	printf("magic index : %d\n",magicIndex(arr,0,n-1));
}