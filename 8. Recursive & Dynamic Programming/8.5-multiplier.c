#define _CRT_SECURE_NO_WARNINGS

/*
8.5 ��� ����
*�����ڸ� ������� �ʰ� ���� ���� �� ���� ���ϴ� ��� �Լ��� �ۼ��϶�.
����, ����, ��Ʈ ������ �����ڸ� ����� �� ������,
�̵��� ��� Ƚ���� �ּ�ȭ�ؾ� �Ѵ�. 
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
	printf("���� �� ���� ���� ������ �Է��Ͻÿ� : ");
	scanf("%d %d",&a,&b);
	if (b > a) {
		temp = a;
		a = b;
		b = temp;
	}

	printf("�� : %d\n",multiply(a,b));
}