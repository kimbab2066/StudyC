#include <stdio.h>

//
int a[5][5];
int x[25], y[25];
int b[25];
int i, j;

int main() {
	//input
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			scanf_s("%d", &a[i][j]);
			x[a[i][j]] = i;
			y[a[i][j]] = j;
		}
	}
	for (i = 0; i < 25; i++) {
		scanf_s("%d", &b[i]);
	}
	//logic
	int tx, ty, cnt = 0;
	for (i = 0; i < 25; i++) {
		tx = x[b[i]];
		ty = y[b[i]];
		a[tx][ty] = 0;
		if (a[tx][0] + a[tx][1] + a[tx][2] + a[tx][3] + a[tx][4] == 0)cnt++;
		if (a[0][ty] + a[1][ty] + a[2][ty] + a[3][ty] + a[4][ty] == 0)cnt++;
		if (tx == ty && a[0][0] + a[1][1] + a[2][2] + a[3][3] + a[4][4] == 0)cnt++;
		if (tx + ty == 4 && a[0][4] + a[1][3] + a[2][2] + a[3][1] + a[4][0] == 0)cnt++;
		//종료 조건
		if (cnt >= 3)break;
	}
	//output
	printf("%d", i + 1);

	return 0;
}//main