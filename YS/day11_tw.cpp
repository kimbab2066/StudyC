#include <stdio.h>

#define MX 500001

int a[MX], s[MX][2], res[MX];

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i, top = -1;
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	//logic
	for (i = n; i >= 1; i--) {
		// 비어 있거나 작은 경우
		if (top == -1 || s[top][0] > a[i]) {
			s[++top][0] = a[i];
			s[top][1] = i;
		}
		// 큰 경우
		else {
			for (top; top >= 0 && s[top][0] <= a[i]; --top) {
				res[s[top][1]] = i;
			}
			s[++top][0] = a[i], s[top][1] = i;
		}
	}//w

	//output
	for (i = 1; i <= n; i++) {
		printf("%d ", res[i]);
	}

	return 0;
}//main