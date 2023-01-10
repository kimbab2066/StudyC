#include <stdio.h>

//모래 시계, 숫자 다이아몬드, V

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
		// 다음 라인 + 조건
		printf("\n");
		// 증감 조건
		if (i == 1) x--, y++, v--, w++;
		else x++, y++, v--, w--;
		// 종료 조건
		if (x > w) break;
	}
	//output

	return 0;
}//main