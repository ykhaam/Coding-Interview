#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
8.11 코인
쿼터(25c),다임(10),니켈(5),페니(1)의 네 가지 동전이 무한히 주어졌을 때
n센트를 표현하는 모든 방법의 수를 계산하는 코드를 작성하라.
*/

int numberOfCoins(int* arr,int centVal,int coinIndex) {
	//solution 개수 세기.
	if (centVal == 0) //soluion 1개
		return 1;
	if (centVal < 0) //solution 0개
		return 0;
	if (centVal >= 1 && coinIndex <= 0)
		//coin 더이상없고 n이 1보다 크면 solution 0개
		return 0;
	return numberOfCoins(arr,centVal-arr[coinIndex-1],coinIndex) + 
		numberOfCoins(arr, centVal, coinIndex - 1);
	//각 coin배열의 coin을 포함한 경우와 아닌 경우를 더함.
}

int main() {
	int n;
	printf("n센트를 입력 : ");
	scanf("%d",&n);
	int coin[] = {1,5,10,25};
	printf("%d\n",numberOfCoins(coin,n,4));
	return 0;
}