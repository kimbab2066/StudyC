#include <stdio.h>

//
int a[5][5];

int main() {
	//input
	int i, j, s = 0;

	//logic

	//row�� Ȧ�� �� �� ������
	// ¦�� �� �� ������
	for (i = 0; i < 5; i++) {
		if (i % 2 == 0) {//Ȧ�� ��
			for (j = 4; j >= 0; j--) a[i][j] = ++s;
		}
		else {
			for (j = 0; j < 5; j++) a[i][j] = ++s;
		}
	}

	//output
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}//main