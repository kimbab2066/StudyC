#include <stdio.h>
#include <string.h>

char res[20];
int idx;

bool d(char a[]) {
	int k = 0;
	for (int i = 0; res[i] != 0; i++) {
		if (res[i] != res[idx - 1 - i])return false;
	}
	return true;
}

void bin(int k) {
	idx = 0;
	int a = k;
	while (1) {
		res[idx++] = a % 2 + '0';
		a /= 2;
		if (a == 0)break;
	}
	if (d(res)) printf("%d\n", k);
}

int main() {
	//input
	int i, j;
	//logic
	for (i = 1; i <= 100000; i++) {
		bin(i);
		//output
	}

	return 0;
}//main