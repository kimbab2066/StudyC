#include <iostream> 
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;
int board1[8][8];
int board2[8][8];
vector<pair<int, int>>cctv;

bool range(int a, int b) {
	return a < 0 || b < 0 || a >= N || b >= M;
}

void update(int x, int y, int dir) {
	dir %= 4;
	while (true) {
		x += dx[dir];
		y += dy[dir];
		// 범위를 벗어나거나 벽인 경우
		if (range(x, y) || board2[x][y] == 6)return;
		// 빈칸이 아닌 경우
		if (board2[x][y] != 0) continue;
		board2[x][y] = -1;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int min_size = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back({ i,j });
			if (board1[i][j] == 0) min_size++;
		}
	}
	// 4의 cctv.size()제곱을 의미하는 건 2 * cctv.size()
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				board2[i][j] = board1[i][j];
			}
		}
		// 아래 연산이 반복되기에 복사해서 사용
		// 상 = 0, 하 = 2, 좌 = 1, 우 = 3인 경우
		// + 2를 하고 %4가 되니 0,2 1,3이 된다
		// 3번 케이스에서 + 1을 해주면  상좌, 좌하, 하우, 우상과 같은 방식으로 반복되기에 정답
		// 4번 케이스에서 + 1과 + 2는 상좌하, 좌하우, 하우상, 우상좌와 같은 방식으로 반복되기에 정답
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
				if (board2[i][j] == 0)val++;
			}
		}
		min_size = min(min_size, val);
	}
	cout << min_size;
}//main