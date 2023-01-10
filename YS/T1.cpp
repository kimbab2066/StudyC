#include <stdio.h>

#define OFF 10

int main() {
	//input
	int n, i, j, num[10] = {};
	//logic
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &n);
		num[i] = n;
	}

	for (i = 0; i < 10; i++) {
		int cnt = 0;
		for (j = 0; j < 10; j++) {
			if (num[i] == num[j]) cnt++;
		}
		if (cnt == 1) printf("%d ", num[i]);
	}
	//output

	return 0;
}//main