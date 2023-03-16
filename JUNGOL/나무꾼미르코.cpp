#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MX 1000100
int n, m, a[MX];

int main() {
	//input
	scanf_s("%d%d", &n, &m);
	int i;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	//logic
	int l, r, mid;
	long long sum;
	l = 0, r = 2000000000;
	while (l <= r) {
		sum = 0;
		mid = (l + r) / 2;
		for (i = 0; i < n; i++) {
			if (a[i] - mid <= 0) continue;
			sum += a[i] - mid;
		}
		if (sum < m) r = mid - 1;
		else if (sum > m) l = mid + 1;
		else break;
	}//w

	//output
	if (l >= r) printf("%d", r);
	else printf("%d", mid);

	return 0;
}//main