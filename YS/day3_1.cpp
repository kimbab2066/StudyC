#include <stdio.h>

void tmp() {
	int i = 0;
	double sum = 0;
	while (1) {
		i++;
		sum += (double)1 / i;
		if (i == 10) break;
	}
	printf("%lf", sum);
}

void tmp2() {
	int i = 1;
	double sum = 0;
	while (1) {
		i++;
		if (i % 2 == 0) sum += (double)(i - 1) / i;
		else sum -= (double)(i - 1) / i;

		if (i == 10) break;
	}
	printf("%lf", sum);
}

void tmp3() {
	int i = 0, total = 1, sum = 0;
	while (1) {
		i += 2;
		total *= (i - 1) * i;
		sum += total;
		// ���� ����
		if (i == 12) break;
	}
	printf("%d", sum);

}
void tmp4() {
	int n, p = 0;
	scanf_s("%d", &n);
	//logic
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j <= p) printf(" ");
			else printf("*");
		}
		p++;
		printf("\n");
	}
	//output
}

void tmp5() {
	//input
	int i, j, n, k, p;
	scanf_s("%d", &n);
	k = n, p = 0;
	//logic
	for (i = 1; i <= n; i++) {
		//���� ó��
		for (j = 1; j <= p; j++) printf(" ");
		//�� ó��
		for (j = 1; j <= k; j++) {
			if (i + p + j == n + 1) printf("$");
			else printf("*");
		}
		printf("\n");
		if (i <= n / 2) p++, k -= 2;
		else p--, k += 2;

	}
	//output
}
// ����(p) = n/2���� ����, 0���� else
// column 1���� ���� n/2+1���� ���� ���ķ� --
// ��ü ĭ�� 1 3 5 3 1�� ���� i +=2, i -= 2�� �ϸ� ��
void tmp6() {
	int i, j, n, k, p, m;
	scanf_s("%d", &n);
	k = 1, p = n / 2;

	//logic
	for (i = 1; i <= n; i++) {
		// ����
		for (j = 1; j <= p; j++) printf(" ");
		m = 0;
		//���� ó��
		for (j = 1; j <= k; j++) {
			if (p + j <= n / 2 + 1)printf("%d", ++m);
			else printf("%d", --m);
		}
		printf("\n");
		if (i <= n / 2) p--, k += 2;
		else p++, k -= 2;
	}
}

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	while (1) {
		printf("%d ", n);
		if (n == 1) break;
		else if (n % 2 == 0)n /= 2;
		else n = n * 3 + 1;
	}
	//logic

	//output

	return 0;
}//main