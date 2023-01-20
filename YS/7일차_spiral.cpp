#include <stdio.h>

int a[20][20];
int n;
int i, j, s;

int main() {
	//input
	scanf_s("%d", &n);
	int x = 0, y = 0;
	int v = 1;
	// 시작 위치
	for (i = 1; i <= n; i++) {
		a[x][y] = ++s;
		y++;
	}
	y--;
	//logic
	for (i = n - 1; i >= 1; i--) {
		//x
		for (j = 1; j <= i; j++) {
			x += v;
			a[x][y] = ++s;
		}

		v = -v;
		//y
		for (j = 1; j <= i; j++) {
			y += v;
			a[x][y] = ++s;
		}
	}
	//output
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}//main