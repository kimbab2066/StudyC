#include <stdio.h>
#include <string.h>

//2진수,10진수 둘 다 회귀수일 때 print
char a[20];
int cnt;

bool d(char a[]) {
	int len = strlen(a);
	if (a[0] == a[len - 1] && a[0] == '0')return false;
	for (int i = 0; i < len / 2; i++) {
		if (a[i] != a[len - i])return false;
	}
	return true;
}//d

void convert(int n) {
	cnt = 0;
	for (int i = 2; i <= 10; i++) {
		// 1.2~10진수 변환
		int k = n;
		int idx = 0;
		while (1) {
			if (i > 9) {
				if (k % i <= 9)a[idx++] = (k % i) + '0'; //아스키코드 숫자
				else a[idx++] = k % i + 'A' - 10; //아스키코드 A~
			}
			else {
				a[idx++] = k % i + '0';
			}
			k /= i;
			if (k == 0) break;
		}
		// 회귀수 판별
		if (d(a)) cnt++;
	}//i
}//convert

int main() {
	//input
	int n, s;
	scanf_s("%d%d", &n, &s);
	int i, j;
	//logic
	for (i = s + 1;; i++) {
		convert(i);
		//output
		if (cnt >= 2) printf("%d\n", i), n--;
		if (n == 0)break;
	}

	return 0;
}//main