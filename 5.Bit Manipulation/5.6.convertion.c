#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
5.6 ��ȯ
���� a�� b�� 2������ ǥ������ ��, a�� b�� �ٲٱ� ���� 
��������ϴ� ��Ʈ�� ������ ���ϴ� �Լ��� �ۼ��϶�.

input  29, 15
output 2
*/

/*
1. a�� b�� XOR����
2. 1bit�� ���� ����
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
	printf("a�� b�� �Է��Ͻÿ�. : ");
	scanf("%d %d",&a,&b);
	printf("%d\n", bitNum(a,b));
}