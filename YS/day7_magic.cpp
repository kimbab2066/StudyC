#include <stdio.h>

//
int a[10][10];
int n, s;
int i, j;

int main() {
	//input
	scanf_s("%d", &n);
	//logic
	int x, y;
	x = 0, y = n / 2;
	int zx, zy;

	for (i = 1; i <= n * n; i++) {
		a[x][y] = ++s;
		//�� ���(2��° ���ܸ� ����)
		zx = x, zy = y;
		//������ �� �밢��(x--,y++)
		x--, y++;
		//������ ����� n-1(x�� 0���� �۾����� n-1���� �ٽ� �����ϸ� ��)
		if (x < 0) x = n - 1;
		//������ ����� n-1(y�� n���� ���ų� Ŀ���� 0���� �ٽ� �����ϸ� ��)
		if (y >= n) y = 0;
		//�̹� ���� ä���� ��� �Ʒ��� �������� �ϴ� ������� �����ͼ� zx+1, y = zy
		if (a[x][y] != 0) x = zx + 1, y = zy;
	}
	//output
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}//main