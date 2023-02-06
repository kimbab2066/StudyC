#include <stdio.h>
#include <string.h>

int n, k;
int dab[31];

// 1의 개수, 0의 개수, 깊이
void pro(int a, int b, int d) {
	//가지치기(사용 할 수 있는 1,0의 개수를 초과하는 경우)
	if (a < 0 || b < 0) return;
	//종료 조건(답을 찾은 경우)
	if (d == n) {
		for (int i = 0; i < n; i++) {
			printf("%d", dab[i]);
		}
		printf("\n");
		return;
	}
	//1적용
	dab[d] = 1;
	pro(a - 1, b, d + 1);
	//0적용
	dab[d] = 0;
	pro(a, b - 1, d + 1);
}

int main() {
	//input
	scanf_s("%d%d", &n, &k);
	//logic
	pro(k, n - k, 0);//1의 개수, 0의 개수,깊이
	//output

	return 0;
}//main