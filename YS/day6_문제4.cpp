#include <stdio.h>

int a[11][11];
int n;
int i, j, k, s;

int main() {
	//input
	scanf_s("%d", &n);
	int x;

	//logic
	//�� �ﰢ��
	for (i = n - 1; i >= 0; i--) {
		x = i;
		for (j = n - 1; j >= i; j--) {
			a[j][x++] = ++s;
		}
	}
	//�Ʒ� �ﰢ��
	for (i = n - 2; i >= 0; i--) {//2�� �� 2~0, 1�϶� 1~0
		x = 0;
		for (j = i; j >= 0; j--) {
			a[j][x++] = ++s;
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