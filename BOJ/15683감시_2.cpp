#include <iostream> 
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board1[8][8];
int board2[8][8];
int N, M;
vector<pair<int, int>> cctv;

bool range(int nx, int ny) {
	return nx < 0 || ny < 0 || nx >= N || ny >= M;
}

void update(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (range(x, y) || board2[x][y] == 6) return;
		if (board2[x][y] != 0) continue;
		board2[x][y] = -1;
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int mn = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back({ i,j });
			if (board1[i][j] == 0) mn++;
		}
	}
	for (int tmp = 0; tmp < (1 << 2 * cctv.size()); tmp++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				board2[i][j] = board1[i][j];
			}
		}
		int brute = tmp;
		for (int d = 0; d < cctv.size(); d++) {
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[d].X;
			int y = cctv[d].Y;
			if (board1[x][y] == 1) update(x, y, dir);
			else if (board1[x][y] == 2) {
				update(x, y, dir); update(x, y, dir + 2);
			}
			else if (board1[x][y] == 3) {
				update(x, y, dir); update(x, y, dir + 1);
			}
			else if (board1[x][y] == 4) {
				update(x, y, dir);
				update(x, y, dir + 1);
				update(x, y, dir + 2);
			}
			else if (board1[x][y] == 5) {
				update(x, y, dir);
				update(x, y, dir + 1);
				update(x, y, dir + 2);
				update(x, y, dir + 3);
			}
		}
		int val = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board2[i][j] == 0) val++;
			}
		}
		mn = min(val, mn);
	}
	cout << mn;
}//main