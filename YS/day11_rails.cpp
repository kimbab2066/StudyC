#include <stdio.h>
#include <string.h>

int n, a[1001], s[1001];

int main() {
	//input
	scanf_s("%d", &n);
	int i, j, top;
	//logic
	while (1) {
		scanf_s("%d", &a[1]);
		//0�̸� ����
		if (a[1] == 0) return 0;
		for (i = 2; i <= n; i++) {
			scanf_s("%d", &a[i]);
		}
		i = 1, j = 0, top = -1;
		while (1) {
			//���� ���ų� ���ð� ���� �ٸ� ���
			if (top == -1 || s[top] != a[i])s[++top] = ++j;
			else { top--, i++; }
			// i==n+1(��� ���� ���� �� ����) || j>n ���ÿ� �ʰ��� ���� ���� �ִ� ���(������)
			if (j > n || i == n + 1) break;
		}
		//output
		if (i == n + 1) printf("Yes\n");
		else printf("No\n");
	}//w

	return 0;
}//main