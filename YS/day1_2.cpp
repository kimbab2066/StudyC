#include <stdio.h> // ��� ����

void tmp1() {
	// ���� ����
	int a, b, c;
	// �Է�
	scanf_s("%d%d", &a, &b);
	// ���
	c = a * b;
	// ���
	printf("%d", c);
}

void tmp2() {
	int a, b, c, d;

	scanf_s("%d%d%d%d", &a, &b, &c, &d);

	d += a * 3600 + b * 60 + c;

	a = d / 3600 % 24;
	b = d % 3600 % 60; // /60 %60�� ����
	c = d % 60;

	printf("%d %d %d", a, b, c);
}

void tmp3() {
	int n, m, p, c;
	scanf_s("%d%d%d%d", &n, &m, &p, &c);

	// N - M + P

	printf("%d", n - m + p);
}

void tmp4() {
	int a, b;
	scanf_s("%d%d", &a, &b);

	if (a > b) printf(">");
	else if (a == b) printf("=");
	else printf("<");
}

void tmp5() {
	double a, b, c, d;
	scanf_s("%lf%lf%lf%lf", &a, &b, &c, &d);
	if (a / b > c / d) printf("1");
	else if (a / b == c / d) printf("0");
	else printf("-1");
}

int main() {
	return 0;
}