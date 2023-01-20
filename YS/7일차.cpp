#include <stdio.h>

//
int a[6][6];

int main() {
	//input
	int i, j, d, k, sum, max = 0;
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	int st, ed, st2, ed2;

	int x1, y1, x2, y2;
	//logic
	for (i = 1; i <= 5; i++) {
		st = i, ed = 5;
		while (ed--) {
			for (j = 1; j <= 5; j++) {
				st2 = j, ed2 = 5;
				while (ed2--) {
					sum = 0;
					for (d = st; d <= ed; d++) {
						for (k = st2; k <= ed2; k++) {
							sum += a[d][k];
							if (max < sum) {
								max = sum;
								x1 = st;
								y1 = ed;
								x2 = st2;
								y2 = ed2;
							}//if
						}//k
					}//d
				}//w2
			}//j
		}//w
	}//i

	//output
	printf("%d\n%d %d %d %d", max, x1, x2, y1, y2);
	return 0;
}//main