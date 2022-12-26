#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

#define MX 100'000

const int NOT = 0;
const int YES = -1;

int n;
int arr[MX + 1];
int vis[MX + 1];


// ?
void run(int x) {
	int cur = x; //start
	while (1) {
		vis[cur] = x;
		cur = arr[cur];
		if (vis[cur] == x) {
			while (vis[cur] != YES) {
				vis[cur] = YES;
				cur = arr[cur];
			}
			return;
		}
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
		//초기화
		fill(vis, vis + n + 1, 0);

		//초기값
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i] == NOT) run(i);
		}

		//output
		int result = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] != YES)result++;
		}
		cout << result << "\n";

	}//while
}//main