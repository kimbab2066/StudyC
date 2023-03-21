#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v;
int n, res, cnt, a[26][26], vis[26][26];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int chk(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void dfs(int i, int j) {
	a[i][j] = 0;
	for (int d = 0; d < 4; d++) {
		int nx = i + dx[d];
		int ny = j + dy[d];
		if (chk(nx, ny) && a[nx][ny] == 1) {
			a[nx][ny] = 0;
			cnt++;
			dfs(nx, ny);
		}
	}
}//bfs

void in() {
	scanf_s("%d", &n);
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf_s("%1d", &a[i][j]);
		}
	}
}

void pro() {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (a[i][j] == 1) {
				res++;
				cnt = 1;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
}

void out() {
	printf("%d\n", res);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
}

int main() {
	in();
	pro();
	out();

	return 0;
}//main