#include <stdio.h>
#include <string.h>

int main() {
	//input
	int st, a, b, c;
	while (1) {
		scanf_s("%d%d%d%d", &st, &a, &b, &c);
		int res = 1080;
		//logic
		//종료 조건
		if (st + a + b + c == 0)break;
		//1번째 비밀번호
		int cnt = 0;
		while (1) {
			if (a - st < st - a) {
				cnt = a - st;
				st = a;
			}
			else {
				if (st - a < 0)cnt = -(st - a);
				else cnt = st - a;
				st = a;
			}
			//종료 조건
			if (st == a) break;
		}//
		res += cnt / 40.0 * 360;
		//2번째 비밀번호
		cnt = 0;
		while (1) {
			if (b - st < st - b) {
				cnt = b - st;
				st = b;
			}
			else {
				if (st - b < 0)cnt = -(st - b);
				else cnt = st - b;
				st = b;
			}
			//종료 조건
			if (st == b)break;
		}
		res += cnt / 40.0 * 360;
		//3번째 비밀번호
		cnt = 0;
		while (1) {
			if (c - st < st - c) {
				cnt = c - st;
				st = c;
			}
			else {
				if (st - c < 0)cnt = -(st - c);
				else cnt = st - c;
				st = c;
			}
			//종료 조건
			if (st == c)break;
		}
		res += cnt / 40.0 * 360;
		//output
		printf("%d\n", res);
	}


	return 0;
}//main