#include <iostream> 
#include <algorithm>
#include <string>

// DP(Dynamic Programing)
// 여러 개의 하위 문제를 먼저 푼 후 그 결과를 쌓아올려 주어진 문제를 해결하는 알고리즘

// DP푸는 과정
// 1. 테이블 정의
// 2. 점화식 찾기
// 3. 초기값 정하기

using namespace std;

int dp[11];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//logic
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	//input
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		//output
		cout << dp[n] << "\n";
	}

	return 0;
}//main