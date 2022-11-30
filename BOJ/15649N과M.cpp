#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int arr[10];
bool used[10];

void func(int k) {//k까지 수 선택
	if (k == m) {//m개 모두 선택한 경우
		for (int i = 0; i < m; i++) {//기록해둔 배열 출력
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {//1~n까지 수
		if (!used[i]) {//i가 사용되지 않은 경우
			arr[k] = i; //k번째의 수로 선택
			used[i] = 1;// 사용 표시
			func(k + 1);//다음 수 정하러 재귀
			used[i] = 0;// 사용 해제
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}