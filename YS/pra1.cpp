#include <stdio.h>
#include <string.h>
//					A		B		C		D			E		F		G		H
char a[8][7] = { "000000","001111","010011","011100","100110","101001","110101","111010" };
char b[8], res[10];
int idx, cnt;

int main() {
	//input
	int n;
	int i, j, k;
	scanf_s("%d", &n);
	//logic
	for (i = 1; i <= n; i++) {
		scanf_s("%6s", b, 7);
		//
		for (j = 0; j < 8; j++) {
			//같을 때
			if (strcmp(a[j], b) == 0) {
				res[idx++] = 'A' + j;
				break;
			}
			// 1개만 다를 때
			cnt = 0;
			for (k = 0; k < 6; k++) {
				if (a[j][k] == b[k])cnt++;
			}
			if (cnt >= 5) { res[idx++] = 'A' + j; break; }
		}//j
		// 아예 다른 경우
		if (j == 8 && cnt < 5)break;
	}
	//output
	if (strlen(res) == n) printf("%s", res);
	else printf("%d", idx + 1);

	return 0;
}//main