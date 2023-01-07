#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

int n, s[10], w[10];
int mx = 0, cnt = 0;// 깨진 계란의 수

void func(int k) {
	// base condition
	if (k == n) {
		//update mx
		mx = max(mx, cnt);
		return;
	}
	// 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없는 경우
	// s[k]는 현재 집고 있는 계란, cnt는 n-1개를 집어야 하니 갯수 맞춰줌
	if (s[k] <= 0 || cnt == n - 1) {
		func(k + 1);
		return;
	}
	// backtracking
	for (int i = 0; i < n; i++) {
		// 순서가 중복되거나 깨져 있는 경우
		if (k == i || s[i] <= 0) continue;
		s[k] -= w[i];
		s[i] -= w[k];
		if (s[k] <= 0) cnt++;
		if (s[i] <= 0) cnt++;
		func(k + 1);
		// 값 되돌리기
		if (s[k] <= 0) cnt--;
		if (s[i] <= 0) cnt--;
		s[k] += w[i];
		s[i] += w[k];
	}
} //func

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i] >> w[i];
	//logic
	func(0);
	//output
	cout << mx;
	return 0;
}//main