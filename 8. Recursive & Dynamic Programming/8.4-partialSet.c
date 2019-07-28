/*
8.4 �κ� ����
� ������ �κ� ������ ���� ��ȯ�ϴ� �޼��带 �ۼ��϶�.
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
	printf("������ ũ�⸦ �Է��Ͻÿ� : ");
	scanf("%d",&n);
	s = (SUBSET*)malloc(sizeof(SUBSET)*n);
	printf("������ �Է��Ͻÿ� : ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i].value);
		s[i].flag = 0;
	}
	printf("�κ������� ������ ����.\n");
	findSubset(s,n,0);
}