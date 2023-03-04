#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, num[101], res[101], vis[101];
int i, j, k;

void dfs(int st, int cur) {
	// 방문한 경우
	if (vis[cur]) {
		// 현재 값과 시작값이 같은 경우 결과 배열에 인덱스 추가
		if (cur == st) {
			res[k++] = st;
		}
	}
	else {
		// 방문체크, dfs이동
		vis[cur] = 1;
		dfs(st, num[cur]);
	}
}//dfs

int main() {
	//input
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &num[i]);
	}
	//logic
	for (i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(i, i);
	}
	//output
	printf("%d\n", k);
	for (i = 0; i < k; i++) {
		printf("%d\n", res[i]);
	}

	return 0;
}//main