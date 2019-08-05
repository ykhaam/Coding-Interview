#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
/*
8.9 ��ȣ
n-���� ��ȣ�� ���� �� �ִ� ��� �մ���
(��ȣ�� ������ ������ ����)
������ ����ϴ� �˰����� �����϶�.
*/

/*
��Ģ
1. {�� ���� ���;� ��.
2. {�� �������� }�� ������ �������� �ȵȴ�. => }�� ������ n�� �Ǹ� �����ϵ��� ��.
3. {�� �������� }�� ������ ������ } ��������� �߰���.

*/
void printBracket(int left, int right, int index, int n);
char str[MAX];

void Bracket(int n) {
	if (n > 0)
		printBracket(0,0,0,n);
	else return;
}

void printBracket(int left,int right,int index,int n) {
	if (right == n) {
		printf("%s\n",str);//���� �����ϸ� print
	}
	else {
		if (left < n) { //���� ��ȣ�� n������ �߰���.
			str[index] = '{';
			printBracket(left+1,right,index+1,n);
		}
		if (left > right) {//���� ��ȣ�� ������ ��ȣ���� �� ���ƾ� ��.
			str[index] = '}';
			printBracket(left,right+1,index+1,n);
		}
	}
}

int main() {
	int n;
	printf("��ȣ�� ������ �Է��Ͻÿ� : ");
	scanf("%d",&n);
	Bracket(n);
}