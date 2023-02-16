#include<stdio.h>
#include<algorithm>
using namespace std;
struct tmp {
	int a, b;
}arr[50];
struct tmp2 {
	int a, b, cnt;
}tc[30];
int id[4] = { 0,2,3,1 };
int chk(tmp i, tmp j) {
	return id[i.a - 1] < id[j.a - 1] || ((i.a == 1 || i.a == 4) && id[i.a - 1] == id[j.a - 1] && i.b < j.b) || ((i.a == 2 || i.a == 3) && id[i.a - 1] == id[j.a - 1] && i.b > j.b);
}
int main()
{
	int n, l, r, l2, r2, cnt = 0, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &arr[i].a, &arr[i].b);
		if (i % 2 == 1) {
			tc[i / 2].a = arr[i - 1].a * 100 + arr[i - 1].b;
			tc[i / 2].b = arr[i].a * 100 + arr[i].b;
		}
	}
	sort(arr, arr + n, chk);
	//
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			// 같은 값이면 j로 바꿔주라는 의미
			if (arr[j].a * 100 + arr[j].b == tc[i].a) tc[i].a = j;
			if (arr[j].a * 100 + arr[j].b == tc[i].b) tc[i].b = j;
		}
	}
	for (int i = 0; i < n / 2 - 1; i++) {
		if (tc[i].a > tc[i].b) {
			l = tc[i].b; r = tc[i].a;
		}
		else {
			l = tc[i].a; r = tc[i].b;
		}
		for (int j = i + 1; j < n / 2; j++) {
			if (tc[j].a > tc[j].b) {
				l2 = tc[j].b; r2 = tc[j].a;
			}
			else {
				l2 = tc[j].a; r2 = tc[j].b;
			}
			// 조건 충족 시 cnt,tc[i],tc[j] ++
			if ((l2 < l && l < r2 && r2 < r) || (l2 < r && r < r2 && l < l2)) {
				cnt++;
				tc[i].cnt++;
				tc[j].cnt++;
			}
		}
	}
	for (int i = 0; i < n / 2; i++) {
		if (tc[i].cnt > max) max = tc[i].cnt;
	}
	printf("%d\n%d", cnt, max);
	return 0;
}