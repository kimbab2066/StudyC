#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

int n, m, num[10], arr[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << num[arr[i]] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[k] = i;
		func(k + 1);
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