#include <stdio.h>

int n, a[1001];
int min = 1001, idx, cnt;

int per(int t) {

}

int main() {
	//input
	scanf_s("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
		if (min > a[i]) { min = a[i], idx = i; }
	}
	//logic
	per(idx);
	//output
	printf("%d", cnt);

	return 0;
}//main