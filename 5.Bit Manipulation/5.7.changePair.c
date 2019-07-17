#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
5.7 �ֳ��� �¹ٲٱ�
��ɾ ������ �� ���� ����ؼ� �־��� ������ ¦�� ��° ��Ʈ�� ����
Ȧ�� ��° ��Ʈ�� ���� �ٲٴ� ���α׷��� �ۼ��϶�.
�� : 0��° ��Ʈ�� 1��° ��Ʈ�� �ٲٰ�, 2��° ��Ʈ�� 3��° ��Ʈ�� �ٲ�
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