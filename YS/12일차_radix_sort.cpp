#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

//����(paren) + ��� + ����(���� ������) + ���(omok 3�ð� ��� ����)
//���� ��� + ���� -> ���(omok 3�ð� 30�� ��� ����) -> 4:17�� ��(Ǯ�� ����)
//���� X
//���� ���� ����(radix) -> 1�ð�(Ǯ�� ����)

int a[10001];
int p[6];
int n, i, j, len;

int digit(int x, int a) {
	return (x / p[a]) % 10;
}

vector<int> l[10];

int main() {
	//input
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
		if (len < a[i])len = a[i];
	}

	//logic
	int d = 6;
	p[0] = 1;
	//�ڸ��� �ʱⰪ ����
	for (i = 1; i < d; i++) {
		p[i] = p[i - 1] * 10;
	}
	//�ڸ��� �ִ밪
	for (i = 1; p[i] != 0; i++) {
		if (len < p[i]) { d = i - 1; break; }
	}
	//radix sorting
	for (i = 0; i < d; i++) {
		//���� û��
		for (j = 0; j < 10; j++) {
			l[j].clear();
		}
		//���Ϳ� �� �߰�
		for (j = 0; j < n; j++) {
			l[digit(a[j], i)].push_back(a[j]);
		}
		int idx = 0;
		for (j = 0; j < 10; j++) {
			for (int k : l[j]) a[idx++] = k;
		}
	}//i

	//output
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}//main