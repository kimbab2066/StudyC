#include <stdio.h>

//
int n, cnt;
int num[101];//값
int result[101];//결과
// k 는 결과 배열에 사용
int i, j, k;

int main() {
	//input
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &num[i]);
	}
	//logic
	for (i = 1; i <= n; i++) {
		int idx = i, val = 0, j = 0;
		while (1) {
			j++;//시간제한을 위한 증감식
			val = num[idx];
			// 종료 조건
			if (i == val) break;
			else idx = val;
			// 종료 조건2
			if (j > n)break;
		}
		//결과값 업데이트(결국 사이클이 돌 때 결과를 업데이트 하라는 의미임)
		if (i == val)result[k++] = i, cnt++;
	}

	//output
	printf("%d\n", cnt);
	for (i = 0; i < k; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}//main