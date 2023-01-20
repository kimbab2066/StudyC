#include <stdio.h>

//
int a[6][6];
int x[5];

int main() {
	//input
	int i, j, sum, max = 0;
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	int k, l, m, n;//시작행, 시작열, 끝행, 끝열
	int r1, c1, r2, c2;

	//logic
	for (i = 1; i <= 5; i++) { // 행 범위
		for (j = 1; j <= 5; j++) { // 열 범위
			for (k = i; k <= 5; k++) { // 시작 행 위치
				for (l = j; l <= 5; l++) { // 시작 열 위치
					sum = 0;
					for (m = i; m <= k; m++) { // 끝 행
						for (n = j; n <= l; n++) { // 끝 열
							sum += a[m][n];
						}//n
					}//m
					if (sum > max) {
						max = sum;
						x[1] = i;
						x[2] = j;
						x[3] = k;
						x[4] = l;
					}//if
				}//l
			}//k
		}//j
	}//i

	//output
	printf("%d\n", max);
	for (i = 1; i <= 4; i++)printf("%d ", x[i]);

	return 0;
}//main