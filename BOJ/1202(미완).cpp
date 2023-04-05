#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, c;
struct tmp {
	long long a, b;
};
int chk(tmp x, tmp y) {
	return x.b > y.b;
}
int chk2(int x, int y) {
	return x > y;
}
vector <tmp> v;
vector <int> v2;

int main(void) {
	//input
	scanf("%d%d", &n, &k);
	int i, j, x, y, z;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		v.push_back({ x,y });
	}
	for (i = 0; i < k; i++) {
		scanf("%d", &z);
		v2.push_back(z);
	}

	sort(v.begin(), v.end(), chk);
	sort(v2.begin(), v2.end(), chk2);
	//logic
	long long res = 0;
	int idx = 0;
	for (i = 0; i < n; i++) {
		long long sum = 0;
		if (v[i].a <= v2[idx++]) {
			sum = v[i].b;
		}
		else {
			swap(v[i], v[n - 1]);
			i--;
		}
		res += sum;
		if (idx == k) break;
	}
	//output
	printf("%lld", res);

	return 0;
}//main