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
		//빈도 체크용? ㄴㄴ 같은 값인지의 여부
		bool check = false;
		for (auto& a : v) {
			if (a.second == val) {// 입력된 값과 vector의 second값이 같은 경우(같은 숫자인 경우)
				check = true; // 값이 같음을 의미하는 true로 바꿔주고
				a.first++; // 빈도수를 증가시켜 준다.
				break; //빠져나오셈
			}
		}
		// 중복 값이 없는 경우 빈도,값의 형태로 1,val을 넣어준다.
		if (!check) v.push_back({ 1,val });
	}
	//logic
	// 정렬하되 기준을 정의해준다(빈도수가 큰 경우 true)
	stable_sort(v.begin(), v.end(), cmp);
	//output
	for (pair <int, int>x : v) {
		//빈도수를 하나씩 줄여가면서 second의 값을 출력해준다.
		//2 1 2 1 2의 경우 v에  (3,2) (2,1)이 들어가 있을 거임 -> 정확했음 
		while (x.first--) cout << x.second << " ";
	}
	return 0;
}//main