#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int t, n, i, j, k, v;
int num[101];

int main() {
	//input
	cin >> t;
	for (i = 1; i <= t; i++) {
		//�ʱ� �л��� ��
		k = 1000;
		//�迭 �ʱ� ����
		fill(num, num + 101, 0);
		// �����
		int max = 0, maxIdx = 0;
		cin >> n;
		//logic
		while (k--) {
			cin >> v;
			num[v]++;
		}
		for (j = 0; j <= 100; j++) {
			if (maxIdx < num[j]) {
				maxIdx = num[j];
				max = j;
			}
			else if (maxIdx == num[j]) {
				max = max > j ? max : j;
			}
		}
		cout << "#" << n << " " << max << "\n";
	}

	//output

	return 0;
}