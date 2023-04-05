#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[1001], d[1001];

int main(void) {
	//input
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	//logic
	int res = 0;
	for (i = 0; i < n; i++) {
		d[i] = 1;
		for (j = 0; j < i; j++) {
			if (a[i] > a[j]) d[i] = max(d[i], d[j] + 1);
		}
		res = max(res, d[i]);
	}
	//output
	printf("%d", res);

	return 0;
}//main