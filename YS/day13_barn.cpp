#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int m, s, c;
int a[200], k[200];

int chk(int x, int y) {
	return x > y;
}

int main() {
	//input
	scanf_s("%d%d%d", &m, &s, &c);
	int i;
	for (i = 0; i < c; i++) {
		scanf_s("%d", &a[i]);
	}
	sort(a, a + c);
	for (i = 0; i < c - 1; i++) {
		k[i] = a[i + 1] - a[i] - 1;
	}
	//logic
	sort(k, k + c - 1, chk);
	int s = 0;
	s = a[c - 1] - a[0] + 1;
	for (i = 0; i < m - 1; i++) {
		s -= k[i];
	}
	//output
	printf("%d", s);

	return 0;
}//main