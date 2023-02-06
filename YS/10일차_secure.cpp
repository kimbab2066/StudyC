#include <stdio.h>
#include <string.h>

int l, c;//패스워드 크기, 소문자의 개수	
char a[27], res[27], t;

bool vowel(char a) {
	return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

void pro(int vow, int con, int d, int idx) {
	//가지치기
	if (d == l && vow && con > 1) {
		for (int i = 0; i < l; i++) {
			printf("%c", res[i]);
		}
		printf("\n");
		return;
	}
	//k = 0 to c
	for (int k = idx; k < c; k++) {
		res[d] = a[k];
		if (vowel(a[k])) pro(vow + 1, con, d + 1, k + 1);
		else pro(vow, con + 1, d + 1, k + 1);
	}
}

int main() {
	//input
	scanf_s("%d%d", &l, &c);
	int i, j;
	for (i = 0; i < c; i++) {
		scanf_s("%s", &a[i], 2);
	}
	//정렬
	for (i = 0; i < c; i++) {
		for (j = i; j < c; j++) {
			if (a[i] > a[j]) t = a[i], a[i] = a[j], a[j] = t;
		}
	}
	//logic
	pro(0, 0, 0, 0);//모음,자음,깊이
	//output

	return 0;
}//main