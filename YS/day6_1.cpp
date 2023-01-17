#include <stdio.h>

//baby_gin

int num[10];
int n;

int main() {
	//input
	int i, j, k = 0;
	for (i = 1; i <= 6; i++) {
		scanf_s("%d", &n);
		num[n]++;
	}
	//logic
	for (i = 0; i <= 9; i++) {
		k += num[i] / 3;
		num[i] %= 3;
	}
	for (i = 0; i <= 7; i++) {
		if (num[i] > 0 && num[i + 1] > 0 && num[i + 2] > 0) {
			num[i]--, num[i + 1]--, num[i + 2]--;
			k++, i--;
		}
	}
	//output
	if (k == 2) printf("gin");
	else printf("lose");

	return 0;
}//main