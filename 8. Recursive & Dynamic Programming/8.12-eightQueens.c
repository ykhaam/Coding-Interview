#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define True 1
#define False 0
/*
8.12 여덟 개의 퀸
8x8 체스판 위에 여덟개의 퀸이 서로 잡아 먹히지 않도록 놓을 수 있는
모든 가능한 방법을 출력하는 알고리즘을 작성하여라.
즉, 퀸은 서로 같은 행, 열, 대각선상에 놓이면 안된다. 
여기서 '대각선'은 모든 대각선을 의미하는 것으로, 
체스판을 양분하는 대각선 두 개로 한정하지 않음.
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
col에는 queen이 이미 있으므로
공격가능한지 아닌지는 왼쪽만 확인하면 된다.
*/
int queenRule(int chess[10][10],int row,int col) {
	for (int i = 0; i < col; i++) //left row check
		if (chess[row][i]==True)
			return False;
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		//up-left 대각선 check
		if (chess[i][j] == True) 
			return False;
	}
	for (int i = row, j = col; j >= 0 && i < 8; i++, j--)
		//down-left 대각선 check
		if (chess[i][j] == True)
			return False;
	return True;
}

int solveProblem(int chess[10][10],int col) {
	int res = False;
	if (col == 8) {
		printChess(chess);
		return True; //모든 queen이 placed-> true
	}
	for (int i = 0; i < 8; i++) {
		if (queenRule(chess, i, col)) {
			//해당 위치에 queen 놓을 수 있는지 check
			chess[i][col] = 1;
			res = solveProblem(chess,col+1) || (res==True);
			//recur -> 나머지 queen 다 놓을 때까지
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