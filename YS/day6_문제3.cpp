#include <stdio.h>

int a[100][100];

int main() {
	//input
	int n;
	int i, j, k, s = 0;
	scanf_s("%d", &n);
	int x, y;
	if (n % 2 == 0)x = y = n / 2 - 1;
	else x = y = n / 2;

	//logic
	for (i = n - 1; i >= 0; i--) { // col
		for (j = x; j >= y; j--) {
			a[j][i] = ++s;
		}
		if (n % 2 == 0) { //Â¦¼ö
			if (i > n / 2)x++, y--;
			else if (i < n / 2) x--, y++;
		}
		else {
			if (i > n / 2)x++, y--;
			else if (i <= n / 2) x--, y++;
		}
	}

	//output
	if (n % 2 == 0) k = n - 1;
	else k = n;
	for (i = 0; i < k; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] != 0) printf("%3d", a[i][j]);
			else printf("   ");
		}
		printf("\n");
	}

	return 0;
}//main