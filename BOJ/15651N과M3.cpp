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
	// 왜 이렇게 하는건지 생각을 해보자.
	// 중복이 가능하다는게 포인트임.
	// 중복이 가능하기에 굳이 방문 여부를 체크할 이유가 없다는 소리.
	for (int i = 1; i <= n; i++) {
		arr[k] = i; // 수 정하기
		func(k + 1); // 들어가면 끝
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}