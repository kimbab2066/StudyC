#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
// 1. 정렬, 그리디 
// 2.상태 괜찮고 다 했으면 4단계부터 복습
// 1~9, 0~9, 0~9, 0~9 총 39가지
#define MX 500001
int a[MX], s[MX][2], res[MX];
int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i;
	//a = (value, index)
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	int top = -1;
	//logic
	for (i = n; i >= 1; i--) {
		// 비어 있거나 제일 위에 있는 값이 현재 a[i][0]보다 큰 경우
		if (top == -1 || s[top][0] > a[i]) {
			//스택에 추가
			s[++top][0] = a[i];
			s[top][1] = i;
		}
		else {
			//값 정산
			for (top; top >= 0 && s[top][0] <= a[i]; top--) {
				res[s[top][1]] = i;
			}
			//top값을 a[i]로 업데이트
			s[++top][0] = a[i];
			s[top][1] = i;
		}
	}
	//output
	for (i = 1; i <= n; i++) {
		printf("%d ", res[i]);
	}

	return 0;
}//main