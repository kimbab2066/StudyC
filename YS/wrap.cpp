#include <stdio.h>

int a[30][30];

int dx[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

bool inRange(int x, int y) {
	return 0 <= x && x < 30 && 0 <= y && y < 30;
}//inRange

int calNum(int i, int j, int nx, int ny) {
	int ans = 0;
	for (int k = i; k <= nx; k++) {
		for (int g = j; g <= ny; g++) {
			ans += a[k][g];
		}
	}
	return ans;
}//calNum

int main() {
	//input
	int i, j, k, d;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 30; j++) {
			a[i][j] = a[i % 10][j % 10];
		}
	}
	int max = -500;
	//logic
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 30; j++) {
			//상하좌우, 대각선
			for (d = 0; d < 8; d++) {
				int val = 0;
				int nx = i;
				int ny = j;
				for (k = 0; k < 5; k++) {//5회
					nx += dx[d];
					ny += dy[d];
					if (inRange(nx, ny)) { // 유효 범위인 경우
						val += a[nx][ny];
					}
					else break;
				}//k
				if (k == 5) max = max > val ? max : val;
			}//d
		}//j
	}//i

	//output
	printf("%d", max);

	return 0;
}//main