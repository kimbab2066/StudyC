#include <stdio.h>

void tmp() {
	int i;
	double sum = 0;
	for (i = 1; i <= 10; i++) {
		sum += 1 / (double)i;
	}
	printf("%lf", sum);
}

void tmp2() {
	double sum = 0;
	int sw = 0;
	int i;
	for (i = 1; i <= 9; i++) {
		if (sw == 0) sum += i / (double)(i + 1), sw = 1;
		else sum -= i / (double)(i + 1), sw = 0;
	}
	printf("%lf", sum);
}

void tmp3() {
	int i, j, sum = 0, k = 1;
	for (i = 1; i <= 10; i++) {
		k *= i;
		sum += k;
	}
	printf("%d", sum);
}

int main() {

	//input

	//logic

	//output

	return 0;
}//main