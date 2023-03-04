#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt = 1;

void hanoi(int num, int from, int tmp, int to) {
	//재귀의 첫번째 조건(Base Condition)
	if (num == 0) return;
	hanoi(num - 1, from, to, tmp);
	printf("%d %d\n", from, to);
	hanoi(num - 1, tmp, from, to);
}

int main() {
	//input
	scanf_s("%d", &n);
	//logic
	int k = n;
	while (1) {
		if (k == 0) { cnt -= 1; break; }
		cnt *= 2;
		k--;
	}
	printf("%d\n", cnt);
	hanoi(n, 1, 2, 3);
	//output

	return 0;
}//main