#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[6], chk[6];
int n, m;

void dice(int i, int d) {
	if (m == 1) {
		//Base Condition
		if (i > 6) return;
		if (d == n) {
			for (int k = 0; k < d; k++) {
				printf("%d ", a[k]);
			}
			printf("\n");
			return;
		}
		//Recursive Condition
		for (int j = 1; j <= 6; j++) {
			a[d] = j;
			dice(j, d + 1);
		}
	}
	else if (m == 2) {
		//Base Condition
		if (i > 6) return;
		if (d == n) {
			for (int k = 0; k < d; k++) {
				printf("%d ", a[k]);
			}
			printf("\n");
			return;
		}
		//Recursive Condition
		a[d] = i;
		dice(i, d + 1);
		a[d] = i + 1;
		dice(i + 1, d);
	}
	else if (m == 3) {
		//Base Condition
		if (i > 6) return;
		if (d == n) {
			for (int k = 0; k < d; k++) {
				printf("%d ", a[k]);
			}
			printf("\n");
			return;
		}
		//Recursive Condition
		for (int j = 1; j <= 6; j++) {
			if (!chk[j]) {
				chk[j] = 1;
				a[d] = j;
				dice(j, d + 1);
				chk[j] = 0;
			}
		}
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