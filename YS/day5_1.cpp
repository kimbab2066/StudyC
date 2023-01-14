#include <stdio.h>

// 1. 에라토스 CLEAR
// 2. 그냥 배열 CLEAR
int i, n, vis[10001];

int main() {
	//input
	scanf_s("%d", &n);
	// 짝수 중 유일한 소수는 2(이로 인해 i의 범위는 +=2로 홀수만)
	vis[0] = 2;
	int idx = 1;
	//logic
	for (i = 3; i <= n; i += 2) {//나눠보는 값의 범위는 고정(2 to n)
		//3 5 7 9일 때
		for (int j = 0; j < idx; j++) {
			// i의 값이 배열의 값으로 나눴을 때 나누어 떨어지는 경우
			if (i % vis[j] == 0) break;
			// 나누어 떨어지지 않는 경우(i % vis[j] != 0와 같음)
			else if (j == idx - 1) {
				vis[idx] = i;
				idx++;
				break;
			}
		}
	}
	//output
	for (i = 0; i < idx; i++) {
		printf("%d ", vis[i]);
	}

	return 0;
}//main