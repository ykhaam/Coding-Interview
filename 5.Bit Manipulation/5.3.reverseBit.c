#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
5.3 비트 뒤집기
어떤 정수가 주어졌을 때 여러분은 이 정수의 비트 하나를
0에서 1로 바꿀 수 있다.
이때 1이 연속으로 나올 수 있는 가장 긴 길이를 구하는 코드를
작성하시오.

input  1775(11011101111)
output 8
*/

/*
만약 다음 비트가 1이면 이전 길이가 현재 now길이에 저장될 것이고,
만약 다음 비트가 0이면 서로 병합할 수 없으므로 이전 길이를 0으로 세팅함.
*/

int flipBit(int num);

int main() {
	int num;
	printf("정수 입력 : ");
	scanf("%d",&num);
	printf("%d\n",flipBit(num));
}

int flipBit(int num) {
	int now = 0,prev = 0,max = 0;

	if (~num == 0) //만약 전부 1이면 원래의 길이+1
		return 8 * sizeof(int);
	while (num != 0) {
		printf("now : %d, prev : %d, max : %d, num :%d\n",now,prev,max,num);
		if ((num & 1) == 1) //현재 비트가 1이면 길이 증가
			now++;
		else if ((num & 1) == 0)// 현재 비트가 0이면 다음 비트 체크함.
		{
			// 만약 다음 비트가 0이면 prev=0, 아니면 prev에 now값 저장.
			prev = (num & 2) == 0 ? 0 : now;
			// 만약 연속된 두개의 비트가 0이면 now도 0으로 됨.
			now = 0;
		}
		max = max(prev + now, max);
		num >>= 1;
	}
	return max+1;
}