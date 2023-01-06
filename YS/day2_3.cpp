#include <stdio.h>

int main() {
	//input
	int a, b, c, max, max2;
	scanf_s("%d%d%d", &a, &b, &c);
	max = c - b - 1;
	max2 = b - a - 1;
	printf("%d", max > max2 ? max : max2);
	//logic

	//output

	return 0;
}//main