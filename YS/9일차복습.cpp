#include <stdio.h>
#include <string.h>

int a[101];

int gcd(int a, int b) {
	while (1) {
		int r = a % b;
		a = b;
		b = r;
		if (b == 0) return a;
	}
}

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
		//logic
	for (int i = 2; i <= n; i++) {
		a[1] = gcd(a[1], a[i]);
	}
		//output
	printf("%d", a[1]);

		return 0;
}//main