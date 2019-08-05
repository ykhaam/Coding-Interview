#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
8.11 ����
����(25c),����(10),����(5),���(1)�� �� ���� ������ ������ �־����� ��
n��Ʈ�� ǥ���ϴ� ��� ����� ���� ����ϴ� �ڵ带 �ۼ��϶�.
*/

int numberOfCoins(int* arr,int centVal,int coinIndex) {
	//solution ���� ����.
	if (centVal == 0) //soluion 1��
		return 1;
	if (centVal < 0) //solution 0��
		return 0;
	if (centVal >= 1 && coinIndex <= 0)
		//coin ���̻���� n�� 1���� ũ�� solution 0��
		return 0;
	return numberOfCoins(arr,centVal-arr[coinIndex-1],coinIndex) + 
		numberOfCoins(arr, centVal, coinIndex - 1);
	//�� coin�迭�� coin�� ������ ���� �ƴ� ��츦 ����.
}

int main() {
	int n;
	printf("n��Ʈ�� �Է� : ");
	scanf("%d",&n);
	int coin[] = {1,5,10,25};
	printf("%d\n",numberOfCoins(coin,n,4));
	return 0;
}