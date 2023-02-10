#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MX 101

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[MX][MX];
int n, m;
int st, ed;
int q[MX * MX][2], chk[MX][MX], path[MX * MX];

int inRange(int x, int y) {
	return (0 < x && x <= n && 0 < y && y <= m);
}

void p(int k) {
	if (k == -1) return;
	p(path[k]); //깊이 따라 들어감
	//사실상 k가 0일 때부터 출력하는 것
	printf("[%d][%d]\n", q[k][0], q[k][1]);
}

int main() {
	//input

	// 1,1 -> N,M으로 가야함
	// 상하좌우를 탐색하면서 갈 수 있는 범위라면 탐색
	// 다시 BFS
	// Q가 비어 있으면 종료
	// chk[N][M] 출력
	scanf_s("%d%d", &n, &m);
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	//Q초기화
	st = ed = -1;
	//q에 추가
	q[++st][0] = 1; q[st][1] = 1;
	//방문 체크
	chk[1][1] = 1;
	//역추적용
	path[st] = -1;

	//logic
	while (st != ed) {
		//빼기
		int x = q[++ed][0];
		int y = q[ed][1];
		//종료 조건
		if (x == n && y == m) break;
		//상하좌우
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//범위를 벗어나거나 방문 한 경우
			if (!inRange(nx, ny) || chk[nx][ny]) continue;
			//이동할 수 없는 경우
			if (map[nx][ny] == 0)continue;
			// BFS
			q[++st][0] = nx;
			q[st][1] = ny;
			chk[nx][ny] = chk[x][y] + 1;
			//역추적용
			path[st] = ed;
		}//i
	}//w

	//output
	printf("%d\n", chk[n][m]);

	//역추적용
	p(ed);//현재 위치

	return 0;
}//main