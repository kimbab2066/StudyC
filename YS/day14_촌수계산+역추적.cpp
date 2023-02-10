#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MX 101

int n, x, y, m, z;
int map[MX][MX];
//path�� ���
int q[MX], d[MX], chk[MX], path[MX];
int st, ed;
//������
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
	//Q�ʱ�ȭ
	st = ed = -1;
	q[++st] = x;
	d[st] = 0;
	chk[x] = 1;
	//������
	path[st] = -1;

	//logic
	while (st != ed) {
		z = q[++ed];
		//���� ����
		if (z == y) break;
		for (j = 1; j <= n; j++) {
			// �̼��� �����ְ� �湮���� ���� ���
			if (chk[j] == 0 && map[z][j] == 1) {
				// Q�� ���� �ֱ�
				q[++st] = j;
				// �湮 üũ && depth
				chk[j] = 1;
				d[st] = d[ed] + 1;
				//������
				path[st] = ed;
			}
		}
	}
	//output
	if (z != y) printf("-1");
	else { printf("%d\n", d[ed]); p(ed); }

	return 0;
}//main