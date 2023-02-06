#include <stdio.h>
#define MX 500001

int a[MX], s[MX][2], res[MX];

int main() {
	//input
	int n, i, top = -1;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	//logic
	for (i = n; i >= 1; i--) {
		//비어 있거나 top > a[i]인 경우
		if (top == -1 || s[top][0] > a[i]) {
			s[++top][0] = a[i];
			s[top][1] = i;
		}
		//반대 경우
		else {
			for (top; top >= 0 && s[top][0] <= a[i]; --top) {
				res[s[top][1]] = i; // ? s[top][1] = 4,5니까 5 res[5] = 4;
			}
			s[++top][0] = a[i];
			s[top][1] = i;
		}
	}
	//output
	for (i = 1; i <= n; i++) {
		printf("%d ", res[i]);
	}

	return 0;
}//main