#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
/* n이 입력되고 n줄이 입력되는 동안 중간값을 출력해라
 7
1
5
2
10
-99
7
5
*/
int n;
priority_queue<int,pair<
int main(void) {
	//input
	scanf("%d", &n);
	int v;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
	}
	//logic

	//output

	return 0;
}//main