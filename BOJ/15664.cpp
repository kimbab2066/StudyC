#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

int n, m, arr[10], num[10];
bool used[10];

void func(int k, int st) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	int tmp = 0;
	for (int i = st; i < n; i++) {
		if (!used[i] && tmp != num[i]) {
			used[i] = 1;
			arr[k] = num[i];
			tmp = arr[k];
			func(k + 1, i);
			used[i] = 0;
		}
	}
} //func

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	//output
	func(0, 0);

	return 0;
}//main