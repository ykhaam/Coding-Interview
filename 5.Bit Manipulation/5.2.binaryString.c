#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define CALL 33

int count = 0;
double f = 0.5;
/*
5.2 2������ ���ڿ���
0.72�� ���� 0�� 1 ������ �Ǽ��� doubleŸ������ �־����� ��,
�� ���� 2���� ���·� ����ϴ� �ڵ带 �ۼ��϶�.
���̰� 32 ������ ���ڿ��� 2������ ��Ȯ�ϰ� ǥ���� �� ���ٸ� error���
*/

void binaryConvert(double data);

int main() {
	double num;
	printf("0�� 1 ������ �Ǽ� �Է� : ");
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