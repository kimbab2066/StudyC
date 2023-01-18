#include <stdio.h>

//
int ar[101][101];
int a, b, k, f;
int i, j;

bool inRange(int x, int y) {
	return 0 < x && 0 < y && x <= a && y <= b;
}

int main() {
	//input
	scanf_s("%d%d%d", &a, &b, &k);
	int r, s, p, t;
	int x1, y1, x2, y2;
	//logic
	while (k--) {
		scanf_s("%d%d%d%d", &r, &s, &p, &t);
		if (t) f++;
		x1 = r - p / 2;
		y1 = s - p / 2;
		x2 = r + p / 2;
		y2 = s + p / 2;

		for (i = x1; i <= x2; i++) {
			for (j = y1; j <= y2; j++) {
				if (inRange(i, j)) {
					if (t) ar[i][j]++;
					else ar[i][j]--;
				}
			}
		}
	}//while

	//output
	int cnt = 0;
	for (i = 1; i <= a; i++) {
		for (j = 1; j <= b; j++) {
			if (ar[i][j] == f)cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}//main