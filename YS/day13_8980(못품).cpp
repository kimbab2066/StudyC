#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//오후 -  그리디 과제(BOJ 2457,8980 둘 다 스스로 푼게 아님...) + 정렬 나머지 문제 1개
//약 1시간 30분 정도 고민해봤는데 둘 다 못했음
//저녁 - 
//너비우선 탐색 + 큐(0210예정)

struct tmp {
	int a, b, c;
}k[10010];
int vis[10010];

int chk(tmp x, tmp y) {
	if (x.a < y.a)return x.a < y.a;
	else return x.a < y.a&& x.b < y.b;
}

int main() {
	//input
	int n, c, m;
	scanf_s("%d%d%d", &n, &c, &m);
	int i, j = 0;
	for (i = 0; i < m; i++) {
		//보내는 마을, 받는 마을, 박스 개수
		scanf_s("%d%d%d", &k[i].a, &k[i].b, &k[i].c);
	}
	//logic
	sort(k, k + m, chk);
	int res = 0;//최대 박스 수
	int now = 1;//현재 위치
	for (i = 0; i < m; i++) {
		//박스가 비어 있지 않고(처음 보낼 경우 or 받는 마을이랑 현재 위치가 같은 경우(보내는 마을과 같은 경우)
		// 조건 1개만 잘달면 될거 같음
		if (now > 1) {
			for (j = 0; j < i; j++) {
				if (k[j].b == now && vis[j] == 1) { c += k[j].c; vis[j] = 0; }
			}
		}

		//보내는 마을이랑 현재 위치가 같은 경우
		if (k[i].a == now) {
			if (c >= k[i].c) {
				res += k[j].c;
				c -= k[i].c;
			}
			else {
				res += c;
				k[i].c -= c;
				c = 0;
				now++;
			}
			vis[i] = 1;
		}

	}//i
	//output
	printf("%d", res + c);
	return 0;
}//main