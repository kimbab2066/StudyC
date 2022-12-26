#include <iostream> 
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int MX = 2'000'000, HALF = MX / 2;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<bool> isnum(MX + 2);

	int n,t;

	cin >> n;
	while (n--) {
		cin >> t;
		isnum[t + HALF] = true;
	}
	for (int i = MX; i >= 0; i--) {
		if (isnum[i]) cout << i - HALF << "\n";
	}

}//main