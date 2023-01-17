#include <stdio.h>

/* offset
5x5�迭
	1. ���� �߰�
	2. dx dy ���鼭 nx,ny���� x,y ���� ũ�� ���� 99�� �ٲ��ش�
	3. loop���鼭 99�� �� * ���
*/
int map[7][7];
int vis[7][7] = { 0 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool inRange(int x, int y) {
	return 0 < x && 0 < y && x <= 5 && y <= 5;
}

int main() {
	//input
	int i, j;
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}
	//logic
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			int all = 0, cnt = 0;
			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (inRange(nx, ny)) {
					all++;
					if (map[nx][ny] > map[i][j]) cnt++;
				}
			}
			if (cnt == all) vis[i][j] = 1;
		}
	}
	//output
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			if (vis[i][j] == 1) printf("* ");
			else printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}//main