#include <stdio.h>

int a[11][11];
int n;
int i, j, s;

int main() {
	//input
	scanf_s("%d", &n);
	int x = n, y = n - 1;
	int v = -1;
	// 시작 위치
	//logic
	for (i = n; i >= 1; i--) {
		for (j = 1; j <= i; j++) {
			x += v;
			a[x][y] = ++s;
		}
		for (j = 1; j < i; j++) {
			y += v;
			a[x][y] = ++s;
		}
		v = -v;
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