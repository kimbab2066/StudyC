#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int num[101], res[101];
int n, cnt;

int main() {
	//input
	scanf_s("%d", &n);
	int i, j, k = 0;
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &num[i]);
	}
	//logic
	for (i = 1; i <= n; i++) {
		int idx = i, val = 0;
		j = 0;
		while (1) {
			// indexüũ
			j++;
			val = num[idx];
			// �ε����� ���� ���� ��� ����
			if (i == val) break;
			// �ƴϸ� �ε����� val�� �ٲ��ֱ�
			else idx = val;
			// ������ ����� ����
			if (j > n) break;
		}
		// ���� �ε����� val���� ������ ��� �迭�� �ε��� ����, ����++
		if (i == val) res[k++] = i, cnt++;
	}
	//output
	printf("%d\n", cnt);
	for (i = 0; i < k; i++) {
		printf("%d\n", res[i]);
	}

	return 0;
}//main