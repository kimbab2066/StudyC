#include <stdio.h>

//n,num[10000]
int n, num[10001];

int main() {
	//input
	scanf_s("%d", &n);
	int i, j = 0, v;
	//logic
	//Penta Number(������ �ִ� ��������)
	for (i = 1; ; i += 3) {
		j += i;
		// ���� ����
		if (j > 10000)break;
		num[j] = 1;
	}

	//output
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &v);
		if (num[v])printf("%d Y", v);
		else printf("%d N", v);
		printf("\n");
	}

	return 0;
}//main