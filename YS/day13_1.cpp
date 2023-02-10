#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct tmp {
	int x, y;
}k[100010];

int n;

int chk(tmp a, tmp b) {
	return a.y < b.y;
}

int main() {
	//input
	scanf_s("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf_s("%d%d", &k[i].x, &k[i].y);
	}
	//logic
	sort(k, k + n, chk);
	//output
	int cnt = 0;
	int max = -30001;
	for (i = 0; i < n; i++) {
		if (k[i].x > max) {
			max = k[i].y;
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}//main