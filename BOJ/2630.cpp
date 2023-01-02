#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

int n, arr[130][130], result[2];

bool check(int x, int y, int z) {
	for (int i = x; i < x + z; i++) {
		for (int j = y; j < y + z; j++) {
			if (arr[x][y] != arr[i][j]) return false;
		}
	}
	return true;
}

void func(int x, int y, int z) {
	if (check(x, y, z)) result[arr[x][y]]++;
	else {
		int n = z / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				func(x + i * n, y + j * n, n);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	//logic
	func(0, 0, n);
	//output
	for (int i = 0; i < 2; i++) cout << result[i] << "\n";

	return 0;
}//main