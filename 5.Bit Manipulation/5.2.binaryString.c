#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define CALL 33

int count = 0;
double f = 0.5;
/*
5.2 2진수를 문자열로
0.72와 같이 0과 1 사이의 실수가 double타입으로 주어졌을 때,
그 값을 2진수 형태로 출력하는 코드를 작성하라.
길이가 32 이하인 문자열로 2진수로 정확하게 표현할 수 없다면 error출력
*/

void binaryConvert(double data);

int main() {
	double num;
	printf("0과 1 사이의 실수 입력 : ");
	scanf("%lf",&num);
	//printf("%lf",num);
	binaryConvert(num);
}

void binaryConvert(double data) {
	count++;
	if (count > CALL) {
		printf("error\n");
		return;
	}
	else {
		
		if (data < f) {
			//printf("data : %lf, f : %lf\n",data,f);
			f /= 2.0;
			printf("0");
			binaryConvert(data);
		}
		else if (data > f) {
			//printf("data : %lf, f : %lf\n", data, f);
			data -= f;
			f /= 2.0;
			printf("1");
			binaryConvert(data);
		}
		else {
			printf("1");
		}
	}
}