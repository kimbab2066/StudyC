#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, res, a[15];
int top;
int chk(int lev) {
	for (int i = 0; i < lev; i++) {
		// 같은 열이거나 대각선인 경우
		if (a[i] == a[lev] || abs(a[lev] - a[i]) == lev - i) return false;
	}
	return true;
}
void dfs(int d) {
	//Base Condition
	if (d == n) { res++; return; }
	//Recur
	for (int j = 0; j < n; j++) {
		a[d] = j;
		if (chk(d)) dfs(d + 1);
	}
}//dfs

int main() {
	//input
	scanf_s("%d", &n);
	//logic
	dfs(0);
	//output
	printf("%d", res);

	return 0;
}//main