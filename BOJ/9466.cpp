#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

#define MAX 100'000

int n;
int arr[MAX + 1];
int vis[MAX + 1];

const int NOT = 0;
const int CYCLE = -1;

void run(int x) {
	int cur = x;//index�� ������
	while (1) {
		vis[cur] = x; // ���� �ε����� X���� ���� ����
		cur = arr[cur]; // ���� �ε����� ������
		if (vis[cur] == x) { // ���� ���� �ε����� �̹� �湮�� ���� �ִ� ���
			while (vis[cur] != CYCLE) { // �̹� CYCLE�� ���¸� �ٴ��� ���� üũ
				vis[cur] = CYCLE;
				cur = arr[cur];
			}
			return;
		}
		// ���� �湮���� ������ ���?
		else if (vis[cur] != NOT) return;
	}
}//run

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		// �ʱ�ȭ
		fill(vis + 1, vis + n + 1, 0);
		// �� �׽�Ʈ���̽� �ʱⰪ
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		// RUN
		for (int i = 1; i <= n; i++) {
			if (vis[i] == NOT) run(i);
		}
		// ��� ���
		int result = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] != CYCLE) result++;
		}
		cout << result << "\n";
	}//while
}//main