#include <stdio.h>

// 1. �����佺 CLEAR
// 2. �׳� �迭 CLEAR
int i, n, vis[10001];

int main() {
	//input
	scanf_s("%d", &n);
	// ¦�� �� ������ �Ҽ��� 2(�̷� ���� i�� ������ +=2�� Ȧ����)
	vis[0] = 2;
	int idx = 1;
	//logic
	for (i = 3; i <= n; i += 2) {//�������� ���� ������ ����(2 to n)
		//3 5 7 9�� ��
		for (int j = 0; j < idx; j++) {
			// i�� ���� �迭�� ������ ������ �� ������ �������� ���
			if (i % vis[j] == 0) break;
			// ������ �������� �ʴ� ���(i % vis[j] != 0�� ����)
			else if (j == idx - 1) {
				vis[idx] = i;
				idx++;
				break;
			}
		}
	}
	//output
	for (i = 0; i < idx; i++) {
		printf("%d ", vis[i]);
	}

	return 0;
}//main