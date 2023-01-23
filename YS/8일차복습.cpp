#include <stdio.h>
#include<string.h>
char a[20][15], b[15];
int s[20], e[20], c, d;
int main() {
	int n, i, j, k;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) scanf_s("%s", &a[i], 15);

	for (k = 0; k < n; k++) {
		scanf_s("%s%d%d", &b, 15, &c, &d);

		for (i = 0; i < n; i++) {
			if (strcmp(a[i], b) == 0) break;
		}
		s[i] = c; if (d != 0) e[i] += c % d;
		for (i = 1; i <= d; i++) {
			scanf_s("%s", &b, 15);
			for (j = 0; j < n; j++) {
				if (strcmp(a[j], b) == 0) break;
			}
			e[j] += c / d;
		}
	}
	for (k = 0; k < n; k++) {
		printf("%s %d\n", a[k], e[k] - s[k]);
	}
	return 0;
}