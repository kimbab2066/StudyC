#include <iostream> 
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MX 20000

int t, n, m, i;
int a[MX], b[MX];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	cin >> t;
	//logic
	while (t--) {
		cin >> n >> m;
		vector <pair<int, int>>v(n + m);
		int val;
		int cnt = 0, res = 0;
		//a
		for (i = 0; i < n; i++) {
			cin >> val;
			v[i] = { val,0 };
		}
		//b
		for (i = n; i < n + m; i++) {
			cin >> val;
			v[i] = { val,1 };
		}
		//logic
		sort(v.begin(), v.end());

		for (i = 0; i < n + m; i++) {
			if (v[i].second == 0) {
				res += cnt;
			}
			else {
				cnt++;
			}
		}
		//output
		cout << res << "\n";
	}//ALL LOOP

	return 0;
}//main