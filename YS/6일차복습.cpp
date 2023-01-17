#include <stdio.h>

int a[5][5];

int main() {
	//input
	int i, j, v, s = 0;
	int n, x, y;
	scanf_s("%d", &n);
	x = n, y = n - 1, v = -1;// 배열의 크기가 5,5일 때 시작 위치는 (n,n-1)
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