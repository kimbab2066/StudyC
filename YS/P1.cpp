#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
// 1. ����, �׸��� 
// 2.���� ������ �� ������ 4�ܰ���� ����
// 1~9, 0~9, 0~9, 0~9 �� 39����
#define MX 500001
int a[MX], s[MX][2], res[MX];
int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i;
	//a = (value, index)
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	int top = -1;
	//logic
	for (i = n; i >= 1; i--) {
		// ��� �ְų� ���� ���� �ִ� ���� ���� a[i][0]���� ū ���
		if (top == -1 || s[top][0] > a[i]) {
			//���ÿ� �߰�
			s[++top][0] = a[i];
			s[top][1] = i;
		}
		else {
			//�� ����
			for (top; top >= 0 && s[top][0] <= a[i]; top--) {
				res[s[top][1]] = i;
			}
			//top���� a[i]�� ������Ʈ
			s[++top][0] = a[i];
			s[top][1] = i;
		}
	}
	//output
	for (i = 1; i <= n; i++) {
		printf("%d ", res[i]);
	}

	return 0;
}//main