#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[6], n, m, sum;

void dice(int i, int d) {
	//Base Condition
	if (i > 6 || sum > m || d > n) return;
	if (d == n && sum == m) {
		for (int k = 0; k < d; k++) {
			printf("%d ", a[k]);
		}
		printf("\n");
		return;
	}
	//Recursive Condition
	for (int j = 1; j <= 6; j++) {
		a[d] = j;
		sum += j;
		dice(j, d + 1);
		sum -= j;
	}
}//dice

int main() {
	//input
	scanf_s("%d%d", &n, &m);
	//logic
	dice(1, 0);
	//output

	return 0;
}//main