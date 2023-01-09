#include <stdio.h>

int main() {
	//input
	int a, b;
	scanf_s("%d%d", &a, &b);
	printf("%d %d ", a, b);
	int prev = a, next = b, tmp;
	while (1) {
		if (prev - next < 0) break;
		printf("%d ", prev - next);
		tmp = prev - next;
		prev = next;
		next = tmp;
	}
	//logic

	//output

	return 0;
}//main