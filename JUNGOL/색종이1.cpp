#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int t[101][101];
int a[101], b[101];
int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i, j, k;
	for (i = 0; i < n; i++) {
		scanf_s("%d%d", &a[i], &b[i]);
		for (j = a[i]; j < a[i] + 10; j++) {
			for (k = b[i]; k < b[i] + 10; k++) {
				t[j][k] = 1;
			}
		}
	}
	//logic
	int cnt = 0;
	for (i = 1; i <= 100; i++) {
		for (j = 1; j <= 100; j++) {
			if (t[i][j])cnt++;
		}
	}
	//output
	printf("%d", cnt);

	return 0;
}//main