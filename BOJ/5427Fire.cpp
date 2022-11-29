#include <iostream> 
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define X first
#define Y second

int arr[1004][1004];
int vis1[1004][1004];//fire
int vis2[1004][1004];//sg
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int T, W, H;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int t = 0; t<T;t++){
		bool out = false;
		queue<pair<int, int>>q = {}, q2 = {};
		cin >> W >> H;
		for (int i = 0; i < H; i++) {
			fill(vis1[i], vis1[i] + H, 0);
			fill(vis2[i], vis2[i] + H, 0);
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				char c;
				cin >> c;
				if (c == '#') arr[i][j] = -1;
				else {
					if (c == '*') {
						q.push({ i,j });
						vis1[i][j] = 1;
					}else if (c == '@') {
						q2.push({ i,j });
						vis2[i][j] = 1;
					}
					arr[i][j] = 0;
				}
			}
		}
		//fire
		while (!q.empty()) {
			auto v = q.front();
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nx = v.X + dx[d];
				int ny = v.Y + dy[d];
				// 범위를 벗어나는 경우
				if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
				// 방문했거나 벽인 경우
				if (vis1[nx][ny] || arr[nx][ny] == -1) continue;
				vis1[nx][ny] = vis1[v.X][v.Y] + 1;
				q.push({ nx,ny });
			}
		}
		//sg
		while ((!q2.empty()) && (!out)) {
			auto v = q2.front();
			q2.pop();
			for (int d = 0; d < 4; d++) {
				int nx = v.X + dx[d];
				int ny = v.Y + dy[d];
				// 범위를 벗어나는 경우(탈출)
				if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
					cout << vis2[v.X][v.Y] << '\n';
					out = true;
					break;
				}
				// 방문했거나 벽인 경우
				if (vis2[nx][ny] || arr[nx][ny] == -1) continue;
				if (vis1[nx][ny] != 0 && vis1[nx][ny] <= vis2[v.X][v.Y] + 1) continue;
				vis2[nx][ny] = vis2[v.X][v.Y] + 1;
				q2.push({ nx,ny });
			}
		}
		if (!out) cout << "IMPOSSIBLE"<<'\n';
	}//while
}