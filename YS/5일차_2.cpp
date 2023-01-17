#include <stdio.h>
//
int num[100][2];
int cnt;
int i, j, k;
int n, m;
int t[2];

int main() {
	//input
	scanf_s("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		num[i][0] = i;
		scanf_s("%d", &num[i][1]);
	}
	//logic
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			// 우선 순위가 높은 경우가 있으면
			if (num[i][1] < num[j][1]) {
				t[0] = num[i][0];
				t[1] = num[i][1];
				for (k = j; k < n - 1; k++) {
					num[k][0] = num[k + 1][0];
					num[k][1] = num[j + 1][1];
				}
				num[n - 1][0] = t[0];
				num[n - 1][1] = t[1];
			}//if
			else {

			}
		}
	}

	//output
	printf("%d", cnt);


	return 0;
}//main