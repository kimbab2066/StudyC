#include <stdio.h>

#define OFF 30

int chk[61], num[20];

int main() {
	//input
	for (int i = 0; i < 20; i++) {
		scanf_s("%d", &num[i]);
		chk[num[i] + OFF]++;
	}
	int max = -40, max2 = -40;
	for (int i = 0; i < 20; i++) {
		// 값이 존재할 때
		if (chk[num[i] + OFF] > 0) {
			if (max <= num[i]) {
				max2 = max;
				max = num[i];
			}
			else if (max2 < num[i]) {
				max2 = num[i];
			}
		}
	}
	printf("%d\n%d %d", max + max2, max2, max);
	//logic

	//output

	return 0;
}//main