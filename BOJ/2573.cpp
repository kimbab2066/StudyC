#include <iostream> 
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m, year;
int map[300][300];
int vis[300][300];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void input() {
	cin >> n >> m;
	// input
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void melting() {
	int zero[300][300] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) continue;//0이면 녹을 필요가 없음
			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (check(nx, ny) && map[nx][ny] == 0)zero[i][j]++;
			}
		}
	}
	// ?잘 모르겠음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = max(0, map[i][j] - zero[i][j]);
		}
	}
}

//범위 체크(continue조건에 역을 취하면 됨)
bool check(int i, int j) {
	return i >= 0 && j >= 0 && i < n&& j < m;
}

//초기화용
void init() {
	for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
}

void bfs(int x, int y) {
	queue<pair<int, int>> Q;
	Q.push({ x,y });

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (check(nx, ny) && map[nx][ny]!=0 && !vis[nx][nx]) {
				Q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
	}
}//bfs

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	while (1) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis[i][j] && map[i][j] != 0) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt == 0) {
			cout << 0;
			return 0;
		}
		else if (cnt == 2) {
			cout << year;
			return 0;
		}
		year++;

		melting();// 녹이기
		init();// 방문 초기화

	}//while
	cout << year;

	return 0;
}//main