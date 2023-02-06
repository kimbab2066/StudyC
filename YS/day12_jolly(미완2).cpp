#include <stdio.h>
#include <string.h>

int a[101];

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i, j;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	//logic
	for (i = 2; i < n - 1; i++) {
		int p = a[i - 1];
		if (i % 2 == 0) {//내림
			for (j = i + 1; j < n; j++) {
				if (p > a[j]) { a[i] = a[j]; a[j] = p; }
			}
		}
		else {//오름
			for (j = i + 1; j < n; j++) {
				if (p < a[j]) { a[i] = a[j]; a[j] = p; }
			}
		}
	}
	//output
	for (i = 0; i < n; i++) {

	}


	return 0;
}//main