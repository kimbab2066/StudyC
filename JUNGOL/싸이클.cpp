#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int cnt, n, p, a[100];

void cycle(int t) {
	//Base Condition
	if (a[t] == 2) return;
	a[t]++;
	cycle(t * n % p);
}

int main() {
	//input
	scanf_s("%d%d", &n, &p);
	//logic
	cycle(n * n % p);
	//output
	for (int i = 0; i < p; i++) {
		if (a[i] == 2) cnt++;
	}
	printf("%d", cnt);

	return 0;
}//main