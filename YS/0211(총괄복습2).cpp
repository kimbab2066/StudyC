#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//댐, 소수길, 원탁의 기사
#define MX 110
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int t, map[MX][MX], q[MX * MX][2], chk[MX][MX];
int x, y, k, cnt;
int st, ed;

int inRange(int x, int y) {
	return 0 < x && x <= t && 0 < y && y <= t;
}

void bfs() {
	while (st != ed) {
		int a = q[++ed][0];
		int b = q[ed][1];
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (inRange(nx, ny) && map[nx][ny] == 0 && chk[nx][ny] == -1) {
				q[++st][0] = nx;
				q[st][1] = ny;
				//방문처리
				chk[nx][ny] = chk[a][b] + 1;
			}
		}//i
	}
}//bfs

int main() {
	//input
	scanf_s("%d", &t);
	int i, j;
	for (i = 1; i <= t; i++) {
		for (j = 1; j <= t; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}
	scanf_s("%d%d%d", &x, &y, &k);
	//logic
	for (i = 1; i <= t; i++) {
		for (j = 1; j <= t; j++) chk[i][j] = -1;
	}
	//Q초기화
	st = ed = -1;
	q[++st][0] = x;
	q[st][1] = y;
	chk[x][y] = 0;
	bfs();

	//output
	for (i = 1; i <= t; i++) {
		for (j = 1; j <= t; j++) {
			if (chk[i][j] == k)cnt++;
		}
	}

	if (cnt != 0) printf("%d", cnt);
	else printf("OH, MY GOD");

	return 0;
}//main