#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

#define X first
#define Y second

int n, m, k;
int map[1000][1000];
int vis[1000][1000];

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
}

int bfs() {
	init();
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();

	cout << bfs();

	return 0;
}//main