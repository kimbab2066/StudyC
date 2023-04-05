#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
/*
이진 탐색으로 최대 크기를 찾기.
mid를 중심으로 타일을 채울 수 있는지 확인.
if(1) then mid보다 큰 범위를 탐색.
else mid보다 작은 범위를 탐색.
탐색 범위가 좁아질 때까지 반복.
최대 크기가 n 이하인 범위 중에서 가장 작은 크기를 찾기.
*/
int n, m, k, x, res;
vector <int> v[1000001];

int chk(int mid) {
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (v[i][j] >= mid) cnt++;
			else cnt = 0;
			if (cnt >= mid) return 1;
		}
	}
	return 0;
}

int main() {
	//in
	scanf("%d%d%d%d", &n, &m, &k, &x);
	int i, a, b;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
	}
	//pro
	int l, r, mid;
	l = 1, r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) l = mid + 1;
		else r = mid - 1;
	}//w
	//out
	printf("%d", l);

	return 0;
}//main