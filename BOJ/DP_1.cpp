#include <iostream> 
#include <algorithm>
#include <string>

// DP(Dynamic Programing)
// ���� ���� ���� ������ ���� Ǭ �� �� ����� �׾ƿ÷� �־��� ������ �ذ��ϴ� �˰���

// DPǪ�� ����
// 1. ���̺� ����
// 2. ��ȭ�� ã��
// 3. �ʱⰪ ���ϱ�

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