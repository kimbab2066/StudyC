#include <stdio.h>
#include <string.h>

int n, k;
int dab[31];

// 1�� ����, 0�� ����, ����
void pro(int a, int b, int d) {
	//����ġ��(��� �� �� �ִ� 1,0�� ������ �ʰ��ϴ� ���)
	if (a < 0 || b < 0) return;
	//���� ����(���� ã�� ���)
	if (d == n) {
		for (int i = 0; i < n; i++) {
			printf("%d", dab[i]);
		}
		printf("\n");
		return;
	}
	//1����
	dab[d] = 1;
	pro(a - 1, b, d + 1);
	//0����
	dab[d] = 0;
	pro(a, b - 1, d + 1);
}

int main() {
	//input
	scanf_s("%d%d", &n, &k);
	//logic
	pro(k, n - k, 0);//1�� ����, 0�� ����,����
	//output

	return 0;
}//main