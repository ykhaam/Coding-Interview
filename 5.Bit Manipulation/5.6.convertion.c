#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
5.6 변환
정수 a와 b를 2진수로 표현했을 때, a를 b로 바꾸기 위해 
뒤집어야하는 비트의 개수를 구하는 함수를 작성하라.

input  29, 15
output 2
*/

/*
1. a랑 b의 XOR구함
2. 1bit의 개수 구함
*/

int bitNum(int a,int b) {
	int mask = a^b;
	int count = 0;
	while (mask!=0) {
		count += mask & 1;
		mask >>= 1;
	}
	return count;
}

int main() {
	int a, b;
	int temp;
	printf("a와 b를 입력하시오. : ");
	scanf("%d %d",&a,&b);
	printf("%d\n", bitNum(a,b));
}