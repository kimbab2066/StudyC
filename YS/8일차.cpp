#include <stdio.h>
#include <string.h>

char c[66];
int idx;
char res[100];

int main() {
	//input
	int i;//x�������� �Ǻ�
	int n, k;

	scanf_s("%s%d%d", &c, 66, &n, &k);

	// n����->10����
	long long num = 0;
	for (i = 0; i < strlen(c); i++) {
		if (c[i] == '-')continue;
		if (c[i] - '0' < 10) num = num * n + (c[i] - '0');
		else num = num * n + (c[i] - 55);
	}
	// 10���� -> k����
	while (1) {
		if (k > 9) {
			if (num % k <= 9) res[idx++] = (num % k) + '0';
			else res[idx++] = num % k + 55;
		}
		else {
			res[idx++] = num % k + '0';
		}
		num /= k;
		// ���� ����
		if (num == 0) break;
	}
	//-�� �� ����
	if (c[0] == '-')printf("-");
	for (i = idx - 1; i >= 0; i--) {
		printf("%c", res[i]);
	}


	return 0;
}//main