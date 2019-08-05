#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define True 1
#define False 0
/*
8.12 ���� ���� ��
8x8 ü���� ���� �������� ���� ���� ��� ������ �ʵ��� ���� �� �ִ�
��� ������ ����� ����ϴ� �˰����� �ۼ��Ͽ���.
��, ���� ���� ���� ��, ��, �밢���� ���̸� �ȵȴ�. 
���⼭ '�밢��'�� ��� �밢���� �ǹ��ϴ� ������, 
ü������ ����ϴ� �밢�� �� ���� �������� ����.
*/



void printChess(int chess[10][10]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%d ",chess[i][j]);
		printf("\n");
	}
	printf("\n");
}
/*
col���� queen�� �̹� �����Ƿ�
���ݰ������� �ƴ����� ���ʸ� Ȯ���ϸ� �ȴ�.
*/
int queenRule(int chess[10][10],int row,int col) {
	for (int i = 0; i < col; i++) //left row check
		if (chess[row][i]==True)
			return False;
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		//up-left �밢�� check
		if (chess[i][j] == True) 
			return False;
	}
	for (int i = row, j = col; j >= 0 && i < 8; i++, j--)
		//down-left �밢�� check
		if (chess[i][j] == True)
			return False;
	return True;
}

int solveProblem(int chess[10][10],int col) {
	int res = False;
	if (col == 8) {
		printChess(chess);
		return True; //��� queen�� placed-> true
	}
	for (int i = 0; i < 8; i++) {
		if (queenRule(chess, i, col)) {
			//�ش� ��ġ�� queen ���� �� �ִ��� check
			chess[i][col] = 1;
			res = solveProblem(chess,col+1) || (res==True);
			//recur -> ������ queen �� ���� ������
			chess[i][col] = 0;
			//backtrack
		}
	}
	return res;
}

void eightQueen(){
	int chess[10][10] = { 0 };
	if (solveProblem(chess,0) == False)
		return;
	return;
}

int main() {
	eightQueen();
	return 0;
}