#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[100000], n, idx;

void nq(int n) {
	if (n % 2 != 0 && n % 3 != 0) {
		//Ȧ��
		for (int i = 1; i <= n / 2; i++) a[idx++] = i * 2 - 1;
		//Ȧ������ ��� ������ ���� �߰�
		if (n % 2 == 1) a[idx++] = n;
		//¦��
		for (int i = 1; i <= n / 2; i++) a[idx++] = i * 2;
	}
	else if (n % 2 == 0) {
		//¦��
		for (int i = 1; i <= n / 2; i++) a[idx++] = i * 2;
		a[idx++] = 3;
		a[idx++] = 1;
		//Ȧ��
		//for (int i = 3; i <= n / 2; i++) a[idx++] = (i * 2) - 1;
		for (int i = ((n / 2) + 2); i < (n - 1); i++) a[idx++] = 1 + (2 * (i - (n / 2) + 1));
		a[idx++] = 5;
	}
	else if (n % 6 == 3) {
		//¦��(2�� ������)
		for (int i = 2; i <= n / 2; i++) a[idx++] = i * 2;
		a[idx++] = 2;
		//Ȧ��(1,3���� ������)
		//for (int i = 3; i <= n / 2; i++) a[idx++] = (i * 2) - 1;
		for (int i = (n / 2); i < (n - 2); i++) a[idx++] = 1 + (((i - (n / 2)) + 2) * 2);
		a[idx++] = 1;
		a[idx++] = 3;
	}
}

int main() {
	//input
	scanf_s("%d", &n);
	//logic
	nq(n);
	//output
	for (int i = 0; i < idx; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}//main