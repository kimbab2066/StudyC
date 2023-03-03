#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MX 100100
int a[MX];

int main() {
	//input
	int n, i, ans = 0, res = -999999;
	scanf_s("%d", &n);
	//logic
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
		ans = max(ans + a[i], a[i]);
		res = max(ans, res);
	}
	//output
	printf("%d", res);

	return 0;
}//main