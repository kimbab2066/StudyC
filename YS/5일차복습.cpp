#include <stdio.h>

//
int n, cnt;
int num[101];//��
int result[101];//���
// k �� ��� �迭�� ���
int i, j, k;

int main() {
	//input
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &num[i]);
	}
	//logic
	for (i = 1; i <= n; i++) {
		int idx = i, val = 0, j = 0;
		while (1) {
			j++;//�ð������� ���� ������
			val = num[idx];
			// ���� ����
			if (i == val) break;
			else idx = val;
			// ���� ����2
			if (j > n)break;
		}
		//����� ������Ʈ(�ᱹ ����Ŭ�� �� �� ����� ������Ʈ �϶�� �ǹ���)
		if (i == val)result[k++] = i, cnt++;
	}

	//output
	printf("%d\n", cnt);
	for (i = 0; i < k; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}//main