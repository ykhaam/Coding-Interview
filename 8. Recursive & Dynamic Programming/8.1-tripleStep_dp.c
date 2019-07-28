/*
8.1 tripple step
� ���̰� n���� ����� ������.
�� ���� 1��� �����⵵ �ϰ�, 2���, 3��� �����⵵ �Ѵ�.
����� ������ ����� �� ������ �ִ��� ����ϴ� �޼��� �����϶�.

in dynamic programming
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int triplestep(int );

int main() {
	srand(time(NULL));
	int random = (rand() % 10) + 1;
	printf("%d���� ����� ������ ����� %d ���̴�.\n", random, triplestep(random));
}

int triplestep(int n) {
	int dp[10];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}