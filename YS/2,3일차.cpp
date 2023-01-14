#include <stdio.h>

int main() {
	//input
	int n, k = 2;
	//logic
	scanf_s("%d", &n);
	while (1) {
		if (n == 1)break;
		else if (n % k == 0) printf("%d ", k), n /= k;
		else k++;
	}
	//output

	return 0;
}//main