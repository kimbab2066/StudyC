#include <stdio.h>

#define MX 101
//
int t;
int num[MX];
int s;
int sex, sw;

int main() {
	//input
	int i, j;
	scanf_s("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf_s("%d", &num[i]);
	}
	scanf_s("%d", &s);

	//logic
	while (s--) {
		scanf_s("%d%d", &sex, &sw);
		if (sex == 1) {//남자
			for (j = sw; j <= t; j += sw) {
				num[j] = !num[j];
			}
		}
		else {//여자
			int x, y; 
			x = y = sw;
			while (num[x - 1] == num[y + 1]) x--, y++;
			for (j = x; j <= y; j++) {
				num[j] = !num[j];
			}
		}
	}//while

	//output
	for (i = 1; i <= t; i++) {
		printf("%d ", num[i]);
		if (i % 20 == 0) printf("\n");
	}

	return 0;
}//main