#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MX 101

int n, x, y, m, z;
int map[MX][MX];
//path는 경로
int q[MX], d[MX], chk[MX], path[MX];
int st, ed;
//역추적
void p(int k) {
	if (k == -1) return;
	p(path[k]);
	printf("[%d]\n", q[k]);
}

int main() {
	//input
	scanf_s("%d%d%d%d", &n, &x, &y, &m);
	int i, j;
	int a, b;
	for (i = 1; i <= m; i++) {
		scanf_s("%d%d", &a, &b);
		map[a][b] = map[b][a] = 1;
	}
	//Q초기화
	st = ed = -1;
	q[++st] = x;
	d[st] = 0;
	chk[x] = 1;
	//역추적
	path[st] = -1;

	//logic
	while (st != ed) {
		z = q[++ed];
		//종료 조건
		if (z == y) break;
		for (j = 1; j <= n; j++) {
			// 촌수가 적혀있고 방문하지 않은 경우
			if (chk[j] == 0 && map[z][j] == 1) {
				// Q에 집어 넣기
				q[++st] = j;
				// 방문 체크 && depth
				chk[j] = 1;
				d[st] = d[ed] + 1;
				//역추적
				path[st] = ed;
			}
		}
	}
	//output
	if (z != y) printf("-1");
	else { printf("%d\n", d[ed]); p(ed); }

	return 0;
}//main