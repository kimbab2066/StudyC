#include <stdio.h>
#include <string.h>

int a[1001];

int main() {
	//input
	int n, s;
	scanf_s("%d%d", &n, &s);
	int i, j, p;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	//logic
	for (i = 1; i < s; i++) {
		p = a[i];//±âÁØÁ¡
		for (j = i - 1; j >= 0; j--) {
			if (a[j] > p) a[j+1] = a[j];
			else break;
		}//j
		a[j + 1] = p;
	}//i

	//output
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}//main