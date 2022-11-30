#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int arr[10];
bool used[10];

void func(int k) {//k���� �� ����
	if (k == m) {//m�� ��� ������ ���
		for (int i = 0; i < m; i++) {//����ص� �迭 ���
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {//1~n���� ��
		if (!used[i]) {//i�� ������ ���� ���
			arr[k] = i; //k��°�� ���� ����
			used[i] = 1;// ��� ǥ��
			func(k + 1);//���� �� ���Ϸ� ���
			used[i] = 0;// ��� ����
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}