#include <stdio.h>

// 1 4 2 3 
//a = 반, b = 번호, c = 순서 조건(1 = 1, 2 = 3, 3 = 4, 4 = 2)
int a[100], b[100], c[5] = { 0,1,3,4,2 }, n;

int main() {
	//input
	scanf_s("%d", &n);
	int i, j, t;
	for (i = 0; i < n; i++) {
		scanf_s("%d%d", &a[i], &b[i]);
	}
	//logic
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			// 순서, 홀수면서 같은 경우(오름차순), 짝수면서 같은 경우(내림차순)
			if (c[a[i]] > c[a[j]] || a[i] % 2 == 1 && a[i] == a[j] && b[i] > b[j] || a[i] % 2 == 0 && a[i] == a[j] && b[i] < b[j]) {
				t = a[i]; a[i] = a[j]; a[j] = t;
				t = b[i]; b[i] = b[j]; b[j] = t;
			}
		}
	}
	//output
	for (i = 0; i < n; i++) {
		printf("%d %d\n", a[i], b[i]);
	}

	return 0;
}//main