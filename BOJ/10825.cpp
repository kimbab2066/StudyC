#include <iostream> 
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

// �� �� ��
// �ι� �ٽ� �Ⱥ��� ��(�� ���� ����)

using namespace std;

int n;
string name;
int k, e, m;

vector<tuple<int, int, int, string>> v;

bool cmp(const tuple<int, int, int, string>& a, const tuple<int, int, int, string>& b) {
	// ��� ������ ���� ��(��������)
	if (get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b)) return get<3>(a) < get<3>(b);
	//����,��� ������ ������ ����(��������)
	else if (get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b)) return get<2>(a) > get<2>(b);
	//��� ������ ��� ����(��������)
	else if (get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
	//���� �� �ƴϸ� ���� ��������
	return get<0>(a) > get<0>(b);
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> k >> e >> m;
		v.push_back({ k,e,m,name });
	}
	//logic
	sort(v.begin(), v.end(), cmp);
	//output
	for (int i = 0; i < n; i++) {
		tie(k, e, m, name) = v[i];
		cout << name << "\n";
	}

	return 0;
}//main