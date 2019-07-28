/*
8.4 부분 집합
어떤 집합의 부분 집합을 전부 반환하는 메서드를 작성하라.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct subset {
	int value;
	int flag;
}SUBSET;

void findSubset(SUBSET *a,int n,int depth) {
	if (n == depth) {
		printf("{");
		for (int i = 0; i < n; i++) {
			if (a[i].flag == 1) 
				printf("%d ",a[i].value);
		}
		printf("}\n");
		return 0;
	}
	a[depth].flag = 1;
	findSubset(a, n, depth + 1);
	a[depth].flag = 0;
	findSubset(a,n,depth+1);
}

int main() {
	int n;
	SUBSET *s;
	printf("집합의 크기를 입력하시오 : ");
	scanf("%d",&n);
	s = (SUBSET*)malloc(sizeof(SUBSET)*n);
	printf("집합을 입력하시오 : ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i].value);
		s[i].flag = 0;
	}
	printf("부분집합은 다음과 같다.\n");
	findSubset(s,n,0);
}