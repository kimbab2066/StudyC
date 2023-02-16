#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MX 100100

int n, a[MX], mi = 0x7fffffff, s1, s2, c1, c2;

int main() {
	//input
	scanf_s("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	//logic
	int m, l, r;
	for (i = 1; i < n; i++) {
		int k = -a[i];
		l = i + 1;
		r = n;
		while (1) {
			//종료 조건
			if (l > r) break;
			m = (l + r) / 2;
			if (a[m] > k)r = m - 1;
			else if (a[m] < k) l = m + 1;
			else { printf("%d %d", a[i], k); exit(0); }
		}
		c1 = a[i] + a[l];
		if (c1 < 0) c1 *= -1;
		if (l <= n && mi > c1) { mi = c1; s1 = a[i]; s2 = a[l]; }
		c2 = a[i] + a[r];
		if (c2 < 0) c2 *= -1;
		if (r > i && mi > c2) { mi = c2; s1 = a[i]; s2 = a[r]; }
	}

	//output
	printf("%d %d", s1, s2);

	return 0;
}//main