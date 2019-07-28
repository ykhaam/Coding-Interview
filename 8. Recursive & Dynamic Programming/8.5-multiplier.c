#define _CRT_SECURE_NO_WARNINGS

/*
8.5 재귀 곱셈
*연산자를 사용하지 않고 양의 정수 두 개를 곱하는 재귀 함수를 작성하라.
덧셈, 뺄셈, 비트 시프팅 연산자를 사용할 수 있지만,
이들의 사용 횟수를 최소화해야 한다. 
*/

#include <stdio.h>

int multiply(int a,int b) {
	if (b == 1)
		return a;
	else
		return a+multiply(a,b-1);
}

int main() {
	int a, b,temp;
	printf("곱할 두 개의 양의 정수를 입력하시오 : ");
	scanf("%d %d",&a,&b);
	if (b > a) {
		temp = a;
		a = b;
		b = temp;
	}

	printf("답 : %d\n",multiply(a,b));
}