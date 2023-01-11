#include <iostream> 
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>>v;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	int n, c, num;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> num;
		bool check = false;
		for (pair<int, int>& a : v) {
			if (a.second == num) {
				check = true;
				a.first++;
				break;
			}
		}
		if (!check) v.push_back({ 1,num });
	}
	//logic
	sort(v.begin(), v.end(), cmp);
	//output
	for (pair<int, int>x : v) {
		while (x.first--) cout << x.second << " ";
	}

	return 0;
}//main