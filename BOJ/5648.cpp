#include <iostream> 
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int arr[100000];

vector<long long> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	int n;
	string val;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		reverse(val.begin(), val.end());
		v.push_back(stoll(val));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) cout << v[i] << "\n";
	//logic

	//output

	return 0;
}//main