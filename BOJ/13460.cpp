#include <algorithm>
#include <iostream>

using namespace std;

char map[11][11];
int a[11][11], b[11][11];
int q[101][2];
int n, m;
int st, ed, res, sw;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
struct tmp {
	int x, y;
}k[3];
int inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs(tmp k[]) {
	//Q초기화
	st = ed = -1;
	q[++st][0] = k[0].x;
	q[st][1] = k[0].y;

	while (st != ed) {
		//Q에서 값 빼기
		int x = q[++ed][0];
		int y = q[ed][1];
		//종료 조건
		if (map[x][y] == 'O') break;
		//Red or Blue
		int NM = n > m ? n : m;
		if (map[i][j] == 'R') {
			for (int d = 0; d < 4; d++) {
				for (int k = 1; k <= NM; k++) {
					int nx = x + dx[d] * k;
					int ny = y + dy[d] * k;
					if (inRange(nx, ny) && map[nx][ny] != '#' && a[nx][ny] == 0) {
						q[++st][0] = nx;
						q[st][1] = ny;
						a[nx][ny] = a[x][y] + 1;
					}
					else break;
				}
			}//d
		}
	}//w
}//bfs

int main(void) {
	//input
	cin >> n >> m;
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//logic
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (map[i][j] == 'R') { k[0].x = i; k[0].y = j; }
			else if (map[i][j] == 'B') { k[1].x = i; k[1].y = j; }
			else if (map[i][j] == 'O') { k[2].x = i; k[2].y = j; }
		}
	}
	bfs(k);
	//output
	cout << res;

	return 0;
}//main