/*
8.1 tripple step
� ���̰� n���� ����� ������. 
�� ���� 1��� �����⵵ �ϰ�, 2���, 3��� �����⵵ �Ѵ�. 
����� ������ ����� �� ������ �ִ��� ����ϴ� �޼��� �����϶�.

in recursive way
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int triplestep(int n);

int main() {
	srand(time(NULL));
	int random = (rand()%10)+1;
	printf("%d���� ����� ������ ����� %d ���̴�.\n",random,triplestep(random));
}

int triplestep(int n) {
	if (n == 0 || n == 1) //��� ��� 1���� -> 1����
		return 1;
	else if (n == 2) //����� 1��or2���� -> 2����
		return 2;
	else
		return triplestep(n-1)+triplestep(n-2)+triplestep(n-3);
}