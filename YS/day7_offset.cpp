#include <stdio.h>

//변위
int a[7][7];
int i, j, k;

int main() {
	//초기 세팅
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			a[i][j] = 10;
		}
	}
	//input
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	//logic
	//output
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			if (a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j]) printf("* ");
			else printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}//main