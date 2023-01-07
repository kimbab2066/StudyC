#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

int n, s[10], w[10];
int mx = 0, cnt = 0;// ���� ����� ��

void func(int k) {
	// base condition
	if (k == n) {
		//update mx
		mx = max(mx, cnt);
		return;
	}
	// �տ� �� ����� �����ų� ������ ���� �ٸ� ����� ���� ���
	// s[k]�� ���� ���� �ִ� ���, cnt�� n-1���� ����� �ϴ� ���� ������
	if (s[k] <= 0 || cnt == n - 1) {
		func(k + 1);
		return;
	}
	// backtracking
	for (int i = 0; i < n; i++) {
		// ������ �ߺ��ǰų� ���� �ִ� ���
		if (k == i || s[i] <= 0) continue;
		s[k] -= w[i];
		s[i] -= w[k];
		if (s[k] <= 0) cnt++;
		if (s[i] <= 0) cnt++;
		func(k + 1);
		// �� �ǵ�����
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