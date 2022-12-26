#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int a[1'000'000], b[1'000'000], c[2'000'000];

void merge() {
	int idxA = 0, idxB = 0;
	for (int i = 0; i < n+m; i++) {
		if (idxA == n)c[i] = b[idxB++];
		else if (idxB == m) c[i] = a[idxA++];
		else if (a[idxA] <= b[idxB]) c[i] = a[idxA++];
		else c[i] = b[idxB++];
	}
}//

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	merge();
	for (int i = 0; i < n + m; i++)cout << c[i] << " ";
}//main