#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//����(paren) + ��� + ����(���� ������) -> paren�� ������ �ָ��� �ٽ� Ǯ���(��￡ ���� �ֱ� ����) + ���(omok 3�ð� ��� ����)
//���� ��� + ���� -> ���(omok 3�ð� 30�� ��� ����)
//���� ������ ����
//���� ����
char a[20][20];
int dx[4] = { 1,1,0,-1 };
int dy[4] = { 0,1,1,1 };
int i, j;
int vis[20][20][4];

int omok(int x, int y, int d, int color) {
	int nx = x + dx[d];
	int ny = y + dy[d];

	//�� ��Ʒ� �Ʒ� �޾Ʒ�
	if (color == a[nx][ny]) return vis[nx][ny][d] = omok(nx, ny, d, color) + 1;
	return 1;//�湮ó��
}//omok

int cal(int x, int y, int dir, int color) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (a[nx][ny] == color) return vis[nx][ny][dir] = cal(nx, ny, dir, color) + 1;
	return 1;
}

int main() {
	//input
	for (i = 1; i <= 19; i++) {
		for (j = 1; j <= 19; j++) {
			scanf_s("%s", &a[i][j], 10);
		}
	}

	//logic
	//x,y,d,b,w
	for (j = 1; j <= 19; j++) {
		for (i = 1; i <= 19; i++) {
			if (a[i][j] != '0') {
				for (int dir = 0; dir < 4; dir++) {
					if (vis[i][j][dir] == 0 && omok(i, j, dir, a[i][j]) == 5) { printf("%d\n%d %d", a[i][j] - '0', i, j); return 0; };
					//if (vis[i][j][dir] == 0 && cal(i, j, dir, a[i][j]) == 5) { printf("%d\n%d %d", a[i][j] - '0', i, j); return 0; }
				}
			}//dir
		}
	}

	//output
	printf("0");

	return 0;
}//main