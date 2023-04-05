#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
#define MX 100010
int n;
// 작은 값들을 저장하는 최소 힙(min heap), 하나는 큰 값들을 저장하는 최대 힙(max heap)
priority_queue <int, vector<int>, less<int>> max_heap;
priority_queue <int, vector<int>, greater<int>> min_heap;

int main(void) {
	//input
	int val;
	scanf("%d", &n);
	//logic
	while (n--) {
		scanf("%d", &val);
		// 새로운 값이 최대 힙의 루트보다 작거나 같은 경우, 최대 힙에 추가
		if (max_heap.empty()) max_heap.push(val);
		// 각 힙의 크기가 같다면, 우선순위 큰(max heap)쪽에 삽입
		else if (max_heap.size() == min_heap.size()) max_heap.push(val);
		// 그렇지 않다면 우선순위 낮은(min heap)쪽에 삽입
		else min_heap.push(val);

		// 최대 힙의 루트가 최소 힙의 루트보다 큰 경우, 서로의 루트를 교환
		if (!max_heap.empty() && !min_heap.empty() && !(max_heap.top() <= min_heap.top())) {
			int a = max_heap.top();
			int b = min_heap.top();
			max_heap.pop();
			min_heap.pop();

			max_heap.push(b);
			min_heap.push(a);
		}
		printf("%d\n", max_heap.top());
	}//n

	return 0;
}//main