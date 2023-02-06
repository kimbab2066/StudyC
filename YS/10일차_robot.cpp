#include <stdio.h>
#include <string.h>

int r, c, st, cnt;
char a[12][12];
int vis[12][12];
int nn[3];

void recur(int x, int y) {
	//Base Condition
	if (x < 0 || y < 0 || x >= r || y >= c) return;
	//방문 한 경우
	if (vis[x][y]) { nn[0] = x; nn[1] = y; nn[2] = vis[x][y]; return; }
	//방문 처리
	cnt++;
	vis[x][y] = cnt;
	//위 아래 오른쪽 왼쪽 순
	if (a[x][y] == 'N') recur(x - 1, y);
	else if (a[x][y] == 'S') recur(x + 1, y);
	else if (a[x][y] == 'E') recur(x, y + 1);
	else if (a[x][y] == 'W') recur(x, y - 1);
}//recur

int main() {
	//input
	scanf_s("%d%d%d", &r, &c, &st);
	int i;
	for (i = 0; i < r; i++) {
		scanf_s("%s", &a[i], 12);
	}
	//logic
	recur(0, st - 1);
	//output
	//빠져나감
	if (!nn[2])printf("%d step(s) to exit", cnt);
	//꼬리뭄
	else printf("%d step(s) before a loop of %d step(s)", nn[2] - 1, cnt - nn[2] + 1);

	return 0;
}//main