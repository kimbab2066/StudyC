#include <stdio.h>
#include <string.h>

int n, cnt;
char res[20];

//O�� ����, X�� ����, ����
void pro(int a, int b, int d) {
	if (b >= n) return;
	if (a == n) {
		cnt++;
		for (int i = 0; i < d; i++) {
			printf("%c", res[i]);
		}
		printf("\n");
		return;
	}
	res[d] = 'o';
	pro(a + 1, b, d + 1);
	res[d] = 'x';
	pro(a, b + 1, d + 1);

}

int main() {
	//input
	scanf_s("%d", &n);
	//logic
	pro(0, 0, 0);
	//output
	printf("total %d case(s)", cnt);

	return 0;
}//main