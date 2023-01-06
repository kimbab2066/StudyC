#include <stdio.h>

int main() {
	//input
	int n, i, j, sum1 = 0, sum2 = 0;
	scanf_s("%d", &n);
	//logic
	for (i = 1;; i++) {
		sum1 += i;
		if (sum1 >= n) break;
	}
	printf("%d ", i);
	for (j = i; j >= 1; j--) {
		sum2 += j;
		if (sum2 >= n) break;
	}
	printf("%d", j - (sum2 - n));

	//output

	return 0;
}//main