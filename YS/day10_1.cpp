#include <stdio.h>

int n, cnt;
char a[20];

void pro(int o, int x, int d) {
	//����ġ��
	if (o < 0 || x < 0) return;
	//find
	if (o == 0) {
		cnt++;
		for (int i = 0; i < d; i++) {
			printf("%c", a[i]);
		}
		printf("\n");
		return;
	}

	a[d] = 'o';
	pro(o - 1, x, d + 1);
	a[d] = 'x';
	pro(o, x - 1, d + 1);
}

int main() {
	//input
	scanf_s("%d", &n);
	//logic
	pro(n, n - 1, 0);//1�ǰ���,0�ǰ���,����
	//output
	printf("total %d case(s)", cnt);

	return 0;
}//main