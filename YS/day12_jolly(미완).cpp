#include <stdio.h>
#include <string.h>
/*
�Է� �ް� ó�� �� ���� �� ���� �������� ����
i%2==0 then i < i+1�� �ǵ���(�ּڰ� ã�Ƽ� �ٲ��ֱ�
else then i > i+1
*/
int a[100];

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i, j, p;
	int min, mink, max, maxk;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	// 0���� 1������ ũ�� �ٲ��ֱ�
	if (a[0] > a[1]) { int t = a[0]; a[0] = a[1]; a[1] = t; }
	//logic
	for (i = 2; i < n - 2; i++) {
		p = a[i]; min = 9999, mink = 0;
		max = maxk = 0;
		if (i % 2 == 0) {
			for (j = i + 1; j < n; j++) {
				if (min > a[j]) { min = a[j]; mink = j; }
			}
			a[mink] = a[i];
			a[i] = min;
		}
		else {
			for (j = i + 1; j < n; j++) {
				if (max < a[j]) { max = a[j]; maxk = j; }
			}
			a[maxk] = a[i];
			a[i] = max;
		}
	}
	//output
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}//main