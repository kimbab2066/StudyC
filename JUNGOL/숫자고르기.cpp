#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int num[101], res[101];
int n, cnt;

int main() {
	//input
	scanf_s("%d", &n);
	int i, j, k = 0;
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &num[i]);
	}
	//logic
	for (i = 1; i <= n; i++) {
		int idx = i, val = 0;
		j = 0;
		while (1) {
			// index체크
			j++;
			val = num[idx];
			// 인덱스와 값이 같은 경우 종료
			if (i == val) break;
			// 아니면 인덱스를 val로 바꿔주기
			else idx = val;
			// 범위를 벗어나면 종료
			if (j > n) break;
		}
		// 현재 인덱스와 val값이 같으면 결과 배열에 인덱스 저장, 개수++
		if (i == val) res[k++] = i, cnt++;
	}
	//output
	printf("%d\n", cnt);
	for (i = 0; i < k; i++) {
		printf("%d\n", res[i]);
	}

	return 0;
}//main