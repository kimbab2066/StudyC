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
	int k, l, m, n;//������, ���ۿ�, ����, ����
	int r1, c1, r2, c2;

	//logic
	for (i = 1; i <= 5; i++) { // �� ����
		for (j = 1; j <= 5; j++) { // �� ����
			for (k = i; k <= 5; k++) { // ���� �� ��ġ
				for (l = j; l <= 5; l++) { // ���� �� ��ġ
					sum = 0;
					for (m = i; m <= k; m++) { // �� ��
						for (n = j; n <= l; n++) { // �� ��
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