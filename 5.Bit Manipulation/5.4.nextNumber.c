#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
/*
5.4 ���� ����
���� ������ �ϳ� �־�����. �� ���ڸ� 2������ ǥ������ �� 1��Ʈ��
������ ���� ���� �߿��� ���� ���� ���� ���� ū ���� ���϶�.
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
	int count = countOnes(n); //1�� ����
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
	printf("���� ���� �Է��Ͻÿ� : ");
	scanf("%d",&num);
	printNum(num);
}