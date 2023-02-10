#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//오후 - 그리디 복습 + 정렬 나머지 문제 1개
//저녁 - 
//너비우선 탐색 + 큐(0210예정)


//달
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct tmp {
	int st, ed;
}k[100010];

int chk(tmp a, tmp b) {
	return a.st < b.st;
}

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i, a, b, c, d;
	for (i = 0; i < n; i++) {
		scanf_s("%d%d%d%d", &a, &b, &c, &d);
		k[i].st = 100 * a + b;
		k[i].ed = 100 * c + d;
	}
	//logic
	sort(k, k + n, chk);

	int cnt = 0, now = 301, max = 0, idx = 0;
	for (i = 0; i < n; i++) {
		//종료 조건
		if (now > 1130)break;
		// 지는 날이 더 크면서 현재보다 먼저 피는 꽃인 경우
		if (max < k[i].ed && k[i].st <= now) {
			idx = i;
			//max 업데이트
			max = k[i].ed;
		}
		//꽃을 다시 봐야 되는 경우?
		if (k[i].st > now && max != 0) {
			//날짜 바꿔주기
			now = k[idx].ed;
			cnt++;
			i--;
			max = 0;
		}
		//모든 꽃 확인하는 경우(종료 조건)
		else if (max != 0 && i == n - 1) {
			now = k[idx].ed;
			cnt++;
			break;
		}
		// 비는 경우(종료 조건)
		else if (max == 0) {
			cnt = 0;
			break;
		}
	}
	//output
	if (now > 1130)printf("%d", cnt);
	else printf("0");


	return 0;
}//main