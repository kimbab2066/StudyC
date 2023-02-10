#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct tmp {
	int s, e;
}k[100000];

int chk(tmp x, tmp y) {
	return x.e < y.e;
}

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf_s("%d%d", &k[i].s, &k[i].e);
	}
	//logic
	sort(k, k + n, chk);
	int max = -40000;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		if (max > k[i].s) {
			max = k[i].e;
			cnt++;
		}
	}
	//output
	printf("%d", cnt);

	return 0;
}//main