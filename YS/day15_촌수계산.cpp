#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MX 101

vector <int> v[MX];
int n, a, b, m, chk[MX], d[MX], q[MX];

int main() {
	//input
	int i, st, ed, x, y;
	scanf_s("%d%d%d%d", &n, &a, &b, &m);
	for (i = 1; i <= m; i++) {
		scanf_s("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	st = ed = -1;
	q[++st] = a;
	d[st] = 0;
	chk[a] = 1;
	//logic
	while (st != ed) {
		x = q[++ed];
		if (x == b) break;
		for (i = 0; i < v[x].size(); i++) {
			if (chk[v[x][i]] == 0) {
				q[++st] = v[x][i];
				d[st] = d[ed] + 1;
				chk[v[x][i]] = 1;
			}
		}
	}
	//output
	if (x == b) printf("%d", d[ed]);
	else printf("-1");

	return 0;
}//main