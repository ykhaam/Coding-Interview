/*
8.1 tripple step
어떤 아이가 n개의 계단을 오른다. 
한 번에 1계단 오르기도 하고, 2계단, 3계단 오르기도 한다. 
계단을 오르는 방법이 몇 가지가 있는지 계산하는 메서드 구현하라.

in recursive way
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int triplestep(int n);

int main() {
	srand(time(NULL));
	int random = (rand()%10)+1;
	printf("%d개의 계단을 오르는 방법은 %d 개이다.\n",random,triplestep(random));
}

int triplestep(int n) {
	if (n == 0 || n == 1) //방법 계단 1개씩 -> 1개뿐
		return 1;
	else if (n == 2) //방법은 1개or2개씩 -> 2개뿐
		return 2;
	else
		return triplestep(n-1)+triplestep(n-2)+triplestep(n-3);
}