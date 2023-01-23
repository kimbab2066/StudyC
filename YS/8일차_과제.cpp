#include <stdio.h>
#include <string.h>

int a[27], b[27];
char aa[27], c[27];

int main() {
	//input
	int n, i, j;
	int res = 0;
	scanf_s("%d", &n);
	//logic
	for (i = 0; i < n; i++) {
		if (i == 0) {
			scanf_s("%s", aa, 27);
			for (j = 0; aa[j] != 0; j++) {
				a[aa[j] - 'A']++;
			}
		}
		else {
			scanf_s("%s", c, 27);
			for (j = 0; c[j] != 0; j++) {
				b[c[j] - 'A']++;
			}
		}
		//
		int cnt = 0;
		if (i > 0) {
			for (j = 0; j < 27; j++) {
				if (a[j] != 0 && a[j] > 0 && b[j] > 0) cnt += a[j] > b[j] ? b[j] : a[j];
			}
			//같을 때 증가
			if (cnt == strlen(aa) && strlen(aa) == strlen(c)) res++;
			else if (cnt <= strlen(aa)) {
				if (strlen(aa) == strlen(c) + 1) {
					if (cnt + 1 == strlen(aa))res++;
				}
				else if (strlen(aa) + 1 == strlen(c)) {
					if (cnt == strlen(aa)) res++;
				}
				else if (strlen(aa) == strlen(c)) {
					if (cnt + 1 == strlen(aa)) res++;
				}
			}//else
			//초기화
			for (j = 0; j < 27; j++) b[j] = 0;
		}//
	}//i

	//output
	printf("%d", res);

	return 0;
}//main