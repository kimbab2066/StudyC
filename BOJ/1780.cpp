#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

int n;
int map[2200][2200];
int cnt[3];//-1,0,1

bool check(int x, int y, int z) {
	for (int i = x; i < x + z; i++) {
		for (int j = y; j < y + z; j++) {
			if (map[x][y] != map[i][j]) return false;
		}
	}
	return true;
}

void solve(int x, int y, int z) {
	if (check(x, y, z)) {
		cnt[map[x][y] + 1]++;
		return;
	}
	int n = z /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + i * n, y + j * n, n);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	solve(0, 0, n);
	for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";

}//main