#include <stdio.h>
#include <string.h>

char e[10], f[10];
int idx, idx2;


bool d(int a) {
	int sum, sum2;
	sum = sum2 = 0;
	int t = a;
	idx = idx2 = 0;
	//16진수
	while (1) {
		if (t % 16 <= 9)e[idx++] = t % 16 + '0';
		else e[idx++] = t % 16 + 55;
		t /= 16;
		//종료 조건
		if (t == 0)break;
	}
	t = a;
	//12진수
	while (1) {
		if (t % 12 <= 9)f[idx2++] = t % 12 + '0';
		else f[idx2++] = t % 12 + 55;
		t /= 12;
		//종료 조건
		if (t == 0)break;
	}
	// 자릿수 합계
	while (1) {
		idx--;
		if ('A' <= e[idx] && e[idx] <= 'Z')sum += e[idx] - 'A' + 10;
		else sum += e[idx] - '0';
		//종료 조건
		if (idx == 0)break;
	}

	if (sum == sum2) return true;
	else return false;
}//d

int main() {
	//input
	int i;
	//logic
	for (i = 2992; i <= 9999; i++) {
		if (d(i))printf("%d\n", i);
	}


	//output

	return 0;
}//main