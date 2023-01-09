#include <stdio.h>

int main() {
	//input
	int a, b, t;
	scanf_s("%d%d", &a, &b);
	int lcm = a * b;
	//logic
	while (1) {
		t = a % b;
		a = b;
		b = t;
		if (b == 0) break;
	}
	//output
	printf("%d %d", a, lcm / a);

	return 0;
}//main