#include <stdio.h>

// 출력
// 짝수와 홀수의 모양이 조금 다름
// 첫 줄은 앞 2칸*, n칸 공백(다음줄엔 n-2), 뒤 2칸*
// 둘째줄부터 i-1칸*, i*i칸*, n-=2칸 공백, 바로 뒤*, 2칸 뒤*
// n이 짝수면 i == n 

// x y  v   w
// 2 3 4+n 5+n
// - +  -   +
// + +  -   -
// y <= v
// x <= w

// 1.초기 분석력이 부족함
// 2.조건식을 세우는데 5~10% 부족함
// 3.종료 조건을 세밀하게 생각 안했음

int main() {
	//input
	int i, j;
	int x, y, v, w, n;
	scanf_s("%d", &n);
	x = 2, y = 3, v = 4 + n, w = 5 + n;
	//logic
	for (i = 1;; i++) {
		for (j = 1; j <= w; j++) {
			if (j == x || j == w) printf("*");
			else if (y <= v && (j == y || j == v)) printf("*");
			else printf(" ");
		}
		printf("\n");
		if (i == 1)x--, y++, v--, w++;
		else x++, y++, v--, w--;
		// 종료 조건
		if (x > w) break;
	}
	//output

	return 0;
}//main