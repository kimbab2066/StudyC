#include <stdio.h>
#include <string.h>

char a[101], s[101];

int main() {
	//input
	int n, top = -1, i;
	scanf_s("%d", &n);
	//logic
	fgets(a, 101, stdin);
	for (i = 0; a[i] != 0; i++) {
		if (a[i] >= 'A' && a[i] <= 'Z')printf("%c", a[i]);
		else if (top == -1 || a[i] == '(') { // ��� �ְų� ���� ��ȣ�� ���
			s[++top] = a[i];
		}
		else if (a[i] == ')') { // ���� ��ȣ�� ���
			while (1) {
				//���� ����(���� ��ȣ�� ���� �� ����)
				if (s[top] == '(') { break; }
				printf("%c", s[top--]);
			}//w1
			top--; //���� ��ȣ idx�� ���ֱ�
		}
		else if (a[i] == '*' || a[i] == '/') {
			while (1) {
				// ����ְų�, ���� ��ȣ�� �����ų�(���� ��ȣ�� ���� ��ȣ�θ� ���� �� ����)
				// +,-�� �켱������ �����⿡ 
				if (top == -1 || s[top] == '(' || s[top] == '+' || s[top] == '-')break;
				printf("%c", s[top--]);
			}
			// a[i](*,/)�� ���ÿ� �߰�
			s[++top] = a[i];
		}
		else if (a[i] == '+' || a[i] == '-') {
			while (1) {
				//��� �ְų�, ���� ��ȣ�� ������ ���
				if (top == -1 || s[top] == '(')break;
				printf("%c", s[top--]);
			}
			// a[i](+,-)�� ���ÿ� �߰�
			s[++top] = a[i];
		}
	}//i

	//output
	while (1) {
		if (top == -1)break;
		printf("%c", s[top--]);
	}

	return 0;
}//main