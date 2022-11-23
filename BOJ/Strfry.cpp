#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int arr[26] = {};
		string a, b;
		cin >> a >> b;
		for (auto c : a) arr[c - 'a']++;
		for (auto c : b) arr[c - 'a']--;

		bool isPos = true;
		for (int i : arr) {
			if (i != 0) isPos = false;
		}
		if (isPos) cout << "Possible\n";
		else cout << "Impossible\n";
	}
}