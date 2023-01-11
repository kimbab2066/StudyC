#include <iostream> 
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>>v; // cnt,num

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	int n, c, val;

	cin >> n >> c;
	//loop
	for (int i = 0; i < n; i++) {
		cin >> val;
		//�� üũ��? ���� ���� �������� ����
		bool check = false;
		for (auto& a : v) {
			if (a.second == val) {// �Էµ� ���� vector�� second���� ���� ���(���� ������ ���)
				check = true; // ���� ������ �ǹ��ϴ� true�� �ٲ��ְ�
				a.first++; // �󵵼��� �������� �ش�.
				break; //����������
			}
		}
		// �ߺ� ���� ���� ��� ��,���� ���·� 1,val�� �־��ش�.
		if (!check) v.push_back({ 1,val });
	}
	//logic
	// �����ϵ� ������ �������ش�(�󵵼��� ū ��� true)
	stable_sort(v.begin(), v.end(), cmp);
	//output
	for (pair <int, int>x : v) {
		//�󵵼��� �ϳ��� �ٿ����鼭 second�� ���� ������ش�.
		//2 1 2 1 2�� ��� v��  (3,2) (2,1)�� �� ���� ���� -> ��Ȯ���� 
		while (x.first--) cout << x.second << " ";
	}
	return 0;
}//main