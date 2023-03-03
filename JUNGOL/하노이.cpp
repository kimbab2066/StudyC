#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

void hanoi(int num, int from, int tmp, int to) {
	if (num == 0) return;
	//n-1개를 시작지점에서 tmp로 
	hanoi(num - 1, from, to, tmp);
	printf("%d : %d -> %d\n", num, from, to);
	hanoi(num - 1, tmp, from, to);
}

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	//logic
	hanoi(n, 1, 2, 3);

	return 0;
}//main