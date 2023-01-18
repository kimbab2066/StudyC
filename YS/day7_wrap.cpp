#include <stdio.h>

//
int a[10][10];
int i, j, x, y;

int main() {
	//input
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	int max = -500;
	//logic
	int sum, x;
	for (i = 0; i < 10; i++) {//row
		for (j = 0; j < 10; j++) {//col
			// ����
			for (x = i, sum = 0; x < i + 5; x++) {
				sum += a[x % 10][j];
			}
			if (sum > max) max = sum;
			// ����
			for (y = j, sum = 0; y < j + 5; y++) {
				sum += a[i][y % 10];
			}
			if (sum > max) max = sum;
			// ������ �Ʒ� �밢��
			for (x = 0, sum = 0; x < 5; x++) {
				sum += a[(i + x) % 10][(j + x) % 10];
			}
			if (sum > max) max = sum;
			// ���� �Ʒ� �밢��
			for (x = 0, sum = 0; x < 5; x++) {
				if (j - x < 0) sum += a[(i + x) % 10][10 + (j - x)];
				else sum += a[(i + x) % 10][j - x];
			}
			if (sum > max) max = sum;
		}//j
	}//i

	//output
	printf("%d", max);

	return 0;
}//main