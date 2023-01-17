#include <stdio.h>

//¹®Á¦2
int a[5][5];

int main() {
	//input
	int i, j, s = 0;

	//logic
	for (i = 0; i < 5; i++) {
		for (j = 4; j >= 4 - i; j--) a[i][j] = ++s;
	}

	//output
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (a[i][j])printf("%3d", a[i][j]);
			else printf("   ");
		}
		printf("\n");
	}

	return 0;
}//main