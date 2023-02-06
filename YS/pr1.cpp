#include <stdio.h>
#include <string.h>

char a[11];
int b[12];
int main() {
	//input
	scanf_s("%[^\n]", a, 11);
	//logic
	int len = strlen(a);
	int i;
	for (i = 0; a[i] != 0; i++) {
		b[a[i] - '0']++;
	}
	//output
	int cnt = 0;
	for (i = 1; i <= len; i++) {
		if (b[i] == 1) cnt++;
	}
	if (cnt == len)printf("yes");
	else printf("no");

	return 0;
}//main