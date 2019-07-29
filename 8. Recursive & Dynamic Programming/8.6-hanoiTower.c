#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
8.6 �ϳ���Ÿ��
�������� �ϳ���Ÿ�������� ũ�Ⱑ ���� �ٸ� n���� ������ �� ���� ��� ��
�ƹ� �����γ� �ű� �� �ִ�. �ʱ⿡ ������ ũ�Ⱑ �� ���������� �Ʒ��� Ŀ���� ������� �׿� �ִ�.
�׸��� �� �������� ������ ���� ���������� �ִ�.
(1) ������ �� ���� �ϳ��� �ű�� ����.
(2) �� ���� �ִ� ���� �ϳ��� �ٸ� ������� �ű� �� ����.
(3) ������ �ڽź��� ũ�Ⱑ ���� ��ũ ���� ���� �� ����.

������ ����Ͽ� ��� ������ ù ��° ��տ��� ������ ������� �ű�� ���α׷��� �ۼ��Ͽ���.
*/

/*
1. n-1 disk���� a->b�� �ű�. hanoi(n-1)
2. ������ disk�� a->c�� �ű�. hanoi(1)
3. n-1 disk���� b->c�� �ű�. hanoi(n-1)
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
	printf("����%d�� %c���� %c�� �̵�\n", n, from, to);
}

// �ϳ��� Ÿ�� �ݺ��� ���� �Լ�(���� �̿�)
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
//���
void HanoiTowerMove(int num, char from, char by, char to) {
	if (num == 1) {
		printf("����1�� %c���� %c�� �̵�\n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("����%d�� %c���� %c�� �̵�\n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main() {
	int num;
	printf("disk�� ���� : ");
	scanf("%d",&num);
	Hanoi(num,'A','B','C');
}