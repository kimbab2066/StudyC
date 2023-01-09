#include <stdio.h>

int main() {
	//input
	double x, y = 0.167;
	//logic
	while (1) {
		scanf_s("%lf", &x);
		if (x < 0)break;
		printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", x, x * y);
	}

	//output

	return 0;
}//main