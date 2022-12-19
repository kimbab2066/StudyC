#include <iostream> 
#include <algorithm>
#include <string>
#include<tuple>
#include<queue>
using namespace std;
const int MX = 31;
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int l, r, c;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> l >> r >> c; \
			// 종료 조건
			if (l == 0 && r == 0 && c == 0) break;
		queue<tuple<int, int, int>> Q;
		char board[MX][MX][MX];
		int dist[MX][MX][MX];
		bool escape = false;

		// 초기값
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) fill(dist[i][j], dist[i][j] + c, 0);
		}

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {
						Q.push({ i,j,k });
						dist[i][j][k] = 0;
					}
					else if (board[i][j][k] == '.') dist[i][j][k] = -1;
				}//C
			}//R
		}//L
		//bfs
		while (!Q.empty()) {
			//true면 탈출 성공
			if (escape) break;
			auto cur = Q.front(); Q.pop();
			int curZ, curX, curY;
			tie(curZ, curX, curY) = cur;
			for (int dir = 0; dir < 6; dir++) {
				int nz = curZ + dz[dir];
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				// 범위를 벗어나는 경우
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
				// 벽이거나 방문한 경우
				if (board[nz][nx][ny] == '#' || dist[nz][nx][ny] > 0) continue;

				dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
				if (board[nz][nx][ny] == 'E') {
					cout << "Escaped in " << dist[nz][nx][ny] << " minute(s).\n";
					escape = true;
					break;
				}
				Q.push({ nz,nx,ny });
			}
		}
		// 여기에 도달하면 탈출할 수 없으니 q를 비워주고 출력하라는 의미
		while (!Q.empty()) Q.pop();
		if (!escape) cout << "Trapped!\n";
	}
}
