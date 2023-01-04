#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

int n, m, arr[10],num[10];
bool used[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << num[arr[i]] << " ";
		}
		cout << "\n";
		return;
	}
	int st = 0;
	if (k > 0) st = arr[k - 1] + 1;
	for (int i = st; i < n; i++) {
		if (!used[i]) {
			arr[k] = i;
			used[i] = 1;
			func(k + 1);
			used[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	//output
	func(0);

	return 0;
}//main