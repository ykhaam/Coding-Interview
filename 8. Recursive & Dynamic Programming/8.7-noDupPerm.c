#define _CRT_SECURE_NO_WARNINGS
#define size 100

#include <stdio.h>
#include <string.h>

/*
8.7 중복 없는 순열
문자열이 주어졌을 때 모든 경우의 순열을 계산하는 메서드를 작성하라.
단, 문자는 중복되어 나타날 수 없다.

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
	if (l == r) //원소가 1개가 될 때까지
		printf("%s\n", s);
	else {
		for (int i = l; i <= r; i++) {
			swap((s + l), (s + i));
			permutation(s, l + 1, r);
			swap((s + l), (s + i)); //다시 원래대로 돌려놓음
		}
	}
}

int main() {
	char a[size];
	printf("문자열을 입력하세요 : ");
	scanf("%s", &a);
	int n = strlen(a); //길이 받아옴.
	permutation(a, 0, n - 1);
}