#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct tmp {
	int a, b;
}k[10001], t;

int gcd(int a, int b) {
	while (1) {
		int r = a % b;
		a = b;
		b = r;
		if (b == 0) return a;
	}
}


int chk(tmp x, tmp y) {
	return (double)x.a / x.b < (double)y.a / y.b;
}

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	//logic
	int i, j, idx = 0;
	for (i = 0; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i <= j && gcd(i, j) == 1) { k[idx].a = i; k[idx++].b = j; }
		}
	}
	sort(k, k + idx, chk);
	//output
	for (i = 0; i < idx; i++) {
		printf("%d/%d\n", k[i].a, k[i].b);
	}

	return 0;
}//main