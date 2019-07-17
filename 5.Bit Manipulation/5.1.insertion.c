#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_SIZE 33

/*
�� ���� 32��Ʈ �� n�� m�� �־�����
��Ʈ ��ġ i�� j�� �־����� �� m�� n�� �����ϴ� �޼��� ����
m�� n�� j��° ��Ʈ���� �����Ͽ� i��° ��Ʈ���� ������.
j��° ��Ʈ���� i��° ��Ʈ�������� m�� ��� ����� ������ �ִٰ� ������.
�ٽ� ����, m=10011�̶�� j�� i ���̿� ��� �ټ���Ʈ�� �ִٰ� ������.
j=3�̰� i=2�� ���ó�� m�� ������ �� ���� ���� ������� ����.
-input n=10000000000, m=10011, i=2 j=6
output n=10001001100 
*/
int deleteNum(int n, int m, int i, int j);
int insertNum(int n, int m, int i, int j);

int main(void) {
	// your code goes here
	int n = 1024;
	int m = 19;
	int i = 2, j = 6;
	int ans = insertNum(n, m, i, j);
	printf("%d\n", ans);
}


//clear the bits.
int deleteNum(int n, int m, int i, int j) {
	int allOne = ~0; //111111...111
	int left = allOne << (j + 1); //11..110000000
	int right = ~(allOne << i);//000...0011
	int answer = left | right;//11...110000011
	return n&answer;
}

int insertNum(int n, int m, int i, int j) {
	int num = deleteNum(n, m, i, j);
	int m_shift = m << i;
	return num | m_shift;
}
/*
1. n�� i~j��° �����.
10000000000��
11110000011�� &����
2. m�� i��ŭ �������� shift�� �Ͱ� or����.
*/