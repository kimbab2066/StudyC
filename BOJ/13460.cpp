#include <algorithm>
#include <iostream>

using namespace std;

char map[11][11];
int a[11][11], chk[11][11];
int q[101][2], d[101];
int n, m;
int st, ed, res, sw;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct tmp {
	int x, y;
}k[2];
int inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
void bfs() {
	while (st != ed) {
		int x = q[++ed][0];
		int y = q[ed][1];
		if (map[x][y] == 'O') { sw = 1; break; }
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			for (int i = 1; i <= 10; i++) {
				if (inRange(nx, ny) && chk[nx][ny] == 0 && map[nx][ny] != 'B') {
					chk[i * nx][i * ny] = 1;
					a[i * nx][i * ny] = a[x][y] + 1;
				}
				else break;
			}//i
		}//d
	}//w
}

int main(void) {
	//input
	cin >> n >> m;
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				k[0].x = i;
				k[0].y = j;
			}
			else if (map[i][j] == 'B') {
				k[1].x = i;
				k[1].y = j;
			}
		}
	}
	//logic
	st = ed = -1;
	q[++st][0] = k[0].x;
	q[st][1] = k[0].y;
	d[st] = 0;
	chk[k[0].x][k[0].y] = 1;
	bfs();
	//output
	if (sw == 1) cout << res;
	else cout << -1;

	return 0;
}//main