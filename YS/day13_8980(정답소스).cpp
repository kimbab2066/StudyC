#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//오후 -  그리디 과제(BOJ 2457,8980 둘 다 스스로 푼게 아님...) + 정렬 나머지 문제 1개
//약 1시간 30분 정도 고민해봤는데 둘 다 못했음
//저녁 - 
//너비우선 탐색 + 큐(0210예정)

int ans;
struct tmp {
	int from, to, cost;
}k[10010];
int box[10010];

int chk(tmp x, tmp y) {
	if (x.from < y.from)return x.from < y.from;
	else return x.from < y.from&& x.to < y.to;
}

int main() {
	//input
	int n, c, m;
	scanf_s("%d%d%d", &n, &c, &m);
	int i, j = 0;
	for (i = 0; i < m; i++) {
		//보내는 마을, 받는 마을, 박스 개수
		scanf_s("%d%d%d", &k[i].from, &k[i].to, &k[i].cost);
	}
	//logic
	sort(k, k + m, chk);
	for (i = 0; i < m; i++) {
		tmp now = k[i];
		int boxCnt = 0;
		for (j = now.from; j < now.to; j++) {
			boxCnt = max(boxCnt, box[j]);
		}
		int add = min(now.cost, c - boxCnt);
		for (j = now.from; j < now.to; j++) {
			box[j] += add;
		}
		ans += add;
	}
	//output
	printf("%d", ans);

	return 0;
}//main