#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
#define MX 100010
int n;
// ���� ������ �����ϴ� �ּ� ��(min heap), �ϳ��� ū ������ �����ϴ� �ִ� ��(max heap)
priority_queue <int, vector<int>, less<int>> max_heap;
priority_queue <int, vector<int>, greater<int>> min_heap;

int main(void) {
	//input
	int val;
	scanf("%d", &n);
	//logic
	while (n--) {
		scanf("%d", &val);
		// ���ο� ���� �ִ� ���� ��Ʈ���� �۰ų� ���� ���, �ִ� ���� �߰�
		if (max_heap.empty()) max_heap.push(val);
		// �� ���� ũ�Ⱑ ���ٸ�, �켱���� ū(max heap)�ʿ� ����
		else if (max_heap.size() == min_heap.size()) max_heap.push(val);
		// �׷��� �ʴٸ� �켱���� ����(min heap)�ʿ� ����
		else min_heap.push(val);

		// �ִ� ���� ��Ʈ�� �ּ� ���� ��Ʈ���� ū ���, ������ ��Ʈ�� ��ȯ
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