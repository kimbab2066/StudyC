#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

//오전(paren) + 재귀 + 스택(과제 남은거) + 재귀(omok 3시간 잡고 있음)
//점심 재귀 + 스택 -> 재귀(omok 3시간 30분 잡고 있음) -> 4:17분 끝(풀이 봤음)
//오후 X
//저녁 정렬 과제(radix) -> 1시간(풀이 봤음)

int a[10001];
int p[6];
int n, i, j, len;

int digit(int x, int a) {
	return (x / p[a]) % 10;
}

vector<int> l[10];

int main() {
	//input
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
		if (len < a[i])len = a[i];
	}

	//logic
	int d = 6;
	p[0] = 1;
	//자리수 초기값 세팅
	for (i = 1; i < d; i++) {
		p[i] = p[i - 1] * 10;
	}
	//자리수 최대값
	for (i = 1; p[i] != 0; i++) {
		if (len < p[i]) { d = i - 1; break; }
	}
	//radix sorting
	for (i = 0; i < d; i++) {
		//벡터 청소
		for (j = 0; j < 10; j++) {
			l[j].clear();
		}
		//벡터에 값 추가
		for (j = 0; j < n; j++) {
			l[digit(a[j], i)].push_back(a[j]);
		}
		int idx = 0;
		for (j = 0; j < 10; j++) {
			for (int k : l[j]) a[idx++] = k;
		}
	}//i

	//output
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}//main