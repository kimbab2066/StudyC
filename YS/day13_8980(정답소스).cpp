#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//���� -  �׸��� ����(BOJ 2457,8980 �� �� ������ Ǭ�� �ƴ�...) + ���� ������ ���� 1��
//�� 1�ð� 30�� ���� ����غôµ� �� �� ������
//���� - 
//�ʺ�켱 Ž�� + ť(0210����)

int ans;
struct tmp {
	int from, to, cost;
}k[10010];
int box[10010];

int chk(tmp x, tmp y) {
	if (x.from < y.from)return x.from < y.from;
	else return x.from < y.from&& x.to < y.to;
}

int main() {
	//input
	int n, c, m;
	scanf_s("%d%d%d", &n, &c, &m);
	int i, j = 0;
	for (i = 0; i < m; i++) {
		//������ ����, �޴� ����, �ڽ� ����
		scanf_s("%d%d%d", &k[i].from, &k[i].to, &k[i].cost);
	}
	//logic
	sort(k, k + m, chk);
	for (i = 0; i < m; i++) {
		tmp now = k[i];
		int boxCnt = 0;
		for (j = now.from; j < now.to; j++) {
			boxCnt = max(boxCnt, box[j]);
		}
		int add = min(now.cost, c - boxCnt);
		for (j = now.from; j < now.to; j++) {
			box[j] += add;
		}
		ans += add;
	}
	//output
	printf("%d", ans);

	return 0;
}//main