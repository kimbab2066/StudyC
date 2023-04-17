 #pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct tmp {
	int a, b, c;
};

int n, seq[501], result[501];
vector<tmp> v;

int chk(tmp x, tmp y) {
	return x.c < y.c;
}

int main() {
	//input
	scanf("%d", &n);
	int i, j, x, y, z;
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		v.push_back({ x,y,z });
	}
	//logic
	sort(v.begin(), v.end(), chk);
	int res = 0;
	for (i = 0; i < n; i++) {
		int cnt = 1, prev = i;
		int idx = 0;
		seq[idx++] = v[i].a;
		for (j = i + 1; j < n; j++) {
			if (v[prev].c <= v[j].b) {
				cnt++;
				prev = j;
				seq[idx++] = v[prev].a;
			}
		}
		if (res < cnt) {
			res = cnt;
			for (j = 0; j < cnt; j++) {
				result[j] = seq[j];
			}
		}
	}//i

	//output
	printf("%d\n", res);
	for (i = 0; i < res; i++) {
		printf("%d ", result[i]);
	}

	return 0;
}//main