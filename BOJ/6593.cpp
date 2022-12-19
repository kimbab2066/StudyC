#include <iostream> 
#include <algorithm>
#include <string>
#include <tuple>
#include<queue>

using namespace std;
const int MX = 31;

int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int L, R, C;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> L >> R >> C;
		// ���� ����
		if (L == 0 && R == 0 && C == 0) break;
		queue<tuple<int, int, int>> q;
		char board[MX][MX][MX];
		int dist[MX][MX][MX];
		bool escape = false;
		// �ʱⰪ
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) fill(dist[i][j], dist[i][j] + C, 0);
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {
						q.push({ i, j, k });
						dist[i][j][k] = 0;
					}
					else if (board[i][j][k] == '.') dist[i][j][k] = -1;
				}//C
			}//R
		}//L
		//bfs
		while (!q.empty()) {
			// true�� ����
			if (escape) break;
			auto cur = q.front(); q.pop();
			int curZ, curX, curY;
			tie(curZ, curX, curY) = cur;
			for (int d = 0; d < 6; d++) {
				int nz = curZ + dz[d];
				int nx = curX + dx[d];
				int ny = curY + dy[d];
				// ������ ����� ���
				if (nx < 0 || ny < 0 || nz < 0 || nz >= L || nx >= R || ny >= C) continue;
				// ���̰ų� �湮�� ���
				if (board[nz][nx][ny] = '#' || dist[nz][nx][ny] > 0) continue;

				dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
				if (board[nz][nx][ny] == 'E') {
					cout << "Escaped in " << dist[nz][nx][ny] << " minute(s).\n";
					escape = true;
					break;
				}
				q.push({ nz,nx,ny });
			}
		}
		// ���⿡ �����ϸ� Ż���� �� ������ q�� ����ְ� ����϶�� �ǹ�
		while (!q.empty()) q.pop();
		if (!escape) cout << "Trapped!\n";
	}//while
}//main