#include <stdio.h>

//
int a[10][10];
int i, j, x, y, sum;


int main() {
	//input
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	int max = -500;
	//logic
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			//세로
			for (x = i, sum = 0; x < i + 5; x++) {
				sum += a[x % 10][j];
			}
			if (max < sum) max = sum;
			//가로
			for (y = j, sum = 0; y < j + 5; j++) {
				sum += a[i][y % 10];
			}
			if (max < sum) max = sum;
			//오른쪽 아래 대각선
			for (x = 0, sum = 0; x < 5; x++) {
				sum += a[(i + x) % 10][(j + x) % 10];
			}
			if (max < sum) max = sum;
			//왼쪽 아래 대각선
			for (x = 0, sum = 0; x < 5; x++) {
				if (j - x < 0) sum += a[(i + x) % 10][10 + (j - x)];
				else sum += a[(i + x) % 10][j - x];
			}
			if (max < sum) max = sum;
		}//j
	}//i

	//output
	printf("%d", max);

	return 0;
}//main