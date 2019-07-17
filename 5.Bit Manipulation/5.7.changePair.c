#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
5.7 쌍끼리 맞바꾸기
명령어를 가능한 한 적게 사용해서 주어진 정수의 짝수 번째 비트의 값과
홀수 번째 비트의 값을 바꾸는 프로그램을 작성하라.
예 : 0번째 비트와 1번째 비트를 바꾸고, 2번째 비트와 3번째 비트를 바꿈
*/
int changePair(int num) {
	int even = num & 0xAAAAAAAA; //1010 10...10
	int odd = num & 0x55555555; //0101 0101...01
	even >>= 1;
	odd <<= 1;
	return (even | odd);
}

int main() {
	int num;
	scanf("%d",&num);
	printf("%d\n", changePair(num));
}