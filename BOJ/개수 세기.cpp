#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

int freq[201];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,val,v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		freq[val + 100]++;
	}
	cin >> v;
	cout << freq[v + 100];
}