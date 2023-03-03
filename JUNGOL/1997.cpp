#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int d, k, t[31];

int recur(int a, int b) {
	t[1] = a;
	t[2] = b;
	for (int i = 3; i <= d; i++) {
		t[i] = t[i - 1] + t[i - 2];
	}
	return t[d];
}


int main() {
	//input
	scanf_s("%d%d", &d, &k);
	//logic
	int i, j;
	for (i = 1; i <= k; i++) {
		for (j = i; j <= k; j++) {
			if (recur(i, j) == k) { printf("%d\n%d", i, j); return 0; }
		}
	}
	//output

	return 0;
}//main