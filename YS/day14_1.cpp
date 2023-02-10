#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
//오후 - 수업(BFS)
//저녁 - 복습
#define MX 101
int map[MX][MX], q[MX * MX], d[MX * MX], chk[MX][MX];
int n, x, y, m, z;
int a, b;
int st, ed;

int main() {
	//input
	scanf_s("%d%d%d%d", &n, &x, &y, &m);
	int i, j;
	for (i = 1; i <= m; i++) {
		scanf_s("%d%d", &a, &b);
		map[a][b] = map[b][a] = 1;
	}
	//logic
	st = ed = -1;
	q[++st] = x;
	d[st] = 0;
	while (st != ed) {
		z = q[++ed];
		if (z == y)break;
		for (i = 1; i <= n; i++) {
			if (map[z][i] == 1 && chk[z][i] == 0) {
				chk[z][i] = 1;
				q[++st] = i;
				d[st] = d[ed] + 1;
			}
		}
	}
	//output
	if (z == y)printf("%d", d[ed]);
	else printf("-1");

	return 0;
}//main