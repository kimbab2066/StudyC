#include <stdio.h>

// 10개의 숫자 입력 받고 중복 제거하여 표현
// 10개의 수가 입력되지만 OFFSET 10 지정해야 함
// 단 한 번 쓰인 숫자 입력순으로 출력
#define OFF 10
int num[10], chk[21];

int main() {
	//input
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &num[i]);
		chk[num[i] + OFF]++;
	}
	//logic
	for (int i = 0; i < 10; i++) {
		if (chk[num[i] + OFF] == 1)printf("%d ", num[i]);
	}

	//output

	return 0;
}//main