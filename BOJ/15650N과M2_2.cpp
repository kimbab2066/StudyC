#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

int n,m;
int arr[9];
bool vis[9];
	
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	int st = 1;
	// 이부분 이해 안됨
	if (k != 0) st = arr[k - 1] + 1;
	for (int i = st; i <= n; i++) {
		if (!vis[i]) {
			arr[k] = i;
			vis[i] = 1;
			func(k + 1);
			vis[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}