#include <stdio.h>
#include <string.h>

int p[100000001];

void prime() {
	for (int k = 2; k * k <= 100000000; k++) {
		if (!p[k]) {
			for (int j = k + k; j <= 100000000; j += k) {
				p[j] = 1;
			}
		}
	}
}

int palin(int a) {
	int k = 0;
	while (1) {
		k = k * 10 + a % 10;
		a /= 10;
		if (a == 0)return k;
	}
}

int main() {
	//input
	prime();
	int a, b;
	int i;
	scanf_s("%d%d", &a, &b);
	//logic
	for (i = a; i <= b; i++) {
		if (!p[i] && palin(i) == i)printf("%d\n", i);
	}

	//output

	return 0;
}//main