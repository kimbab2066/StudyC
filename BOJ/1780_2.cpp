#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;
int n;
int map[2200][2200];
int result[3];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

bool check(int x, int y, int z) {
	for (int i = x; i < x + z; i++) {
		for (int j = y; j < y + z; j++) {
			if (map[i][j] != map[x][y])return false;
		}
	}
	return true;
}

void logic(int x, int y, int z) {
	if (check(x, y, z)) {
		result[map[x][y] + 1]++;
		return;
	}
	int n = z / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			logic(x + i * n, y + j * n, n);
		}
	}
}


void output() {
	for (int i = 0; i < 3; i++) cout << result[i] << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	logic(0, 0, n);
	output();
}//main