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
	p(path[k]); //���� ���� ��
	//��ǻ� k�� 0�� ������ ����ϴ� ��
	printf("[%d][%d]\n", q[k][0], q[k][1]);
}

int main() {
	//input

	// 1,1 -> N,M���� ������
	// �����¿츦 Ž���ϸ鼭 �� �� �ִ� ������� Ž��
	// �ٽ� BFS
	// Q�� ��� ������ ����
	// chk[N][M] ���
	scanf_s("%d%d", &n, &m);
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	//Q�ʱ�ȭ
	st = ed = -1;
	//q�� �߰�
	q[++st][0] = 1; q[st][1] = 1;
	//�湮 üũ
	chk[1][1] = 1;
	//��������
	path[st] = -1;

	//logic
	while (st != ed) {
		//����
		int x = q[++ed][0];
		int y = q[ed][1];
		//���� ����
		if (x == n && y == m) break;
		//�����¿�
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//������ ����ų� �湮 �� ���
			if (!inRange(nx, ny) || chk[nx][ny]) continue;
			//�̵��� �� ���� ���
			if (map[nx][ny] == 0)continue;
			// BFS
			q[++st][0] = nx;
			q[st][1] = ny;
			chk[nx][ny] = chk[x][y] + 1;
			//��������
			path[st] = ed;
		}//i
	}//w

	//output
	printf("%d\n", chk[n][m]);

	//��������
	p(ed);//���� ��ġ

	return 0;
}//main