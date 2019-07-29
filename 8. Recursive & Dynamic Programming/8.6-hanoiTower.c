#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
8.6 하노이타워
전형적인 하노이타워에서는 크기가 서로 다른 n개의 원반을 세 개의 기둥 중
아무 곳으로나 옮길 수 있다. 초기에 원반은 크기가 맨 위에서부터 아래로 커지는 순서대로 쌓여 있다.
그리고 이 문제에는 다음과 같은 제약조건이 있다.
(1) 원반은 한 번에 하나만 옮기기 가능.
(2) 맨 위에 있는 원반 하나를 다른 기둥으로 옮길 수 있음.
(3) 원반은 자신보다 크기가 작은 디스크 위에 놓을 수 없음.

스택을 사용하여 모든 원반을 첫 번째 기둥에서 마지막 기둥으로 옮기는 프로그램을 작성하여라.
*/

/*
1. n-1 disk들을 a->b로 옮김. hanoi(n-1)
2. 마지막 disk를 a->c로 옮김. hanoi(1)
3. n-1 disk들을 b->c로 옮김. hanoi(n-1)
*/
#define size 50

int cur; 
int Stack[size];

void InitStack()
{
	cur = -1;
}

void Push(int data)
{
	if (cur >= size - 1)
	{
		printf("Stack overflow\n");
		return;
	}

	Stack[++cur] = data;
}

int Pop()
{
	if (cur < 0)
	{
		printf("Stack is already empty\n");
		return 0;
	}

	return Stack[cur--];
}

int IsEmpty()
{
	if (cur < 0)
		return 1;
	else
		return 0;
}

void Print(int n, int from, int to)
{
	printf("원반%d를 %c에서 %c로 이동\n", n, from, to);
}

// 하노이 타워 반복문 구현 함수(스택 이용)
void Hanoi(int n, int from, int by, int to)
{
	int keep = 1;
	InitStack();

	while (keep)
	{
		while (n > 1)
		{
			Push(to);
			Push(by);
			Push(from);
			Push(n);
			--n;
			Push(to);
			to = by;
			by = Pop();
		}
		Print(n, from, to);
		if (!IsEmpty())
		{
			n = Pop();
			from = Pop();
			by = Pop();
			to = Pop();
			Print(n, from, to);
			--n;
			Push(from);
			from = by;
			by = Pop();
		}
		else
			keep = 0;
	}
}
//재귀
void HanoiTowerMove(int num, char from, char by, char to) {
	if (num == 1) {
		printf("원반1을 %c에서 %c로 이동\n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반%d를 %c에서 %c로 이동\n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main() {
	int num;
	printf("disk의 개수 : ");
	scanf("%d",&num);
	Hanoi(num,'A','B','C');
}