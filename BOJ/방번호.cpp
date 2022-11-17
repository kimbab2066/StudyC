#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

int freq[10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 1;
	cin >> n;
	while (n) {
		freq[n % 10]++;
		n/= 10;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9)continue;
		ans = max(ans, freq[i]);
	}
	ans = max(ans, (freq[6] + freq[9] + 1) / 2);
	cout << ans;
}