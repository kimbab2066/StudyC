#include <stdio.h>
#include <string.h>

char a[31], b[31], s[1000];
int res[1000];


int main() {
	//input
	int i, top = -1, idx = 0;
	scanf_s("%s", &a, 100);
	int len = strlen(a);
	char j = 'a';
	//logic
	i = 0;
	while (1) {
		if (top < -1 || i == len)break;
		if (top == -1 || a[i] != s[top]) {
			s[++top] = j++;
			res[idx++] = 1;
		}
		else {
			res[idx++] = 3;
			top--;
			i++;
		}
	}//w
	//output
	if (top == -1) {
		for (i = 0; i < idx; i++) {
			if (res[i] == 3) printf("pop\n");
			else if (res[i] == 1) printf("push\n");
		}
	}
	else printf("impossible");

	return 0;
}//main