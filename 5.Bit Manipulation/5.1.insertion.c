#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_SIZE 33

/*
두 개의 32비트 수 n과 m이 주어지고
비트 위치 i와 j가 주어졌을 때 m을 n에 삽입하는 메서드 구현
m은 n의 j번째 비트에서 시작하여 i번째 비트에서 끝난다.
j번째 비트에서 i번째 비트까지에는 m을 담기 충분한 공간이 있다고 가정함.
다시 말해, m=10011이라면 j와 i 사이에 적어도 다섯비트가 있다고 가정함.
j=3이고 i=2인 경우처럼 m을 삽입할 수 없는 경우는 고려하지 않음.
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
1. n의 i~j번째 지운다.
10000000000과
11110000011의 &연산
2. m을 i만큼 왼쪽으로 shift한 것과 or연산.
*/