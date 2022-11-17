#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;
int arr[2000001] = {};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, val, cnt = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> val;
		arr[val]++;
	}
	cin >> x;

	for (int i = 1; i < (x+1)/2; i++) {
		if (arr[i] == 1 && arr[x - i] == 1)cnt++;
	}
	cout << cnt;
}