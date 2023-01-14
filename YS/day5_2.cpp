#include <stdio.h>

// 1.에라토스 CLEAR
// 2.배열 CLEAR

int i, j, n, num[10001] = { 2 }, k = 1;
//

int main() {
	//input
	scanf_s("%d", &n);
	//logic
	for (i = 3; i <= n; i += 2) {
		for (j = 0; j < k; j++) {
			if (i % num[j] == 0) break;
		}
		if (j == k)num[k++] = i;
	}
	//output
	for (i = 0; i < k; i++) {
		printf("%d ", num[i]);
	}

	return 0;
}//main