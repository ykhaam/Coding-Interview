#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
5.3 ��Ʈ ������
� ������ �־����� �� �������� �� ������ ��Ʈ �ϳ���
0���� 1�� �ٲ� �� �ִ�.
�̶� 1�� �������� ���� �� �ִ� ���� �� ���̸� ���ϴ� �ڵ带
�ۼ��Ͻÿ�.

input  1775(11011101111)
output 8
*/

/*
���� ���� ��Ʈ�� 1�̸� ���� ���̰� ���� now���̿� ����� ���̰�,
���� ���� ��Ʈ�� 0�̸� ���� ������ �� �����Ƿ� ���� ���̸� 0���� ������.
*/

int flipBit(int num);

int main() {
	int num;
	printf("���� �Է� : ");
	scanf("%d",&num);
	printf("%d\n",flipBit(num));
}

int flipBit(int num) {
	int now = 0,prev = 0,max = 0;

	if (~num == 0) //���� ���� 1�̸� ������ ����+1
		return 8 * sizeof(int);
	while (num != 0) {
		printf("now : %d, prev : %d, max : %d, num :%d\n",now,prev,max,num);
		if ((num & 1) == 1) //���� ��Ʈ�� 1�̸� ���� ����
			now++;
		else if ((num & 1) == 0)// ���� ��Ʈ�� 0�̸� ���� ��Ʈ üũ��.
		{
			// ���� ���� ��Ʈ�� 0�̸� prev=0, �ƴϸ� prev�� now�� ����.
			prev = (num & 2) == 0 ? 0 : now;
			// ���� ���ӵ� �ΰ��� ��Ʈ�� 0�̸� now�� 0���� ��.
			now = 0;
		}
		max = max(prev + now, max);
		num >>= 1;
	}
	return max+1;
}