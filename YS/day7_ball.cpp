#include <stdio.h>

int a[3][3];
int i, j, k;
int main() {
	//input
	for (i = 0; i < 3; i++) {
		for (j = 0; j <= 2 - i; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	//logic
	int x, y;
	for (i = 1; i <= 6; i++) {
		printf("%d ", a[2][0]);
		x = 2, y = 0;
		for (j = 1; j <= 2; j++) {
			if (a[x - 1][y] > a[x - 1][y + 1]) {
				a[x][y] = a[x - 1][y];
				a[x - 1][y] = 0;
				x--;
			}
			else {
				a[x][y] = a[x - 1][y + 1];
				a[x - 1][y + 1] = 0;
				x--, y++;
			}
		}
	}

	return 0;
}//main