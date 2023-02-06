#include <stdio.h>

char ch[31];
int s[31];

int main() {
	//input
	scanf_s("%s", ch, 31);
	//logic
	int i, j, sw, sum, top;
	sw = sum = 0, top = -1;
	for (i = 0; ch[i] != 0; i++) {
		if (ch[i] == '(') s[++top] = -1;
		else if (ch[i] == ')') {
			if (s[top--] != -1)sw = 1;
		}
		else if (ch[i] == '[') s[++top] = -3;
		else if (ch[i] == ']') {
			if (s[top--] != -3)sw = 1;
		}
		if (top < -1)sw = 1;
	}
	//output
	//정석으로 돌면 top은 -1이 될 수 밖에 없음(안될 경우 0)
	if (sw == 1 || top != -1) printf("0");
	else {
		for (i = 0; ch[i] != 0; i++) {
			sum = 0;
			if (ch[i] == '(')s[++top] = -1;
			else if (ch[i] == '[')s[++top] = -3;
			else if (ch[i] == ')') {
				for (j = top;; j--) {
					if (s[j] == -1)break;
					sum += s[j];
				}
				top = j;
				if (sum == 0)s[top] = 2;
				else s[top] = sum * 2;
			}
			else if (ch[i] == ']') {
				for (j = top;; j--) {
					if (s[j] == -3)break;
					sum += s[j];
				}
				top = j;
				if (sum == 0)s[top] = 3;
				else s[top] = sum * 3;
			}
		}//i
		sum = 0;
		for (i = 0; i <= top; i++) {
			sum += s[i];
		}
		printf("%d", sum);
	}

	return 0;
}