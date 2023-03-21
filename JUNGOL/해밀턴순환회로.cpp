#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, minVal = 0x7fffffff, a[14][14], vis[14];

void back(int r, int d, int minn) {
	//Base Condition
	if (d >= n) {
		if (a[r][1] && minVal > minn + a[r][1]) minVal = minn + a[r][1];
		return;
	}
	//Recursion
	for (int i = 2; i <= n; i++) {
		if (minn + a[r][i] > minVal) continue;
		if (vis[i] == 0 && a[r][i] != 0) {
			vis[i] = 1;
			back(i, d + 1, minn + a[r][i]);
			vis[i] = 0;
		}
	}

}//back

int main() {
	//input
	scanf_s("%d", &n);
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	//logic
	vis[1] = 1;
	// 무조건 i는1에서 시작하니 방문체크하고 depth도 1증가시켜서 시작
	back(1, 1, 0); //row depth min
	//output
	printf("%d", minVal);

	return 0;
}//main