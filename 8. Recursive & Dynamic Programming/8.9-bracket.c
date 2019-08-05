#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
/*
8.9 괄호
n-쌍의 괄호로 만들 수 있는 모든 합당한
(괄호가 적절히 열리고 닫힌)
조합을 출력하는 알고리즘을 구현하라.
*/

/*
규칙
1. {가 먼저 나와야 함.
2. {의 개수보다 }의 개수가 많아지면 안된다. => }의 개수가 n이 되면 종료하도록 함.
3. {의 개수보다 }의 개수가 적으면 } 재귀적으로 추가함.

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
		printf("%s\n",str);//끝에 도달하면 print
	}
	else {
		if (left < n) { //왼쪽 괄호는 n까지만 추가함.
			str[index] = '{';
			printBracket(left+1,right,index+1,n);
		}
		if (left > right) {//왼쪽 괄호가 오른쪽 괄호보다 더 많아야 함.
			str[index] = '}';
			printBracket(left,right+1,index+1,n);
		}
	}
}

int main() {
	int n;
	printf("괄호의 개수를 입력하시오 : ");
	scanf("%d",&n);
	Bracket(n);
}