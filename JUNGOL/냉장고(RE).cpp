#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
/*
N���� ȭ�� ������ �־�����
���� �µ��� �ְ� �µ��� Ȱ���� �ּҷ� �ʿ��� ������� ������ ����ض�.
���� + �׸���

�ְ� �µ� �������� ����??
prev�� 0���� �����ؼ�
if <= then prev������Ʈ
else prev ������Ʈ + cnt++

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
		if (maxx < v[i].a) {//���� ������� �ִ밪���� ������ ���̽�ũ�� �ּҰ� ��ũ��
			maxx = v[i].b;//����� �߰��ϰ� �ִ밪 ������Ʈ
			cnt++;
		}
	}
	//output
	printf("%d", cnt);


	return 0;
}//main