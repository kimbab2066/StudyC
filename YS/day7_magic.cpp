#include <stdio.h>

//
int a[10][10];
int n, s;
int i, j;

int main() {
	//input
	scanf_s("%d", &n);
	//logic
	int x, y;
	x = 0, y = n / 2;
	int zx, zy;

	for (i = 1; i <= n * n; i++) {
		a[x][y] = ++s;
		//값 백업(2번째 예외를 위함)
		zx = x, zy = y;
		//오른쪽 위 대각선(x--,y++)
		x--, y++;
		//범위를 벗어나면 n-1(x가 0보다 작아지면 n-1에서 다시 시작하면 됨)
		if (x < 0) x = n - 1;
		//범위를 벗어나면 n-1(y가 n보다 같거나 커지면 0에서 다시 시작하면 됨)
		if (y >= n) y = 0;
		//이미 값이 채워진 경우 아래로 내려가야 하니 백업값을 가져와서 zx+1, y = zy
		if (a[x][y] != 0) x = zx + 1, y = zy;
	}
	//output
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}//main