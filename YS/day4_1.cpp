#include <stdio.h>

// å ������ N, ���� �� K
// k�ٿ� speed, time, rest�� �־���
// �� ���̽����� ������� ����ض�

int main() {
	//input
	int n, k, s, t, r, tmp, cnt, result;
	scanf_s("%d%d", &n, &k);
	//logic
	for (int i = 0; i < k; i++) {
		scanf_s("%d%d%d", &s, &t, &r);
		tmp = n, cnt = 0, result = 0;
		while (1) {
			//������(�ð�)
			cnt++, result++;
			tmp -= s;
			//���� ����
			if (tmp <= 0) break;
			if (cnt == t) result += r, cnt = 0;
		}
		printf("%d\n", result);
	}

	//output

	return 0;
}//main