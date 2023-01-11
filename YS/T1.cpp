#include <stdio.h>

int main() {
	//input
	int a, b, c;
	//logic
	scanf_s("%d%d%d", &a, &b, &c);
	printf("0.");
	while (c--) {
		a *= 10;
		printf("%d", a / b);
		a %= b;
	}

	//output

	return 0;
}//main