#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

int n, arr[2200][2200], result[3];

bool check(int x, int y, int z) {
	for (int i = x; i < x + z; i++) {
		for (int j = y; j < y + z; j++) {
			// ~~绢录备 历录备老 锭 return false;
			if (arr[x][y] != arr[i][j]) return false;
		}
	}
	return true;
} //check

void func(int x, int y, int z) {
	if (check(x, y, z)) result[arr[x][y] + 1]++;
	else {
		int n = z / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				func(x + i * n, y + j * n, n);
			}
		}
	}
} //func

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
	for (int i = 0; i < 3; i++) cout << result[i] << "\n";
	return 0;
}//main