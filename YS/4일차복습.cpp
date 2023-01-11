#include <stdio.h>

// 20°³ÀÇ ¼ö(i = 0 to 20)
// offset 30
// max, max2
// chk[61], num[20]
#define OFF 30
int chk[61], num[20];
int max = -31, max2 = -31, i;

int main() {
	//input
	for (i = 0; i < 20; i++) {
		scanf_s("%d", &num[i]);
		chk[num[i] + OFF]++;
	}
	//logic
	for (i = 0; i < 20; i++) {
		if (chk[num[i] + OFF] > 0) {
			if (max < num[i]) {
				max2 = max;
				max = num[i];
			}
			else if (max2 < num[i]) {
				max2 = num[i];
			}
		}
	}
	//output
	printf("%d\n%d %d", max + max2, max2, max);

	return 0;
}//main