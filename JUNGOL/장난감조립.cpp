#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, res[101];
struct tmp {
	int y, k;
}tt[101];
vector<tmp> v[101];

void recur(int t) {
	//Base Condition
	if (v[t].size() == 0) {
		res[t]++;
		return;
	}
	//Recursion
	for (int i = 0; i < v[t].size(); i++) {
		for (int j = 0; j < v[t][i].k; j++) {
			recur(v[t][i].y);
		}
	}
}//recur

int main() {
	//input
	scanf_s("%d%d", &n, &m);
	int i, x, y, k;
	for (i = 1; i <= m; i++) {
		scanf_s("%d%d%d", &x, &y, &k);
		v[x].push_back({ y,k });
	}
	//logic
	recur(n);
	//output
	for (i = 1; i <= 100; i++) {
		if (res[i]) printf("%d %d\n", i, res[i]);
	}

	return 0;

}//main