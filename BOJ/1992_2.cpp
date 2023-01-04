#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

#define MX 64

int n, map[MX][MX];

bool check(int x, int y, int z) {
	for (int i = x; i < x + z; i++) {
		for (int j = y; j < y + z; j++) {
			if (map[i][j] != map[x][y]) return false;
		}
	}
	return true;
}

void func(int x, int y, int z) {
	if (check(x, y, z)) {
		cout << map[x][y];
		return;
	}
	else {
		cout << "(";
		int n = z / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				func(x + i * n, y + j * n, n);
			}
		}
		cout << ")";
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	//logic + output
	func(0, 0, n);

}//main