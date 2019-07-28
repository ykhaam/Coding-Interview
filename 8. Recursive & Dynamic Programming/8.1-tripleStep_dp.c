/*
8.1 tripple step
어떤 아이가 n개의 계단을 오른다.
한 번에 1계단 오르기도 하고, 2계단, 3계단 오르기도 한다.
계단을 오르는 방법이 몇 가지가 있는지 계산하는 메서드 구현하라.

in dynamic programming
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int triplestep(int );

int main() {
	srand(time(NULL));
	int random = (rand() % 10) + 1;
	printf("%d개의 계단을 오르는 방법은 %d 개이다.\n", random, triplestep(random));
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