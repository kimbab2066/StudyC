#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct tmp {
	int a, b;
};
vector <tmp> v;
int n;
int chk(tmp x, tmp y) {
	return x.b < y.b;
}
int main() {
	//input
	scanf("%d", &n);
	int i, x, y;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		v.push_back({ x,y });
	}
	//logic
	sort(v.begin(), v.end(), chk);
	int maxx = -30001, cnt = 0;
	for (i = 0; i < n; i++) {
		if (maxx < v[i].a) {
			maxx = v[i].b;
			cnt++;
		}
	}
	//output
	printf("%d", cnt);

	return 0;
}//main