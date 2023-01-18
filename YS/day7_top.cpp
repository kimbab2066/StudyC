#include <stdio.h>

//
int a[4][4];
int i, j, x;

int main() {
	//input
	for (i = 0; i <= 3; i++) {
		for (j = 0; j <= i; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	//logic
	for (i = 2; i >= 0; i--) {
		for (j = 0; j <= i; j++) {
			for (x = 0; x <= j; x++) {
				a[j][x] = a[j][x] + a[j + 1][x] + a[j + 1][x + 1];
			}
		}
	}

	//output
	printf("%d", a[0][0]);

	return 0;
}//main