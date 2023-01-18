#include <stdio.h>

int a[10][10];

int dx[4] = { 4,0,-4,0 };
int dy[4] = { 0,4,0,-4 };

bool inRange(int x, int y) {
	return 0 <= x && x < 10 && 0 <= y && y < 10;
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
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	//logic
	int max = 0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (inRange(nx, ny)) {
					int val = calNum(i, j, nx, ny);
					max = max > val ? max : val;
				}
			}//d
		}//j
	}//i

	//output
	printf("%d", max);

	return 0;
}//main