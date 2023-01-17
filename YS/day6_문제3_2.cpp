#include <stdio.h>

int a[100][100];
int n;
int i, j, k, s;

int main() {
	//input
	scanf_s("%d", &n);
	int x, y;
	if (n % 2 == 0)x = y = n / 2 - 1;
	else x = y = n / 2;
	//logic
	for (i = n - 1; i >= 0; i--) {
		for (j = x; j >= y; j--) {
			a[j][i] = ++s;
		}
		if (n % 2 == 0) {//짝수일 땐 중앙에서 그대로인 범위가 존재
			if (i > n / 2) x++, y--;
			else if (i < n / 2)x--, y++;
		}
		else {
			if (i > n / 2) x++, y--;
			else if (i <= n / 2)x--, y++;
		}
	}
	//output
	if (n % 2 == 0) k = n - 1;
	else k = n;
	for (i = 0; i < k; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j]) printf("%3d", a[i][j]);
			else printf("   ");
		}
		printf("\n");
	}

	return 0;
}//main