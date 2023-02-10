#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MX 26

int map[MX][MX], q[MX * MX][2], d[MX * MX], chk[MX][MX];
int res[MX];
int n;
int st, ed, total;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int inRange(int x, int y) {
	return 0 < x && x <= n && 0 < y && y <= n;
}

void bfs(int x, int y) {
	int cnt = 1;
	//bfs
	while (st != ed) {
		int a = q[++ed][0];
		int b = q[ed][1];
		//종료 조건
		//if (a == n && b == n) break;
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			//범위이면서 방문하지 않은 경우
			if (inRange(nx, ny) && map[nx][ny] == 1) {
				//map방문
				map[nx][ny] = 0;
				q[++st][0] = nx; q[st][1] = ny;
				cnt++;
			}
		}
	}//while
	res[total] = cnt;
}//bfs

int main() {
	//input
	scanf_s("%d", &n);
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	//logic
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				//Q초기화
				st = ed = -1;
				map[i][j] = 0;
				q[++st][0] = i; q[st][1] = j;
				//BFS
				bfs(i, j);
				total++;
			}
		}//j
	}//i
	//output
	printf("%d\n", total);
	sort(res, res + total);
	for (i = 0; res[i] != 0; i++) {
		printf("%d\n", res[i]);
	}

	return 0;
}//main