#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//오후 - 학원
//저녁 - 복습 + 문제풀이
struct tmp {
	int x, y;
}k[100], t;

int chk(tmp a, tmp b) {
	return a.x < b.x;
}

int main() {
	//input
	int r, c, n;
	scanf_s("%d%d%d", &c, &r, &n);
	int i, j;
	int d, v;
	for (i = 0; i < n; i++) {
		scanf_s("%d%d", &d, &v);
		if (d == 0)k[i].x = v;
		else k[i].y = v;
	}
	//logic
	sort(k, k + n, chk);

	//output
	printf("111");

	return 0;
}//main