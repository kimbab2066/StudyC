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
	int cur = x;//index를 가져옴
	while (1) {
		vis[cur] = x; // 현재 인덱스에 X값을 집어 넣음
		cur = arr[cur]; // 다음 인덱스를 가져옴
		if (vis[cur] == x) { // 만약 다음 인덱스가 이미 방문한 적이 있는 경우
			while (vis[cur] != CYCLE) { // 이미 CYCLE의 형태를 뛰는지 여부 체크
				vis[cur] = CYCLE;
				cur = arr[cur];
			}
			return;
		}
		// 이전 방문에서 도달한 경우?
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
		// 초기화
		fill(vis + 1, vis + n + 1, 0);
		// 각 테스트케이스 초기값
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		// RUN
		for (int i = 1; i <= n; i++) {
			if (vis[i] == NOT) run(i);
		}
		// 결과 출력
		int result = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] != CYCLE) result++;
		}
		cout << result << "\n";
	}//while
}//main