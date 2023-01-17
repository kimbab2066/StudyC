#include <stdio.h>

//
int a[11][11];
int n;
int i, j, s;

int main() {
	//input
	scanf_s("%d", &n);
	int x, y;
	int v = -1;
	if (n % 2 == 0) x = n / 2, y = n / 2 - 1;
	else x = y = n / 2;
	// 시작 위치
	a[x][y] = ++s;
	//logic
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			x += v;
			a[x][y] = ++s;
			if (s == n * n)break;
		}
		if (s == n * n)break;
		v = -v;
		for (j = 1; j <= i; j++) {
			y += v;
			a[x][y] = ++s;
		}
	}
	//output
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j]) printf("%3d", a[i][j]);
			else printf("   ");
		}
		printf("\n");
	}

	return 0;
}//main