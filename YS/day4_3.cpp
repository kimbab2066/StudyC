#include <stdio.h>

// 10���� ���� �Է� �ް� �ߺ� �����Ͽ� ǥ��
// 10���� ���� �Էµ����� OFFSET 10 �����ؾ� ��
// �� �� �� ���� ���� �Է¼����� ���
#define OFF 10
int num[10], chk[21];

int main() {
	//input
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &num[i]);
		chk[num[i] + OFF]++;
	}
	//logic
	for (int i = 0; i < 10; i++) {
		if (chk[num[i] + OFF] == 1)printf("%d ", num[i]);
	}

	//output

	return 0;
}//main