#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//���� -  �׸��� ����(BOJ 2457,8980 �� �� ������ Ǭ�� �ƴ�...) + ���� ������ ���� 1��
//�� 1�ð� 30�� ���� ����غôµ� �� �� ������
//���� - 
//�ʺ�켱 Ž�� + ť(0210����)

struct tmp {
	int a, b, c;
}k[10010];
int vis[10010];

int chk(tmp x, tmp y) {
	if (x.a < y.a)return x.a < y.a;
	else return x.a < y.a&& x.b < y.b;
}

int main() {
	//input
	int n, c, m;
	scanf_s("%d%d%d", &n, &c, &m);
	int i, j = 0;
	for (i = 0; i < m; i++) {
		//������ ����, �޴� ����, �ڽ� ����
		scanf_s("%d%d%d", &k[i].a, &k[i].b, &k[i].c);
	}
	//logic
	sort(k, k + m, chk);
	int res = 0;//�ִ� �ڽ� ��
	int now = 1;//���� ��ġ
	for (i = 0; i < m; i++) {
		//�ڽ��� ��� ���� �ʰ�(ó�� ���� ��� or �޴� �����̶� ���� ��ġ�� ���� ���(������ ������ ���� ���)
		// ���� 1���� �ߴ޸� �ɰ� ����
		if (now > 1) {
			for (j = 0; j < i; j++) {
				if (k[j].b == now && vis[j] == 1) { c += k[j].c; vis[j] = 0; }
			}
		}

		//������ �����̶� ���� ��ġ�� ���� ���
		if (k[i].a == now) {
			if (c >= k[i].c) {
				res += k[j].c;
				c -= k[i].c;
			}
			else {
				res += c;
				k[i].c -= c;
				c = 0;
				now++;
			}
			vis[i] = 1;
		}

	}//i
	//output
	printf("%d", res + c);
	return 0;
}//main