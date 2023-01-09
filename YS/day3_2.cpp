#include <stdio.h>

// ���
// ¦���� Ȧ���� ����� ���� �ٸ�
// ù ���� �� 2ĭ*, nĭ ����(�����ٿ� n-2), �� 2ĭ*
// ��°�ٺ��� i-1ĭ*, i*iĭ*, n-=2ĭ ����, �ٷ� ��*, 2ĭ ��*
// n�� ¦���� i == n 

// x y  v   w
// 2 3 4+n 5+n
// - +  -   +
// + +  -   -
// y <= v
// x <= w

// 1.�ʱ� �м����� ������
// 2.���ǽ��� ����µ� 5~10% ������
// 3.���� ������ �����ϰ� ���� ������

int main() {
	//input
	int i, j;
	int x, y, v, w, n;
	scanf_s("%d", &n);
	x = 2, y = 3, v = 4 + n, w = 5 + n;
	//logic
	for (i = 1;; i++) {
		for (j = 1; j <= w; j++) {
			if (j == x || j == w) printf("*");
			else if (y <= v && (j == y || j == v)) printf("*");
			else printf(" ");
		}
		printf("\n");
		if (i == 1)x--, y++, v--, w++;
		else x++, y++, v--, w--;
		// ���� ����
		if (x > w) break;
	}
	//output

	return 0;
}//main