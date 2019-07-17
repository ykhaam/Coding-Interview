#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
/*
5.4 다음 숫자
양의 정수가 하나 주어졌다. 이 숫자를 2진수로 표기했을 때 1비트의
개수가 같은 숫자 중에서 가장 작은 숫와 가장 큰 수를 구하라.
*/

int countOnes(int num) {
	int count = 0;
	while (num != 0) {
		if ((num & 1) == 1)
			count++;
		num >>= 1;
	}
	return count;
}

void printNum(int n) {
	int count = countOnes(n); //1의 개수
	printf("count : %d\n",count);
	int num = 0;
	int f = 1;
	for (int i = 0; i < count; i++) {
		num += f;
		f <<= 1;
	}
	int large = num << 1;
	printf("Closest Smaller = %d\n",num);
	printf("Closest larger = %d\n", large);
}

int main() {
	int num;
	printf("양의 정수 입력하시오 : ");
	scanf("%d",&num);
	printNum(num);
}