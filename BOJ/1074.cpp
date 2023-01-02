#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

int n, r, c;

void input() {
	cin >> n >> r >> c;
}

int recur(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1 << (n - 1);
	if (n < half && c < half) return recur(n - 1, r, c);
	else if (n < half && c >= half) return half * half + recur(n - 1, r, c - half);
	else if (n >= half && c < half) return 2 * half * half + recur(n - 1, r - half, c);
	return 3 * half * half + recur(n - 1, r - half, c - half);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	cout << recur(n, r, c);

	return 0;

}//main