#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int  c[5] = { 0,1,3,4,2 };

struct tmp {
	int a, b;
}k[100], t;

int chk(tmp x, tmp y) {
	return c[x.a] < c[y.a] || (x.a == y.a && x.a % 2 == 1 && x.b < y.b) || (x.a == y.a && x.a % 2 == 0 && x.b > y.b);
}

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i, j, t;
	for (i = 0; i < n; i++) {
		scanf_s("%d%d", &k[i].a, &k[i].b);
	}
	//logic
	sort(k, k + n, chk);
	//output
	for (i = 0; i < n; i++) {
		printf("%d %d\n", k[i].a, k[i].b);
	}

	return 0;
}//main