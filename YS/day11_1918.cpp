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
		else if (top == -1 || a[i] == '(') { // 비어 있거나 열린 괄호인 경우
			s[++top] = a[i];
		}
		else if (a[i] == ')') { // 닫힌 괄호인 경우
			while (1) {
				//종료 조건(열린 괄호를 만날 때 까지)
				if (s[top] == '(') { break; }
				printf("%c", s[top--]);
			}//w1
			top--; //열린 괄호 idx라서 빼주기
		}
		else if (a[i] == '*' || a[i] == '/') {
			while (1) {
				// 비어있거나, 열린 괄호를 만나거나(열린 괄호는 닫힌 괄호로만 지울 수 있음)
				// +,-는 우선순위가 후위기에 
				if (top == -1 || s[top] == '(' || s[top] == '+' || s[top] == '-')break;
				printf("%c", s[top--]);
			}
			// a[i](*,/)를 스택에 추가
			s[++top] = a[i];
		}
		else if (a[i] == '+' || a[i] == '-') {
			while (1) {
				//비어 있거나, 열린 괄호를 만나는 경우
				if (top == -1 || s[top] == '(')break;
				printf("%c", s[top--]);
			}
			// a[i](+,-)를 스택에 추가
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