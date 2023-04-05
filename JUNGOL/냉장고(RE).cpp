#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
/*
N개의 화학 물질이 주어지면
최저 온도와 최고 온도를 활용해 최소로 필요한 냉장고의 개수를 출력해라.
정렬 + 그리디

최고 온도 오름차순 정렬??
prev를 0부터 시작해서
if <= then prev업데이트
else prev 업데이트 + cnt++

*/
int n;
struct tmp {
	int a, b;
};
vector<tmp> v;

int chk(tmp x, tmp y) {
	return x.b < y.b;
}

int main() {
	//input
	scanf("%d", &n);
	int i, x, y;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end(), chk);
	//logic
	int cnt = 0, maxx = -33333;
	for (i = 0; i < n; i++) {
		if (maxx < v[i].a) {//현재 냉장고의 최대값보다 보관할 아이스크림 최소값 더크면
			maxx = v[i].b;//냉장고 추가하고 최대값 업데이트
			cnt++;
		}
	}
	//output
	printf("%d", cnt);


	return 0;
}//main