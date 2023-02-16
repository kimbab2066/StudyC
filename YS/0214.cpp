#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// 1.재귀, 스택, 정렬, 그리디 
// 2.상태 괜찮고 다 했으면 4단계부터 복습
// 1~9, 0~9, 0~9, 0~9 총 39가지
int q[10010];
char ch[20];
int st, ed;
int main() {
	//input
	int n;
	scanf_s("%d", &n);
	st = ed = -1;
	while (n--) {
		scanf_s("%s", &ch, 20);
		if (strcmp(ch, "push") == 0) {
			int x;
			scanf_s("%d", &x);
			q[++st] = x;
		}
		else if (strcmp(ch, "pop") == 0) {
			if (st == ed) printf("-1\n");
			else printf("%d\n", q[++ed]);
		}
		else if (strcmp(ch, "size") == 0) {
			printf("%d\n", st - ed);
		}
		else if (strcmp(ch, "empty") == 0) {
			if (st == ed) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(ch, "front") == 0) {
			if (st - ed == 0) printf("-1\n");
			else printf("%d\n", q[ed + 1]);
		}
		else if (strcmp(ch, "back") == 0) {
			if (st - ed == 0) printf("-1\n");
			else printf("%d\n", q[st]);
		}
	}//w

	//logic

	//output

	return 0;
}//main