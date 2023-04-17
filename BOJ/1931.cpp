#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
struct tmp {
	int x, y;
};
vector <tmp> v;

int chk(tmp a, tmp b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int main(void) {
	//input
	scanf("%d", &n);
	int i, x, y;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		v.push_back({ x,y });
	}
	//logic
	sort(v.begin(), v.end(), chk);
	int cnt = 1;
	int idx = 0;
	for (i = 1; i < n; i++) {
		if (v[idx].y <= v[i].x) {
			cnt++;
			idx = i;
		}
	}
	//output
	printf("%d", cnt);

	return 0;
}//main