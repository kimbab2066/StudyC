#include <stdio.h>

//�� �ð�, ���� ���̾Ƹ��, V

int main() {
	//input
	int n, x, y, v, w, i, j;
	scanf_s("%d", &n);
	x = 2, y = 3, v = 4 + n, w = 5 + n;
	//logic
	for (i = 1;; i++) {
		for (j = 1; j <= w; j++) {
			if (j == x || j == w) printf("*");
			else if (y <= v && (j == y || j == v)) printf("*");
			else printf(" ");
		}
		// ���� ���� + ����
		printf("\n");
		// ���� ����
		if (i == 1) x--, y++, v--, w++;
		else x++, y++, v--, w--;
		// ���� ����
		if (x > w) break;
	}
	//output

	return 0;
}//main