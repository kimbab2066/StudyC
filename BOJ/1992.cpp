#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

int n, map[64][64];


void func(int x, int y, int z) {
	if (z == 1) {
		cout << map[x][y];
		return;
	}
	bool zero = true, one = true;
	for (int i = x; i < x + z; i++) {
		for (int j = y; j < y + z; j++) {
			if (map[i][j]) zero = false;
			else one = false;
		}
	}
	if (zero) cout << 0;
	else if (one) cout << 1;
	else {
		cout << "(";
		func(x, y, z / 2);//���� ��
		func(x, y + z / 2, z / 2);//������ ��
		func(x + z / 2, y, z / 2);//���� �Ʒ�
		func(x + z / 2, y + z / 2, z / 2);//������ �Ʒ�
		cout << ")";
	}
	return;
}//func

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;//�׳� 0 1 �̷��� �ҷ��� �� ����.
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	//logic + output
	func(0, 0, n);

}//main