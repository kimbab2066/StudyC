#include <stdio.h>
#include <string.h>

char a[101];
char b[101];

int main() {
	//input
	int i, j, k;
	scanf_s("%s", a, 100);
	int len = strlen(a);
	int p = len % 3;//³ª¸ÓÁö

	if (len <= 3) printf("%s", a);
	else {
		if (p == 0)p = 3;
		if (p == 1) printf("%c", a[0]);
		else if (p == 2) printf("%c%c", a[0], a[1]);
		else if (p == 3)printf("%c%c%c", a[0], a[1], a[2]);
		for (i = p; a[i] != 0; i += 3) {
			printf(",%c%c%c", a[i], a[i + 1], a[i + 2]);
		}
	}

	return 0;
}//main