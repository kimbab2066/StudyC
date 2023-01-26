#include <stdio.h>
#include <string.h>

int n, s;
int i, j;
int cnt, idx;
char res[30];

bool d() {
	if (res[0] == res[idx - 1] && res[0] == '0') return false;
	for (int i = 0; i <= idx / 2; i++) {
		if (res[i] != res[idx - 1 - i]) return false;
	}
	return true;
}

void palin(int a) {
	cnt = 0;
	//2~10진수 변환
	for (j = 2; j <= 10; j++) {
		int k = a;
		idx = 0;
		while (1) {
			res[idx++] = (k % j) + '0';
			k /= j;
			//종료 조건
			if (k == 0)break;
		}
		//회귀수 판별
		if (d())cnt++;
	}//j
}//palin

int main() {
	//input
	scanf_s("%d%d", &n, &s);
	for (i = s + 1;; i++) {
		palin(i);
		if (cnt >= 2) { printf("%d\n", i); n--; };
		// 종료 조건
		if (n == 0)break;
	}
	//logic

	//output

	return 0;
}//main