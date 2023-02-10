#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//오전(paren) + 재귀 + 스택(과제 남은거)
//점심 재귀 + 스택
//오후 예전꺼 복습
//저녁 정렬

int a[1000], cnt;



int main() {
	//input
	int n, i;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	//logic
	int l = 0;
	int r = n - 1;
	int s = 0;
	while (l < r) {
		for (i = l; i < r; i++) {
			if (a[i] > a[i + 1]) { int t = a[i]; a[i] = a[i + 1]; a[i + 1] = t; s = i + 1; }
		}
		r = s;
		for (i = r; i > l; i--) {
			if (a[i] < a[i - 1]) { int t = a[i]; a[i] = a[i - 1]; a[i - 1] = t; s = i - 1; }
		}
		l = s;
		cnt++;
	}
	//output
	printf("%d", cnt);

	return 0;
}//main