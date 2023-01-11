#include <stdio.h>


int main() {
	//input
	int n, i;
	scanf_s("%d", &n);
	//logic
	int* arr = new int[n];
	for (i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	//output
	for (i = n - 1; i >= 0; i--) {
		printf("%d ", arr[i]);
	}

	return 0;
}//main