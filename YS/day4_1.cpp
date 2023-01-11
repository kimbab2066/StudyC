#include <stdio.h>

// 책 페이지 N, 참가 소 K
// k줄에 speed, time, rest가 주어짐
// 각 케이스별로 결과값을 출력해라

int main() {
	//input
	int n, k, s, t, r, tmp, cnt, result;
	scanf_s("%d%d", &n, &k);
	//logic
	for (int i = 0; i < k; i++) {
		scanf_s("%d%d%d", &s, &t, &r);
		tmp = n, cnt = 0, result = 0;
		while (1) {
			//증감식(시간)
			cnt++, result++;
			tmp -= s;
			//종료 조건
			if (tmp <= 0) break;
			if (cnt == t) result += r, cnt = 0;
		}
		printf("%d\n", result);
	}

	//output

	return 0;
}//main