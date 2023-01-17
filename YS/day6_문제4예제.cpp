#include <stdio.h>

int a[11][11];
int n;
int i, j, k, s;

int main() {
	//input
	scanf_s("%d", &n);
	int x;
	//logic
	//À§ÀÇ »ï°¢Çü
	for (i = 0; i < n; i++) {
		x = i;
		for (j = 0; j <= i; j++) {
			a[j][x--] = ++s;
		}
	}
	//¾Æ·¡ »ï°¢Çü
	for (i = 1; i < n; i++) {
		x = n - 1;
		for (j = i; j < n; j++) {
			a[j][x--] = ++s;
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