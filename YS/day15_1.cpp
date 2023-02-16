#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// 1.재귀, 스택, 정렬, 그리디 
// 2.상태 괜찮고 다 했으면 4단계부터 복습
// 1~9, 0~9, 0~9, 0~9 총 39가지
#define MX 100100
struct tmp {
	int x, c;
}k;
vector <tmp> map[MX];
int n, v, S, E, res;
int q[MX], chk[MX];

int bfs(int m) {
	int i, st, ed, z;
	st = ed = -1;
	memset(chk, 0, sizeof(chk));
	q[++st] = S; chk[S] = 1;
	while (st != ed) {
		z = q[++ed];
		//종료 조건
		if (z == E) return 1;
		for (i = 0; i < map[z].size(); i++) {
			if (chk[map[z][i].x] == 0 && map[z][i].c >= m) {
				q[++st] = map[z][i].x;
				chk[map[z][i].x] = 1;
			}
		}
	}
	return 0;
}

int main() {
	//input
	scanf_s("%d%d", &n, &v);
	int i, a, b, c, l, r, mid;
	for (i = 0; i < v; i++) {
		scanf_s("%d%d%d", &a, &b, &c);
		k.x = b; k.c = c;
		map[a].push_back(k);
		k.x = a; k.c = c;
		map[b].push_back(k);
	}
	scanf_s("%d%d", &S, &E);
	//logic
	l = 1, r = 1000000000;

	while (1) {
		mid = (l + r) / 2;
		if (bfs(mid)) {
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
		if (l > r) break;
	}
	//output
	printf("%d", res);

	return 0;
}//main