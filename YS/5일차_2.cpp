#include <stdio.h>

//프린터(다른 사람꺼 내껀 따로)
#define MAX 100

int main() {
	//input
	int arr[MAX];
	int n, m;
	int i, j;
	int mx, temp;
	scanf_s("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf_s("%d", &arr[i]);
	//logic
	for (i = 0; i < n; i++) {
		mx = i;
		for (j = i; j < n; j++) mx = arr[mx] < arr[j] ? j : mx;
		while (mx != i) {
			temp = arr[i];
			if (i == m) m = n;
			for (j = i; j < n - 1; j++) {
				arr[j] = arr[j + 1];
				if (j + 1 == m) m--;
			}
			arr[n - 1] = temp;
			if (m == n) m--;
			mx--;
		}//while
	}//for

	//output
	printf("%d", m + 1);

	return 0;
}//main