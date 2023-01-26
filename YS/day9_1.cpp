#include <stdio.h>

int a[5];
int chk[10000];
int min, cnt;

int p(int a[]) {
	int res = 10000;
	for (int k = 0; k < 4; k++) {
		int min = 0;
		for (int i = k; i < k + 4; i++) {
			min = min * 10 + a[i % 4];
		}
		if (res > min) res = min;
	}
	return res;
}//p


int main() {
	//input
	for (int i = 0; i < 4; i++) {
		scanf_s("%d", &a[i]);
	}
	//logic
	min = p(a);
	int i, j, k, l;
	int w;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			for (k = 1; k <= 9; k++) {
				for (l = 1; l <= 9; l++) {
					a[0] = i, a[1] = j;
					a[2] = k, a[3] = l;
					w = p(a);
					if (chk[w] == 0) { chk[w] = 1, cnt++; }
					//output
					if (w == min) { printf("%d", cnt); return 0; }
				}//l
			}//k
		}//j
	}//i


	return 0;
}//main