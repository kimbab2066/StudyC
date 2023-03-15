#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int k, a[50], b[50], chk[50];

void per(int t) {
	if (t == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < k; i++) {
		if (!chk[i]) {
			if (t > 0 && b[t - 1] > a[i]) continue;
			chk[i] = 1;
			b[t] = a[i];
			per(t + 1);
			chk[i] = 0;
		}
	}
}

int main() {
	//input
	scanf_s("%d", &k);
	int i;
	for (i = 0; i < k; i++) {
		scanf_s("%d", &a[i]);
	}
	//logic
	per(0);
	//output

	return 0;
}//main