#include <stdio.h>

//
int a[10000];
int b[10000];
int num[100001];
int m;
double result;

int main() {
	//input
	int i, j;
	scanf_s("%d", &m);
	int v;
	//logic
	for (i = 1; i <= m; i++) {
		scanf_s("%d%d%d", &v, &a[i], &b[i]);
		if (a[i - 1] + b[i - 1] <= a[i]) {
			for (j = a[i]; j < a[i] + b[i]; j++) {
				num[j]++;
			}
		}
		else {
			for (j = a[i]; j < a[i - 1] + b[i - 1]; j++)num[j]++;
			a[i] += a[i - 1] + b[i - 1] - a[i];
			for (j = a[i]; j < a[i] + b[i]; j++) num[j]++;
		}
	}

	//output
	for (i = 1; i <= 100000; i++) {
		if (num[i] > 1)result += (num[i] - 1);
	}
	//output
	printf("%.1lf", result / m);

	return 0;
}//main