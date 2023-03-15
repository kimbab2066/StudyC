#include <stdio.h>
#include <algorithm>
using namespace std;
int n, k;
int a[11], b[11], c[11], chk[11];

void per(int t) {
	if (t == k) {
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			if (b[i] == c[i]) cnt++;
		}
		if (cnt == k) {
			for (int i = 0; i < k; i++) {
				printf("%d ", a[i]);
			}
			exit(0);
		}
		for (int i = 0; i < k; i++) b[i] = a[i];
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			if (t > 0 && a[t - 1] > i) continue;
			chk[i] = 1;
			a[t] = i;
			per(t + 1);
			chk[i] = 0;
		}
	}
}

int main(void) {
	//input
	scanf_s("%d%d", &n, &k);
	int i;
	for (i = 0; i < k; i++) {
		scanf_s("%d", &c[i]);
	}
	//logic
	per(0);
	//output
	printf("NONE");

	return 0;

}//main