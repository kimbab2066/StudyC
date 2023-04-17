#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MX 1000001
int f, s, g, u, d;
queue <int> q;
int chk[MX];

/*
IN
10 1 10 2 1
OUT
6
-----
IN
100 2 1 1 0
OUT
use the stairs
-----
IN
50 1 11 4 13
OUT
11
*/
void bfs() {
	while (!q.empty()) {
		int x = q.front(); q.pop();
		//종료 조건
		if (x == g) break;
		//범위를 벗어나지 않으며 방문하지 않은 경우
		if (x + u <= f && chk[x + u] == 0) {
			q.push(x + u);
			chk[x + u] = chk[x] + 1;
		}
		//범위를 벗어나지 않으며 방문하지 않은 경우
		if (x - d > 0 && chk[x - d] == 0) {
			q.push(x - d);
			chk[x - d] = chk[x] + 1;
		}
	}
}//bfs

int main(void) {
	//input
	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	//logic
	q.push(s);
	chk[s] = 1;
	bfs();
	//output
	if (chk[g]) printf("%d", chk[g] - 1);
	else printf("use the stairs");

	return 0;
}//main