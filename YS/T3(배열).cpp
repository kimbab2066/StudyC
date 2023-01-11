#include <stdio.h>

int i, chk[21], num[10];

int main() {
	//input
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &num[i]);
		chk[num[i] + 10]++;
	}
	//logic
	for (i = 0; i < 10; i++) {
		if (chk[num[i] + 10] == 1)printf("%d ", num[i]);
	}
	//output

	return 0;
}//main