#define _CRT_SECURE_NO_WARNINGS
#define size 100

#include <stdio.h>
#include <string.h>

/*
8.7 �ߺ� ���� ����
���ڿ��� �־����� �� ��� ����� ������ ����ϴ� �޼��带 �ۼ��϶�.
��, ���ڴ� �ߺ��Ǿ� ��Ÿ�� �� ����.

input : abc
output : abc acb bac bca cab cba
(3C2)

*/

void swap(char *x, char *y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permutation(char *s, int l, int r) {
	printf("permutation(%s,%d,%d)\n",s,l,r);
	if (l == r) //���Ұ� 1���� �� ������
		printf("%s\n", s);
	else {
		for (int i = l; i <= r; i++) {
			swap((s + l), (s + i));
			permutation(s, l + 1, r);
			swap((s + l), (s + i)); //�ٽ� ������� ��������
		}
	}
}

int main() {
	char a[size];
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", &a);
	int n = strlen(a); //���� �޾ƿ�.
	permutation(a, 0, n - 1);
}