#include <iostream> 
#include <algorithm>
#include <string>
#include<queue>
#include<tuple>
using namespace std;

#define X first
#define Y second

int n, m, cnt = 0;
char map[1000][1000];
int vis[1000][1000][2];

queue<tuple<int, int, int>>Q;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfs() {
	//초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j][0] = vis[i][j][1] = -1;
		}
	}
	vis[0][0][0] = vis[0][0][1] = 1;

	Q.push({ 0,0,0 });

	//BFS
	while (!Q.empty()) {
		int x, y, broken;
		tie(x, y, broken) = Q.front();
		// 종료 조건
		if (x == n - 1 && y == m - 1) return vis[x][y][broken];
		Q.pop();
		int next = vis[x][y][broken] + 1;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			// 범위를 벗어나는 경우
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			// 안부수고 이동
			if (vis[nx][ny][broken] == -1 && map[nx][ny] == '0') {
				vis[nx][ny][broken] = next;
				Q.push({ nx,ny,broken });
			}
			// 부수기
			if (!broken && map[nx][ny] == '1' && vis[nx][ny][1] == -1) {
				vis[nx][ny][1] = next;
				Q.push({ nx,ny ,1 });
			}
		}
	}//while
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cout << bfs();
}//main