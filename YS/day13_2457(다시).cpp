#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//���� - �׸��� ���� + ���� ������ ���� 1��
//���� - 
//�ʺ�켱 Ž�� + ť(0210����)


//��
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct tmp {
	int st, ed;
}k[100010];

int chk(tmp a, tmp b) {
	return a.st < b.st;
}

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i, a, b, c, d;
	for (i = 0; i < n; i++) {
		scanf_s("%d%d%d%d", &a, &b, &c, &d);
		k[i].st = 100 * a + b;
		k[i].ed = 100 * c + d;
	}
	//logic
	sort(k, k + n, chk);

	int cnt = 0, now = 301, max = 0, idx = 0;
	for (i = 0; i < n; i++) {
		//���� ����
		if (now > 1130)break;
		// ���� ���� �� ũ�鼭 ���纸�� ���� �Ǵ� ���� ���
		if (max < k[i].ed && k[i].st <= now) {
			idx = i;
			//max ������Ʈ
			max = k[i].ed;
		}
		//���� �ٽ� ���� �Ǵ� ���?
		if (k[i].st > now && max != 0) {
			//��¥ �ٲ��ֱ�
			now = k[idx].ed;
			cnt++;
			i--;
			max = 0;
		}
		//��� �� Ȯ���ϴ� ���(���� ����)
		else if (max != 0 && i == n - 1) {
			now = k[idx].ed;
			cnt++;
			break;
		}
		// ��� ���(���� ����)
		else if (max == 0) {
			cnt = 0;
			break;
		}
	}
	//output
	if (now > 1130)printf("%d", cnt);
	else printf("0");


	return 0;
}//main