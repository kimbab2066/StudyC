#include <stdio.h>
#include <string.h>

char a[101];
int k;

int main() {
	//input
	int d, r;
	scanf_s("%d%d", &d, &r);
	int i;
	//logic
	while (1) {
		if (d % r <= 9)a[k++] = (d % r) + '0';
		else a[k++] = d % r + 55;
		d /= r;
		if (d == 0)break;
	}
	//output
	for (i = k - 1; i >= 0; i--) {
		printf("%c", a[i]);
	}

	return 0;
}//main