#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int arr[8];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	// �� �̷��� �ϴ°��� ������ �غ���.
	// �ߺ��� �����ϴٴ°� ����Ʈ��.
	// �ߺ��� �����ϱ⿡ ���� �湮 ���θ� üũ�� ������ ���ٴ� �Ҹ�.
	for (int i = 1; i <= n; i++) {
		arr[k] = i; // �� ���ϱ�
		func(k + 1); // ���� ��
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}