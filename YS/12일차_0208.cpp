#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//오전(paren) + 재귀 + 스택(과제 남은거) + 재귀(omok 3시간 잡고 있음)
//점심 재귀 + 스택 -> 재귀(omok 3시간 30분 잡고 있음) -> 4:17분 끝(풀이 봤음)
//오후 X
//저녁 정렬 과제(radix) -> 1시간(풀이 봤음) + 35분(paper 못품)
// total : 5시간 50분

/*
19 20
4
0 5
1 3
0 4
1 18
*/

int a[101][101];

int main() {
	//input
	int r, c, n;
	scanf_s("%d%d%d", &r, &c, &n);
	int i, j;
	for (i = 1; i <= c; i++) {
		for (j = 1; j <= r; j++) {
			a[i][j] = 1;
		}
	}
	int v, v2;
	int w = 0, l = 0;
	for (i = 0; i < n; i++) {
		scanf_s("%d%d", &v, &v2);
		if (v == 0) l = l < v2 ? v2 : l;
		else w = w < v2 ? v2 : w;
	}
	//logic
	int cnt = 0, cnt2 = 0;
	for (i = 1; i <= l; i++) {
		for (j = 1; j <= w; j++) {
			if (a[i][j])cnt2++;
		}
	}
	for (i = l + 1; i <= c; i++) {
		for (j = w + 1; j <= r; j++) {
			if (a[i][j])cnt++;
		}
	}
	//output
	printf("%d", cnt);

	return 0;
}//main